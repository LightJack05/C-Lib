#include <stdlib.h>

struct GenericLinkedList
{
    int Length;
    struct GenericLinkedListElement *ptrStart;
    struct GenericLinkedListElement *ptrEnd;
};

struct GenericLinkedListElement
{
    int data;
    struct GenericLinkedListElement *ptrNextElement;
};

struct GenericLinkedList *newGenericLinkedList()
{
    struct GenericLinkedList *newArray = (struct GenericLinkedList *)malloc(sizeof(struct GenericLinkedList));
    newArray->Length = 0;
    newArray->ptrStart = NULL;
    newArray->ptrEnd = NULL;
}

int genericLinkedListIsEmpty(struct GenericLinkedList *this)
{
    return this->ptrStart == NULL;
}

int genericLinkedListGetElementAtPosition(struct GenericLinkedList *this, int position)
{
    struct GenericLinkedListElement *currentElement = this->ptrStart;
    for (int i = 0; i < position; i++)
    {
        currentElement = currentElement->ptrNextElement;
    }
    return currentElement->data;
}

struct GenericLinkedListElement *genericLinkedListGetFullElementAtPosition(struct GenericLinkedList *this, int position)
{
    struct GenericLinkedListElement *currentElement = this->ptrStart;
    for (int i = 0; i < position; i++)
    {
        currentElement = currentElement->ptrNextElement;
    }
    return currentElement;
}

void genericLinkedListPushBack(struct GenericLinkedList *this, int data)
{
    struct GenericLinkedListElement *newElement = (struct GenericLinkedListElement *)malloc(sizeof(struct GenericLinkedListElement));
    newElement->data = data;
    newElement->ptrNextElement = NULL;

    if (genericLinkedListIsEmpty(this))
    {
        this->ptrStart = newElement;
        this->ptrEnd = newElement;
    }
    else
    {
        this->ptrEnd->ptrNextElement = newElement;
        this->ptrEnd = newElement;
    }
    this->Length++;
}

void genericLinkedListPushFront(struct GenericLinkedList *this, int data)
{
    struct GenericLinkedListElement *newElement = (struct GenericLinkedListElement *)malloc(sizeof(struct GenericLinkedListElement));
    newElement->data = data;
    newElement->ptrNextElement = NULL;

    if (genericLinkedListIsEmpty(this))
    {
        this->ptrStart = newElement;
        this->ptrEnd = newElement;
    }
    else
    {
        newElement->ptrNextElement = this->ptrStart;
        this->ptrStart = newElement;
    }
    this->Length++;
}

void genericLinkedListPushAtIndex(struct GenericLinkedList *this, int index, int data)
{
    // TODO: Check if array is empty
    if (index == 0)
    {
        genericLinkedListPushFront(this, data);
        return;
    }
    if (index == this->Length - 1)
    {
        genericLinkedListPushBack(this, data);
    }

    struct GenericLinkedListElement *newElement = malloc(sizeof(struct GenericLinkedListElement));
    newElement->data = data;
    struct GenericLinkedListElement *previousElement = genericLinkedListGetFullElementAtPosition(this, index - 1);
    struct GenericLinkedListElement *nextElement = genericLinkedListGetFullElementAtPosition(this, index);
    previousElement->ptrNextElement = newElement;
    newElement->ptrNextElement = nextElement;

    this->Length++;
}

int genericLinkedListPopLast(struct GenericLinkedList *this)
{

    int poppedData = this->ptrEnd->data;
    free(this->ptrEnd);
    this->ptrEnd = genericLinkedListGetFullElementAtPosition(this, this->Length - 2);
    if (this->ptrEnd == NULL)
    {
        this->ptrStart = NULL;
    }
    else
    {
        this->ptrEnd->ptrNextElement = NULL;
    }
    this->Length--;
    return poppedData;
}

int genericLinkedListPopFirst(struct GenericLinkedList *this)
{
    int poppedData;

    struct GenericLinkedListElement *newStart = this->ptrStart->ptrNextElement;
    poppedData = this->ptrStart->data;
    free(this->ptrStart);
    this->ptrStart = newStart;
    this->Length--;
    return poppedData;
}

