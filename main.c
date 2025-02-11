#include <stdio.h>
#include "raylib.h"
#include "ui.h"
#include "items.h"


int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Inventory UI");

    InitializeInventory(items);

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Main game loop
    {
        BeginDrawing();
        ClearBackground(BLACK);


        DrawUIPanel(inventoryPanel);
        DrawUIPanel(controlPanel);

        DrawTableHeader(tableHeader);
        DrawTableContent(tableContent);


        EndDrawing();
    }

    CloseWindow();

    return 0;
}