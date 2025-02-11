#include "raylib.h"
#include "ui.h"
#include "items.h"

Panel inventoryPanel = { { 10, 10, 600, 580 }, DARKGRAY, "Inventory" };
Panel controlPanel = { { 620, 10, 170, 300 }, GRAY, "Controls" };

TableHeader tableHeader =
    {
        { 10, 60, 600, 40 },
        GRAY,
        { "Name", "Value", "Rarity", "Weight" },
        20
    };

TableContent tableContent =
    {
        { 10, 40, 600, 550 },
        LIGHTGRAY,
        items,
        3,
        20
    };


void DrawUIPanel(Panel panel)
{
    DrawRectangleRec(panel.rectangle, panel.color);
    DrawText(panel.header, panel.rectangle.x + 10, panel.rectangle.y + 10, 30, WHITE);
}


void DrawTableHeader(TableHeader header)
{
    DrawRectangleRec(header.rectangle, header.color);
    DrawText(header.headers[0], header.rectangle.x + 10, header.rectangle.y + 10, header.fontSize, WHITE);
    DrawText(header.headers[1], header.rectangle.x + 150, header.rectangle.y + 10, header.fontSize, WHITE);
    DrawText(header.headers[2], header.rectangle.x + 300, header.rectangle.y + 10, header.fontSize, WHITE);
    DrawText(header.headers[3], header.rectangle.x + 450, header.rectangle.y + 10, header.fontSize, WHITE);
}

void DrawTableContent(TableContent content)
{
    for (int i = 0; i < content.numRows; i++) {
        Item* item = content.items[i];

        DrawText(item->name, content.rectangle.x + 10, content.rectangle.y + 30 + i * 30, content.fontSize, WHITE);
        DrawText(TextFormat("%d", item->value), content.rectangle.x + 150, content.rectangle.y + 30 + i * 30, content.fontSize, WHITE);
        DrawText(TextFormat("%d", item->rarity), content.rectangle.x + 300, content.rectangle.y + 30 + i * 30, content.fontSize, WHITE);
        DrawText(TextFormat("%d", item->weight), content.rectangle.x + 450, content.rectangle.y + 30 + i * 30, content.fontSize, WHITE);
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