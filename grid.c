
#include <stdio.h>
#include <ncurses.h>

#include "gamedefinitions.h"

#define CYAN 106
#define BLUE 44
#define ORANGE 43
#define YELLOW 103
#define GREEN 102
#define MAGENTA 45
#define RED 101
#define BLACK 40
#define WHITE 47

// Assumes grid is a ROWxCOL char-array
void initgrid(char grid[ROW][COL])
{  
    for (int y = 0; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            grid[y][x] = EMPTYCHAR;
        }
    }
}


void print_block(WINDOW *gridwin, char c)
{
    waddch(gridwin, c);
    waddch(gridwin, c);
}


// Print the grid and return to top-left corner of it.
void printgrid(WINDOW *gridwin, char _2darray[ROW][COL])
{
    char element;
    for (int y = 2; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            element = _2darray[y][x];
            
            if (element == EMPTYCHAR) {
                print_block(gridwin, ' ');
            } 
            else {
                print_block(gridwin, element);
            }
        }
    }
    wmove(gridwin, 0, 0);
}


void draw_gridborder(int gridy, int gridx)
{
    int bordery = gridy - 1;
    int borderx = gridx - 2;

    attron(A_DIM);

    // Top border
    mvwhline(stdscr, bordery, borderx, 'X', (COL+2)*2);

    // Left border
    mvwvline(stdscr, bordery+1, borderx, 'X', ROW-1);
    mvwvline(stdscr, bordery+1, borderx+1, 'X', ROW-1);

    // Right border
    mvwvline(stdscr, bordery+1, (borderx+COL+1)*2, 'X', ROW-1);
    mvwvline(stdscr, bordery+1, (borderx+COL+1)*2+1, 'X', ROW-1); 

    // Bottom border
    mvwhline(stdscr, bordery+ROW-1, borderx, 'X', (COL+2)*2);

    attroff(A_DIM);
}
