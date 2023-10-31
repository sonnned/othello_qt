#include "matriz.h"
#include "macros.h"
#include"utilities.h"
#include <iostream>
//crea la matriz
matriz::matriz(){
    int mitad=row/2;
    for (int i = 0; i < row; i++) {   
        for (int j = 0; j < column; j++) {

           if(i==mitad-1 && j==mitad-1){
                        board[i][j]=WHITE;
                    }
            else if(i==mitad-1 && j==mitad){
                        board[i][j]=BLACK;
                    }
           else if(i==mitad && j==mitad-1){
                        board[i][j]=BLACK;
                    }
           else if(i==mitad && j==mitad){
                         board[i][j]=WHITE;
                    }

            else{
            board[i][j] = ' ';
            }
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
}
    //modifica la matriz
    void matriz::modify_matriz(char sign)
    {
    int row=validator_input_row();
    int col=validator_input_col();
    std::cout<<row<<std::endl;
    board[row][col]=sign;


    }
