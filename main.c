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

    struct GenericLinkedList *array = newGenericLinkedList();
    genericLinkedListPushBack(array, 8);
    genericLinkedListPushFront(array, 21);
    genericLinkedListPushBack(array, 40);
    genericLinkedListPushBack(array, 20);
    genericLinkedListPushAtIndex(array, 2, 120);
    genericLinkedListAssignAt(array, 2, 90);

    for (int i = 0; i < array->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", genericLinkedListGetElementAtPosition(array, i));
    }

    printf("-------------------\n");
    genericLinkedListSortReverse(array);
    printf("Contains returned: %d\n", genericLinkedListContains(array, 77));

    for (int i = 0; i < array->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", genericLinkedListGetElementAtPosition(array, i));
    }

    genericLinkedListClear(array);

    printf("Cleared Array: \n");
    for (int i = 0; i < array->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", genericLinkedListGetElementAtPosition(array, i));
    }

    return 0;
}