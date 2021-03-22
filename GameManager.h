#pragma once
#include"Board.h"
#include"SaveAndLoad.h"
#include"Player.h"

class GameManager
{
private:
	bool isMatching;
	bool isDraw;
	bool isSet;
	bool isQuit;
	int n;
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

	bool IsQuit(); 

	void GameMode();

	void NewGame();

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

