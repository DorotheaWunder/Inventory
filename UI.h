#ifndef UI_H
#define UI_H

#include "raylib.h"
#include "items.h"

#define SCREEN_WIDTH 1580
#define SCREEN_HEIGHT 900

typedef struct Panel
{
    Rectangle rectangle;
    Color color;
    const char* header;
} Panel;

typedef struct TableHeader
{
    Rectangle rectangle;
    Color color;
    const char* headers[4];
    int fontSize;
} TableHeader;

typedef struct TableContent
{
    Rectangle rectangle;
    Color color;
    Item** items;
    int numRows;
    int fontSize;
} TableContent;






extern Panel inventoryPanel;
extern Panel controlPanel;

extern TableHeader tableHeader;
extern TableContent tableContent;

void DrawUIPanel(Panel panel);
void DrawTableHeader(TableHeader header);
void DrawTableContent(TableContent content);
void DrawTable(TableHeader header, TableContent content);
void DrawMenu();

#endif //UI_H





//
//
// typedef struct Button
// {
//     float height;
//     float width;
//
//     int posX;
//     int posY;
//
//     Color defaultColor;
//     Color hoverColor;
//
//     //text
//     //trigger method
// } Button;
