#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>

typedef void *voidPtr;
#define declareGenericLinkedList(T)                                                                                                                \
    struct GenericLinkedList##T                                                                                                                    \
    {                                                                                                                                              \
        int Length;                                                                                                                                \
        struct GenericLinkedListElement##T *ptrStart;                                                                                              \
        struct GenericLinkedListElement##T *ptrEnd;                                                                                                \
        int (*isEmpty)(struct GenericLinkedList##T * this);                                                                                        \
        T(*at)                                                                                                                                     \
        (struct GenericLinkedList##T * this, int position);                                                                                        \
        struct GenericLinkedListElement##T *(*fullElementAt)(struct GenericLinkedList##T * this, int position);                                    \
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
    int genericLinkedListIsEmpty##T(struct GenericLinkedList##T *this);                                                                            \
                                                                                                                                                   \
    T genericLinkedListGetElementAtPosition##T(struct GenericLinkedList##T *this, int position);                                                   \
                                                                                                                                                   \
    struct GenericLinkedListElement##T *genericLinkedListGetFullElementAtPosition##T(struct GenericLinkedList##T *this, int position);             \
                                                                                                                                                   \
    void genericLinkedListPushBack##T(struct GenericLinkedList##T *this, T data);                                                                  \
                                                                                                                                                   \
    void genericLinkedListPushFront##T(struct GenericLinkedList##T *this, T data);                                                                 \
                                                                                                                                                   \
    void genericLinkedListPushAtIndex##T(struct GenericLinkedList##T *this, int index, T data);                                                    \
                                                                                                                                                   \
    T genericLinkedListPopLast##T(struct GenericLinkedList##T *this);                                                                              \
                                                                                                                                                   \
    T genericLinkedListPopFirst##T(struct GenericLinkedList##T *this);                                                                             \
                                                                                                                                                   \
    T genericLinkedListPopAt##T(struct GenericLinkedList##T *this, int index);                                                                     \
                                                                                                                                                   \
    int genericLinkedListFind##T(struct GenericLinkedList##T *this, T elementToSearch);                                                            \
                                                                                                                                                   \
    int genericLinkedListFindLast##T(struct GenericLinkedList##T *this, T elementToSearch);                                                        \
                                                                                                                                                   \
    void genericLinkedListAssignAt##T(struct GenericLinkedList##T *this, int index, T data);                                                       \
                                                                                                                                                   \
    void genericLinkedListSwapValuesAtPositions##T(struct GenericLinkedList##T *this, int indexOne, int indexTwo);                                 \
                                                                                                                                                   \
    void genericLinkedListSwapValuesAtPointers##T(struct GenericLinkedListElement##T *elementOne, struct GenericLinkedListElement##T *elementTwo); \
                                                                                                                                                   \
    void genericLinkedListSort##T(struct GenericLinkedList##T *this);                                                                              \
                                                                                                                                                   \
    void genericLinkedListSortReverse##T(struct GenericLinkedList##T *this);                                                                       \
                                                                                                                                                   \
    int genericLinkedListContains##T(struct GenericLinkedList##T *this, T value);                                                                  \
                                                                                                                                                   \
    int genericLinkedListClear##T(struct GenericLinkedList##T *this);                                                                              \
                                                                                                                                                   \
    struct GenericLinkedList##T *newGenericLinkedList##T();

#define newGenericLinkedList(T) newGenericLinkedList##T()
#define GenericLinkedList(T) GenericLinkedList##T

declareGenericLinkedList(int);
declareGenericLinkedList(long);
declareGenericLinkedList(float);
declareGenericLinkedList(double);
declareGenericLinkedList(voidPtr);

#endif // ARRAY_H