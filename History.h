#pragma once
#include"Player.h"
#include<string>
#include<fstream>
#include<iostream>

using namespace std; 

class History {
public:
	void ShowHistory() {
		//stream untuk membaca file
		ifstream myfile;
		char sv_text;

		//membuka file yang telah ada
		myfile.open("HistoryPlayer.txt");

		cout << endl;
		cout << endl;
		cout << "_____________________________________________________________\n\n";
		cout << "\t\t  *** History Player ***" << endl;

		//fail() -> untuk memeriksa suatu pada kesalahan operasi file
		if (!myfile.fail())
		{
			//ulang selama program belum mencapai akhir konten dari file
			while (!myfile.eof())
			{
				myfile.get(sv_text);
				cout << sv_text;

			}
			myfile.close(); //menutup file
			cout << "_____________________________________________________________\n\n";
		}

		else {
			cout << "File tidak ditemukan" << endl;
		}
	}
};

//4210191021 - Intan Putri K. W
