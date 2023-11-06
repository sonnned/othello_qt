#include "matriz.h"

int matriz::getAmount_of_pieces()
{
    return amount_of_pieces + 4;
}

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
        j += dir_y;
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
        std::cout << SPACER << char(i + 65);
    }
    std::cout << std::endl;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if(j == 0) std::cout << (i + 1) << SPACER;
            std::cout << "[" << board[i][j] << "]" << SPACER;
        }
        std::cout << std::endl << std::endl;
    }
}

void matriz::make_move(int x, int y, char piece)
{
    board[x][y] = piece;
    amount_of_pieces++;

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

int matriz::getAmount_of_black_pieces() {
    int black_pieces = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == BLACK) black_pieces++;
        }
    }
    return black_pieces;
}

int matriz::getAmount_of_white_pieces() {
    int white_pieces = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == WHITE) white_pieces++;
        }
    }
    return white_pieces;
}

void matriz::save_stats() {
    int amount_of_games = get_amount_of_games();
    std::ofstream file;
    file.open("database.txt", std::ios::app);

    if (file.fail()) {
        std::cout << "Error al abrir el archivo" << std::endl;
        exit(1);
    }

    file << "Partida: " << (amount_of_games + 1) << std::endl;
    file << "Tamano del tablero: " << BOARD_SIZE << std::endl;
    file << "Cantidad de piezas: " << getAmount_of_pieces() << std::endl;
    file << "Cantidad de piezas blancas: " << getAmount_of_white_pieces() << std::endl;
    file << "Cantidad de piezas negras: " << getAmount_of_black_pieces() << std::endl;
    file << "-----------------------------" << std::endl;

    file.close();
}

void matriz::print_stats() {
    std::ifstream file;
    file.open("database.txt", std::ios::in);

    if (file.fail()) {
        std::cout << "Error al abrir el archivo" << std::endl;
        exit(1);
    }

    char c;
    while (!file.eof()) {
        file.get(c);
        std::cout << c;
    }

    file.close();
}

int matriz::get_amount_of_games() {
    int amount_of_games = 0;
    std::ifstream file;
    file.open("database.txt", std::ios::in);

    if (file.fail()) {
        std::cout << "Error al abrir el archivo" << std::endl;
        exit(1);
    }

    char c;
    int count = 0;
    while (!file.eof()) {
        file.get(c);
        if (c == "Partida"[count]) {
            count++;
            if (count == 7) {
                amount_of_games++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    file.close();
    return amount_of_games;
}
