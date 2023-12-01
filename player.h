#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    Player();
    /**
     * @brief Función que obtiene la ficha del jugador
     * @return char
    */
    char getPiece();
    /**
     * @brief Función que obtiene la cantidad de fichas del jugador
     * @return int
    */
    int getAmountOfPieces();
    /**
     * @brief Función que aumenta la cantidad de fichas del jugador
     * @return void
    */
    void increaseAmountOfPieces();
    /**
     * @brief Función que disminuye la cantidad de fichas del jugador
     * @return void
    */
    void decreaseAmountOfPieces();
    /**
     * @brief Función que cambia la ficha del jugador
     * @param piece Ficha del jugador
     * @return void
    */
    void setPiece(char piece);
    void setAmountOfPiece(int i) {
        amountOfPieces = i;
    }
private:
    char piece; /**< Ficha del jugador */
    int amountOfPieces = 2; /**< Cantidad de fichas del jugador */
};

#endif // PLAYER_H
