#include<iostream>
#include<string>
#include"GameManager.h"

using namespace std;

int main() 
{
	GameManager gm;

	gm.StartGame();

	/*while (!gm.IsMatching())
	{
		gm.Input();
	}*/

	return 0;
}