#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
/*
Example usage:

    defineGenericQueue(char);
    struct Queue(char) *charQueue = newQueue(char);
    charQueue->enQueue(charQueue, 'A');
    charQueue->enQueue(charQueue, 'B');
    charQueue->enQueue(charQueue, 'C');
    printf("%c\n", charQueue->deQueue(charQueue));
    printf("%c\n", charQueue->deQueue(charQueue));
    printf("%c\n", charQueue->deQueue(charQueue));
    printf("%d\n", charQueue->isEmpty(charQueue));
*/

#define defineGenericQueue(T)                                                                                  \
                                                                                                               \
    int isQueueEmpty##T(struct Queue##T *queue)                                                                \
    {                                                                                                          \
        return (queue->start == NULL);                                                                         \
    }                                                                                                          \
                                                                                                               \
    void enQueue##T(struct Queue##T *queue, T data)                                                            \
    {                                                                                                          \
        struct QueueElement##T *newElement = (struct QueueElement##T *)malloc(sizeof(struct QueueElement##T)); \
                                                                                                               \
        if (newElement == NULL)                                                                                \
        {                                                                                                      \
            fprintf(stderr, "Memory allocation failed in enQueue.");                                           \
            return;                                                                                            \
        }                                                                                                      \
        newElement->data = data;                                                                               \
        newElement->ptrNextElement = NULL;                                                                     \
        if (isQueueEmpty##T(queue))                                                                            \
        {                                                                                                      \
            queue->start = newElement;                                                                         \
            queue->end = newElement;                                                                           \
        }                                                                                                      \
        else                                                                                                   \
        {                                                                                                      \
            queue->end->ptrNextElement = newElement;                                                           \
        }                                                                                                      \
        queue->end = newElement;                                                                               \
    }                                                                                                          \
                                                                                                               \
    T deQueue##T(struct Queue##T *queue)                                                                       \
    {                                                                                                          \
                                                                                                               \
        if (queue->start->ptrNextElement == NULL)                                                              \
        {                                                                                                      \
            T lastValue = queue->start->data;                                                                  \
            free(queue->start);                                                                                \
            queue->start = NULL;                                                                               \
            return lastValue;                                                                                  \
        }                                                                                                      \
        T startValue = queue->start->data;                                                                     \
        struct QueueElement##T *newStart = queue->start->ptrNextElement;                                       \
        free(queue->start);                                                                                    \
        queue->start = newStart;                                                                               \
        return startValue;                                                                                     \
    }                                                                                                          \
                                                                                                               \
    struct Queue##T *newQueue##T()                                                                             \
    {                                                                                                          \
        struct Queue##T *queue = (struct Queue##T *)malloc(sizeof(struct Queue##T));                           \
        queue->start = NULL;                                                                                   \
        queue->end = NULL;                                                                                     \
        queue->isEmpty = isQueueEmpty##T;                                                                      \
        queue->enQueue = enQueue##T;                                                                           \
        queue->deQueue = deQueue##T;                                                                           \
        return queue;                                                                                          \
    }

#define QueueElement(T) QueueElement##T
#define Queue(T) Queue##T
// #define isQueueEmpty(T) isQueueEmpty##T
// #define enQueue(T) enQueue##T
// #define deQueue(T) deQueue##T
#define newQueue(T) newQueue##T()

defineGenericQueue(short);
defineGenericQueue(int);
defineGenericQueue(long);

defineGenericQueue(float);
defineGenericQueue(double);

defineGenericQueue(voidPtr);