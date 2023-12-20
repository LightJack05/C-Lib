#include <stdlib.h>
#include <stdio.h>
#include "safeGet.h"
#include "queue.h"
#include "genericLinkedList.h"

int main()
{
    float someFloat = safeGetFloat();
    printf("%f\n", someFloat);
    return 0;
}