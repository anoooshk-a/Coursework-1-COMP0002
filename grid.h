#ifndef GRID_H
#define GRID_H

#include "util.h"

typedef enum
{
    EMPTY,
    MARKER, // grey
    BLOCK,  // black
    HOME    // blue
} GridType;

typedef struct
{
    Coordinates position;
    GridType type; // has an enum name of GridType and a variable name of type
    int row, col;
} GridSquare;

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

#define SQUARE_WIDTH 50
#define SQUARE_HEIGHT 50

#define ROWS_AND_COLUMNS 10
#define HOME_ROW 0
#define HOME_COL 0

// func that counts the number of markers in the grid and as a parameter take in the grid
int countMarker(GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS]);

void createGrid(GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS]);
void drawGrid(GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS]);
void drawGridSquare(GridSquare *grid);

#endif