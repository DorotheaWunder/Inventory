#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "items.h"
#include "ui.h"

typedef enum Category
{
    NAME,
    VALUE,
    RARITY,
    WEIGHT

    //--- last aquired?
} Category;


int CompareByName(Item* a, Item* b);
int CompareByValue(Item* a, Item* b);
int CompareByRarity(Item* a, Item* b);
int CompareByWeight(Item* a, Item* b);

void SwapPosition(Item** a, Item** b);

void BubbleSortAlgorithm(Item** inventory, int size, int (*compare)(Item*, Item*));

void SortInventory(Item** inventory, int size, Category category);

#endif //ALGORITHMS_H

// SORTING HAS TO BE OTHER WAY ROUND, HIGHEST VALUE ON TOP