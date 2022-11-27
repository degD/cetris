
#include <ncurses.h>
#include <stdio.h>
#include <time.h>

#include "cetrominobase.h"
#include "cetromino_functions.h"

#include "grid.h"
#include "gamedefinitions.h"
#include "bagfunc.h"

#include "time_manage.h"

int main()
{	
	// Init ncurses interface
	initscr();
	cbreak();
	noecho();

	// Set cursor invisible
	curs_set(0);
	
	// Initialize the grid
	char cetris_grid[ROW][COL];
	initgrid(cetris_grid);

	// The game window
	WINDOW *gridwin;
	gridwin = newwin(ROW-2, COL*2, 1, 2); // height, width, starty, startx
	wborder(gridwin, ' ', ' ', ' ',' ',' ',' ',' ',' ');

	keypad(gridwin, TRUE);
	wtimeout(gridwin, 1);

	// Game window border
	draw_gridborder(1, 2);
	wrefresh(stdscr);

	// Cetromino bag
	char cetromino_bag[7] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char codename;
	cetrominobase curr_cetromino;

	// Creating timers. They will be used to calculate 
	// time for the descend and to stop at bottom.
	struct timespec tpstart, tpstop;
	int passed_time_in_ms;

	// The game loop
	do {

		// The random cetromino bag
		if (is_bag_empty(cetromino_bag) == 1) {
			init_cetris_bag(cetromino_bag);
		}

		// Init the current cetromino
		codename = current_codename(cetromino_bag);
		curr_cetromino = initcetromino(codename);

		// Getting the current time
		clock_gettime(CLOCK_MONOTONIC, &tpstart);

		// Control loop.
		while (curr_cetromino.active == 1)
		{
			
			// Key control system
			int ckey = wgetch(gridwin);
			switch (ckey)
			{
				case (KEY_LEFT):
					rm_from_grid(&curr_cetromino, cetris_grid);
					move_cetromino(&curr_cetromino, -1, cetris_grid);
					add_to_grid(&curr_cetromino, cetris_grid);
					printgrid(gridwin, cetris_grid);
					wrefresh(gridwin);
					break;
				case (KEY_RIGHT):
					rm_from_grid(&curr_cetromino, cetris_grid);
					move_cetromino(&curr_cetromino, 1, cetris_grid);
					add_to_grid(&curr_cetromino, cetris_grid);
					printgrid(gridwin, cetris_grid);
					wrefresh(gridwin);
					break;
				case (KEY_DOWN):
					rm_from_grid(&curr_cetromino, cetris_grid);
					move_cetromino_down(&curr_cetromino, cetris_grid);
					add_to_grid(&curr_cetromino, cetris_grid);
					printgrid(gridwin, cetris_grid);
					wrefresh(gridwin);
					break;

				case ('z'):
					rm_from_grid(&curr_cetromino, cetris_grid);
					super_rotation_system(-1, &curr_cetromino, cetris_grid);
					add_to_grid(&curr_cetromino, cetris_grid);
					printgrid(gridwin, cetris_grid);
					wrefresh(gridwin);
					break;
				case ('Z'):
					rm_from_grid(&curr_cetromino, cetris_grid);
					super_rotation_system(-1, &curr_cetromino, cetris_grid);
					add_to_grid(&curr_cetromino, cetris_grid);
					printgrid(gridwin, cetris_grid);
					wrefresh(gridwin);
					break;					
				case ('x'):
					rm_from_grid(&curr_cetromino, cetris_grid);
					super_rotation_system(1, &curr_cetromino, cetris_grid);
					add_to_grid(&curr_cetromino, cetris_grid);
					printgrid(gridwin, cetris_grid);
					wrefresh(gridwin);
					break;
				case ('X'):
					rm_from_grid(&curr_cetromino, cetris_grid);
					super_rotation_system(1, &curr_cetromino, cetris_grid);
					add_to_grid(&curr_cetromino, cetris_grid);
					printgrid(gridwin, cetris_grid);
					wrefresh(gridwin);
					break;

				case ('c'):
					while (isatbottom(&curr_cetromino, cetris_grid) == FALSE)
					{
						rm_from_grid(&curr_cetromino, cetris_grid);
						move_cetromino_down(&curr_cetromino, cetris_grid);
						add_to_grid(&curr_cetromino, cetris_grid);
					}
					add_to_grid(&curr_cetromino, cetris_grid);
					printgrid(gridwin, cetris_grid);
					wrefresh(gridwin);
					break;		
				case ('C'):
					while (isatbottom(&curr_cetromino, cetris_grid) == FALSE)
					{
						rm_from_grid(&curr_cetromino, cetris_grid);
						move_cetromino_down(&curr_cetromino, cetris_grid);
						add_to_grid(&curr_cetromino, cetris_grid);
					}
					add_to_grid(&curr_cetromino, cetris_grid);
					printgrid(gridwin, cetris_grid);
					wrefresh(gridwin);
					break;								
			}

			// Checking the time passed since the last descend
			clock_gettime(CLOCK_MONOTONIC, &tpstop);
			passed_time_in_ms = ms_passed(tpstart, tpstop);

			if (isatbottom(&curr_cetromino, cetris_grid) == TRUE)
			{
				if (passed_time_in_ms > 500)
				{
					curr_cetromino.active = 0;
				}
			}
			else if (passed_time_in_ms > 1000) 
			{
				rm_from_grid(&curr_cetromino, cetris_grid);
				move_cetromino_down(&curr_cetromino, cetris_grid);
				add_to_grid(&curr_cetromino, cetris_grid);
				printgrid(gridwin, cetris_grid);
				wrefresh(gridwin);
				clock_gettime(CLOCK_MONOTONIC, &tpstart);
			} 
		}
	} while(1);

	endwin();
	return 0;
}

