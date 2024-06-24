#include "automatic.h"
#include <fstream>
#include <iostream>
using namespace std;

Automatic::Automatic() : MyGame() {}

Automatic::Automatic(int boardSize, int snakesNum, int laddersNum, int snakesPenalty, int laddersBonus, int maxTurns, int playersNum) : MyGame(boardSize, snakesNum, laddersNum, snakesPenalty, laddersBonus, maxTurns, playersNum)
{
    this->boardSize = boardSize;
    this->snakesNum = snakesNum;
    this->laddersNum = laddersNum;
    this->snakesPenalty = snakesPenalty;
    this->laddersBonus = laddersBonus;
    this->maxTurns = maxTurns;
    this->playersNum = playersNum;
}

void Automatic::start()
{
    ofstream myfile("output.txt");

    myfile << "Welcome to the fabulous Snake game!!\n\n";
    MyGame juego(boardSize, snakesNum, laddersNum, snakesPenalty, laddersBonus, maxTurns, playersNum);
    while (turnCount <= maxTurns)
    {
        for (int i = 0; i < playersNum; ++i)
        {
            juego.processTurn(i, myfile);
            if (positions[i] >= boardSize)
                return;
        }
        myfile << "-------------------------------" << endl;
    }

    myfile << "The maximum number of turns has been reached...\n-- GAME OVER --" << endl;
}