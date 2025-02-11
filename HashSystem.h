﻿#ifndef HASHSYSTEM_H
#define HASHSYSTEM_H

#include "items.h"

typedef struct Node
{
    Item* item;
    struct Node* previous;
    struct Node* next;
} Node;

#define TABLE_SIZE 20

typedef struct HashTable
{
    Node* hashTable[TABLE_SIZE];
} HashTable;


#endif //HASHSYSTEM_H
