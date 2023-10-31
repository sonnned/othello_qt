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
    Piece(char value): value(value) {
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


    void setX_pos(unsigned int newX_pos);

    void setY_pos(unsigned int newY_pos);

private:
    char value; /**< The value of the piece */
    unsigned int x_pos=0; /**< The row (x) position of the piece */
    unsigned int y_pos=0; /**< The column (y) position of the piece */

};

#endif // PIECE_H
