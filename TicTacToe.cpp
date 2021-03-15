#include<iostream>
#include<string>
#include"GameManager.h"

using namespace std;

int main() 
{
	GameManager gm;
	string filename;

	gm.StartGame();

	while (!gm.IsMatching())
	{
		gm.Input();
	}
	
	//cout << "Input File Name : "; cin >> filename;
	//gm.SaveGame(filename + ".txt");
	//cout << "Input File Name : "; cin >> filename;
	//gm.LoadGame(filename + ".txt");

	return 0;
}