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

    defineGenericLinkedList(int);

    struct GenericLinkedList(int) *linkedList = newGenericLinkedList(int);
    linkedList->pushBack(linkedList, 8);
    linkedList->pushFront(linkedList, 21);
    linkedList->pushBack(linkedList, 40);
    linkedList->pushBack(linkedList, 20);
    linkedList->pushAtIndex(linkedList, 2, 120);
    linkedList->assignAt(linkedList, 2, 90);

    for (int i = 0; i < linkedList->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", linkedList->at(linkedList, i));
    }

    printf("-------------------\n");
    linkedList->sortReverse(linkedList);
    printf("Contains returned: %d\n", linkedList->contains(linkedList, 77));

    for (int i = 0; i < linkedList->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", linkedList->at(linkedList, i));
    }

    linkedList->clear(linkedList);

    printf("Cleared Array: \n");
    for (int i = 0; i < linkedList->Length; i++)
    {
        printf("At position %d:", i);
        printf("%d\n", linkedList->at(linkedList, i));
    }

    return 0;
}