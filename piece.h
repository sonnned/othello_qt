#ifndef PIECE_H
#define PIECE_H

/**
 * @brief A class that represents a Piece of othello game
*/
class Piece
{
public:
    /**
     * @brief Constructor for Piece
     * @param value The value of the representation of piece either WHITE (*) or BLACK (-)
     * @param x_pos The row (x) position of the piece in the board
     * @param y_pos The column (y) position of the piece in the board
    */
    Piece(char value, unsigned int x_pos, unsigned int y_pos): value(value), x_pos(x_pos), y_pos(y_pos) {
        amount_of_pieces++;
    }
    /**
     * @brief Get the value of the piece
     * @return A char that represents either WHITE (*) or BLACK (-)
    */
    char get_value();
    /**
     * @brief Get the value row (x) position of the piece
     * @return The row (x) position of the piece
    */
    unsigned int getX_pos();
    /**
     * @brief Get the value column (y) position of the piece
     * @return The column (y) position of the piece
    */
    unsigned int getY_pos();
    /**
     * @brief The number of pieces created so far
    */
    static int amount_of_pieces;
private:
    char value; /**< The value of the piece */
    unsigned int x_pos; /**< The row (x) position of the piece */
    unsigned int y_pos; /**< The column (y) position of the piece */
};

#endif // PIECE_H
