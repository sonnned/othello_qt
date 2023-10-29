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
