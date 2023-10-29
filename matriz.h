#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>

class matriz
{
private:
    static const int column =8;
    static const int row =8;
    char** board;

public:
    matriz();
   void print_matriz();
   ~matriz();
   void modify_matriz(char sign,int line,char col);
};

#endif // MATRIZ_H
