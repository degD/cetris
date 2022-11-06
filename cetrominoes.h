
#define CYAN 96
#define BLUE 34
#define ORANGE 208
#define YELLOW 93
#define GREEN 92
#define MAGENTA 35
#define RED 91

typedef struct Cetrominobase {
    int color;
    int coords[4][2];
    char codename;
    int rstate;
} cetrominobase;




cetrominobase initcetromino(char codename)
{
    cetrominobase cetromino;
    switch (codename)
    {
        case 'I':
            cetromino.color = CYAN;
            int coords[4][2] = {{3, 1}, {4, 1}, {5, 1}, {6, 1}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }
            cetromino.codename = 'I';
            break;
        case 'J':
            cetromino.color = BLUE;
            int coords[4][2] = {{3, 0}, {3, 1}, {4, 1}, {4, 2}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'J';
            break;
        case 'L':
            cetromino.color = ORANGE;
            int coords[4][2] = {{3, 1}, {4, 1}, {5, 1}, {5, 0}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'L';
            break;
        case 'O':
            cetromino.color = YELLOW;
            int coords[4][2] = {{4, 0}, {4, 1}, {5, 0}, {5, 1}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'O';
            break;
        case 'S':
            cetromino.color = GREEN;
            int coords[4][2] = {{3, 1}, {4, 1}, {4, 0}, {5, 0}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'S';
            break;       
        case 'T':
            cetromino.color = MAGENTA;
            int coords[4][2] = {{3, 1}, {4, 1}, {4, 0}, {5, 1}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'T';
            break;
        case 'Z':
            cetromino.color = GREEN;
            int coords[4][2] = {{3, 0}, {4, 0}, {4, 1}, {5, 1}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'Z';
            break;
    }
    cetromino.rstate = 0;
    return cetromino;
}


int rotatecetromino(char direction, cetrominobase cetromino)
{
    switch (cetromino.codename)
    {
        case 'I':


    }
}



void descendcetromino(cetrominobase cetromino)
{   
    int coordy;
    for (int i = 0; i < 4; i++) {
        coordy = cetromino.coords[i][0];
        cetromino.coords[i][0] = --coordy;
    }
}

