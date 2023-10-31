#include <iostream>
#include "matriz.h"
#include "piece.h"
#include "macros.h"


int main()
{
    int flag=1;
    matriz tablero;
    Piece gamer1(WHITE);
    Piece gamer2(BLACK);
    while(true){
//acciones del jugador 1
        tablero.print_matriz();
        tablero.info_user_matriz(gamer1);
        tablero.modify_matriz(gamer1);
        tablero.print_matriz();


//acciones del jugador 2
        tablero.info_user_matriz(gamer2);
        tablero.modify_matriz(gamer2);
        tablero.print_matriz();


      std::cout<<std::endl;
      std::cout<<std::endl<<"si o no";
      std::cin>>flag;

    if(flag==1){

        break;
    }

}




}
