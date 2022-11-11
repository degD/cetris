
#ifndef CETROMINOBASE_H
#define CETROMINOBASE_H

typedef struct Cetrominobase {
    int coords[4][2];
    char codename;
    int rstate;
} cetrominobase;

// rstate -> 0: spawn state
// rstate -> 1: clockwise rotated
// rstate -> 2: rotated twice in any direction
// rstate -> 3: counter-clockwise rotated

#endif