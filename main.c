#include "graphics.h"
#include "grid.h"
#include "robot.h"

int main()
{
    GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS];
    createGrid(grid);
    Robot robot;
    initialiseRobot(&robot, HOME_ROW, HOME_COL, grid);

    background();
    setWindowSize(800, 800);
    drawGrid(grid);

    foreground();
    drawRobot(&robot);
}
