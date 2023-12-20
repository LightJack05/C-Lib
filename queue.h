#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef void *voidPtr;

#define declareGenericQueue(T)                                                                               \
    struct QueueElement##T                                                                                   \
    {                                                                                                        \
        T data;                                                                                              \
        struct QueueElement##T *ptrNextElement; /*Pointer to the next element in the queue, enqueued later*/ \
    };                                                                                                       \
    struct Queue##T                                                                                          \
    {                                                                                                        \
        struct QueueElement##T *end;   /* Pointer to last element enqueued*/                                 \
        struct QueueElement##T *start; /* Pointer to first element in queue*/                                \
        int (*isEmpty)(struct Queue##T *);                                                                   \
        void (*enQueue)(struct Queue##T *, T);                                                               \
        T(*deQueue)                                                                                          \
        (struct Queue##T *);                                                                                 \
    };                                                                                                       \
                                                                                                             \
    int isQueueEmpty##T(struct Queue##T *queue);                                                             \
    void enQueue##T(struct Queue##T *queue, T data);                                                         \
    T deQueue##T(struct Queue##T *queue);                                                                    \
    struct Queue##T *newQueue##T();

declareGenericQueue(short);
declareGenericQueue(int);
declareGenericQueue(long);

declareGenericQueue(float);
declareGenericQueue(double);

declareGenericQueue(voidPtr);

#define QueueElement(T) QueueElement##T
#define Queue(T) Queue##T
#define isQueueEmpty(T) isQueueEmpty##T
#define newQueue(T) newQueue##T()

#endif // QUEUE_H
