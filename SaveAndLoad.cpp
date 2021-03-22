#pragma once
#include"SaveAndLoad.h"
#include<string>
#include<fstream>
#include"Player.h"
#include"Board.h"

using namespace std;

void SaveAndLoad::SaveGame(string _filename, Player p1, Player p2, Board b) {
	ofstream file;

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open(_filename, ios::out);
		cout << "File created successfully." << endl;
		file.write((char*)&p1, sizeof(p1));
		file.write((char*)&p2, sizeof(p2));
		file.write((char*)&b, sizeof(b));
		cout << "Data has been saved." << endl;
	}
	catch (const std::exception & e)
	{
		cout << e.what() << endl;
	}
	file.close();
}

void SaveAndLoad::LoadGame(string _filename, Player p1, Player p2, Board b) {
	ifstream file;

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		file.open(_filename, ios::in);
		cout << "File opened successfully." << endl;
		file.read((char*)&p1, sizeof(p1));
		file.read((char*)&p2, sizeof(p2));
		file.read((char*)&b, sizeof(b));
	}
	catch (const std::exception & e)
	{
		cout << e.what() << endl;
	}
}

//4210191015 - Vivian Azalia A
