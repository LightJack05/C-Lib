#include <stdlib.h>
#include <stdio.h>
#include "safeGet.h"
#include "queue.h"
#include "genericLinkedList.h"

int main()
{
    int someInt = safeGetIntInRange(2, 20);
    printf("%d\n", someInt);
    return 0;
}