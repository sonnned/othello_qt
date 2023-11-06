#ifndef BOARD_FUNCTIONS_H
#define BOARD_FUNCTIONS_H

#include <iostream>
#include "macros.h"
#include "piece.h"

/**
     * @brief Modify the positions of the board whit an empty character representation (' ')
     * @param board The board of the game
    */
void fill_board_empty(char board[BOARD_HEIGHT][BOARD_WEIGHT]);
/**
     * @brief Modify the positions of the board whit a piece value either WHITE (*) or BLACK (-)
     * @param board The board of the game
     * @param piece The piece that will fill a board position
    */
void fill_boar_with_piece(char board[BOARD_HEIGHT][BOARD_WEIGHT],Piece piece);
/**
 * Imprime las primeras fichas del juego
 *
 *
*/

void first_pieces(char board[BOARD_HEIGHT][BOARD_WEIGHT],char white,char black);





/**
     * @brief Print the board
     * @param board The board of the game
    */
void print_board(char board[BOARD_HEIGHT][BOARD_WEIGHT]);



#endif // BOARD_FUNCTIONS_H

