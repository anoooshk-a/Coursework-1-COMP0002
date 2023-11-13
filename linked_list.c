#include "grid.h"
#include "util.h"
#include "robot.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *top = NULL;

// source: https://www.youtube.com/watch?v=311qJJHiQjU&ab_channel=NesoAcademy
int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(Robot *robot, GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS])
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        // exits the code due to stack overflow
        printf("Stack overflow");
        exit(1);
    }
    newNode->row = robot->gridSquare->row;
    newNode->col = robot->gridSquare->col;
    newNode->direction = robot->direction;

    newNode->next = top;
    top = newNode; // top pointer now points to newNode pointer
}

// source: https://www.javatpoint.com/ds-linked-list-implementation-of-stack
Node pop()
{
    struct Node *temp;
    if (isEmpty())
    {
        printf("Stack underflow");
        exit(1);
    }
    temp = top; // assigns temp pointer to memory address of top pointer
    Node copy = *temp;
    top = top->next; // top pointer points to the memory address of the next node
    free(temp);
    return copy;
}

void peek()
{
    struct Node *temp;
    temp = top;
    while (temp != NULL)
    {
        printf("%d, %d, %d\n", temp->direction, temp->row, temp->col);
        temp = temp->next;
    }
    printf("NULL\n");
}
