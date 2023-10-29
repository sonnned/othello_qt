#include <iostream>
#include "matriz.h"
using namespace std;

int main()
{
    int line;
    char col;
    int flag=1;

    while(true){
    matriz tablero;
    tablero.print_matriz();
    std::cout<<"ingrese fila: ";
    std::cin>>line;
    std::cout<<"ingrese columna: ";
    std::cin>>col;
    if (std::islower(col)) {
        col = std::toupper(col);
    }
    tablero.modify_matriz('*',line,col);
    tablero.print_matriz();

    std::cout<<std::endl<<"si o no";
    std::cin>>flag;

    if(flag==1){

        break;
    }

}




}
