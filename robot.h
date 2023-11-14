#ifndef ROBOT_H
#define ROBOT_H

#include "grid.h"
#include "util.h"

typedef enum
{
    NORTH,
    EAST,
    SOUTH,
    WEST,
} Direction;

// struct of Robot that will store the coordinates of the robot, the direction it's facing, and the type of the gridsquare that it's on
typedef struct Robot
{
    Coordinates position; // represents the robots position on screen
    Direction direction;  // field "direction" of the type "enum Direction"
    GridSquare *gridSquare;
    int carryingMarker;
} Robot;

void initialiseRobot(Robot *robot, int homeRow, int homeCol, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS]);
void drawRobot(const Robot *robot); // this func will locate HOME and draw the robot on top of it.
void initDirection(Robot *robot, Direction direction);

void forward(Robot *robot, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS]); // all of these functions will take a pointer to the robot

void left(Robot *robot);

void right(Robot *robot);

int atMarker(Robot *robot);

int canMoveForward(Robot *robot, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS]);

int atHome(Robot *robot);

void pickUpMarker(Robot *robot);

void dropMarker(Robot *robot);

int isCarryingAMarker(Robot *robot);

Direction reverseDirection(Direction direction);

#endif