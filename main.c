#include <stdlib.h>
#include <stdio.h>
#include "safeGet.h"
#include "queue.h"
#include "genericLinkedList.h"

int main()
{
    for (int i = 0; i < 10; i++)
    {
        struct GenericLinkedList(int) *linkedList = newGenericLinkedList(int);
        for (int i = 0; i < 100000; i++)
        {
            linkedList->pushBack(linkedList, rand());
        }

        for (int i = 0; i < linkedList->Length; i++)
        {
            printf("%d", linkedList->at(linkedList, i));
        }
        linkedList->dispose(linkedList);
    }
}