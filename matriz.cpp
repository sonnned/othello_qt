#include "matriz.h"

#include <iostream>
//crea la matriz
matriz::matriz(){
    board= new char*[row];
    for (int i = 0; i < row; i++) {
        board[i] = new char[column];
        for (int j = 0; j < column; j++) {
            board[i][j] = ' ';
        }
    }
}



// imprime la matriz
void matriz::print_matriz()
{
    int number=1;
  char letter=65;
  for(int i=0;i<=row;i++){
        if(i==0){
            std::cout<<"   ";
        }
        else{
  std::cout<<letter<<"    ";
        letter++;
        }
  }
  std::cout<<std::endl;



    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
        if(j==0){
            std::cout<<number<<" ";
            number++;
        }
            std::cout <<"["<< board[i][j] <<"]"<<"  ";
        }
        std::cout <<std::endl;
        std::cout<<std::endl;
    }

}




   //destruye la matriz dinamica
    matriz::~matriz()
{
    for (int i = 0; i < row; i++) {
        delete[] board[i];
    }
    delete[] board;

    }
    //modifica la matriz
    void matriz::modify_matriz(char sign,int line,char col)
    {
    int line1=line-1;
    int col1=static_cast<int>(col)-65;

     board[line1][col1]=sign;

    }


