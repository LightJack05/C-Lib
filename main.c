#include <stdlib.h>
#include <stdio.h>
#include "safeGet.h"
#include "queue.h"
#include "genericLinkedList.h"

int main()
{
    char *string[100];
    safeGetStringNotEmpty(string, 99);
    printf(string);
}