#include "manual.h"
#include <iostream>
#include <fstream>
using namespace std;

Manual::Manual() : MyGame() {}

Manual::Manual(int boardSize, int snakesNum, int laddersNum, int snakesPenalty, int laddersBonus, int maxTurns, int playersNum) : MyGame(boardSize, snakesNum, laddersNum, snakesPenalty, laddersBonus, maxTurns, playersNum)
{
    this->boardSize = boardSize;
    this->snakesNum = snakesNum;
    this->laddersNum = laddersNum;
    this->snakesPenalty = snakesPenalty;
    this->laddersBonus = laddersBonus;
    this->maxTurns = maxTurns;
    this->playersNum = playersNum;
}

void Manual::start()
{
    ofstream myfile("output.txt");
    myfile << "Welcome to the fabulous Snake game!!\n\n";
    vector<string> players(playersNum);

    cout << "Please enter the names of the players:\n";
    for (int i = 0; i < playersNum; ++i)
    {
        cout << "Player " << i + 1 << ": ";
        cin >> players[i];
    }
    try
    {
        while (turnCount <= maxTurns)
        {
            if (turnCount > 1)
            {
                char command;
                cout << "Press C to continue next turn, or E to end the game: ";
                cin >> command;
                int i = 0;
                while (command != 'C' && command != 'E' && i < 5)
                {
                    if (i == 4)
                    {
                        throw runtime_error("Invalid menu choice exceeded");
                    }
                    cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
                    cout << "Press C to continue next turn, or E to end the game: ";
                    cin >> command;
                    i++;
                }

                command = toupper(command);
                if (command == 'E')
                {
                    cout << "Thanks for playing!\n-- GAME OVER --" << endl;
                    return;
                }
            }

            for (int i = 0; i < playersNum; ++i)
            {
                processTurn(i, myfile);
                if (positions[i] >= boardSize)
                    return;
            }

            myfile << "-------------------------------" << endl;
        }
    }
    catch (const exception &e)
    {
        cout << e.what() << endl << "--GAME OVER--" << endl;
    }

    myfile << "The maximum number of turns has been reached...\n-- GAME OVER --" << endl;
}