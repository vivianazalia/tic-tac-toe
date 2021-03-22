#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include"GameManager.h"
#include"History.h"

using namespace std;

//Global variable
GameManager gm;

//Prototype Function
void ShowGame();
void SetColor(unsigned short);

int main() 
{
	
	History history;

	int menu;

	bool gameOn = true;

	while (gameOn != false) {
		SetColor(07);
		cout << endl;
		cout << "=========================================================" << endl;
		cout << "                      TIC TAC TOE                        " << endl;
		cout << "=========================================================" << endl;
		cout << "                        made by : " << endl;
		cout << "             4210191015 - Vivian Azalia A" << endl;
		cout << "             4210191021 - Intan Putri K. W" << endl << endl;
		cout << "               Praktikum Pemrograman 4" << endl << endl;
		cout << " 1) Start the game.\n";
		cout << " 2) History.\n";
		cout << " 3) Exit.\n\n";
		cout << " Enter your choice and press return: ";

		cin >> menu;

		switch (menu)
		{
		case 1:
			SetColor(03);
			ShowGame();
			// rest of code here
			break;
		case 2:
			system("cls");
			SetColor(06);
			history.ShowHistory();
			// rest of code here
			break;
		case 3:
			SetColor(12);
			cout << "\n --- The game has ended !!! ---\n";
			gameOn = false;
			break;
		default:
			SetColor(12);
			cout << " Not a Valid Choice. \n";
			cout << " Choose again.\n";
			cin >> menu;
			break;
		}

	}

	system("pause");
	return 0;
}

void ShowGame() {
	string filename;

	gm.StartGame();

	while (!gm.IsMatching())
	{
		gm.Input();
	}

	cout << "Input File Name : "; cin >> filename;
	gm.SaveGame(filename + ".txt");
}

void SetColor(unsigned short color) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}
