#ifndef TURN_H
#define TURN_H

#include <iostream>
using namespace std;

class Turn
{
public:
    Turn();
    Turn(int turnCount, int player, int startPosition, int roll, char squareType, int endPosition);

    friend ostream &operator<<(ostream &os, const Turn &turn);

private:
    int turnCount;
    int player;
    int startPosition;
    int roll;
    char squareType;
    int endPosition;
};

#endif
