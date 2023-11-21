#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main()
{
    struct Queueint *intQueue = newQueue(int);
    intQueue->enQueue(intQueue, 24);
    intQueue->enQueue(intQueue, 25);
    intQueue->enQueue(intQueue, 26);
    intQueue->enQueue(intQueue, 27);
    intQueue->enQueue(intQueue, 28);
    printf("%d\n", intQueue->deQueue(intQueue));
    printf("%d\n", intQueue->deQueue(intQueue));
    printf("%d\n", intQueue->deQueue(intQueue));
    printf("%d\n", intQueue->deQueue(intQueue));
    printf("%d\n", intQueue->deQueue(intQueue));
    printf("%d\n", intQueue->isEmpty(intQueue));

    printf("------------------\n");

    struct Queue(float) *floatQueue = newQueue(float);
    floatQueue->enQueue(floatQueue, 0.1);
    floatQueue->enQueue(floatQueue, 0.2);
    floatQueue->enQueue(floatQueue, 0.3);
    floatQueue->enQueue(floatQueue, 0.4);
    floatQueue->enQueue(floatQueue, 0.5);
    printf("%f\n", floatQueue->deQueue(floatQueue));
    printf("%f\n", floatQueue->deQueue(floatQueue));
    printf("%f\n", floatQueue->deQueue(floatQueue));
    printf("%f\n", floatQueue->deQueue(floatQueue));
    printf("%f\n", floatQueue->deQueue(floatQueue));
    printf("%d\n", floatQueue->isEmpty(floatQueue));

    printf("-----------------------\n");

    struct Queue(voidPtr) *voidQueue = newQueue(voidPtr);
    struct someObject
    {
        int something;
    };
    struct someObject *object = malloc(sizeof(struct someObject));
    object->something = 2;

    voidQueue->enQueue(voidQueue, object);
    printf("%d\n", ((struct someObject *)voidQueue->deQueue(voidQueue))->something);
}