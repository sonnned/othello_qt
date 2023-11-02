#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include "macros.h"

class matriz
{
private:
    char board[BOARD_SIZE][BOARD_SIZE];
public:
    matriz() {
        init_board();
    }
    void init_board();
    void modify_matriz(char sign,int line,char col);
    bool is_valid_direction(int x, int y, char piece, int dir_x, int dir_y);
    bool is_valid_pos(int x, int y);
    bool is_valid_move(int x, int y, char piece);
    void print_matriz();
    void make_move(int x,int y, char piece);
    void sandwich_movement(int x, int y, char piece, int dir_x, int dir_y);
};

#endif // MATRIZ_H
