#include "square.h"

#include <iostream>
using namespace std;

Square::Square()
{
    value = 0;
    type = N;
};
Square::Square(int value, SquareType type)
{
    this->value = value;
    this->type = type;
}

int Square::operator+(int move) const
{
    switch (type)
    {
    case S:
        return move - abs(value);
    case L:
        return move + value;
    case N:
        return move;
    default:
        return move;
    }
}

SquareType Square::getType() const
{
    return type;
}
