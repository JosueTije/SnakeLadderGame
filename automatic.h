#ifndef AUTOMATIC_H
#define AUTOMATIC_H

#include "mygame.h"

class Automatic : public MyGame {
public:
    Automatic();
    Automatic(int boardSize, int snakesNum, int laddersNum, int snakesPenalty, int laddersBonus, int maxTurns, int playersNum);
    void start();
};

#endif