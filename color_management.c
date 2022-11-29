
#include <ncurses.h>

void init_color_pairs()
{
    init_pair(1, COLOR_CYAN, COLOR_CYAN);       // CYAN
    init_pair(2, COLOR_BLUE, COLOR_BLUE);       // BLUE
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);   // ORANGE, YELLOW
    init_pair(4, COLOR_GREEN, COLOR_GREEN);     // GREEN
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA); // MAGENTA
    init_pair(6, COLOR_RED, COLOR_RED);         // RED
    init_pair(7, COLOR_WHITE, COLOR_WHITE);     // WHITE
}

// win is window
// colorcode is first characters of CYAN, BLUE, ORANGE, YELLOW, GREEN, MAGENTA
// RED or NORMAL
// state is either 1 or 0
// Returns 1 if terminal doesn't support colors, -1 if colorcode is unknown
// And finally 0 if everything goes correct
int block_color_control(WINDOW *win, char colorcode, int state)
{
    if (has_colors() == FALSE)
        return 1;

    // Enable/disable attributes based on argumants.
    switch (colorcode)
    {
        case 'C':
            if (state == 1) 
                wattron(win, COLOR_PAIR(1));
            else
               wattroff(win, COLOR_PAIR(1)); 
            break;
        
        case 'B':
            if (state == 1) 
                wattron(win, COLOR_PAIR(2));
            else
               wattroff(win, COLOR_PAIR(2)); 
            break;

        case 'O':
            if (state == 1)
                wattron(win, COLOR_PAIR(3));
            else 
                wattroff(win, COLOR_PAIR(3)); 
            break;

        case 'Y':
            if (state == 1) {
                wattron(win, A_BOLD | A_REVERSE);
                wattron(win, COLOR_PAIR(3));
            }
            else {
                wattroff(win, A_BOLD | A_REVERSE);
                wattroff(win, COLOR_PAIR(3));
            }
            break;

        case 'G':
            if (state == 1)
                wattron(win, COLOR_PAIR(4));
            else
                wattroff(win, COLOR_PAIR(4));
            break;

        case 'M':
            if (state == 1)
                wattron(win, COLOR_PAIR(5));
            else
                wattroff(win, COLOR_PAIR(5));
            break;

        case 'R':
            if (state == 1) {
                wattron(win, A_BOLD | A_REVERSE);
                wattron(win, COLOR_PAIR(6));
            }
            else {
                wattroff(win, A_BOLD | A_REVERSE);
                wattroff(win, COLOR_PAIR(6));
            }
            break;

        case 'W':
            if (state == 1)
                wattron(win, COLOR_PAIR(7));
            else
                wattroff(win, COLOR_PAIR(7));
            break;

        case 'N':
            wstandend(win);
            break;

        default:
            return -1;
    }
    return 0;
}
