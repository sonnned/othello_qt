#ifndef GAME_H
#define GAME_H

#include "macros.h"
#include "matriz.h"
#include "player.h"

#include <iostream>
#include <fstream>

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
    void makeMove(int x, int y, Player &player, Player &opponent);
    /**
     * @brief Función que valida si el movimiento es válido
     * @param x Posición en x
     * @param y Posición en y
     * @param player Jugador que juega el turno
     * @return bool
    */
    void displayBoard();
    /**
     * @brief Función que guarda las estadísticas del juego
    */
    void save_stats(int amountBlackPieces, int amountWhitePieces, char winner);
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
    matriz board; /**< Tablero del juego */
};

#endif // GAME_H
