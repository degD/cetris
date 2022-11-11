
#include <stdio.h>

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
    char grid[ROW][COL];    
    for (int y = 0; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            grid[y][x] = EMPTYCHAR;
        }
    }
}


int printcolorblock(int colorcode)
{
    int ret = printf("\e[%dm  \e[0m", colorcode);
    return ret;
}


// Print the grid and return to top-left corner of it.
void printgrid(char _2darray[ROW][COL])
{
    

    char element, color;
    for (int y = 2; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            element = _2darray[y][x];
            
            switch (element)
            {
                case 'I':
                    printcolorblock(CYAN);
                    break;
                case 'J':
                    printcolorblock(BLUE);
                    break;
                case 'L':
                    printcolorblock(ORANGE);
                    break;
                case 'O':
                    printcolorblock(YELLOW);
                    break;         
                case 'S':
                    printcolorblock(GREEN);
                    break; 
                case 'T':
                    printcolorblock(MAGENTA);
                    break;
                case 'Z':
                    printcolorblock(RED);
                    break; 
                case EMPTYCHAR:
                    printcolorblock(BLACK);
                    break;
            }

        }
        puts("");
    }
    // Move the cursor ROW cells up. It's an ANSI escape sequence. 
    printf("\e[%dA", ROW);
}
