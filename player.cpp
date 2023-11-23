#include "player.h"

Player::Player()
{

}

int Player::getAmountOfPieces()
{
    return amountOfPieces;
}

void Player::increaseAmountOfPieces()
{
    amountOfPieces++;
}

void Player::decreaseAmountOfPieces()
{
    amountOfPieces--;
}

void Player::setPiece(char piece)
{
    this->piece = piece;
}
