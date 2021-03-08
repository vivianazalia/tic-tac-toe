#pragma once
#ifndef TicTacToe
#define TicTacToe

#include <array>
#include <string>

using namespace std;

class Player {

private:

    string name;
    string symbol;

public:

    void setName(string n);
    void setSymbol(string s);
    string getName();
    string getSymbol();

};

#endif // TicTacToe

//4210191021 - Intan Putri K. W
