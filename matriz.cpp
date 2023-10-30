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
    int line;
    char col;
    bool val;
    int col1;
    int line1;
    std::cout<<"ingrese el número de fila: ";
            std::cin>>line;
             line1=line-1;
    while(true){
        val=validator(line1);
        if(val==true){
            break;
        }
        else{
            std::cout<<"ingrese un valor correcto: ";
                    std::cin>>line;
            line1=line-1;
     }
  }
    std::cout<<"ingrese la columna: ";
    std::cin>>col;
    if (std::islower(col)) {
     col = std::toupper(col);
     col1=static_cast<int>(col)-65;
    }
    while(true){
        val=validator(col1);
        if(val==true){
               break;
        }
        else{
            std::cout<<"ingrese una letra correcta: ";
            std::cin>>col;
            col1=static_cast<int>(col)-65;
        }

    }

    board[line1][col1]=sign;
    }






