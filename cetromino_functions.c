
#include "gamedefinitions.h"
#include "cetrominobase.h"

#define TRUE 1
#define FALSE 0

cetrominobase initcetromino(char codename)
{
    cetrominobase cetromino;
    switch (codename)
    {
        case 'I':
            int coords[4][2] = {{3, 1}, {4, 1}, {5, 1}, {6, 1}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }
            cetromino.codename = 'I';
            break;
        case 'J':
            int coords[4][2] = {{3, 0}, {3, 1}, {4, 1}, {4, 2}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'J';
            break;
        case 'L':
            int coords[4][2] = {{3, 1}, {4, 1}, {5, 1}, {5, 0}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'L';
            break;
        case 'O':
            int coords[4][2] = {{4, 0}, {4, 1}, {5, 0}, {5, 1}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'O';
            break;
        case 'S':
            int coords[4][2] = {{3, 1}, {4, 1}, {4, 0}, {5, 0}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'S';
            break;       
        case 'T':
            int coords[4][2] = {{3, 1}, {4, 1}, {4, 0}, {5, 1}};
            for (int i = 0; i < 4; ++i) {
                cetromino.coords[i][0] = coords[i][0];
                cetromino.coords[i][1] = coords[i][1];
            }            
            cetromino.codename = 'T';
            break;
        case 'Z':
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
        return FALSE;
    }
    return TRUE;
}


// location valid -> 1, invalid -> 0
int is_cetromino_location_valid(cetrominobase cetromino, char grid[ROW][COL])
{
    int x, y;
    for (int i = 4; i < 4; i++)
    {
        x = cetromino.coords[i][0];
        y = cetromino.coords[i][1];

        if (isoccupied(x, y, grid))
        {
            return FALSE;
        }
    }
    return TRUE;
}


int isatbottom(cetrominobase cetromino, char grid[ROW][COL])
{
    int coordx, coordy;
    for (int i = 0; i < 4; i++) {
        coordx = cetromino.coords[i][0];
        coordy = cetromino.coords[i][1];
        
        int res = isoccupied(coordx, coordy+1, grid);

        if (res == TRUE) {
            return TRUE;
        }
    }
    return FALSE;
}


int is_at_edge(cetrominobase cetromino, char grid[ROW][COL])
{
    int coordx, coordy, resl, resr;
    for (int i = 0; i < 4; i++) {
        coordx = cetromino.coords[i][0];
        coordy = cetromino.coords[i][1];
        
        resl = isoccupied(coordx-1, coordy, grid); // Left edge
        resr = isoccupied(coordx+1, coordy, grid); // Right edge

        if (resl == TRUE || resr == TRUE) {
            return TRUE;
        }

    }
    return FALSE;
}


/* 
For rotations, use this instead. It will rotate the cetromino with
SRS. It will return a 0 if rotation somehow (basic or wallkick)
completed successfully. And 1 if unavailable. 
*/
int super_rotation_system(int direction, cetrominobase cetromino, char grid[ROW][COL])
{
    int old_state, new_state, rchange;

    // Each column is a wallkick test. Adding the x, y values in the table
    // to each of the cetromino coordinates. And tests.
    int wallkick_table[8][4][2] = {
        {{-1, 0}, {-1, 1}, {0, -2}, {-1, -2}},
        {{ 1, 0}, {1, -1}, { 0, 2}, { 1, 2 }},
        {{ 1, 0}, {1, -1}, { 0, 2}, { 1, 2 }},
        {{-1, 0}, {-1, 1}, {0, -2}, {-1, -2}},
        {{ 1, 0}, { 1, 1}, {0, -2}, { 1, -2}},
        {{-1, 0}, {-1,-1}, { 0, 2}, { -1, 2}},
        {{-1, 0}, {-1,-1}, { 0, 2}, { -1, 2}},
        {{ 1, 0}, { 1, 1}, {0, -2}, { 1, -2}},
    };
    
    int wallkick_I_table[8][4][2] = {
        {{-2, 0}, { 1, 0}, {-2, -1}, { 1, 2}},
        {{ 2, 0}, {-1, 0}, { 2, 1 }, {-1,-2}},
        {{-1, 0}, { 2, 0}, {-1, 2 }, {2, -1}},
        {{ 1, 0}, {-2, 0}, { 1, -2}, {-2, 1}},
        {{ 2, 0}, {-1, 0}, { 2, 1 }, {-1,-2}},
        {{-2, 0}, { 1, 0}, {-2, -1}, { 1, 2}},
        {{ 1, 0}, {-2, 0}, { 1, -2}, {-2, 1}},
        {{-1, 0}, { 2, 0}, {-1, 2 }, {2, -1}},
    };

    old_state = cetromino.rstate;
    rotatecetromino(direction, cetromino);
    if (is_cetromino_location_valid == TRUE) {
        return 0; // No problem! Basic rotation worked.
    }

    new_state = cetromino.rstate;

    // rchange means change of rotation. Like state 0->1, 0->2 etc.
    // And each rchange corresponds to rows of rotation tables.
    if (old_state == 0 && new_state == 1) {
        rchange = 0;
    }
    if (old_state == 1 && new_state == 0) {
        rchange = 1;
    }
    if (old_state == 1 && new_state == 2) {
        rchange = 2;
    }
    if (old_state == 2 && new_state == 1) {
        rchange = 3;
    }
    if (old_state == 2 && new_state == 3) {
        rchange = 4;
    }
    if (old_state == 3 && new_state == 2) {
        rchange = 5;
    }
    if (old_state == 0 && new_state == 3) {
        rchange = 6;
    }
    if (old_state == 3 && new_state == 0) {
        rchange = 7;
    }

    // Here, testing the wallkicks. SRS consists of 5 tests.
    // Modifying the cetrominoes by the tests. If all the tests fails,
    // that means the cetromino is in a position with no possible rotations.
    int xopr, yopr, cetrox, cetroy;
    for (int c = 0; c < 4; c++)
    {
        if (cetromino.codename == 'I') 
        {
            xopr = wallkick_I_table[c][rchange][0];
            yopr = wallkick_I_table[c][rchange][1];
        }
        else
        {
            xopr = wallkick_table[c][rchange][0];
            yopr = wallkick_table[c][rchange][1];
        }

        for (int i = 0; i < 4; i++)
        {
            cetrox = cetromino.coords[i][0];
            cetroy = cetromino.coords[i][1];
            cetromino.coords[i][0] = cetrox + xopr;
            cetromino.coords[i][1] = cetroy - yopr;
        }

        if (is_cetromino_location_valid(cetromino, grid) == TRUE) {
            return 0; // 0 Here means no problem.
        }
        else 
        {
            // Keep in mind that each test is applied on the basic rotation state.
            // So reverting after each failed test.
            for (int i = 0; i < 4; i++)
            {
                cetrox = cetromino.coords[i][0];
                cetroy = cetromino.coords[i][1];
                cetromino.coords[i][0] = cetrox - xopr;
                cetromino.coords[i][1] = cetroy + yopr;
            }
        }
    }

    // All the tests failed. Revert cetromino to the first state.
    rotatecetromino(-direction, cetromino);
    return 1;
}


void add_to_grid(cetrominobase cetromino, int grid[ROW][COL])
{
    int x, y;
    for (int i = 0; i < 4; i++)
    {
        x = cetromino.coords[i][0];
        y = cetromino.coords[i][1];
        grid[y][x] = cetromino.codename;
    }
}