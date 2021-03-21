#pragma once
#include<string>
#include<fstream>
#include"Player.h"

using namespace std;

class SaveAndLoad
{
private:
	string fileName;
	fstream file;
public:
	void SaveGame(string _filename, Player p1, Player p2, Board b);

	void LoadGame(string _filename, Player p1, Player p2, Board board);
};

//4210191015 - Vivian Azalia A
