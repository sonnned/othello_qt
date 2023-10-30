#include <iostream>
#include "matriz.h"


int main()
{
    int flag=1;
    matriz tablero;
    while(true){

        tablero.print_matriz();
        tablero.modify_matriz('*');
        tablero.print_matriz();
        tablero.modify_matriz('-');
        tablero.print_matriz();
      std::cout<<std::endl;
      std::cout<<std::endl<<"si o no";
      std::cin>>flag;

    if(flag==1){

        break;
    }

}




}
