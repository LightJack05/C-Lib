#include <stdlib.h>
#include <stdio.h>
#include "queue.c"
#include "array.c"

int main()
{
    // defineGenericQueue(int);
    // struct Queue(int) *intQueue = newQueue(int);
    // intQueue->enQueue(intQueue, 16);
    // printf("%d\n", intQueue->deQueue(intQueue));
    // printf("%d\n", intQueue->isEmpty(intQueue));

    struct Array *array = newArray();
    arrayPushBack(array, 3);
    arrayPushBack(array, 10);
    arrayPushBack(array, 20);
    for (int i = 0; i < array->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", arrayGetElementAtPosition(array, i));
    }
    // printf("%d\n", arrayPopLast(array));
    printf("%d\n", arrayPopAt(array, 1));
    for (int i = 0; i < array->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", arrayGetElementAtPosition(array, i));
    }

    return 0;
}