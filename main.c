#include <stdlib.h>
#include <stdio.h>
#include "safeGet.h"
#include "queue.h"
#include "genericLinkedList.h"

int main()
{
    // setvbuf(stdin, NULL, _IONBF, 0);

    for (int i = 0; i < 1; i++)
    {
        struct GenericLinkedList(voidPtr) *linkedList = newGenericLinkedList(voidPtr);
        for (int j = 0; j < 5; j++)
        {
            char string[20];
            // safeGetStringNotEmpty(string, 19);
            safeGetStringNotEmpty(string, sizeof(string) - 1);
            linkedList->pushBack(linkedList, string);
        }

        for (int j = 0; j < linkedList->Length; j++)
        {
            free(linkedList->at(linkedList, j));
        }
        linkedList->dispose(linkedList);
    }
}