#include "safeGet.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void flushInputBuffer();

/// @brief Safely retrieve an integer from the console.
/// @return An integer entered and confirmed by the user.
int safeGetInt()
{
    int isValidInt = 0;
    int inputValue = 0;
    while (!isValidInt)
    {
        printf("[int]: ");
        scanf("%d", &inputValue);

        printf("Got: %d\n", inputValue);
        isValidInt = safeGetContinue();
    }
    return inputValue;
}

/// @brief Safely retrieve a positive integer from the console.
/// @return A positive integer entered and confirmed by the user.
int safeGetPositiveInt()
{
    int isValidInt = 0;
    int inputValue = 0;
    while (!isValidInt)
    {
        printf("[int>=0]: ");
        scanf("%d", &inputValue);
        if (inputValue >= 0)
        {
            printf("Got: %d\n", inputValue);
            isValidInt = safeGetContinue();
        }
    }
    return inputValue;
}

/// @brief Safely retrieve an integer from the user that lies within a specific range (both exclusive).
/// @param min Minimum value of the integer (exclusive).
/// @param max Maximum value of the integer (exclusive).
/// @return A value between the two integer values min and max (both exclusive).
int safeGetIntInRange(int min, int max)
{
    int isValidInt = 0;
    char inputString[10];
    int inputValue = 0;
    while (!isValidInt)
    {
        printf("[%d - %d]: ", min + 1, max - 1);
        scanf("%s", inputString);
        sscanf(inputString, "%d", &inputValue);
        if (inputValue > min && inputValue < max)
        {
            printf("Got: %d\n", inputValue);

            isValidInt = safeGetContinue();
        }
        else
        {
            printf("Out of range!\n");
        }
    }
    return inputValue;
}

/// @brief Retrieve int 0 or 1.
/// @return Either 1 or 0.
int safeGetBoolFromInt()
{
    return safeGetIntInRange(-1, 2);
}

/// @brief Confirm that the user wants to continue by typing y or n.
/// @warning: Will strip out any non-alpha chars from confirmation. May unexpectedly continue if the user enters non-alpha input alongside y or n.
/// @return 1 if user chose continue, otherwise 0.
int safeGetContinue()
{
    char validatedInput[10] = "";
    char input[10];

    int isValidInput = 0;
    while (!isValidInput)
    {
        printf("Continue? [y/n] ");
        safeGetStringAndFlushInputBuffer(input, 10);
        memset(validatedInput, 0, 10);
        for (int i = 0; i < strlen(input); i++)
        {
            if (isalpha(input[i]))
            {
                char currentChar[2];
                memset(currentChar, 0, 2);
                currentChar[0] = input[i];
                strcat(validatedInput, currentChar);
            }
        }

        if (!strcmp(validatedInput, "y") || !strcmp(validatedInput, "n"))
        {
            isValidInput = 1;
        }
    }
    return !strcmp(validatedInput, "y") ? 1 : 0;
}

/// @brief Safely retrieve a floating point number from user input.
/// @return A float number entered by the user.
float safeGetFloat()
{
    int isValidFloat = 0;
    float inputValue = 0.0;
    while (!isValidFloat)
    {
        printf("[decimal]: ");
        scanf("%f", &inputValue);

        printf("Got: %f\n", inputValue);
        isValidFloat = safeGetContinue();
    }
    return inputValue;
}

/// @brief Retrieve a string of length `maxLength` that is not empty from the user and write it into `string`.
/// @param string The string to write the input into.
/// @param maxLength The maximum length of the input. Must be smaller or equal to the string behind the char pointer.
void safeGetStringNotEmpty(char *string, int maxLength)
{
    char validatedInput[maxLength];
    char input[maxLength];

    int isValidInput = 0;
    while (!isValidInput)
    {
        printf("[text (max %d)]: ", maxLength - 1);
        safeGetStringAndFlushInputBuffer(input, maxLength);
        memset(validatedInput, 0, maxLength);
        for (int i = 0; i < strlen(input); i++)
        {
            if (!iscntrl(input[i]))
            {
                char currentChar[2];
                memset(currentChar, 0, 2);
                currentChar[0] = input[i];
                strcat(validatedInput, currentChar);
            }
        }
        printf("Got: %s\n", input);
        if (strlen(validatedInput) > 0 && safeGetContinue())
        {
            isValidInput = 1;
        }
        else
        {
            printf("Please enter something.\n");
        }
    }
    strcpy(string, validatedInput);
}

/// @brief Retrieve a string of length `maxLength` from user input and store it into `input`, then flush the buffer if necessary.
/// @param input The string to save the input into.
/// @param maxLengthThe maximum length of the input. Must be smaller or equal to the string behind the char pointer.
void safeGetStringAndFlushInputBuffer(char *input, int maxLength)
{
    fgets(input, maxLength, stdin);
    if (input[strlen(input) - 1] != '\n')
    {
        flushInputBuffer();
    }
}

/// @brief Flush the input buffer.
/// @warning `NOTE:` Do not use if the buffer is already empty, as it will cause the input to block and wait for a character.
static void flushInputBuffer()
{
    int flushDump;
    while (flushDump != '\n' && flushDump != EOF)
    {
        flushDump = getchar();
    }
}