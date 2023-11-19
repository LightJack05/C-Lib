#include <stdlib.h>

struct Array
{
    int Length;
    struct ArrayElement *ptrStart;
    struct ArrayElement *ptrEnd;
};

struct ArrayElement
{
    int data;
    struct ArrayElement *ptrNextElement;
};

struct Array *newArray()
{
    struct Array *newArray = (struct Array *)malloc(sizeof(struct Array));
    newArray->Length = 0;
    newArray->ptrStart = NULL;
    newArray->ptrEnd = NULL;
}

int arrayIsEmpty(struct Array *this)
{
    return this->ptrStart == NULL;
}

int arrayGetElementAtPosition(struct Array *this, int position)
{
    struct ArrayElement *currentElement = this->ptrStart;
    for (int i = 0; i < position; i++)
    {
        currentElement = currentElement->ptrNextElement;
    }
    return currentElement->data;
}

struct ArrayElement *arrayGetFullElementAtPosition(struct Array *this, int position)
{
    struct ArrayElement *currentElement = this->ptrStart;
    for (int i = 0; i < position; i++)
    {
        currentElement = currentElement->ptrNextElement;
    }
    return currentElement;
}

void arrayPushBack(struct Array *this, int data)
{
    struct ArrayElement *newElement = (struct ArrayElement *)malloc(sizeof(struct ArrayElement));
    newElement->data = data;
    newElement->ptrNextElement = NULL;

    if (arrayIsEmpty(this))
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

void arrayPushFront(struct Array *this, int data)
{
    struct ArrayElement *newElement = (struct ArrayElement *)malloc(sizeof(struct ArrayElement));
    newElement->data = data;
    newElement->ptrNextElement = NULL;

    if (arrayIsEmpty(this))
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

void arrayPushAtIndex(struct Array *this, int index, int data)
{
    // TODO: Check if array is empty
    if (index == 0)
    {
        arrayPushFront(this, data);
        return;
    }
    if (index == this->Length - 1)
    {
        arrayPushBack(this, data);
    }

    struct ArrayElement *newElement = malloc(sizeof(struct ArrayElement));
    newElement->data = data;
    struct ArrayElement *previousElement = arrayGetFullElementAtPosition(this, index - 1);
    struct ArrayElement *nextElement = arrayGetFullElementAtPosition(this, index);
    previousElement->ptrNextElement = newElement;
    newElement->ptrNextElement = nextElement;

    this->Length++;
}

int arrayPopLast(struct Array *this)
{

    int poppedData = this->ptrEnd->data;
    free(this->ptrEnd);
    this->ptrEnd = arrayGetFullElementAtPosition(this, this->Length - 2);
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

int arrayPopFirst(struct Array *this)
{
    int poppedData;

    struct ArrayElement *newStart = this->ptrStart->ptrNextElement;
    poppedData = this->ptrStart->data;
    free(this->ptrStart);
    this->ptrStart = newStart;
    this->Length--;
    return poppedData;
}

int arrayPopAt(struct Array *this, int index)
{
    // TODO: Check if array is empty
    if (index == this->Length - 1)
    {
        return arrayPopLast(this);
    }
    if (index == 0)
    {
        return arrayPopFirst(this);
    }

    struct ArrayElement *elementToPop = arrayGetFullElementAtPosition(this, index);
    struct ArrayElement *previousElement = arrayGetFullElementAtPosition(this, index - 1);
    struct ArrayElement *nextElement = arrayGetFullElementAtPosition(this, index + 1);
    previousElement->ptrNextElement = nextElement;
    int dataOfPoppedElement = elementToPop->data;
    free(elementToPop);
    this->Length--;
    return dataOfPoppedElement;
}

int arrayFind(struct Array *this, int elementToSearch)
{
    int index = -1;
    struct ArrayElement *currentElement = this->ptrStart;
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

int arrayFindLast(struct Array *this, int elementToSearch)
{
    int index = -1;
    struct ArrayElement *currentElement = this->ptrStart;
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

int assignAt(struct Array *this, int index, int data)
{
    arrayGetFullElementAtPosition(this, index)->data = data;
}

void arraySwapValuesAtPositions(struct Array *this, int indexOne, int indexTwo)
{
    int temp = arrayGetElementAtPosition(this, indexOne);
    arrayGetFullElementAtPosition(this, indexOne)->data = arrayGetElementAtPosition(this, indexTwo);
    arrayGetFullElementAtPosition(this, indexTwo)->data = temp;
}

void arraySwapValuesAtPointers(struct ArrayElement *elementOne, struct ArrayElement *elementTwo)
{
    int temp = elementOne->data;
    elementOne->data = elementTwo->data;
    elementTwo->data = temp;
}

void arraySort(struct Array *this)
{
    int endIndex = this->Length;
    while (endIndex > 0)
    {
        for (int i = 0; i < endIndex - 1; i++)
        {
            struct ArrayElement *elementOne = arrayGetFullElementAtPosition(this, i);
            struct ArrayElement *elementTwo = arrayGetFullElementAtPosition(this, i + 1);
            if (elementTwo->data < elementOne->data)
            {
                arraySwapValuesAtPointers(elementOne, elementTwo);
            }
        }

        endIndex--;
    }
}

void arraySortReverse(struct Array *this)
{
    int endIndex = this->Length;
    while (endIndex > 0)
    {
        for (int i = 0; i < endIndex - 1; i++)
        {
            struct ArrayElement *elementOne = arrayGetFullElementAtPosition(this, i);
            struct ArrayElement *elementTwo = arrayGetFullElementAtPosition(this, i + 1);
            if (elementTwo->data > elementOne->data)
            {
                arraySwapValuesAtPointers(elementOne, elementTwo);
            }
        }

        endIndex--;
    }
}

int arrayContains(struct Array *this, int value)
{
    return (arrayFind(this, value) != -1);
}

int arrayClear(struct Array *this)
{
    while (this->Length > 0)
    {
        arrayPopFirst(this);
    }
}
