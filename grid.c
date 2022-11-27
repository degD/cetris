
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

    attron(A_REVERSE);

    // Top border
    mvwhline(stdscr, bordery, borderx, ' ', (COL+2)*2);

    // Left border
    mvwvline(stdscr, bordery+1, borderx, ' ', ROW-1);
    mvwvline(stdscr, bordery+1, borderx+1, ' ', ROW-1);

    // Right border
    mvwvline(stdscr, bordery+1, (borderx+COL+1)*2, ' ', ROW-1);
    mvwvline(stdscr, bordery+1, (borderx+COL+1)*2+1, ' ', ROW-1); 

    // Bottom border
    mvwhline(stdscr, bordery+ROW-1, borderx, ' ', (COL+2)*2);

    attroff(A_REVERSE);
}


// Test if there are filled lines, lines that should got cleared.
// If it doesn't, then just skip. But if there are, clear those lines
// and descend all the blocks above.
void test_clear_line(char grid[ROW][COL])
{
    // Clearing filled lines and also saving
    // number of lines cleared(or filled).
    int num_of_filled_lines = 0;
    int is_curr_line_filled = 0; 
    for (int y = 0; y < ROW; y++)
    {
        is_curr_line_filled = 1;
        for (int x = 0; x < COL; x++)
        {
            if (grid[y][x] == EMPTYCHAR)
            {
                is_curr_line_filled = 0;
                break;
            }
        }

        if (is_curr_line_filled)
        {
            num_of_filled_lines += 1;
            for (int x = 0; x < COL; x++)
                grid[y][x] = EMPTYCHAR;           
        }
    }

    // Because some lines got cleard, blocks above them
    // also fall down. This loop here controls this behavior.
    if (num_of_filled_lines > 0)
    {
        char c;
        for (int y = ROW-1; y > -1; y--)
        {
            for (int x = 0; x < COL; x++)
            {
                c = grid[y][x];
                if (grid[y][x] != EMPTYCHAR)
                {
                    grid[y][x] = EMPTYCHAR;

                    while ((y+1 < ROW) && (grid[y+1][x] == EMPTYCHAR))
                    {
                        y++;
                    }
                    grid[y][x] = c;
                }
            }
        }
    }

}
