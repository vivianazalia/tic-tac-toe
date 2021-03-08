#pragma once
#include"Player.h"
#include<string>

using namespace std; 

class History {

private:

    string date;
    string time;
    Player player1;
    Player player2;
    string statePlayer1;
    string statePlayer2;
    int history;

public:

    void setDate(string d);
    void setTime(string t);
    void setStatePlayer1(string p1);
    void setStatePlayer2(string p2);
    void setHistory(int h);
    string getDate();
    string getTime();
    Player player3();
    Player player4();
    string getStatePlayer1();
    string getStatePlayer2();
    int getHistory();

};

//4210191021 - Intan Putri K. W
