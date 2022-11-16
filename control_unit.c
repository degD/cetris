
#include "cetrominobase.h"
#include "cetromino_functions.h"
#include "gamedefinitions.h"
#include <ncurses.h>
#include <time.h>

#define DESCEND_SECOND 1
#define BOTTOM_TIMER 0.5

int control_unit(cetrominobase cetromino, char grid[ROW][COL])
{
    clock_t start_t, end_t;

    start_t = clock();

    char c;

    do {
        c = getch();
        switch (c)
        {
            case 'r':
                super_rotation_system(-1, cetromino, grid);
                break;
            case 
        }
        
    }

}
