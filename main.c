
#include <ncurses.h>
#include <time.h>

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
	wtimeout(gridwin, 5);

	// Game window border
	draw_gridborder(1, 2);

	// Cetromino bag
	char cetromino_bag[7] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char codename;
	cetrominobase curr_cetromino;

	// Creating timers. They will be used to calculate 
	// time for the descend and to stop at bottom.
	clock_t timer_start = clock();
	clock_t timer_stop;
	float time_passed; 

	// The game loop
	do {

		// The random cetromino bag
		if (is_bag_empty == 1) {
			init_cetris_bag(cetromino_bag);
		}

		// Init the current cetromino
		codename = current_codename(cetromino_bag);
		curr_cetromino = initcetromino(codename);
		add_to_grid(curr_cetromino, cetris_grid);

		// Control loop.
		while (curr_cetromino.active == 1)
		{
			// Getting the current CPU time
			timer_start = clock();

			// Key control system
			char ckey = wgetch(gridwin);
			switch (ckey)
			{
				case (KEY_LEFT):
					rm_from_grid(curr_cetromino, cetris_grid);
					move_cetromino(curr_cetromino, -1, cetris_grid);
					add_to_grid(curr_cetromino, cetris_grid);
					wrefresh(gridwin);
					break;
				case (KEY_RIGHT):
					rm_from_grid(curr_cetromino, cetris_grid);
					move_cetromino(curr_cetromino, 1, cetris_grid);
					add_to_grid(curr_cetromino, cetris_grid);
					wrefresh(gridwin);
					break;

				case ('z'):
					rm_from_grid(curr_cetromino, cetris_grid);
					super_rotation_system(-1, curr_cetromino, cetris_grid);
					add_to_grid(curr_cetromino, cetris_grid);
					wrefresh(gridwin);
					break;
				case ('Z'):
					rm_from_grid(curr_cetromino, cetris_grid);
					super_rotation_system(-1, curr_cetromino, cetris_grid);
					add_to_grid(curr_cetromino, cetris_grid);
					wrefresh(gridwin);
					break;					
				case ('x'):
					rm_from_grid(curr_cetromino, cetris_grid);
					super_rotation_system(-1, curr_cetromino, cetris_grid);
					add_to_grid(curr_cetromino, cetris_grid);
					wrefresh(gridwin);
					break;
				case ('X'):
					rm_from_grid(curr_cetromino, cetris_grid);
					super_rotation_system(-1, curr_cetromino, cetris_grid);
					add_to_grid(curr_cetromino, cetris_grid);
					wrefresh(gridwin);
					break;								
			}

			// Checking the time passed since the last descend
			timer_stop = clock();
			time_passed = ((float)(timer_start - timer_stop)) / CLOCKS_PER_SEC;

			if (isatbottom(curr_cetromino, cetris_grid) == TRUE)
			{
				if (time_passed > 0.5)
				{
					curr_cetromino.active = 0;
				}
			}
			else if (time_passed > 1) 
			{
				rm_from_grid(curr_cetromino, cetris_grid);
				descendcetromino(curr_cetromino);
				add_to_grid(curr_cetromino, cetris_grid);
				wrefresh(gridwin);
				timer_start = clock();
			} 
		}




	}





	endwin();
	return 0;
}

