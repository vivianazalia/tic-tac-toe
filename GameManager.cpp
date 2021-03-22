#pragma once
#include"GameManager.h"
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include"Board.h"
#include"SaveAndLoad.h"
#include"Player.h"

void GameManager::StartGame() {
	srand(time(0));

	n = 9;
	isMatching = false;
	isDraw = false;
	isSet = false;
	isQuit = false;
	
	board.ResetBoard();

	GameMode();

	board.DisplayBoard();

	isMatching = board.CheckMatch();
}

void GameManager::CheckTileAvailable(int a) {
	if (board.GetTiles(a) != 'O' && board.GetTiles(a) != 'X')
	{
		board.SetTile(a, playerTurn.getSymbol());
		isSet = true;
		n--;
	}
	else
	{
		isSet = false;
	}
}

bool GameManager::IsMatching() {
	return isMatching;
}

void GameManager::IsDraw() {
	if (n <= 1 && isMatching == false)
	{
		isDraw = true;
	}
}

bool GameManager::IsQuit() {
	return isQuit;
}

void GameManager::GameMode() {
	int input; 
	string filename;

	cout << "==== GAME MODE ====" << endl;
	cout << "1. New Game" << endl;
	cout << "2. Load Game" << endl;
	input:
	cout << "Enter number : "; cin >> input;

	switch (input)
	{
	case 1:
		NewGame();
		break;
	case 2:
		cout << "Enter filename : "; cin >> filename;
		LoadGame(filename + ".txt");
		break;
	default:
		cout << "Invalid input! Please try again." << endl;
		goto input;
		break;
	}
}

void GameManager::NewGame() {
	int firstTurn;

	//set input data player
	SetData();

	firstTurn = rand() % 2;

	if (firstTurn == 0)
	{
		SwitchTurn(player1);
	}
	else
	{
		SwitchTurn(player2);
	}
}

void GameManager::SetData() {
	cout << "==> player 1's name: "; cin >> name1;
	cout << "==> player 2's name: "; cin >> name2;

	player1.setName(name1);
	player2.setName(name2);
	player1.setSymbol('X');
	player2.setSymbol('O');
}

void GameManager::Input() {
	int inputNumber;
	char inputQuit;
	string filename;

	isMatching = board.CheckMatch();
	IsDraw();

	if (isMatching == false)
	{
		cout << "\n============== " << playerTurn.getName() << " (" << playerTurn.getSymbol() << ") Turn ==============" << endl;

	input:
		//input angka 
		cout << "==> Input a number : "; cin >> inputNumber;

		if (inputNumber > 9)
		{
			cout << "Please input number between 1 - 9!" << endl;
			goto input;
		}
		else
		{
			//cek tile kosong atau tidak
			CheckTileAvailable(inputNumber);
		}

	quitGame:
		cout << "\n--> Want to quit game? (y/n) : "; cin >> inputQuit;
		if (inputQuit == 'Y' || inputQuit == 'y')
		{
			cout << "Enter filename for saving game : "; cin >> filename;
			SaveGame(filename + ".txt");

			isQuit = true;
		}
		else if (inputQuit == 'N' || inputQuit == 'n')
		{
			//next step
		}
		else
		{
			cout << "Input is invalid! Please try again." << endl;
			goto quitGame;
		}

		//cek giliran player mana
		if (playerTurn.getSymbol() == player1.getSymbol() && isSet == true)
		{
			SwitchTurn(player2);
			board.DisplayBoard();
		}
		else if (playerTurn.getSymbol() == player2.getSymbol() && isSet == true)
		{
			SwitchTurn(player1);
			board.DisplayBoard();
		}
		else
		{
			cout << "==> Choose other number!" << endl;
			SwitchTurn(playerTurn);
		}
	}
	else
	{
		if (playerTurn.getSymbol() == player1.getSymbol())
		{
			SwitchTurn(player2);
		}
		else
		{
			SwitchTurn(player1);
		}
		WinCondition(playerTurn);
	}

	if (isDraw == true)
	{
		cout << "\n============== Game is Drawn! ==============" << endl;
		isMatching = true;
	}

	if (isQuit)
	{
		cout << "\n============== Game has been saved! ==============" << endl;
	}
}

void GameManager::SwitchTurn(Player p) {
	playerTurn = p;
}

void GameManager::SetColor(unsigned short color) {

	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

void GameManager::WinCondition(Player p) {
	SetColor(07);
	//stream untuk menulis file
	ofstream myfile;

	//membuka file,
	//jika file tidak ditemukan maka file akan otomatis dibuat
	myfile.open("HistoryPlayer.txt", ios::app);

	cout << endl;
	cout << "\n     ============== " << playerTurn.getName() << " (" << playerTurn.getSymbol() << ") is Win! ==============\n" << endl;

	SetColor(12);
	cout << "===> Data telah tersimpan. Tekan (2) untuk melihat history" << endl;
	cout << "------------------------------------------------------" << endl;

	//fail() -> untuk memeriksa suatu kesalahan pada operasi file
	if (!myfile.fail())
	{
		//menulis ke dalam file
		//set player yang menang
		myfile << "\n \t============== " << playerTurn.getName() << " (" << playerTurn.getSymbol() << ") is Win! ==============" << endl;
		myfile.close(); //menutup file
		cout << endl;
	}

	else {
		cout << "File tidak ditemukan" << endl;
	}
}

void GameManager::SaveGame(string _filename) {
	file.SaveGame(_filename, player1, player2, board);
}

void GameManager::LoadGame(string _filename) {
	file.LoadGame(_filename, player1, player2, board);
}


//4210191015 - Vivian Azalia A
//4210191021 - Intan Putri Kusuma W
