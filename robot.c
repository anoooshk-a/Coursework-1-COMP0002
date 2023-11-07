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

int canMoveForward(Robot *robot, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS])
{
    if (robot->direction == NORTH)
    {
        return robot->gridSquare->row > 0 && (grid[robot->gridSquare->row - 1][robot->gridSquare->col].type == BLOCK);
    }
    if (robot->direction == WEST)
    {
        return robot->gridSquare->col > 0 && (grid[robot->gridSquare->row][robot->gridSquare->col - 1].type == BLOCK);
    }
    if (robot->direction == SOUTH)
    {
        return robot->gridSquare->row < 9 && (grid[robot->gridSquare->row + 1][robot->gridSquare->col].type == BLOCK);
    }
    if (robot->direction == EAST)
    {
        return robot->gridSquare->col < 9 && (grid[robot->gridSquare->row][robot->gridSquare->col + 1].type == BLOCK);
    }
}

void forward(Robot *robot, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS])
{
    if (robot->direction == NORTH)
    {
        robot->gridSquare = &grid[robot->gridSquare->row - 1][robot->gridSquare->col];
    }
    if (robot->direction == SOUTH)
    {
        robot->gridSquare = &grid[robot->gridSquare->row + 1][robot->gridSquare->col];
    }
    if (robot->direction == EAST)
    {
        robot->gridSquare = &grid[robot->gridSquare->row][robot->gridSquare->col + 1];
    }
    if (robot->direction == WEST)
    {
        robot->gridSquare = &grid[robot->gridSquare->row][robot->gridSquare->col - 1];
    }
    robot->position.x = robot->gridSquare->position.x;
    robot->position.y = robot->gridSquare->position.y;
}

void left(Robot *robot)
{
    if (robot->direction == NORTH)
    {
        robot->direction == WEST;
    }
    else if (robot->direction == SOUTH)
    {
        robot->direction == EAST;
    }
    else if (robot->direction == WEST)
    {
        robot->direction == SOUTH;
    }
    else if (robot->direction == EAST)
    {
        robot->direction == NORTH;
    }
}
void right(Robot *robot)
{
    if (robot->direction == NORTH)
    {
        robot->direction == EAST;
    }
    else if (robot->direction == SOUTH)
    {
        robot->direction == WEST;
    }
    else if (robot->direction == WEST)
    {
        robot->direction == NORTH;
    }
    else if (robot->direction == EAST)
    {
        robot->direction == SOUTH;
    }
}
