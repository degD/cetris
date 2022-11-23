
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

#define COLOR_ORANGE 8

void init_game_colors(void) 
{   
    // Defining an "orange" color
    init_color(COLOR_ORANGE, 252*1000/255, 166*1000/255, 67*1000/255);

    init_pair(1, COLOR_BLACK, COLOR_CYAN);    // CYAN
    init_pair(2, COLOR_BLACK, COLOR_BLUE);    // BLUE
    init_pair(3, COLOR_ORANGE, COLOR_BLACK);  // ORANGE
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);  // YELLOW
    init_pair(5, COLOR_BLACK, COLOR_GREEN);   // GREEN
    init_pair(6, COLOR_BLACK, COLOR_MAGENTA); // MAGENTA
    init_pair(7, COLOR_BLACK, COLOR_RED);     // RED
    init_pair(8, COLOR_BLACK, COLOR_BLACK);   // BLACK
    init_pair(9, COLOR_BLACK, COLOR_WHITE);   // WHITE
}

// Assumes grid is a ROWxCOL char-array
void initgrid(char grid[ROW][COL])
{  
    for (int y = 0; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            grid[y][x] = EMPTYCHAR;
        }
    }
}


int printcolorblock(WINDOW *gridwin, int colorcode)
{
    int ret = wprintw(gridwin, "  ");
    return ret;
}


// Print the grid and return to top-left corner of it.
void printgrid(WINDOW *gridwin, char _2darray[ROW][COL])
{
    char element;
    for (int y = 2; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            element = _2darray[y][x];
            
            switch (element)
            {
                case 'I':
                    printcolorblock(gridwin, CYAN);
                    break;
                case 'J':
                    printcolorblock(gridwin, BLUE);
                    break;
                case 'L':
                    printcolorblock(gridwin, ORANGE);
                    break;
                case 'O':
                    printcolorblock(gridwin, YELLOW);
                    break;         
                case 'S':
                    printcolorblock(gridwin, GREEN);
                    break; 
                case 'T':
                    printcolorblock(gridwin, MAGENTA);
                    break;
                case 'Z':
                    printcolorblock(gridwin, RED);
                    break; 
                case EMPTYCHAR:
                    printcolorblock(gridwin, BLACK);
                    break;
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
        printcolorblock(stdscr, WHITE);
    }
    move(bordery+ROW-2, borderx);
    for (int i = 0; i < hlen; i++) {
        printcolorblock(stdscr, WHITE);
    }

    // Printing horizontal borders
    for (int i = 0; i < vlen; i++) {
        move(i, borderx);
        printcolorblock(stdscr, WHITE);
    }
    for (int i = 0; i < vlen; i++) {
        move(i, borderx+ROW*2-1);
        printcolorblock(stdscr, WHITE);
    }

}
