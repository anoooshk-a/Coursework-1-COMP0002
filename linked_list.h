#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "grid.h"
#include "util.h"
#include "robot.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    Direction direction;
    int row, col;
    struct Node *next;
} Node;

extern Node *top;

int isEmpty();
void push(Robot *robot, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS]);
Node pop();
void peek();

#endif