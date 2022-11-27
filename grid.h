
#include <ncurses.h>

#include "gamedefinitions.h"

#ifndef GRID_H
#define GRID_H

void initgrid(char grid[ROW][COL]);

int print_block(WINDOW *gridwin, int colorcode);

void printgrid(WINDOW *gridwin, char _2darray[ROW][COL]);

void draw_gridborder(int gridy, int gridx);

void test_clear_line(char grid[ROW][COL]);

#endif