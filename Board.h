#pragma once

class Board
{
private : 
	const static int INDEX = 3;
	char grid[INDEX][INDEX];
	int row, column;
	bool isMatching = false;
public:
	void DisplayBoard();

	char GetTiles(int);

	void SetTile(int, char);

	bool CheckMatch();

	void ResetBoard();
};


//4210191015 - Vivian Azalia A
