#include "piece.h"

int Piece::amount_of_pieces = 0;

char Piece::get_value() {
    return value;
}

unsigned int Piece::getX_pos() {
    return x_pos;
}

unsigned int Piece::getY_pos() {
    return y_pos;
}

void Piece::setX_pos(unsigned int newX_pos)
{
    x_pos = newX_pos;
}

void Piece::setY_pos(unsigned int newY_pos)
{
    y_pos = newY_pos;
}
