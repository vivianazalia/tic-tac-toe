#pragma once
#include"Board.h"
#include"SaveAndLoad.h"
#include"Player.h"

class GameManager
{
private:
	bool isMatching = false;
	Player player1;
	Player player2;
	Player playerTurn;
	Player winner;
	Board board;
public:
	void StartGame() {
		board.CreateBoard();
		CheckMatch();
	}

	void CheckTileAvailable(int a) {
		if (board.GetTiles(a) != 'O' || board.GetTiles(a) != 'X')
		{
			//isi dengan simbol player yang mendapat giliran input 
		}
		else
		{
			//player tidak bisa isi di sini
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
	}

	bool IsMatching() {
		return isMatching;
	}

	void Input() {
		CheckMatch();
		if (isMatching == false)
		{
			//input angka 
			//cek giliran player mana
			//cek tile kosong atau tidak
			//Set tile yang dipilih ke simbol player 
		}
		else
		{
			//Tampilkan kemenangan 
		}
	}

	/*void SwitchTurn(Player p) {
		playerTurn = p;
	}*/

	Player CheckTurn(Player p) {
		playerTurn = p;
		return playerTurn;
	}

	/*void WinCondition(Player p) {
		//set player yang menang
	}*/

	void SaveGame(string _fileName, string _path) {
		SaveAndLoad file(_fileName);
		file.SaveGame(_path);
	}

	void LoadGame(string filename) {
		//method untuk load data game dari file 
		//cari file dengan nama sesuai yang diminta 
		//buka file 
		//pindahkan data dalam file ke variabel yang diminta 
	}
};

