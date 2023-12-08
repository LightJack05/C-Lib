#include "safeGet.h"
#include <stdio.h>

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
        printf("[int>0]: ");
        scanf("%d", &inputValue);
        if (inputValue > 0)
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
    int inputValue = 0;
    while (!isValidInt)
    {
        printf("[%d - %d]: ", min + 1, max - 1);
        scanf("%d", &inputValue);
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
    safeGetIntInRange(0, 2);
}

int safeGetContinue()
{

    char symbol = 'f';

    int isValidInput = 0;
    while (!isValidInput)
    {
        printf("Continue? [y/n] ");
        scanf(" %c", &symbol);
        if (symbol == 'y' || symbol == 'n')
        {
            isValidInput = 1;
        }
    }
    return symbol == 'y' ? 1 : 0;
}

float safeGetFloat();

char *safeGetStringNotEmpty();