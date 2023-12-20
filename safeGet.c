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
                strcat(validatedInput, &(input[i]));
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
    float isValidInt = 0.0;
    float inputValue = 0.0;
    while (!isValidInt)
    {
        printf("[decimal]: ");
        scanf("%f", &inputValue);

        printf("Got: %f\n", inputValue);
        isValidInt = safeGetContinue();
    }
    return inputValue;
}

char *safeGetStringNotEmpty();