
#include <ncurses.h>

#ifndef COLOR_MANAGE
#define COLOR_MANAGE

void init_color_pairs();

int block_color_control(WINDOW *win, char colorcode, int state);

#endif