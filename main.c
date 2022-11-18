
#include <ncurses.h>

#include "grid.h"
#include "gamedefinitions.h"
#include "bagfunc.h"

int main()
{	
	// Init ncurses interface
	initscr();
	cbreak();
	noecho();
	
	// Initialize the grid
	char cetris_grid[ROW][COL];
	initgrid(cetris_grid);

	// The game window
	WINDOW *gridwin;
	gridwin = newwin(ROW-2, COL, 1, 2); // height, width, starty, startx
	wborder(gridwin, ' ', ' ', ' ',' ',' ',' ',' ',' ');

	// Game window border
	draw_gridborder(1, 2);

	// The game loop
	do {
		// Game window printing
		printgrid(gridwin, cetris_grid);

		char c = getch();
		while (c != KEY_F(1))
		{
			switch (c)
			{
				case (KEY_LEFT):
			}
		}
	}






	return 0;
}

