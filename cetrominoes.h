
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
int rotatecetromino(int direction, cetrominobase cetromino)
{
    switch (cetromino.codename)
    {
        case 'I':
            float centerx = ((float)cetromino.coords[1][0] + (float)cetromino.coords[2][0]) / 2;
            float centery = ((float)cetromino.coords[1][1] + (float)cetromino.coords[2][1]) / 2;

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
            
            break;
        
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

