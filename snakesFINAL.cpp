#include <iostream>
#include <fstream>
#include <string>
#include "automatic.h"
#include "manual.h"
using namespace std;

int main() {
    string inputs[8];
    string line;
    ifstream inputFile("input.txt");
    int i = 0;
    while (getline(inputFile, line)) {
        inputs[i] = line;
        i++;
    }

    int boardSize = stoi(inputs[0]);
    int snakesNum = stoi(inputs[1]);
    int laddersNum = stoi(inputs[2]);
    int snakesPenalty = stoi(inputs[3]);
    int laddersBonus = stoi(inputs[4]);
    int maxTurns = stoi(inputs[5]);
    int playersNum = stoi(inputs[6]);
    string gameType = inputs[7];

    inputFile.close();

    if (gameType == "A") {
        Automatic a(boardSize, snakesNum, laddersNum, snakesPenalty, laddersBonus, maxTurns, playersNum);
        a.start();
    } else if (gameType == "M") {
        Manual m(boardSize, snakesNum, laddersNum, snakesPenalty, laddersBonus, maxTurns, playersNum);
        m.start();
    } else {
        cout << "Invalid game type specified in input.txt. Please use 'A' for automatic or 'M' for manual." << endl;
    }

    return 0;
}