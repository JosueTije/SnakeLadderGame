#ifndef MANUAL_H
#define MANUAL_H

#include "mygame.h"

class Manual : public MyGame {
public:
    Manual();
    Manual(int boardSize, int snakesNum, int laddersNum, int snakesPenalty, int laddersBonus, int maxTurns, int playersNum);
    void start();
};

#endif