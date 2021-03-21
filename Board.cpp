#pragma once
#include"Board.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

void Board::DisplayBoard() {
	system("cls");
	cout << "=========================================================" << endl;
	cout << "                      TIC TAC TOE                        " << endl;
	cout << "=========================================================" << endl;
	cout << "\n\t\t___________________" << endl;
	cout << "\t\t|     |     |     | " << endl;
	cout << "\t\t|  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << "  |  " << endl;
	cout << "\t\t|     |     |     | " << endl;
	cout << "\t\t___________________" << endl;
	cout << "\t\t|     |     |     | " << endl;
	cout << "\t\t|  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << "  |  " << endl;
	cout << "\t\t|     |     |     | " << endl;
	cout << "\t\t___________________" << endl;
	cout << "\t\t|     |     |     | " << endl;
	cout << "\t\t|  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << "  |  " << endl;
	cout << "\t\t|     |     |     | " << endl;
	cout << "\t\t___________________" << endl;
}

char Board::GetTiles(int number) {
	row = number / 3;
	if (number % 3 == 0)
	{
		row = row - 1;
		column = 2;
	}
	else
	{
		column = number % 3 - 1;
	}

	return grid[row][column];
}

void Board::SetTile(int number, char c) {
	row = number / 3;
	if (number % 3 == 0)
	{
		row = row - 1;
		column = 2;
	}
	else
	{
		column = number % 3 - 1;
	}
	grid[row][column] = c;
}

bool Board::CheckMatch() {
	if (GetTiles(1) == GetTiles(2) && GetTiles(1) == GetTiles(3) && GetTiles(2) == GetTiles(3) ||
		GetTiles(4) == GetTiles(5) && GetTiles(4) == GetTiles(6) && GetTiles(5) == GetTiles(6) ||
		GetTiles(7) == GetTiles(8) && GetTiles(7) == GetTiles(9) && GetTiles(8) == GetTiles(9))
	{
		isMatching = true;
	}
	else if (GetTiles(1) == GetTiles(4) && GetTiles(1) == GetTiles(7) && GetTiles(4) == GetTiles(7) ||
		GetTiles(2) == GetTiles(5) && GetTiles(2) == GetTiles(8) && GetTiles(5) == GetTiles(8) ||
		GetTiles(3) == GetTiles(6) && GetTiles(3) == GetTiles(9) && GetTiles(6) == GetTiles(9))
	{
		isMatching = true;
	}
	else if (GetTiles(1) == GetTiles(5) && GetTiles(1) == GetTiles(9) && GetTiles(5) == GetTiles(9) ||
		GetTiles(3) == GetTiles(5) && GetTiles(3) == GetTiles(7) && GetTiles(5) == GetTiles(7))
	{
		isMatching = true;
	}
	else
	{
		isMatching = false;
	}
	return isMatching;
}


//4210191015 - Vivian Azalia A
