#include"utilities.h"
#include <iostream>
#include "macros.h"


//valida que el numero de columna o fila esté dentro de la matriz, retorna un true si es cierto
bool validator(int value)
{
    bool flag;
    if(value<0 || value>BOARD_WEIGHT-1){
        flag=false;

    }
    else{
        flag=true;

    }
    return flag;
}



//pide las filas, y las valida, si no es una fila valida, la vuelve a pedir
int validator_input_row(){

    while(true){
        int row;
        int row1;
        bool flag;

        std::cout<<"ingrese un numero: ";
        std::cin>>row;
        row1=row-1;
        flag=validator(row1);
        if(flag==false){
           std::cout<<"informacion mala, ingrese una nueva letra "<<std::endl;
        }
        else{
             return row1;
             break;



        }

    }

}
//pide la columna y la valida, si no es una columna valida, la vuelve a pedir
int validator_input_col(){
    char col;
    char col1;
    bool flag;
    while(true){
    std::cout<<"ingrese la letra: ";
    std::cin>>col;
    if (std::islower(col)) {
        col = std::toupper(col);
    }
    col1=static_cast<int>(col)-65;
    flag=validator(col1);
    if(flag==false){
       std::cout<<"informacion mala, ingrese una nueva letra "<<std::endl;
    }
    else{
        break;
    }
    }
    return col1;
}






