
#define CYAN 96
#define BLUE 34
#define ORANGE 208
#define YELLOW 93
#define GREEN 92
#define MAGENTA 35
#define RED 91

struct cetrominobase {
    int color;
    int coords[4][2];
    char codename;
};

int isoccupied(char emptychar, int coord[2], char grid[20][10])
{
    int x = coord[0], y = coord[1];
    if (grid[y][x] == emptychar) {
        return 0;
    }
    return 1;
}



int descendcetromino(struct cetrominobase cetromino)
{   
    int coordy;
    for (int i = 0; i < 4; i++) {
        coordy = cetromino.coords[i][0];
        cetromino.coords[i][0] = --coordy;
    }
}

