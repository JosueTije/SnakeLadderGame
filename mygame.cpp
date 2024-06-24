#include "mygame.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

MyGame::MyGame()
{
    boardSize = 0;
    snakesNum = 0;
    laddersNum = 0;
    snakesPenalty = 0;
    laddersBonus = 0;
    maxTurns = 0;
    playersNum = 0;
    turnCount = 0;
}

MyGame::MyGame(int boardSize, int snakesNum, int laddersNum, int snakesPenalty, int laddersBonus, int maxTurns, int playersNum)
{
    this->boardSize = boardSize;
    this->snakesNum = snakesNum;
    this->laddersNum = laddersNum;
    this->snakesPenalty = snakesPenalty;
    this->laddersBonus = laddersBonus;
    this->maxTurns = maxTurns;
    this->playersNum = playersNum;
    this->turnCount = 1;
    setupBoard();
    positions.resize(playersNum, 1);
}

void MyGame::setupBoard()
{
    try
    {
        if (boardSize < 10 || boardSize > 100)
        {
            throw boardSize;
        }
        if (snakesNum < 1 || snakesNum > 5)
        {
            throw snakesNum;
        }
        if (laddersNum < 1 || laddersNum > 5)
        {
            throw laddersNum;
        }
        if (snakesPenalty < 1 || snakesPenalty > 5)
        {
            throw snakesPenalty;
        }
        if (laddersBonus < 1 || laddersBonus > 5)
        {
            throw laddersBonus;
        }
        if (maxTurns < 1 )
        {
            throw maxTurns;
        }
        if (playersNum < 1)
        {
            throw playersNum;
        }
    }
    catch (int e)
    {
        cout << "Invalid board size. Value entered:" << e << endl;
        exit(0);
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
        exit(0);
    }

    board.resize(boardSize, Square(0, N));
    int low = 5, high = boardSize - 5;
    srand(time(0));

    for (int i = 0; i < snakesNum; ++i)
    {
        int pos = rand() % (high - low + 1) + low;
        if (board[pos].getType() == N)
        {
            board[pos] = Square(snakesPenalty, S);
        }
        else
        {
            --i;
        }
    }

    for (int i = 0; i < laddersNum; ++i)
    {
        int pos = rand() % (high - low + 1) + low;
        if (board[pos].getType() == N)
        {
            board[pos] = Square(laddersBonus, L);
        }
        else
        {
            --i;
        }
    }
}

void MyGame::processTurn(int player, ofstream &myfile)
{
    int roll = dice.roll();

    int startPosition = positions[player];
    positions[player] = startPosition + roll;
    char squareType = board[positions[player] - 1].getType();

    Turn turn(turnCount, player + 1, startPosition, roll, 'N', positions[player]);
    myfile << turn << endl;
    if (positions[player] >= boardSize)
    {
        myfile << "Player " << player + 1 << " wins!\n-- GAME OVER --" << endl;
        exit(0);
    }

    turnCount++;
}
