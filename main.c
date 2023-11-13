#include "graphics.h"
#include "grid.h"
#include "robot.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    setWindowSize(800, 800);
    GridSquare grid[ROWS_AND_COLUMNS][ROWS_AND_COLUMNS];
    createGrid(grid);
    Robot robot;
    initialiseRobot(&robot, HOME_ROW, HOME_COL, grid);
    Node *top = NULL;

    background();
    drawGrid(grid);

    while (countMarker(grid) > 0)
    {
        // finding the marker
        foreground();
        while (!atMarker(&robot))
        {
            while (!atMarker(&robot) && canMoveForward(&robot, grid))
            {
                clear();
                forward(&robot, grid);
                drawRobot(&robot);
                sleep(100);
                push(&robot, grid);
            }
            right(&robot);
        }
        // marker has been found
        pickUpMarker(&robot);
        background();
        clear();
        drawGrid(grid);

        // time to go home!
        foreground();
        while (!atHome(&robot))
        {
            Node lastMove = pop();
            Direction opposite = reverseDirection(lastMove.direction);

            while (robot.direction != opposite)
            {
                clear();
                right(&robot);
                drawRobot(&robot);
                sleep(100);
            }

            forward(&robot, grid);
            clear();
            drawRobot(&robot);
            sleep(100);
        }

        dropMarker(&robot);
    }
}
