
#include <stdio.h>

#define ROW 22
#define COL 10

void printgrid(char _2darray[ROW][COL]);

int main(void)
{
    char grid[ROW][COL];
    for (int y = 0; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            grid[y][x] = '.';
        }
    }

    printgrid(grid);



}

void printgrid(char _2darray[ROW][COL])
{
    char element;
    for (int y = 0; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            element = _2darray[y][x];
            printf(" %c ", element);
        }
        puts("");
    }

    printf("\e[22");
}

