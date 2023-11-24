#include "game.h"

Game::Game()
{
    matriz board;
    Player white;
    Player black;
}

Game::~Game()
{
    //delete currentPiece;
}

void Game::startGame()
{

    board.init_board();
    white.setPiece(WHITE);
    black.setPiece(BLACK);
    currentPiece = white.getPiece();
}

void Game::playTurn(Player &player)
{

}

void Game::switchPlayer()
{

}

bool Game::isValidMove(int x, int y, Player &player)
{
    return true;
}

void Game::makeMove(int x, int y, Player &player)
{

}

void Game::displayBoard()
{
    board.print_matriz();
}

bool Game::isGameOver()
{
    return false;
}

void Game::getWinner()
{

}

void Game::resetGame()
{

}

int Game::getAmount_of_pieces()
{
    return white.getAmountOfPieces() + black.getAmountOfPieces();
}

int Game::getAmount_of_white_pieces()
{
    return white.getAmountOfPieces();
}

int Game::getAmount_of_black_pieces()
{
    return black.getAmountOfPieces();
}

void Game::save_stats()
{

}

void Game::print_stats()
{

}

int Game::get_amount_of_games()
{
    return 1;
}

void Game::save_game()
{

}
