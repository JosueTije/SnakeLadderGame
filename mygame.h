#ifndef MYGAME_H
#define MYGAME_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "square.h"
#include "turn.h"
#include "diceFINAL.h"
using namespace std;

class MyGame {
public:
    MyGame();
    MyGame(int boardSize, int snakesNum, int laddersNum, int snakesPenalty, int laddersBonus, int maxTurns, int playersNum);
    void processTurn(int player, ofstream &myfile);
        int boardSize;
    int snakesNum;
    int laddersNum;
    int snakesPenalty;
    int laddersBonus;
    int maxTurns;
    int playersNum;
    int turnCount;
    DiceFINAL dice;
    vector<Square> board;
    vector<int> positions;
protected:


    void setupBoard();

};

#endif
