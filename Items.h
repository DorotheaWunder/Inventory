#ifndef ITEMS_H
#define ITEMS_H

typedef struct Item
{
    char name[50];
    int value;
    int rarity;
    float weight;
} Item;

#define INVENTORY_SIZE 20
extern Item* items[];

Item* createItem(const char* name, int value, int rarity, float weight);
void InitializeInventory(Item** inventory);


#endif //ITEMS_H
