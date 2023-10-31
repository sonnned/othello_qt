#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>
#include "piece.h"

class matriz
{
private:
    static const int column =8;
    static const int row =8;
    char board[row][column];

public:
    matriz();
   void print_matriz();
   ~matriz();
   void info_user_matriz(Piece gamer);
   void modify_matriz(Piece gamer);

};

#endif // MATRIZ_H
