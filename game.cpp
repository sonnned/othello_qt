#include "game.h"

Game::Game()
{
    std::ifstream checkFile("database.txt");
    if (!checkFile) {
        std::ofstream createFile("database.txt");
        if (!createFile) {
            std::cerr << "Error creating file" << std::endl;
            exit(1);
        }
        createFile.close();
    }
    checkFile.close();

    matriz board;
}

Game::~Game()
{
    //delete currentPiece;
}

void Game::startGame()
{
    board.init_board();
}

bool Game::isValidMove(int x, int y, Player &player)
{
    return board.is_valid_move(x, y, player.getPiece());
}

void Game::makeMove(int x, int y, Player &player, Player &opponent)
{
    board.make_move(x, y, player, opponent);
}

void Game::displayBoard()
{
    board.print_matriz();
}

void Game::save_stats(int amountBlackPieces, int amountWhitePieces, char winner)
{
    int amount_of_games = get_amount_of_games();
    std::ofstream file;
    file.open("database.txt", std::ios::app);

    if (file.fail()) {
        std::cout << "Error while open file" << std::endl;
        exit(1);
    }

    file << "Game: " << (amount_of_games + 1) << std::endl;
    file << "Board size: " << BOARD_SIZE << std::endl;
    file << "Amount of pieces: " << (amountBlackPieces + amountWhitePieces) << std::endl;
    file << "White pieces: " << amountWhitePieces << std::endl;
    file << "Black pieces: " << amountBlackPieces << std::endl;
    file << "Winner: " << "( " << winner << " )" << std::endl;
    file << "-----------------------------" << std::endl;

    file.close();
}

void Game::print_stats()
{
    std::ifstream file;
    file.open("database.txt", std::ios::in);

    if (file.fail()) {
        std::cout << "Error while open file" << std::endl;
        exit(1);
    }

    char c;
    while (!file.eof()) {
        file.get(c);
        std::cout << c;
    }

    file.close();
}

void Game::save_game()
{

}

int Game::get_amount_of_games()
{
    int amount_of_games = 0;
    std::ifstream file;
    file.open("database.txt", std::ios::in);

    if (file.fail()) {
        std::cout << "Error while open file" << std::endl;
        exit(1);
    }

    char c;
    int count = 0;
    while (!file.eof()) {
        file.get(c);
        if (c == "Game"[count]) {
            count++;
            if (count == 4) {
                amount_of_games++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    file.close();
    return amount_of_games;
}
