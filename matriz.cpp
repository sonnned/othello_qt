#include "matriz.h"
#include "macros.h"
#include"utilities.h"
#include <iostream>
#include"piece.h"
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




   //destructor
    matriz::~matriz()
{
}
    void matriz::info_user_matriz(Piece gamer)
    {
    /*
     * retorno=vacio
     * parametro=clase piece
     * utiliza validator_input_row y col para crear la fila y la columna
     * da esos valores a la clase con el metodo set
     */
    int row=validator_input_row();
    int col=validator_input_col();
    gamer.setX_pos(row);
    gamer.setY_pos(col);
    }

    void matriz::modify_matriz(Piece gamer)
    /*
     * retorno=void
     * parametro=piece
     * agrega el signo a la matriz, utilizando los metodos get para obtener los atributos "x" y "y" de la clase piece
     */
    {
    unsigned int x=gamer.getX_pos();
    unsigned int y=gamer.getY_pos();
    char sign= gamer.get_value();
    board[x][y]=sign;

    }
