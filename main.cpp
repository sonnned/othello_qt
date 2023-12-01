#include "macros.h"
#include "game.h"
#include "matriz.h"
#include "player.h"

#include <iostream>
#include <limits>

//Para BOARD_SIZE = 4
//(2,D) (3,D) (4,D) (1,D) (3,A) (4,A) (1,C) (1,B) (2,A) (1,A) (4,B) (4,C)
int main()
{
    Game game;
    bool startMainMenu = true;
    int currentPlayer = 1;
    int isDraw = 0;
    while(startMainMenu) {
        std::cout << "Welcome to Othello" << std::endl;
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
                game.startGame();
                Player *white = new Player();
                white->setPiece(WHITE);
                Player *black = new Player();
                black->setPiece(BLACK);
                bool startInternalGame = true;
                while (startInternalGame) {
                    if (game.getAmount_of_pieces() == BOARD_SIZE * BOARD_SIZE || isDraw == 2) {
                        std::cout << "--------Game over--------" << std::endl;
                        if (game.getAmount_of_black_pieces() > game.getAmount_of_white_pieces()) std::cout << "Winner: " << "< " << BLACK << " >" << std::endl;
                        else if (game.getAmount_of_black_pieces() < game.getAmount_of_white_pieces()) std::cout << "Winner: " << "< " << WHITE << " >" << std::endl;
                        else std::cout << "Draw" << std::endl;
                        std::cout << "Would u like to see the stats? (1/0): ";
                        int option;
                        std::cin >> option;
                        if (option == 1) {
                            game.save_stats();
                            startInternalGame = false;
                            break;
                        }
                        mainMenuOption = false;
                        break;
                    }
                    std::cout << "--------Current board--------" << std::endl;
                    game.displayBoard();
                    std::cout << std::endl << "Current player: " << "< " << (currentPlayer % 2 == 0 ? BLACK : WHITE) << " >" << std::endl << std::endl;
                    std::cout << "1. Play" << std::endl;
                    std::cout << "2. Pass" << std::endl;
                    std::cout << "3. Exit" << std::endl;
                    std::cout << "Option: ";
                    int option;
                    if (std::cin >> option) {
                        switch (option) {
                        case 1:
                            int xPosition;
                            char yPosition;
                            std::cout << "--------Position X: ";
                            std::cin >> xPosition;
                            std::cout << "--------Position Y: ";
                            std::cin >> yPosition;
                            if (game.isValidMove(xPosition - 1, int(std::toupper(yPosition) - 65), (currentPlayer % 2 == 0 ? *black : *white))) {
                                game.makeMove(xPosition - 1, int(std::toupper(yPosition) - 65), (currentPlayer % 2 == 0 ? *black : *white));
                                currentPlayer++;
                            } else std::cout << "--------Invalid Movement--------" << std::endl;
                            break;
                        case 2:
                            currentPlayer++;
                            isDraw++;
                            break;
                        case 3:
                            startInternalGame = false;
                            break;
                        default:
                            break;
                        }
                    } else {
                        std::cout << "Invalid option" << std::endl;
                        std::cin.clear();	// Limpia el error
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// Descarta inputs malos < fuera de rango>
                    }
                }
                break;
            }
            case 2:
                game.startGame();
                currentPlayer = 1;
                isDraw = 0;
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
