#pragma once
#include<string>
#include<fstream>
#include"Player.h"
#include"Board.h"

using namespace std;

class SaveAndLoad
{
private:
	string fileName;
public:
	void SaveGame(string _filename, Player p1, Player p2, Board b);

	void LoadGame(string _filename, Player p1, Player p2, Board b);
};

//4210191015 - Vivian Azalia A
