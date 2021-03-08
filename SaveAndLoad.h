#pragma once
#include<string>
#include<fstream>
#include"Player.h"

using namespace std;

class SaveAndLoad
{
private:
	string fileName;
	ofstream file;
public:
	SaveAndLoad(string _fileName) {
		fileName = _fileName;
		//file.open(nama, mode)
		//file.write()
	}

	void SaveGame(string path) {
		//method untuk simpan game saat di tengah permainan. 
		//simpan menggunakan file.txt
	}

	void virtual LoadGame(string filename, Player p1, Player p2, Board board) {
		//method untuk load game
		//set data-data dalam file ke variabel yang sesuai
	}
};

//4210191015 - Vivian Azalia A
