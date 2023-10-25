#include "matriz.h"

#include <iostream>

matriz::matriz(){


    //char letter;
    for (int i = 0; i < row; ++i) {

        for (int j = 0; j < column; ++j) {



            board[i][j] = '+';

        }
    }

}


void matriz::print_matriz()
{
    unsigned int num = 1;
    char abc = 65;
    for (int i = 0; i < row+1; ++i) {
        for (int j = 0; j < column+1; ++j) {

            if((i == 0) && (j  == 0)) {
                std::cout << "[]";
            }

            else if((i==0) && (j > 0)){
                std::cout << "[" <<abc<< "]" ;
                abc++;
            }
            else if((j==0) && (i > 0)){
                std::cout << "[" <<num<< "]" ;
                num++;
            }
            else {
                std::cout<<"["<< board[i][j] << "]"; //error de index
            }
        }
        std::cout<<std::endl;
    }
}

matriz::~matriz()
{

}
