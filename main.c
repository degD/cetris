
#include <stdio.h>
#include "cetrominoes.h"

#define ROW 22
#define COL 10
#define EMPTYCHAR '.'

void printgrid(char _2darray[ROW][COL]);

int main(void)
{
    // Initializing the grid.
    char grid[ROW][COL];
    for (int y = 0; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            grid[y][x] = EMPTYCHAR;
        }
    }



    printgrid(grid);



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

