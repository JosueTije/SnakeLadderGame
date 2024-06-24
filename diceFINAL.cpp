#include "diceFINAL.h"
#include <random>
#include <iostream>
#include <ctime>

using namespace std;

DiceFINAL::DiceFINAL(){
    srand(time(0));
}

int DiceFINAL::roll(){
    return (rand() % 6) + 1;
}