int genericLinkedListPopAt(struct GenericLinkedList *this, int index)
{
    // TODO: Check if array is empty
    if (index == this->Length - 1)
    {
        return genericLinkedListPopLast(this);
    }
    if (index == 0)
    {
        return genericLinkedListPopFirst(this);
    }

    struct GenericLinkedListElement *elementToPop = genericLinkedListGetFullElementAtPosition(this, index);
    struct GenericLinkedListElement *previousElement = genericLinkedListGetFullElementAtPosition(this, index - 1);
    struct GenericLinkedListElement *nextElement = genericLinkedListGetFullElementAtPosition(this, index + 1);
    previousElement->ptrNextElement = nextElement;
    int dataOfPoppedElement = elementToPop->data;
    free(elementToPop);
    this->Length--;
    return dataOfPoppedElement;
}

int genericLinkedListFind(struct GenericLinkedList *this, int elementToSearch)
{
    int index = -1;
    struct GenericLinkedListElement *currentElement = this->ptrStart;
    for (int i = 0; i < this->Length; i++)
    {
        if (currentElement->data == elementToSearch)
        {
            index = i;
            break;
        }
        currentElement = currentElement->ptrNextElement;
    }
    return index;
}

int genericLinkedListFindLast(struct GenericLinkedList *this, int elementToSearch)
{
    int index = -1;
    struct GenericLinkedListElement *currentElement = this->ptrStart;
    for (int i = 0; i < this->Length; i++)
    {
        if (currentElement->data == elementToSearch)
        {
            index = i;
        }
        currentElement = currentElement->ptrNextElement;
    }
    return index;
}

int genericLinkedListAssignAt(struct GenericLinkedList *this, int index, int data)
{
    genericLinkedListGetFullElementAtPosition(this, index)->data = data;
}

void genericLinkedListSwapValuesAtPositions(struct GenericLinkedList *this, int indexOne, int indexTwo)
{
    int temp = genericLinkedListGetElementAtPosition(this, indexOne);
    genericLinkedListGetFullElementAtPosition(this, indexOne)->data = genericLinkedListGetElementAtPosition(this, indexTwo);
    genericLinkedListGetFullElementAtPosition(this, indexTwo)->data = temp;
}

void genericLinkedListSwapValuesAtPointers(struct GenericLinkedListElement *elementOne, struct GenericLinkedListElement *elementTwo)
{
    int temp = elementOne->data;
    elementOne->data = elementTwo->data;
    elementTwo->data = temp;
}

void genericLinkedListSort(struct GenericLinkedList *this)
{
    int endIndex = this->Length;
    while (endIndex > 0)
    {
        for (int i = 0; i < endIndex - 1; i++)
        {
            struct GenericLinkedListElement *elementOne = genericLinkedListGetFullElementAtPosition(this, i);
            struct GenericLinkedListElement *elementTwo = genericLinkedListGetFullElementAtPosition(this, i + 1);
            if (elementTwo->data < elementOne->data)
            {
                genericLinkedListSwapValuesAtPointers(elementOne, elementTwo);
            }
        }

        endIndex--;
    }
}

void genericLinkedListSortReverse(struct GenericLinkedList *this)
{
    int endIndex = this->Length;
    while (endIndex > 0)
    {
        for (int i = 0; i < endIndex - 1; i++)
        {
            struct GenericLinkedListElement *elementOne = genericLinkedListGetFullElementAtPosition(this, i);
            struct GenericLinkedListElement *elementTwo = genericLinkedListGetFullElementAtPosition(this, i + 1);
            if (elementTwo->data > elementOne->data)
            {
                genericLinkedListSwapValuesAtPointers(elementOne, elementTwo);
            }
        }

        endIndex--;
    }
}

int genericLinkedListContains(struct GenericLinkedList *this, int value)
{
    return (genericLinkedListFind(this, value) != -1);
}

int genericLinkedListClear(struct GenericLinkedList *this)
{
    while (this->Length > 0)
    {
        genericLinkedListPopFirst(this);
    }
}
