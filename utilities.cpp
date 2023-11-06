#include"utilities.h"
#include <iostream>
#include "macros.h"



bool validator(int value)
/*
 * retorno=bool(variable validadora)
 * parametros int(fila o columna)
 * funcion que analiza el valor del numero ingresado, verificando que si esté dentro de las dimensiones de la matriz
 */

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




int validator_input_row(){
    /*retorno=int(fila validada)
     * parametros=null
     * funcion que se encarga de validar la entrada del usuario de la fila
     * mira que la fila si esté en la matriz
     *si la informacion pedida es erronea la vuelve a pedir
     */
    while(true){
        int row;
        int row1;
        bool flag;

        std::cout<<"ingrese un numero: ";
        std::cin>>row;
        row1=row-1;
        flag=validator(row1);
        if(flag==false){
           std::cout<<"informacion mala, ingrese un nuevo numero:  "<<std::endl;
        }
        else{
             return row1;
             break;



        }

    }

}

int validator_input_col(){
    /*retorno=int(la columna validada)
     *parametros=null
     * funcion que se encarga de validar la entrada de usuario de la columna
     * convierte el char recibido por un int, utilizando el ascii
     * si la informacion pedida es erronea la vuelve a pedir
     */

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






