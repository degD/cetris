
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


int printcolorblock(WINDOW *gridwin, int colorcode)
{
    int ret = wprintw(gridwin, "\e[%dm  \e[0m", colorcode);
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
        wprintw(gridwin, "\n\r");
    }
    // Move the cursor ROW cells up. It's an ANSI escape sequence. 
    printf("\e[%dA", ROW);
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
