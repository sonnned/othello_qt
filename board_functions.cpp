#include "board_functions.h"

void fill_board_empty(char board[BOARD_HEIGHT][BOARD_WEIGHT]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WEIGHT; j++) {
            board[i][j] = BOARD_EMPTY_SPACE;
        }
    }
}

void fill_boar_with_piece(char board[BOARD_HEIGHT][BOARD_WEIGHT], Piece piece) {
    board[piece.getX_pos()][piece.getY_pos()] = piece.get_value();
}

void print_board(char board[BOARD_HEIGHT][BOARD_WEIGHT]) {
    for (int i = 0; i < BOARD_WEIGHT; i++) {
        std::cout << BOARD_SPACING << char(i + 65);
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WEIGHT; j++) {
            if (j == 0) {
                std::cout << (i + 1) << BOARD_SPACING;
            }
            std::cout << board[i][j] << BOARD_SPACING;
        }
        std::cout << std::endl;
    }
}
