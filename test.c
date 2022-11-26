
#include "cetrominobase.h"
#include "cetromino_functions.h"

int main()
{
    cetrominobase cetro;
    cetro = initcetromino('I');

    rotatecetromino(1, &cetro);

    return 0;
}