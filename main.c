
#include "cetromino_functions.h"
#include "grid.h"
#include "gamedefinitions.h"

int main(void)
{
    char garid[ROW][COL];

    initgrid(garid);
    cetrominobase I = initcetromino('I');
    add_to_grid(I, garid);
    printgrid(garid);

    return 0;
}


