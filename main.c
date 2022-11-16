
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
	gridwin = newwin(ROW, COL, 0, 0); // height, width, starty, startx
	box(gridwin, ' ', ' ');
	

	// The game loop
	do {
		getch()
	}






	return 0;
}

