#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "items.h"

typedef enum Category
{
    NAME,
    VALUE,
    RARITY,
    WEIGHT

    //--- last aquired?
} Category;

void SwapPosition(Item** a, Item** b);
void BubbleSort(Item** inventory, int size);

#endif //ALGORITHMS_H
