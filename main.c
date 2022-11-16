
#include <ncurses.h>

#include "grid.h"
#include "gamedefinitions.h"

int main()
{	
	// Init ncurses interface
	initscr();
	cbreak();
	noecho();
	
	// Initialize the grid
	char cetris_grid[ROW][COL];
	initgrid(cetris_grid);
	





	return 0;
}

