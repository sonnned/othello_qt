#ifndef GAME_H
#define GAME_H

#include "matriz.h"
#include "player.h"

class Game
{
public:
    Game();
    ~Game();
    /**
     * @brief Función que inicia el juego y configura el proyecto
     * @return void
    */
    void startGame();
    /**
     * @brief Función que juega el turno del jugador
     * @param player Jugador que juega el turno
     * @return void
    */
    void playTurn(Player &player);
    /**
     * @brief Función que cambia el turno del jugador
     * @return void
    */
    void switchPlayer();
    /**
     * @brief Función que valida si el movimiento es válido
     * @param x Posición en x
     * @param y Posición en y
     * @param player Jugador que juega el turno
     * @return bool
    */
    bool isValidMove(int x, int y, Player &player);
    /**
     * @brief Función que realiza el movimiento
     * @param x Posición en x
     * @param y Posición en y
     * @param player Jugador que juega el turno
     * @return void
    */
    void makeMove(int x, int y, Player &player);
    /**
     * @brief Función que valida si el movimiento es válido
     * @param x Posición en x
     * @param y Posición en y
     * @param player Jugador que juega el turno
     * @return bool
    */
    void displayBoard();
    /**
     * @brief Función que valida si el juego ha terminado
     * @return bool
    */
    bool isGameOver();
    /**
     * @brief Función que imprime el ganador del juego
     * @return bool
    */
    void getWinner();
    /**
     * @brief Función que reinicia el juego
     * @return void
    */
    void resetGame();
    /**
     * @brief Función que obtiene la cantidad de piezas actuales en juego
     * @return int que es las piezas actuales en juego
    */
    int getAmount_of_pieces();
    /**
     * @brief Función que obtiene la cantidad de piezas blancas actuales en juego
     * @return int que es las piezas blancas actuales en juego
    */
    int getAmount_of_white_pieces();
    /**
     * @brief Función que obtiene la cantidad de piezas blancas actuales en juego
     * @return int que es las piezas blancas actuales en juego
    */
    int getAmount_of_black_pieces();
    /**
     * @brief Función que guarda las estadísticas del juego
    */
    void save_stats();
    /**
     * @brief Función que imprime las estadísticas del juego
    */
    void print_stats();
    /**
     * @brief Función que nos dice la cantidad de juegos que se han jugado
     * @return int que es la cantidad de juegos que se han jugado
    */
    int get_amount_of_games();
    /**
     * @brief Función que guarda el estado del juego
     */
    void save_game();
private:
    matriz *board; /**< Tablero del juego */
    Player *white; /**< Jugador fichas blancas */
    Player *black; /**< Jugador fichas negras */
    Player *currentPiece; /**< Ficha del turno actual */
    bool gameOver = false; /**< Guarda el estado del juego */
};

#endif // GAME_H
