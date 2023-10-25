#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>

class matriz
{
private:
    static const int column = 8;
    static const int row = 8;
    std::string board[row][column];

public:
    matriz();
    //void releaseMatriz();
    void print_matriz();
    ~matriz();
};

#endif // MATRIZ_H
