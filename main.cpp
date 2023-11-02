#include <iostream>
#include "matriz.h"
#include "macros.h"
using namespace std;
//Para BOARD_SIZE = 4
//(2,D) (3,D) (4,D) (1,D) (3,A) (4,A) (1,C) (1,B) (2,A) (1,A) (4,B) (4,C)
int main()
{
    matriz board;
    int current_piece = 1; // 1 -> White / 2 -> Black
    bool ban = true;

    std::cout << "Bienvenido a Othello" << std::endl;

    while (ban) {
        if (board.getAmount_of_pieces() + 4 == BOARD_SIZE * BOARD_SIZE) {
            std::cout << "El juego ha terminado" << std::endl;
            std::cout << "Ganador: " << std::endl;
            ban = false;
            break;
        }
        std::cout << "Tablero" << std::endl;
        board.print_matriz();
        std::cout << std::endl << "Turno de: " << "<" << (current_piece % 2 == 0 ? BLACK : WHITE) << ">" << std::endl << std::endl;
        std::cout << "1. Jugar" << std::endl;
        std::cout << "2. Pasar turno" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Opcion: ";
        int option;
        std::cin >> option;

        switch (option) {
            case 1: {
                int x;
                char y;
                std::cout << "Posicion X: ";
                std::cin >> x;
                std::cout << "Posicion Y: ";
                std::cin >> y;

                std::cout << (x - 1) << " " << (int(y - 65)) << std::endl;
                if (board.is_valid_move(x - 1, int(y - 65), current_piece % 2 == 0 ? BLACK : WHITE)) {
                    board.make_move(x - 1, int(y - 65), current_piece % 2 == 0 ? BLACK : WHITE);
                    current_piece++;
                } else {
                    std::cout << std::endl << "\tMovimiento invalido" << std::endl;
                }
                break;
            }
            case 2: {
                current_piece++;
                break;
            }
            case 3: {
                ban = false;
                break;
            }
            default: {
                std::cout << "Opcion invalida" << std::endl;
                break;
            }
        }
    }
}
