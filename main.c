
#include <ncurses.h>

#include "cetrominobase.h"
#include "cetromino_functions.h"

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

	keypad(gridwin, TRUE);

	// Game window border
	draw_gridborder(1, 2);

	// Cetromino bag
	char cetromino_bag[7] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char codename;
	cetrominobase curr_cetromino;

	// The game loop
	do {

		if (is_bag_empty == 1) {
			init_cetris_bag(cetromino_bag);
		}

		codename = current_codename(cetromino_bag);
		curr_cetromino = initcetromino(codename);

		while (isatbottom == FALSE)
		{
			char ckey = wgetch(gridwin);
			switch (ckey)
			{
				case (KEY_LEFT):
					
			}
		}
	}






	return 0;
}

