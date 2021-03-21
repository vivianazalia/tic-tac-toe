#pragma once
#include"Board.h"
#include"SaveAndLoad.h"
#include"Player.h"

class GameManager
{
private:
	bool isMatching = false;
	bool isDraw = false;
	bool isSet = false;
	int n = 9;
	string name1, name2;
	Player player1;
	Player player2;
	Player playerTurn;
	Board board;
	SaveAndLoad file;
public:
	void StartGame();

	void CheckTileAvailable(int a);

	bool IsMatching();

	void IsDraw();

	void SetData();

	void Input();

	void SwitchTurn(Player p);

	void SetColor(unsigned short color);

	void WinCondition(Player p);

	void SaveGame(string _filename);

	void LoadGame(string _filename); 
};

//4210191015 - Vivian Azalia A
//4210191021 - Intan Putri Kusuma W

