#include "matriz.h"

#include <iostream>

matriz::matriz(){


    for (int i = 0; i < row; ++i) {

        for (int j = 0; j < column; ++j) {
            board[i][j] = ' ';
        }
    }
}


void matriz::print_matriz()
{

  char letter=65;
  for(int i=0;i<=row;i++){
        if(i==0){
            std::cout<<" ";
        }
        else{
  std::cout<<letter<<"    ";
        letter++;
        }
  }
  std::cout<<std::endl;



    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {

            std::cout <<"["<< board[i][j] <<"]"<<"  ";
        }
        std::cout <<std::endl;
        std::cout<<std::endl;
    }

}


    matriz::~matriz()
{

    }

