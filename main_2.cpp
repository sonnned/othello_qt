#include <iostream>
#include "matriz.h"
#include "piece.h"
#include "board_functions.h"
using namespace std;

bool is_valid_position(int x, int y)
{
    return x >= 0 && x < BOARD_HEIGHT && y >= 0 && y < BOARD_WEIGHT;
}

bool is_empty_position(char board[BOARD_HEIGHT][BOARD_WEIGHT], int x, int y) {
    return board[x][y] == BOARD_EMPTY_SPACE;
}

void fill_board_false(bool board[BOARD_HEIGHT][BOARD_WEIGHT])
{
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WEIGHT; j++)
        {
            board[i][j] = false;
        }
    }
}

void possible_movements(char board[BOARD_HEIGHT][BOARD_WEIGHT], char piece_value) {
    int current_pos[2] = {-1, -1};
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WEIGHT; j++) {
            if (board[i][j] != BOARD_EMPTY_SPACE) {
                current_pos[0] = i;
                current_pos[1] = j;
                std::cout << "--------" << std::endl;
                std::cout << "X: " << current_pos[0] << " Y: " <<  current_pos[1] << std::endl;

                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        //std::cout << k << ", " << l << std::endl;
                        if (i == k && j == l) {
                            continue;
                        } else {
                            //std::cout << "X: " << k << " Y: " <<  l << std::endl;
                            if (board[k][l] != piece_value && board[k][l] != BOARD_EMPTY_SPACE) {
                                std::cout << "X: " << k << " Y: " <<  l << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    char board[BOARD_HEIGHT][BOARD_WEIGHT];
    fill_board_empty(board);
    Piece piece_1(BLACK, BOARD_HEIGHT / 2, BOARD_WEIGHT / 2 - 1);
    Piece piece_2(BLACK, BOARD_HEIGHT / 2 - 1, BOARD_WEIGHT / 2);
    Piece piece_3(WHITE, BOARD_HEIGHT / 2 - 1, BOARD_WEIGHT / 2 - 1);
    Piece piece_4(WHITE, BOARD_HEIGHT / 2, BOARD_WEIGHT / 2);
    fill_boar_with_piece(board, piece_1);
    fill_boar_with_piece(board, piece_2);
    fill_boar_with_piece(board, piece_3);
    fill_boar_with_piece(board, piece_4);
    print_board(board);

    possible_movements(board, WHITE);

    return 0;
}
