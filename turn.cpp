#include "turn.h"
#include <iostream>
using namespace std;

Turn::Turn()
{
    turnCount = 0;
    player = 0;
    startPosition = 0;
    roll = 0;
    squareType = 'N';
    endPosition = 0;
}
Turn::Turn(int turnCount, int player, int startPosition, int roll, char squareType, int endPosition)
{
    this->turnCount = turnCount;
    this->player = player;
    this->startPosition = startPosition;
    this->roll = roll;
    this->squareType = squareType;
    this->endPosition = endPosition;
}

ostream &operator<<(ostream &os, const Turn &turn)
{
    os << "Turn: " << turn.turnCount << " | Player: " << turn.player
       << " | Start: " << turn.startPosition << " | Roll: " << turn.roll
       << " | Square: " << turn.squareType << " | End: " << turn.endPosition;
    return os;
}