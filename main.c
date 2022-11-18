
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
	mvprintw(0, 0, "\e[%dm  \e[0m", colorcode);
	

	// The game loop
	do {
		getch()
	}






	return 0;
}

