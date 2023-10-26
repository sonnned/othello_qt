#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>

class matriz
{
private:
    static const int column = 8;
    static const int row =8;
    char board[row][column];

public:
    matriz();
    void print_matriz();
    ~matriz();
   void abc_row();
   void num_column();
};

#endif // MATRIZ_H
