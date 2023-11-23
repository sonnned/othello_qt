#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <fstream>
#include "macros.h"

class matriz
{
private:
    char board[BOARD_SIZE][BOARD_SIZE]; /**< Tablero del juego de tamaño nxn */
public:
    /**
     * @brief Constructor del tablero
     * Se encarga de llamar una función que rellena el tablero con valores vacíos
    */
    matriz();
    /**
     * @brief Función que rellena el tablero con un caracter específico
     * En nuestro caso <EMPTY>
    */
    void init_board();
    /**
     * @brief Función que verifica si la dirección apuntada a partir de un posición de referencia es correcta
     * Por ejemplo para la posición (3,3) vemos las posiciones adyacentes a este punto
     * Vemos que tengamos piezas iguales a la pieza actual que está jugando lo que significa que podemos hacer un encierro de sandwich
     * @param x es la posición en la filas
     * @param y es la posición en las columnas
     * @param piece es la pieza actual que estamos usando, es decir, el jugador actual <WHITE, BLACK>
     * @param dir_x es el iterador de la posición x, va desde x - 1 hasta x + 1 que son las adyacentes
     * @param dir_y es el iterador de la posición y, va desde y - 1 hasta y + 1 que son las adyacentes
     * @return bool que indica si que se puede realizar un encierro
    */
    bool is_valid_direction(int x, int y, char piece, int dir_x, int dir_y);
    /**
     * @brief Función que verifica si una posición <x,y> es válida
     * Ve si está dentro de los límites del tablero
     * @param x es la posición en la filas
     * @param y es la posición en las columnas
     * @return bool que indica si la pocisión es válida
    */
    bool is_valid_pos(int x, int y);
    /**
     * @brief Función que verifica si el movimiento es válido
     * Itera sobre las posiciones aledañas a la posición actual <Arriba, Abajo, Izquierda, Derecha>
     * Por cada iteración de la posición llama a is_valid_direction para verificar que la dirección apunta es correcta
     * @param x es la posición en la filas
     * @param y es la posición en las columnas
     * @param piece es la pieza actual que estamos usando, es decir, el jugador actual <WHITE, BLACK>
     * @return bool que indica si que el movimiento es correcto
    */
    bool is_valid_move(int x, int y, char piece);
    /**
     * @brief Función que imprime el tablero del juego
    */
    void print_matriz();
    /**
     * @brief Función que se encarga de hacer el movimiento
     * Lo que hace es posicionar la pieza en la posiciones que le pasamos y verifica que las posiciones sean correctas para realizar un encierro
     * @param x es la posición en la filas
     * @param y es la posición en las columnas
     * @param piece es la pieza actual que estamos usando, es decir, el jugador actual <WHITE, BLACK>
    */
    void make_move(int x,int y, char piece);
    /**
     * @brief Función que realiza el encierro y cambia de color todas las piezas atrapadas
     * Va validando las posiciones y realizando el cambio
     * @param x es la posición en la filas
     * @param y es la posición en las columnas
     * @param piece es la pieza actual que estamos usando, es decir, el jugador actual <WHITE, BLACK>
     * @param dir_x es el iterador de la posición x, va desde x - 1 hasta x + 1 que son las adyacentes
     * @param dir_y es el iterador de la posición y, va desde y - 1 hasta y + 1 que son las adyacentes
     * @return bool que indica si que el movimiento es correcto
    */
    void sandwich_movement(int x, int y, char piece, int dir_x, int dir_y);
};

#endif // MATRIZ_H
