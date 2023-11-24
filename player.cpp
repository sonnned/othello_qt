#include "player.h"

Player::Player()
{

}

char Player::getPiece()
{
    return piece;
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
