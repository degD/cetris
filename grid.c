
#include <stdio.h>
#include <ncurses.h>

#include "gamedefinitions.h"
#include "color_management.h"


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
    if (has_colors() == TRUE)
    {
        char colorcode;
        switch (c)
        {
            case 'I':
                colorcode = 'C';
                break;
            case 'J':
                colorcode = 'B';
                break;
            case 'L':
                colorcode = 'O';
                break;
            case 'O':
                colorcode = 'Y';
                break;
            case 'S':
                colorcode = 'G';
                break;
            case 'T':
                colorcode = 'M';
                break;
            case 'Z':
                colorcode = 'R';
                break;
            case EMPTYCHAR:
                colorcode = 'N';
                break;
        }
        block_color_control(gridwin, colorcode, 1);
        waddch(gridwin, ' ');
        waddch(gridwin, ' ');
        block_color_control(gridwin, colorcode, 0);
    }
    else 
    {
        waddch(gridwin, c);
        waddch(gridwin, c);
    }
}

// Print the grid and return to top-left corner of it.
void printgrid(WINDOW *gridwin, char _2darray[ROW][COL])
{
    char element;
    for (int y = 2; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            element = _2darray[y][x];
            print_block(gridwin, element);
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
    int x, y, line_filled;
    for (y = ROW-1; y > -1; y--)
    {
        // Looking for available lines.
        line_filled = 1;
        for (x = 0; x < COL; x++)
        {
            if (grid[y][x] == EMPTYCHAR)
            {
                line_filled = 0;
                break;
            }
        }

        // If there is a line that's suitable for cleaning...
        if (line_filled)
        {
            // Deletes every character on that line...
            for (x = 0; x < COL; x++)
                grid[y][x] = EMPTYCHAR;

            // Then descends every block by one.
            for (y = ROW-2; y > -1; y--)
                for (x = 0; x < COL; x++)
                    grid[y+1][x] = grid[y][x];

            // Because all the grid got moved down by a block,
            // We also move down y.
            y = y + 1;
        }

    }
}
