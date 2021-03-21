#pragma once
#include"SaveAndLoad.h"
#include<string>
#include<fstream>
#include"Player.h"
#include"Board.h"

using namespace std;

void SaveAndLoad::SaveGame(string _filename, Player p1, Player p2, Board b) {
	//method untuk simpan game saat di tengah permainan. 
	//simpan menggunakan file.txt
	//create file 

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open(_filename, ios::out);
		cout << "file create is success" << endl;
		//file.write((char*)&p1.getName(), sizeof(p1.getName()));
		//file.write((char*)&p1.getSymbol(), sizeof(p1.getSymbol()));
		//file.write((char*)&p2.getName(), sizeof(p2.getName()));
		//file.write((char*)&p2.getSymbol(), sizeof(p2.getSymbol()));
		//file.write((char*)&p2, sizeof(p2));
		//file.write((char*)&b, sizeof(b));
	}
	catch (const std::exception & e)
	{
		cout << e.what() << endl;
	}
	file.close();

	/*if (!file)
	{
		cout << "create file is error" << endl;
	}

	cout << "file create is success" << endl;*/

}


void SaveAndLoad::LoadGame(string _filename, Player p1, Player p2, Board board) {
	string firstPlayerName, secondPlayerName;
	string firstPlayerSymbol, secondPlayerSymbol;

	//method untuk load game
	//set data-data dalam file ke variabel yang sesuai

	//file.open(_filename, ios::in);

	/*if (!file.is_open())
	{
		cout << "open file failed" << endl;
	}
	else
	{
		file.read((char*)&firstPlayerName, sizeof(firstPlayerName));
		file.read((char*)&firstPlayerSymbol, sizeof(firstPlayerSymbol));
		file.read((char*)&secondPlayerName, sizeof(secondPlayerName));
		file.read((char*)&secondPlayerSymbol, sizeof(secondPlayerSymbol));
		//p1.setName(firstPlayerName);
		//p1.setSymbol(firstPlayerSymbol);
		//p2.setName(secondPlayerName);
		//p2.setSymbol(secondPlayerSymbol);
		//file.read((char*)&board, sizeof(board));
		cout << "read data is success" << endl;
	}*/

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open(_filename, ios::in);
		getline(file, firstPlayerName);
		p1.setName(firstPlayerName);
		cout << "p1 name : " << p1.getName() << endl;
		//cout << "First player name : " << firstPlayerName << endl;
		//file.read((char*)&firstPlayerName, sizeof(firstPlayerName));
		//file.read((char*)&firstPlayerSymbol, sizeof(firstPlayerSymbol));
		//file.read((char*)&secondPlayerName, sizeof(secondPlayerName));
		//file.read((char*)&secondPlayerSymbol, sizeof(secondPlayerSymbol));
		//file.write((char*)&b, sizeof(b));
		cout << "file open is success" << endl;

	}
	catch (const std::exception & e)
	{
		cout << e.what() << endl;
	}
}

//4210191015 - Vivian Azalia A
