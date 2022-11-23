
#include <stdlib.h>
#include "gamedefinitions.h"

// Create cetris cetromino bag
void init_cetris_bag(char cbag[7])
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
            cbag[i] = selection;
        }
        while (selection == ' ');
    }
}

int is_bag_empty(char cbag[7])
{
    for (int i = 0; i < 7; i++)
    {
        if (cbag[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

char current_codename(char cbag[7])
{
    char c;
    for (int i = 0; i < 7; i++)
    {
        if (cbag[i] != ' ') {
            c = cbag[i];
            return c;
        }
    }
    return ' ';
}