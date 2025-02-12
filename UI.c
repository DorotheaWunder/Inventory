#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "ui.h"
#include "items.h"

//---------------------------------------------------------------------------------- Panels
Panel inventoryPanel;
Panel categoryPanel;
Panel algorithmPanel;

void InitPanelElement(Panel* panel, Rectangle rectangle, Color color, const char* header)
{
    panel->rectangle = rectangle;
    panel->color = color;
    panel->header = header;
}

void InitializePanels()
{
    InitPanelElement(&inventoryPanel,
        (Rectangle){ 20, 20, 1300, 860 },
        (Color){ 80, 80, 80, 255 },
        "--- Inventory -------------------------------------------");

    InitPanelElement(&categoryPanel,
        (Rectangle){ 1340, 20, 220, 360 },
        (Color){ 130, 130, 130, 255 },
        "Sort by:");

    InitPanelElement(&algorithmPanel,
        (Rectangle){ 1340, 400, 220, 480 },
        (Color){ 130, 130, 130, 255 },
        "Using:");
}

void DrawPanelElement(Panel panel)
{
    DrawRectangleRec(panel.rectangle, panel.color);
    DrawText(panel.header, panel.rectangle.x + 10, panel.rectangle.y + 10, 45, WHITE);
}

void DrawAllPanels()
{
    DrawPanelElement(inventoryPanel);
    DrawPanelElement(categoryPanel);
    DrawPanelElement(algorithmPanel);
}

//---------------------------------------------------------------------------------- Table
TableHeader tableHeader;
TableContent tableContent;

void InitHeaderElement(TableHeader* header, Rectangle rectangle, Color color, const char* headers[4], int fontSize)
{
    header->rectangle = rectangle;
    header->color = color;

    for (int i = 0; i < 4; i++)
    {
        header->headers[i] = headers[i];
    }
    header->fontSize = fontSize;
}

void InitContentElement(TableContent* content, Rectangle rectangle, Color color, Item** items, int numRows, int fontSize)
{
    content->rectangle = rectangle;
    content-> color = color;
    content->items = items;
    content->numRows = numRows;
    content->fontSize = fontSize;
}

void InitializeTable()
{
    const char* headers[4] = { "Name", "Value", "Rarity", "Weight" };
    InitializeInventory(items);
    //would this be where I hash?

    InitHeaderElement(&tableHeader,
        (Rectangle){ 30, 100, 1280, 50 },
        GRAY,
        headers,
        30);

    InitContentElement(&tableContent,
        (Rectangle){ 30, 150, 600, 10 },
        LIGHTGRAY,
        items,
        INVENTORY_SIZE,
        25);
}

void PositionTextInCol(const char* text, float x, float y, float fontSize, Color color, float padding)
{
    DrawText(text, x + padding, y, fontSize, color);
}

//------------ change to percentage instead of pixel, also padding
void DrawTableHeader(TableHeader header)
{
    DrawRectangleRec(header.rectangle, header.color);

    float xPos = header.rectangle.x;
    float yPos = header.rectangle.y + 10;

    for (int i = 0; i < 4; i++)
    {
        PositionTextInCol(header.headers[i], xPos + i * 300, yPos, header.fontSize, WHITE, 10);
    }
}

void DrawTableContent(TableContent content)
{
    for (int i = 0; i < content.numRows; i++) {
        Item* item = content.items[i];
        float yPos = content.rectangle.y + 30 + i * 30;


        PositionTextInCol(item->name, content.rectangle.x, yPos, content.fontSize, WHITE, 10);
        PositionTextInCol(TextFormat("%d", item->value), content.rectangle.x + 400, yPos, content.fontSize, WHITE, 10);
        PositionTextInCol(TextFormat("%d", item->rarity), content.rectangle.x + 800, yPos, content.fontSize, WHITE, 10);
        PositionTextInCol(TextFormat("%0.1f", item->weight), content.rectangle.x + 1200, yPos, content.fontSize, WHITE, 10);
    }
}

void DrawTable(TableHeader header, TableContent content)
{
    DrawTableHeader(header);
    DrawTableContent(content);
}

//---------------------------------------------------------------------------------- Button

void InitButtonElement(Button* button, Rectangle rectangle, Color defColor, Color hovColor, const char* text)
{
    button->rectangle = rectangle;
    button->defaultColor = defColor;
    button->hoverColor = hovColor;
    button->text = text;
}


bool IsHovering(Button button)
{
    Vector2 mousePosition = GetMousePosition();
    //return CheckCollisionPointTriangle(mousePosition, (Rectangle) );
}

void DrawButton(Button button)
{
    //if hovering
}

//--- get mouse position?,check hover; check click


//---------------------------------------------------------------------------------- Whole UI

void DrawMenu()
{
    DrawAllPanels();
    DrawTable(tableHeader, tableContent);
}