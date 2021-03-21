#pragma once

class Board
{
private : 
	char grid[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
	int row, column;
	bool isMatching = false;
public:
	void DisplayBoard();

	char GetTiles(int);

	void SetTile(int, char);

	bool CheckMatch();
};


//4210191015 - Vivian Azalia A
