#include <iostream>
#include "matriz.h"
#include "macros.h"
using namespace std;

int main()
{
    matriz board;
    int current_piece = 1; // 1 -> White / 2 -> Black

    while (true) {
        board.print_matriz();

        std::cout << "Turno de: " << (current_piece % 2 == 0 ? BLACK : WHITE) << std::endl;
        int x;
        int y;
        std::cout << "Posicion X: ";
        std::cin >> x;
        std::cout << "Posicion Y: ";
        std::cin >> y;

        if (board.is_valid_move(x, y, current_piece % 2 == 0 ? BLACK : WHITE)) {
            board.make_move(x, y, current_piece % 2 == 0 ? BLACK : WHITE);
            current_piece++;
        } else {
            std::cout << "Movimiento invalido" << std::endl;
        }
    }
}
