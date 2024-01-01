#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "safeGet.h"
#include "queue.h"
#include "genericLinkedList.h"

int main()
{
    int test = safeGetIntInRange(2, 10);
    printf("%d", test);

    char string[20];
    safeGetStringNotEmpty(string, 19);
}