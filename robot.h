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
} Robot;

// move the robot forward to the next grid square in the direction the
//  robot is facing. The robot is always in the middle of a square and moves forward to the
//  middle of the next square. If there is a block or wall in front of the robot it does not
//  move. A block occupies one square and prevents the robot from moving onto the
//  square. The robot cannot move diagonally and can only move in the direction it is
//  facing
void forward(); // all of these functions will take a pointer to the robot

// turn the robot left (anti-clockwise) by 90 degrees, while remaining on the
// same square.
void left();

// turn the robot right (clockwise) by 90 degrees, while remaining on the
//  same square.
void right();

// return true if the robot is on a marker square, otherwise false.
// Markers can be placed on one or more squares.
void atMarker();

// return true if the robot can move forward, there is no wall or
// block in front of it. Return false otherwise.
int canMoveForward(Robot *robot, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS]);

// the ‘home’ square is the initial position of the robot. The function
// returns true if the robot is on the home square, otherwise false. By definition, there
// can only be one home square.
int atHome();

// the robot can pick up and carry a marker if it is on a marker
// square. If there is no marker on the square nothing happens. The robot can only carry
// a single marker at any time.
void pickUpMarker();

// – the robot can drop a marker on any square that is not occupied by
// a block. Multiple markers can be dropped on the same square.
void dropMarker();

// returns true if the robot is carrying a marker, otherwise false.
int isCarryingAMarker();

void initialiseRobot(Robot *robot, int homeRow, int homeCol, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS]);
void drawRobot(const Robot *robot); // takes 2D array of "GridSquare" structure, and a pointer to a "Robot" structure. this func will locate HOME and draw the robot on top of it.
void initDirection(Robot *robot, Direction direction);

#endif