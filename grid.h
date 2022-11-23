
#include <ncurses.h>

#include "gamedefinitions.h"

#ifndef GRID_H
#define GRID_H

void init_game_colors(void);

void initgrid(char grid[ROW][COL]);

int printcolorblock(WINDOW *gridwin, int colorcode);

void printgrid(WINDOW *gridwin, char _2darray[ROW][COL]);

void draw_gridborder(int gridy, int gridx);

#endif