#include "grid.h"
#include "graphics.h"
#include "robot.h"

void initialiseRobot(Robot *robot, int homeRow, int homeCol, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS])
{
    // sets up the robot's initial state
    robot->gridSquare = &grid[homeRow][homeCol];
    robot->position.x = robot->gridSquare->position.x;
    robot->position.y = robot->gridSquare->position.y;
    robot->direction = EAST;
}

void drawRobot(const Robot *robot)
{
    foreground();
    int x = robot->position.x;
    int y = robot->position.y;
    // draws the robot
    setColour(red);
    fillOval(x, y, 50, 50);
}

// void forward(Robot *robot, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS], int x, int y)
// {
//     drawRobot(grid, robot);
//     for (int row = 0; row < ROWS_AND_COLUMNS; row++)
//     {
//         for (int col = 0; col < ROWS_AND_COLUMNS; col++)
//         {
//             if (grid[row][col].type == EMPTY)
//             {
//                 robot->position.x = x + SQUARE_WIDTH;
//                 setColour(red);
//                 fillOval(x, y, 50, 50);
//             }
//         }
//     }
// }