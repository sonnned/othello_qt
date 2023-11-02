#include "matriz.h"

void matriz::init_board()
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    board[BOARD_SIZE / 2][BOARD_SIZE / 2] = WHITE;
    board[(BOARD_SIZE / 2) - 1][(BOARD_SIZE / 2) - 1] = WHITE;
    board[(BOARD_SIZE / 2) - 1][BOARD_SIZE / 2] = BLACK;
    board[BOARD_SIZE / 2][(BOARD_SIZE / 2) - 1] = BLACK;
}

bool matriz::is_valid_direction(int x, int y, char piece, int dir_x, int dir_y)
{
    int i = x + dir_x;
    int j = y + dir_y;

    if (!is_valid_pos(i, j) || board[i][j] != (piece == BLACK ? WHITE : BLACK)) return false;

    while (is_valid_pos(i, j)) {
        if (board[i][j] == EMPTY) return false;
        if (board[i][j] == piece) return true;
        i += dir_x;
        y += dir_y;
    }
    return false;
}

bool matriz::is_valid_pos(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

bool matriz::is_valid_move(int x, int y, char piece)
{
    if (!is_valid_pos(x, y) || board[x][y] != EMPTY) return false;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (is_valid_direction(x, y, piece, i, j)) return true;
        }
    }
    return false;
}

void matriz::print_matriz()
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << SPACER << int(i + 0);
    }
    std::cout << std::endl;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if(j == 0) std::cout << (i + 0) << SPACER;
            std::cout << "[" << board[i][j] << "]" << SPACER;
        }
        std::cout << std::endl << std::endl;
    }
}

void matriz::make_move(int x, int y, char piece)
{
    board[x][y] = piece;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (is_valid_direction(x, y, piece, i, j)) {
                sandwich_movement(x, y, piece, i, j);
            }
        }
    }
}

void matriz::sandwich_movement(int x, int y, char piece, int dir_x, int dir_y)
{
    int i = x + dir_x;
    int j = y + dir_y;

    while (is_valid_pos(x, y)) {
        if (board[i][j] == piece) {
            return;
        }
        board[i][j] = piece;

        i += dir_x;
        j += dir_y;
    }
}

