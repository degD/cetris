
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
                print_block(gridwin, '.');
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

    int hlen = (COL + 2);
    int vlen = (ROW + 2);

    // Printing upper and lower borders
    move(bordery, borderx);
    for (int i = 0; i < hlen; i++) {
        print_block(stdscr, 'X');
    }
    move(bordery+ROW-2, borderx);
    for (int i = 0; i < hlen; i++) {
        print_block(stdscr, 'X');
    }

    // Printing horizontal borders
    for (int i = 0; i < vlen; i++) {
        move(i, borderx);
        print_block(stdscr, 'X');
    }
    for (int i = 0; i < vlen; i++) {
        move(i, borderx+ROW*2-1);
        print_block(stdscr, 'X');
    }

}
