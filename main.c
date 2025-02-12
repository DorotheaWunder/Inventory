#include <stdio.h>
#include "raylib.h"
#include "ui.h"
#include "items.h"
#include "algorithms.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Inventory UI");

    InitializePanels();
    InitializeTable();

    SetTargetFPS(60);


    while (!WindowShouldClose()) // Main game loop
    {
        BeginDrawing();
        ClearBackground(BLACK);


        DrawMenu();

        //BubbleSort(items, INVENTORY_SIZE);


        EndDrawing();
    }

    CloseWindow();

    return 0;
}