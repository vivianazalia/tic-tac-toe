#pragma once
#include<iostream>
#include<stdlib.h>

using namespace std;

class Board
{
private : 
	char grid[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
	int row, column;
public:
	void DisplayBoard() {
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

	char GetTiles(int number) {
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

	void SetTile(int number, char c) {
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
};


//4210191015 - Vivian Azalia A
