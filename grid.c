#include "grid.h"
#include "graphics.h"

void createGrid(GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS])
{
    int grid_start_x = 125, grid_start_y = 125;

    for (int row = 0; row < ROWS_AND_COLUMNS; row++)
    {
        for (int col = 0; col < ROWS_AND_COLUMNS; col++)
        {
            grid[row][col].row = row;
            grid[row][col].col = col;
            grid[row][col].type = EMPTY; // initialises all gridsquares to empty
            grid[row][col].position.x = grid_start_x + (col * SQUARE_WIDTH);
            grid[row][col].position.y = grid_start_y + (row * SQUARE_HEIGHT);
        }
    }
    grid[0][0].type = HOME;
    grid[7][8].type = MARKER;
    grid[9][8].type = MARKER;
    grid[0][5].type = MARKER;
    grid[6][0].type = BLOCK;
    grid[5][5].type = BLOCK;
    grid[8][8].type = BLOCK;
}

void drawGrid(GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS])
{
    for (int row = 0; row < ROWS_AND_COLUMNS; row++)
    {
        for (int col = 0; col < ROWS_AND_COLUMNS; col++)
        {
            drawGridSquare(&grid[row][col]);
        }
    }
}

void drawGridSquare(GridSquare *grid)
{
    if (grid->type == BLOCK)
    {
        setColour(black);
    }
    else if (grid->type == HOME)
    {
        setColour(blue);
    }
    else if (grid->type == MARKER)
    {
        setColour(gray);
    }
    else if (grid->type == EMPTY)
    {
        setColour(white);
    }
    fillRect(grid->position.x, grid->position.y, SQUARE_WIDTH, SQUARE_HEIGHT);
    // draws the outline of the squares
    setColour(black);
    drawRect(grid->position.x, grid->position.y, SQUARE_WIDTH, SQUARE_HEIGHT);
}

int countMarker(GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS])
{
    int counter = 0;
    for (int row = 0; row < ROWS_AND_COLUMNS; row++)
    {
        for (int col = 0; col < ROWS_AND_COLUMNS; col++)
        {
            if (grid[row][col].type == MARKER)
            {
                counter++;
            }
        }
    }
    return counter;
}
