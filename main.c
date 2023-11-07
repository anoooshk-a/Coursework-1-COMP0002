#include "graphics.h"
#include "grid.h"
#include "robot.h"
#include <stdio.h>

int main()
{
    setWindowSize(800, 800);
    GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS];
    createGrid(grid);
    Robot robot;
    initialiseRobot(&robot, HOME_ROW, HOME_COL, grid);

    background();
    drawGrid(grid);

    foreground();
    while (!atMarker(&robot))
    {
        while (!atMarker(&robot) && canMoveForward(&robot, grid))
        {
            clear();
            forward(&robot, grid);
            drawRobot(&robot);
            sleep(250);
        }
        right(&robot);
    }
}
