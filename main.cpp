#include <iostream>
#include "matriz.h"
#include "macros.h"
//Para BOARD_SIZE = 4
//(2,D) (3,D) (4,D) (1,D) (3,A) (4,A) (1,C) (1,B) (2,A) (1,A) (4,B) (4,C)
int main()
{
    matriz board;
    int current_piece = 1; // 1 -> White / 2 -> Black
    bool ban = true;
    bool ban_menu = true;
    int is_draw = 0;

    std::cout << "Bienvenido a Othello" << std::endl;
    while(ban_menu) {
        std::cout << "1. Jugar" << std::endl;
        std::cout << "2. Empezar juego nuevo" << std::endl;
        std::cout << "3. Ver estadisticas" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Opcion: ";
        char option_menu;
        std::cin >> option_menu;

        switch(option_menu - '0') {
            case 2: {
                board.init_board();
                current_piece = 1;
                is_draw = 0;
            }
            case 1: {
                ban = true;
                while (ban) {
                    if (board.getAmount_of_pieces() == BOARD_SIZE * BOARD_SIZE || is_draw == 2) {
                        std::cout << "El juego ha terminado" << std::endl;
                        if (board.getAmount_of_black_pieces() > board.getAmount_of_white_pieces()) {
                            std::cout << "Ganador: <" << BLACK << ">" << std::endl;
                        } else if (board.getAmount_of_white_pieces() > board.getAmount_of_black_pieces()) {
                            std::cout << "Ganador: <" << WHITE << ">" << std::endl;
                        } else {
                            std::cout << "Empate" << std::endl;
                        }

                        std::cout << "Desea guardar las estadisticas? (1/0): ";
                        int option;
                        std::cin >> option;

                        if (option == 1) {
                            board.save_stats();
                            ban = false;
                            break;
                        }

                        ban_menu = false;
                        break;
                    }
                    std::cout << "Tablero" << std::endl;
                    board.print_matriz();
                    std::cout << std::endl << "Turno de: " << "<" << (current_piece % 2 == 0 ? BLACK : WHITE) << ">" << std::endl << std::endl;
                    std::cout << "1. Jugar" << std::endl;
                    std::cout << "2. Pasar turno" << std::endl;
                    std::cout << "3. Salir" << std::endl;
                    std::cout << "Opcion: ";
                    char option;
                    std::cin >> option;
                    switch (option - '0') {
                        case 1: {
                            int x;
                            char y;
                            std::cout << "Posicion X: ";
                            std::cin >> x;
                            std::cout << "Posicion Y: ";
                            std::cin >> y;

                            if (board.is_valid_move(x - 1, int(std::toupper(y) - 65), current_piece % 2 == 0 ? BLACK : WHITE)) {
                                board.make_move(x - 1, int(std::toupper(y) - 65), current_piece % 2 == 0 ? BLACK : WHITE);
                                current_piece++;
                            } else {
                                std::cout << std::endl << "\tMovimiento invalido" << std::endl;
                            }
                            break;
                        }
                        case 2: {
                            current_piece++;
                            is_draw++;
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

                break;
            }

            case 3: {
                std::cout << std::endl;
                board.print_stats();
                break;
            }
            case 4: {
                ban_menu = false;
                break;
            }
            default: {
                std::cout << "Opcion invalida" << std::endl;
                break;
            }
        }
    }
}
