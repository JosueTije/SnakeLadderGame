#include <math.h>
#ifndef SQUARE_H
#define SQUARE_H

enum SquareType
{
    N,
    S,
    L
};

class Square
{
public:

    Square();
    Square(int value, SquareType type);
    int operator+(int move) const;

    SquareType getType() const;

private:
    int value;
    SquareType type;
};

#endif