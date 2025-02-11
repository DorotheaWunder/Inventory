#include "raylib.h"
#include "ui.h"
#include "items.h"

Panel inventoryPanel = { { 20, 20, 1300, 860 },
    DARKGRAY, "--- Inventory -------------------------------------------" };
Panel controlPanel = { { 1340, 20, 220, 860 },
    GRAY, "Controls" };

TableHeader tableHeader =
    {
        { 30, 100, 1280, 50 },
        GRAY,
        { "Name", "Value", "Rarity", "Weight" }, //columns for better spacing?
        30
    };

TableContent tableContent =
    {
        { 30, 150, 600, 10 },
        LIGHTGRAY,
        items,
        15,
        25
    };


void DrawUIPanel(Panel panel)
{
    DrawRectangleRec(panel.rectangle, panel.color);
    DrawText(panel.header, panel.rectangle.x + 10, panel.rectangle.y + 10, 45, WHITE);
}


//------------ change to percentage instead of pixel, also padding
void DrawTableHeader(TableHeader header)
{
    DrawRectangleRec(header.rectangle, header.color);
    DrawText(header.headers[0], header.rectangle.x + 10, header.rectangle.y + 10, header.fontSize, WHITE);
    DrawText(header.headers[1], header.rectangle.x + 400, header.rectangle.y + 10, header.fontSize, WHITE);
    DrawText(header.headers[2], header.rectangle.x + 700, header.rectangle.y + 10, header.fontSize, WHITE);
    DrawText(header.headers[3], header.rectangle.x + 1050, header.rectangle.y + 10, header.fontSize, WHITE);
}

void DrawTableContent(TableContent content)
{
    for (int i = 0; i < content.numRows; i++) {
        Item* item = content.items[i];

        DrawText(item->name, content.rectangle.x + 10, content.rectangle.y + 30 + i * 30, content.fontSize, WHITE);
        DrawText(TextFormat("%d", item->value), content.rectangle.x + 430, content.rectangle.y + 30 + i * 30, content.fontSize, WHITE);
        DrawText(TextFormat("%d", item->rarity), content.rectangle.x + 740, content.rectangle.y + 30 + i * 30, content.fontSize, WHITE);
        DrawText(TextFormat("%d", item->weight), content.rectangle.x + 1090, content.rectangle.y + 30 + i * 30, content.fontSize, WHITE);
    }
}

void DrawTable(TableHeader header, TableContent content)
{
    DrawTableHeader(header);
    DrawTableContent(content);
}

void DrawMenu()
{
    DrawUIPanel(inventoryPanel);
    DrawUIPanel(controlPanel);
    DrawTable(tableHeader, tableContent);
}