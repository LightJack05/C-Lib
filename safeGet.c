#include "safeGet.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int safeGetBoolFromInt()
{
    return safeGetIntInRange(0, 2);
}

int safeGetContinue()
{
    char validatedInput[10] = "";
    char input[10];

    int isValidInput = 0;
    while (!isValidInput)
    {
        printf("Continue? [y/n] ");
        scanf("%9s", input);
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

void safeGetStringNotEmpty(char *string, int maxLength)
{
    char validatedInput[maxLength];
    char input[maxLength];

    int isValidInput = 0;
    while (!isValidInput)
    {
        printf("[text]: ");
        char lengthAsString[20];
        sprintf(lengthAsString, "%d", maxLength - 1);
        char format[22] = "%";
        strcat(format, lengthAsString);
        strcat(format, "s");
        scanf(format, input);
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
    }
    strcpy(string, validatedInput);
}