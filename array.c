#include <stdlib.h>

#define defineGenericLinkedList(T)                                                                                                                 \
    struct GenericLinkedList##T                                                                                                                    \
    {                                                                                                                                              \
        int Length;                                                                                                                                \
        struct GenericLinkedListElement##T *ptrStart;                                                                                              \
        struct GenericLinkedListElement##T *ptrEnd;                                                                                                \
        int (*isEmpty)(struct GenericLinkedList##T * this);                                                                                        \
        T(*at)                                                                                                                                     \
        (struct GenericLinkedList##T * this, int position);                                                                                        \
        struct GenericLinkedListElement##T (*FullElementAt)(struct GenericLinkedList##T * this, int position);                                     \
        void (*pushBack)(struct GenericLinkedList##T * this, T data);                                                                              \
        void (*pushFront)(struct GenericLinkedList##T * this, T data);                                                                             \
        void (*pushAtIndex)(struct GenericLinkedList##T * this, int index, T data);                                                                \
        T(*popLast)                                                                                                                                \
        (struct GenericLinkedList##T * this);                                                                                                      \
        T(*popFirst)                                                                                                                               \
        (struct GenericLinkedList##T * this);                                                                                                      \
        T(*popAt)                                                                                                                                  \
        (struct GenericLinkedList##T * this, int index);                                                                                           \
        int (*find)(struct GenericLinkedList##T * this, T elementToSearch);                                                                        \
        int (*findLast)(struct GenericLinkedList##T * this, T elementToSearch);                                                                    \
        void (*assignAt)(struct GenericLinkedList##T * this, int index, T data);                                                                   \
        void (*swapValuesAtPositions)(struct GenericLinkedList##T * this, int indexOne, int indexTwo);                                             \
        void (*swapValuesAtPointers)(struct GenericLinkedListElement##T * elementOne, struct GenericLinkedListElement##T *elementTwo);             \
        void (*sort)(struct GenericLinkedList##T * this);                                                                                          \
        void (*sortReverse)(struct GenericLinkedList##T * this);                                                                                   \
        int (*contains)(struct GenericLinkedList##T * this, T value);                                                                              \
        int (*clear)(struct GenericLinkedList##T * this);                                                                                          \
    };                                                                                                                                             \
                                                                                                                                                   \
    struct GenericLinkedListElement##T                                                                                                             \
    {                                                                                                                                              \
        T data;                                                                                                                                    \
        struct GenericLinkedListElement##T *ptrNextElement;                                                                                        \
    };                                                                                                                                             \
                                                                                                                                                   \
    struct GenericLinkedList##T *newGenericLinkedList##T()                                                                                         \
    {                                                                                                                                              \
        struct GenericLinkedList##T *newArray = (struct GenericLinkedList##T *)malloc(sizeof(struct GenericLinkedList));                           \
        newArray->Length = 0;                                                                                                                      \
        newArray->ptrStart = NULL;                                                                                                                 \
        newArray->ptrEnd = NULL;                                                                                                                   \
        newArray->isEmpty = genericLinkedListIsEmpty##T;                                                                                           \
        /*TODO: Add function references*/                                                                                                          \
    }                                                                                                                                              \
                                                                                                                                                   \
    int genericLinkedListIsEmpty##T(struct GenericLinkedList##T *this)                                                                             \
    {                                                                                                                                              \
        return this->ptrStart == NULL;                                                                                                             \
    }                                                                                                                                              \
                                                                                                                                                   \
    T genericLinkedListGetElementAtPosition##T(struct GenericLinkedList##T *this, int position)                                                    \
    {                                                                                                                                              \
        struct GenericLinkedListElement##T *currentElement = this->ptrStart;                                                                       \
        for (int i = 0; i < position; i++)                                                                                                         \
        {                                                                                                                                          \
            currentElement = currentElement->ptrNextElement;                                                                                       \
        }                                                                                                                                          \
        return currentElement->data;                                                                                                               \
    }                                                                                                                                              \
                                                                                                                                                   \
    struct GenericLinkedListElement##T *genericLinkedListGetFullElementAtPosition##T(struct GenericLinkedList##T *this, int position)              \
    {                                                                                                                                              \
        struct GenericLinkedListElement##T *currentElement = this->ptrStart;                                                                       \
        for (int i = 0; i < position; i++)                                                                                                         \
        {                                                                                                                                          \
            currentElement = currentElement->ptrNextElement;                                                                                       \
        }                                                                                                                                          \
        return currentElement;                                                                                                                     \
    }                                                                                                                                              \
                                                                                                                                                   \
    void genericLinkedListPushBack##T(struct GenericLinkedList##T *this, T data)                                                                   \
    {                                                                                                                                              \
        struct GenericLinkedListElement##T *newElement = (struct GenericLinkedListElement##T *)malloc(sizeof(struct GenericLinkedListElement##T)); \
        newElement->data = data;                                                                                                                   \
        newElement->ptrNextElement = NULL;                                                                                                         \
                                                                                                                                                   \
        if (genericLinkedListIsEmpty##T(this))                                                                                                     \
        {                                                                                                                                          \
            this->ptrStart = newElement;                                                                                                           \
            this->ptrEnd = newElement;                                                                                                             \
        }                                                                                                                                          \
        else                                                                                                                                       \
        {                                                                                                                                          \
            this->ptrEnd->ptrNextElement = newElement;                                                                                             \
            this->ptrEnd = newElement;                                                                                                             \
        }                                                                                                                                          \
        this->Length++;                                                                                                                            \
    }                                                                                                                                              \
                                                                                                                                                   \
    void genericLinkedListPushFront##T(struct GenericLinkedList##T *this, T data)                                                                  \
    {                                                                                                                                              \
        struct GenericLinkedListElement##T *newElement = (struct GenericLinkedListElement##T *)malloc(sizeof(struct GenericLinkedListElement##T)); \
        newElement->data = data;                                                                                                                   \
        newElement->ptrNextElement = NULL;                                                                                                         \
                                                                                                                                                   \
        if (genericLinkedListIsEmpty##T(this))                                                                                                     \
        {                                                                                                                                          \
            this->ptrStart = newElement;                                                                                                           \
            this->ptrEnd = newElement;                                                                                                             \
        }                                                                                                                                          \
        else                                                                                                                                       \
        {                                                                                                                                          \
            newElement->ptrNextElement = this->ptrStart;                                                                                           \
            this->ptrStart = newElement;                                                                                                           \
        }                                                                                                                                          \
        this->Length++;                                                                                                                            \
    }                                                                                                                                              \
                                                                                                                                                   \
    void genericLinkedListPushAtIndex##T(struct GenericLinkedList##T *this, int index, T data)                                                     \
    {                                                                                                                                              \
                                                                                                                                                   \
        if (index == 0)                                                                                                                            \
        {                                                                                                                                          \
            genericLinkedListPushFront##T(this, data);                                                                                             \
            return;                                                                                                                                \
        }                                                                                                                                          \
        if (index == this->Length - 1)                                                                                                             \
        {                                                                                                                                          \
            genericLinkedListPushBack##T(this, data);                                                                                              \
        }                                                                                                                                          \
                                                                                                                                                   \
        struct GenericLinkedListElement##T *newElement = malloc(sizeof(struct GenericLinkedListElement));                                          \
        newElement->data = data;                                                                                                                   \
        struct GenericLinkedListElement##T *previousElement = genericLinkedListGetFullElementAtPosition##T(this, index - 1);                       \
        struct GenericLinkedListElement##T *nextElement = genericLinkedListGetFullElementAtPosition##T(this, index);                               \
        previousElement->ptrNextElement = newElement;                                                                                              \
        newElement->ptrNextElement = nextElement;                                                                                                  \
                                                                                                                                                   \
        this->Length++;                                                                                                                            \
    }                                                                                                                                              \
                                                                                                                                                   \
    T genericLinkedListPopLast##T(struct GenericLinkedList##T *this)                                                                               \
    {                                                                                                                                              \
                                                                                                                                                   \
        T poppedData = this->ptrEnd->data;                                                                                                         \
        free(this->ptrEnd);                                                                                                                        \
        this->ptrEnd = genericLinkedListGetFullElementAtPosition##T(this, this->Length - 2);                                                       \
        if (this->ptrEnd == NULL)                                                                                                                  \
        {                                                                                                                                          \
            this->ptrStart = NULL;                                                                                                                 \
        }                                                                                                                                          \
        else                                                                                                                                       \
        {                                                                                                                                          \
            this->ptrEnd->ptrNextElement = NULL;                                                                                                   \
        }                                                                                                                                          \
        this->Length--;                                                                                                                            \
        return poppedData;                                                                                                                         \
    }                                                                                                                                              \
                                                                                                                                                   \
    T genericLinkedListPopFirst##T(struct GenericLinkedList##T *this)                                                                              \
    {                                                                                                                                              \
        T poppedData;                                                                                                                              \
                                                                                                                                                   \
        struct GenericLinkedListElement##T *newStart = this->ptrStart->ptrNextElement;                                                             \
        poppedData = this->ptrStart->data;                                                                                                         \
        free(this->ptrStart);                                                                                                                      \
        this->ptrStart = newStart;                                                                                                                 \
        this->Length--;                                                                                                                            \
        return poppedData;                                                                                                                         \
    }                                                                                                                                              \
                                                                                                                                                   \
    T genericLinkedListPopAt##T(struct GenericLinkedList##T *this, int index)                                                                      \
    {                                                                                                                                              \
                                                                                                                                                   \
        if (index == this->Length - 1)                                                                                                             \
        {                                                                                                                                          \
            return genericLinkedListPopLast##T(this);                                                                                              \
        }                                                                                                                                          \
        if (index == 0)                                                                                                                            \
        {                                                                                                                                          \
            return genericLinkedListPopFirst##T(this);                                                                                             \
        }                                                                                                                                          \
                                                                                                                                                   \
        struct GenericLinkedListElement##T *elementToPop = genericLinkedListGetFullElementAtPosition##T(this, index);                              \
        struct GenericLinkedListElement##T *previousElement = genericLinkedListGetFullElementAtPosition##T(this, index - 1);                       \
        struct GenericLinkedListElement##T *nextElement = genericLinkedListGetFullElementAtPosition##T(this, index + 1);                           \
        previousElement->ptrNextElement = nextElement;                                                                                             \
        T dataOfPoppedElement = elementToPop->data;                                                                                                \
        free(elementToPop);                                                                                                                        \
        this->Length--;                                                                                                                            \
        return dataOfPoppedElement;                                                                                                                \
    }                                                                                                                                              \
                                                                                                                                                   \
    int genericLinkedListFind##T(struct GenericLinkedList##T *this, T elementToSearch)                                                             \
    {                                                                                                                                              \
        int index = -1;                                                                                                                            \
        struct GenericLinkedListElement##T *currentElement = this->ptrStart;                                                                       \
        for (int i = 0; i < this->Length; i++)                                                                                                     \
        {                                                                                                                                          \
            if (currentElement->data == elementToSearch)                                                                                           \
            {                                                                                                                                      \
                index = i;                                                                                                                         \
                break;                                                                                                                             \
            }                                                                                                                                      \
            currentElement = currentElement->ptrNextElement;                                                                                       \
        }                                                                                                                                          \
        return index;                                                                                                                              \
    }                                                                                                                                              \
                                                                                                                                                   \
    int genericLinkedListFindLast##T(struct GenericLinkedList##T *this, T elementToSearch)                                                         \
    {                                                                                                                                              \
        int index = -1;                                                                                                                            \
        struct GenericLinkedListElement##T *currentElement = this->ptrStart;                                                                       \
        for (int i = 0; i < this->Length; i++)                                                                                                     \
        {                                                                                                                                          \
            if (currentElement->data == elementToSearch)                                                                                           \
            {                                                                                                                                      \
                index = i;                                                                                                                         \
            }                                                                                                                                      \
            currentElement = currentElement->ptrNextElement;                                                                                       \
        }                                                                                                                                          \
        return index;                                                                                                                              \
    }                                                                                                                                              \
                                                                                                                                                   \
    void genericLinkedListAssignAt##T(struct GenericLinkedList##T *this, int index, T data)                                                        \
    {                                                                                                                                              \
        genericLinkedListGetFullElementAtPosition##T(this, index)->data = data;                                                                    \
    }                                                                                                                                              \
                                                                                                                                                   \
    void genericLinkedListSwapValuesAtPositions##T(struct GenericLinkedList##T *this, int indexOne, int indexTwo)                                  \
    {                                                                                                                                              \
        T temp = genericLinkedListGetElementAtPosition##T(this, indexOne);                                                                         \
        genericLinkedListGetFullElementAtPosition##T(this, indexOne)->data = genericLinkedListGetElementAtPosition##T(this, indexTwo);             \
        genericLinkedListGetFullElementAtPosition##T(this, indexTwo)->data = temp;                                                                 \
    }                                                                                                                                              \
                                                                                                                                                   \
    void genericLinkedListSwapValuesAtPointers##T(struct GenericLinkedListElement##T *elementOne, struct GenericLinkedListElement##T *elementTwo)  \
    {                                                                                                                                              \
        T temp = elementOne->data;                                                                                                                 \
        elementOne->data = elementTwo->data;                                                                                                       \
        elementTwo->data = temp;                                                                                                                   \
    }                                                                                                                                              \
                                                                                                                                                   \
    void genericLinkedListSort##T(struct GenericLinkedList##T *this)                                                                               \
    {                                                                                                                                              \
        int endIndex = this->Length;                                                                                                               \
        while (endIndex > 0)                                                                                                                       \
        {                                                                                                                                          \
            for (int i = 0; i < endIndex - 1; i++)                                                                                                 \
            {                                                                                                                                      \
                struct GenericLinkedListElement##T *elementOne = genericLinkedListGetFullElementAtPosition##T(this, i);                            \
                struct GenericLinkedListElement##T *elementTwo = genericLinkedListGetFullElementAtPosition##T(this, i + 1);                        \
                if (elementTwo->data < elementOne->data)                                                                                           \
                {                                                                                                                                  \
                    genericLinkedListSwapValuesAtPointers##T(elementOne, elementTwo);                                                              \
                }                                                                                                                                  \
            }                                                                                                                                      \
                                                                                                                                                   \
            endIndex--;                                                                                                                            \
        }                                                                                                                                          \
    }                                                                                                                                              \
                                                                                                                                                   \
    void genericLinkedListSortReverse##T(struct GenericLinkedList##T *this)                                                                        \
    {                                                                                                                                              \
        int endIndex = this->Length;                                                                                                               \
        while (endIndex > 0)                                                                                                                       \
        {                                                                                                                                          \
            for (int i = 0; i < endIndex - 1; i++)                                                                                                 \
            {                                                                                                                                      \
                struct GenericLinkedListElement##T *elementOne = genericLinkedListGetFullElementAtPosition##T(this, i);                            \
                struct GenericLinkedListElement##T *elementTwo = genericLinkedListGetFullElementAtPosition##T(this, i + 1);                        \
                if (elementTwo->data > elementOne->data)                                                                                           \
                {                                                                                                                                  \
                    genericLinkedListSwapValuesAtPointers##T(elementOne, elementTwo);                                                              \
                }                                                                                                                                  \
            }                                                                                                                                      \
                                                                                                                                                   \
            endIndex--;                                                                                                                            \
        }                                                                                                                                          \
    }                                                                                                                                              \
                                                                                                                                                   \
    int genericLinkedListContains##T(struct GenericLinkedList##T *this, T value)                                                                   \
    {                                                                                                                                              \
        return (genericLinkedListFind##T(this, value) != -1);                                                                                      \
    }                                                                                                                                              \
                                                                                                                                                   \
    int genericLinkedListClear##T(struct GenericLinkedList##T *this)                                                                               \
    {                                                                                                                                              \
        while (this->Length > 0)                                                                                                                   \
        {                                                                                                                                          \
            genericLinkedListPopFirst##T(this);                                                                                                    \
        }                                                                                                                                          \
    }                                                                                                                                              \
    \