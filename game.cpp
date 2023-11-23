#include "game.h"

Game::Game()
{
    board = new matriz;
    white = new Player;
    black = new Player;
    currentPiece = white;
}

Game::~Game()
{
    delete board;
    delete white;
    delete black;
    delete currentPiece;
}

void Game::startGame()
{
}

void Game::playTurn(Player &player)
{

}

void Game::switchPlayer()
{

}

bool Game::isValidMove(int x, int y, Player &player)
{

}

void Game::makeMove(int x, int y, Player &player)
{

}

void Game::displayBoard()
{

}

bool Game::isGameOver()
{

}

void Game::getWinner()
{

}

void Game::resetGame()
{

}

int Game::getAmount_of_pieces()
{
    return white->getAmountOfPieces() + black->getAmountOfPieces();
}

int Game::getAmount_of_white_pieces()
{
    return white->getAmountOfPieces();
}

int Game::getAmount_of_black_pieces()
{
    return black->getAmountOfPieces();
}

void Game::save_stats()
{

}

void Game::print_stats()
{

}

int Game::get_amount_of_games()
{

}

void Game::save_game()
{

}
