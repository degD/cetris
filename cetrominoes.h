
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
} cetrominobase;


cetrominobase initcetromino(char codename)
{
    cetrominobase cetromino;
    switch (codename)
    {
        case 'I':
            cetromino.color = CYAN;
            int coords[4][2] = {{3, 1}, {4, 1}, {5, 1}, {6, 1}};
            cetromino.codename = 'I';
            break;
        case 'J':
            cetromino.color = BLUE;
            int coords[4][2] = {{3, 0}, {3, 1}, {4, 1}, {4, 2}};
            cetromino.codename = 'J';
            break;
        

        for (int i = 0; i < 4; ++i) {
            cetromino.coords[i][0] = coords[i][0];
            cetromino.coords[i][1] = coords[i][1];
        }
    }
}


int isoccupied(char emptychar, int coord[2], char grid[20][10])
{
    int x = coord[0], y = coord[1];
    if (grid[y][x] == emptychar) {
        return 0;
    }
    return 1;
}



int descendcetromino(cetrominobase cetromino)
{   
    int coordy;
    for (int i = 0; i < 4; i++) {
        coordy = cetromino.coords[i][0];
        cetromino.coords[i][0] = --coordy;
    }
}

