#include <iostream>
#define BOARD_HEIGHT 8
#define BOARD_WEIGHT 8
#define BOARD_SPACING '\t'
#define BOARD_EMPTY_SPACE ' '
#define WHITE '*'
#define BLACK '-'

class Piece
{
public:
    Piece(char value, unsigned int x_pos, unsigned int y_pos): value(value), x_pos(x_pos), y_pos(y_pos) {
        amount_of_pieces++;
    }
    char get_value();
    unsigned int getX_pos();
    unsigned int getY_pos();
    static int amount_of_pieces;
private:
    char value;
    unsigned int x_pos;
    unsigned int y_pos;
};

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
    std::cout << std::endl;

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

int main() {
    char board[BOARD_HEIGHT][BOARD_WEIGHT];
    fill_board_empty(board);
    Piece piece_1(WHITE, 1, 7);
    Piece piece_2(BLACK, 7, 2);
    Piece piece_3(WHITE, 4, 6);
    fill_boar_with_piece(board, piece_1);
    fill_boar_with_piece(board, piece_2);
    fill_boar_with_piece(board, piece_3);
    print_board(board);

    return 0;
}
