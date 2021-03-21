#pragma once
#include <array>
#include <string>
#include "Player.h"

using namespace std;

void Player::setName(string n) {
    name = n;
}

void Player::setSymbol(char s) {
    symbol = s;
};

string Player::getName() { return name; };
char Player::getSymbol() { return symbol; };

//4210191021 - Intan Putri K. W
