
#include "gamedefinitions.h"

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

// rstate -> 0: spawn state
// rstate -> 1: clockwise rotated
// rstate -> 2: rotated twice in any direction
// rstate -> 3: counter-clockwise rotated


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

// dir = 1 clockwise, -1 counter-clockwise
float* rotatecoord(float cx, float cy, float x, float y, int dir)
{
    float rcoord[2];

    x = x - cx;
    y = y - cy;

    if (dir == 1) {
        rcoord[0] = y;
        rcoord[1] = -x;
    }
    if (dir == -1) {
        rcoord[0] = -y;
        rcoord[1] = x;
    }

    rcoord[0] += cx;
    rcoord[1] += cy;

    return rcoord;
}

// dir = 1 clockwise, -1 counter-clockwise
void rotatecetromino(int direction, cetrominobase cetromino)
{
    float centerx, centery;
    char codename = cetromino.codename;
    if (codename == 'I')
    {
        centerx = ((float)cetromino.coords[1][0] + (float)cetromino.coords[2][0]) / 2;
        centery = ((float)cetromino.coords[1][1] + (float)cetromino.coords[2][1]) / 2;

        switch (cetromino.rstate)
        {
            case 0:
                centery += 0.5;
                break;
            case 1:
                centerx -= 0.5;
                break;
            case 2:
                centery -= 0.5;
                break;
            case 3:
                centerx += 0.5;
                break;
        }
    }
    else if (codename == 'O')
    {
        centerx = ((float)cetromino.coords[1][0] + (float)cetromino.coords[2][0]) / 2;
        centery = ((float)cetromino.coords[1][1] + (float)cetromino.coords[2][1]) / 2;       
    }
    else if (codename == 'J' || codename == 'Z')
    {
        centerx = (float)cetromino.coords[2][0];
        centery = (float)cetromino.coords[2][1];
    }
    else if (codename == 'T' || codename == 'S' || codename == 'L')
    {
        centerx = (float)cetromino.coords[1][0];
        centery = (float)cetromino.coords[1][1];
    }

    for (int i = 0; i < 4; i++)  
    {
        float x = cetromino.coords[i][0];
        float y = cetromino.coords[i][1];

        float *rcoord = rotatecoord(centerx, centery, x, y, direction);

        cetromino.coords[i][0] = (int)rcoord[0];
        cetromino.coords[i][1] = (int)rcoord[1];               
    }

    if (direction == 1);
        cetromino.rstate += 1;
    if (direction == -1);
        cetromino.rstate += 3;
    if (cetromino.rstate == 4);
        cetromino.rstate = 0;
}


void descendcetromino(cetrominobase cetromino)
{   
    int coordy;
    for (int i = 0; i < 4; i++) {
        coordy = cetromino.coords[i][1];
        cetromino.coords[i][1] = ++coordy;
    }
}


// 0 is FALSE and 1 is TRUE
int isoccupied(int x, int y, char grid[ROW][COL])
{
    if (grid[y][x] == EMPTYCHAR) {
        return 0;
    }
    return 1;
}


int isatbottom(cetrominobase cetromino, char grid[ROW][COL])
{
    int coordx, coordy;
    for (int i = 0; i < 4; i++) {
        coordx = cetromino.coords[i][0];
        coordy = cetromino.coords[i][1];
        
        int res = isoccupied(coordx, coordy, grid[ROW][COL]);

        if (res == 1) {
            return 1;
        }
    }
    return 0;
}



