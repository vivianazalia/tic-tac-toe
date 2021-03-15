#pragma once
#include<stdlib.h>
#include<time.h>
#include"Board.h"
#include"SaveAndLoad.h"
#include"Player.h"

class GameManager
{
private:
	bool isMatching = false;
	bool isDrawn = false;
	bool isSet = false;
	int n = 9;
	string name1, name2;
	Player player1;
	Player player2;
	Player playerTurn;
	Board board;
	SaveAndLoad file;
public:
	void StartGame() {
		int firstTurn;
		srand(time(0));

		board.DisplayBoard();

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

		CheckMatch();
	}

	void CheckTileAvailable(int a) {
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

	void CheckMatch() {
		if (board.GetTiles(1) == board.GetTiles(2) && board.GetTiles(1) == board.GetTiles(3) && board.GetTiles(2) == board.GetTiles(3) ||
			board.GetTiles(4) == board.GetTiles(5) && board.GetTiles(4) == board.GetTiles(6) && board.GetTiles(5) == board.GetTiles(6) ||
			board.GetTiles(7) == board.GetTiles(8) && board.GetTiles(7) == board.GetTiles(9) && board.GetTiles(8) == board.GetTiles(9))
		{
			isMatching = true;
		}
		else if (board.GetTiles(1) == board.GetTiles(4) && board.GetTiles(1) == board.GetTiles(7) && board.GetTiles(4) == board.GetTiles(7) ||
			board.GetTiles(2) == board.GetTiles(5) && board.GetTiles(2) == board.GetTiles(8) && board.GetTiles(5) == board.GetTiles(8) ||
			board.GetTiles(3) == board.GetTiles(6) && board.GetTiles(3) == board.GetTiles(9) && board.GetTiles(6) == board.GetTiles(9))
		{
			isMatching = true;
		}
		else if (board.GetTiles(1) == board.GetTiles(5) && board.GetTiles(1) == board.GetTiles(9) && board.GetTiles(5) == board.GetTiles(9) ||
			board.GetTiles(3) == board.GetTiles(5) && board.GetTiles(3) == board.GetTiles(7) && board.GetTiles(5) == board.GetTiles(7))
		{
			isMatching = true;
		}
		else
		{
			isMatching = false;
		}

		if (n <= 1 && isMatching == false)
		{
			isDrawn = true;
		}
	}

	bool IsMatching() {
		return isMatching;
	}

	void SetData() {
		cout << "==> player 1's name: "; cin >> name1;
		cout << "==> player 2's name: "; cin >> name2;

		player1.setName(name1);
		player2.setName(name2);
		player1.setSymbol('X');
		player2.setSymbol('O');
	}

	void Input() {
		int inputNumber;

		CheckMatch();

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

		if (isDrawn == true)
		{
			cout << "\n============== Game is Drawn! ==============" << endl;
			isMatching = true;
		}
	}

	void SwitchTurn(Player p) {
		playerTurn = p;
	}

	void WinCondition(Player p) {
		//set player yang menang
		cout << "\n============== " << playerTurn.getName() << " (" << playerTurn.getSymbol() << ") is Win! ==============" << endl;
	}

	void SaveGame(string _filename) {
		file.SaveGame(_filename, player1, player2, board);
	}

	void LoadGame(string _filename) {
		file.LoadGame(_filename, player1, player2, board);
		cout << "player 1 name : " << player1.getName() << endl;
		cout << "player 1 symbol : " << player1.getSymbol() << endl;
		cout << "player 2 name : " << player2.getName() << endl;
		cout << "player 2 symbol : " << player2.getSymbol() << endl;
		//method untuk load data game dari file 
		//cari file dengan nama sesuai yang diminta 
		//buka file 
		//pindahkan data dalam file ke variabel yang diminta 
		
	}
};

