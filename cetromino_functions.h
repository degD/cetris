
#include "cetrominobase.h"
#include "gamedefinitions.h"

#ifndef CETROMINOES_H
#define CETROMINOES_H

cetrominobase initcetromino(char codename);

void rotatecoord(float cx, float cy, float coord, int dir);

void rotatecetromino(int direction, cetrominobase cetromino);

void descendcetromino(cetrominobase cetromino);

int isoccupied(int x, int y, char grid[ROW][COL]);

int is_cetromino_location_valid(cetrominobase cetromino, char grid[ROW][COL]);

int isatbottom(cetrominobase cetromino, char grid[ROW][COL]);

int is_at_edge(cetrominobase cetromino, char grid[ROW][COL]);

int super_rotation_system(int direction, cetrominobase cetromino, char grid[ROW][COL]);

void add_to_grid(cetrominobase cetromino, char grid[ROW][COL]);

#endif