#pragma once
#ifndef TicTacToe
#define TicTacToe

#include <array>
#include <string>

using namespace std;

class Player {

private:

    string name;
    char symbol;

public:
    void setName(string n) {
        name = n;
    };
    void setSymbol(char s) {
        symbol = s;
    };
    string getName() { return name; };
    char getSymbol() { return symbol; };

};

#endif // TicTacToe

//4210191021 - Intan Putri K. W
