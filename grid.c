
#include "gamedefinitions.h"

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

// Print the grid and return to top-left corner of it.
void printgrid(char _2darray[ROW][COL])
{
    char element;
    for (int y = 2; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            element = _2darray[y][x];
            printf(" %c ", element);
        }
        puts("");
    }
    // Move the cursor ROW cells up. It's an ANSI escape sequence. 
    printf("\e[%dA", ROW);
}
