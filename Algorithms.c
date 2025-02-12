#include "raylib.h"
#include "algorithms.h"
#include "items.h"
#include <string.h>

void SwapPosition(Item** a, Item** b)
{
    Item* temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(Item** inventory, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (inventory[j]->weight > inventory[j + 1]->weight)
            {
                SwapPosition(&inventory[j], &inventory[j+1]);
            }
        }
    }
}