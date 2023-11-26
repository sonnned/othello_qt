#include "macros.h"
#include "game.h"
#include "matriz.h"
#include <iostream>
#include <limits>

//Para BOARD_SIZE = 4
//(2,D) (3,D) (4,D) (1,D) (3,A) (4,A) (1,C) (1,B) (2,A) (1,A) (4,B) (4,C)
int main()
{
    Game game;
    bool startMainMenu = true;
    std::cout << "Welcome to Othello" << std::endl;
    while(startMainMenu) {
        std::cout << "1. Play" << std::endl;
        std::cout << "2. New game" << std::endl;
        std::cout << "3. Game stats" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Option: ";
        int mainMenuOption;
        if (std::cin >> mainMenuOption) {
            switch (mainMenuOption) {
            case 1 :
            {
                bool startInternalGame = true;
                while (startInternalGame) {
                    std::cout << "--------Current board--------" << std::endl;
                    game.displayBoard();
                }
                break;
            }
            case 2:
                game.startGame();
                break;
            case 3:
                std::cout << std::endl;
                game.print_stats();
                break;
            case 4:
                startMainMenu = false;
                std::cout << "--------Game over--------" << std::endl;
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
            }
        } else {
            std::cout << "Invalid option" << std::endl;
            std::cin.clear();	// Limpia el error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// Descarta inputs malos < fuera de rango>
        }
    }
}
