#include <stdlib.h>
#include <stdio.h>
#include "queue.c"
#include "array.c"

int main()
{
    defineGenericQueue(int);
    struct Queue(int) *intQueue = newQueue(int);
    intQueue->enQueue(intQueue, 16);
    printf("%d\n", intQueue->deQueue(intQueue));
    printf("%d\n", intQueue->isEmpty(intQueue));

    struct Array *array = newArray();
    arrayPushBack(array, 8);
    arrayPushFront(array, 21);
    arrayPushBack(array, 40);
    arrayPushBack(array, 20);
    arrayPushAtIndex(array, 2, 120);
    assignAt(array, 2, 90);

    for (int i = 0; i < array->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", arrayGetElementAtPosition(array, i));
    }

    printf("-------------------\n");
    arraySortReverse(array);
    printf("Contains returned: %d\n", arrayContains(array, 77));

    for (int i = 0; i < array->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", arrayGetElementAtPosition(array, i));
    }

    arrayClear(array);

    printf("Cleared Array: \n");
    for (int i = 0; i < array->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", arrayGetElementAtPosition(array, i));
    }

    return 0;
}