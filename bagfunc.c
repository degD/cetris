
#include <stdlib.h>
#include "gamedefinitions.h"

// Create cetris cetromino bag
void init_cetris_bag(int cbag[7])
{
    int i, num;
    char selection = ' ';
    char cetromino_list[7] = {'I', 'J', 'L', 'O', 'S', 'T', 'Z'};

    for (i = 0; i < 7; i++)
    {
        do {
            num = rand() % 7;
            selection = cetromino_list[num];
            cetromino_list[num] = ' ';
            cbag[num] = selection;
        }
        while (selection == ' ');
    }
}