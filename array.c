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

int arrayPopLast(struct Array *this)
{

    int poppedData = this->ptrEnd->data;
    free(this->ptrEnd);
    this->ptrEnd = arrayGetFullElementAtPosition(this, this->Length - 2);
    this->ptrEnd = NULL;
    this->Length--;
    return poppedData;
}

int arrayPopAt(struct Array *this, int index)
{
    struct ArrayElement *elementToPop = arrayGetFullElementAtPosition(this, index);
    struct ArrayElement *previousElement = arrayGetFullElementAtPosition(this, index - 1);
    struct ArrayElement *nextElement = arrayGetFullElementAtPosition(this, index + 1);
    previousElement->ptrNextElement = nextElement;
    int dataOfPoppedElement = elementToPop->data;
    free(elementToPop);
    this->Length--;
    return dataOfPoppedElement;
}
