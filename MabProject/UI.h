#ifndef UIFile
#define UIFile
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

void ChapeMshin() {
	string car[6];
	car[0] = "          ___________\n";
	car[1] = "  -  ----// --|||-- \\\\ \n";
	car[2] = " ---- __//____|||____\\____  \n";
	car[3] = "      | _|      |    --_  ||\n";
	car[4] = "  ----|/ \\______|______/ \\_|| \n";
	car[5] = " ______\\_/_____________\\_/_______\n";

	for (int i = 0; i < 47; i++) {
		system("cls");

		for (int k = 0; k < 6; k++) {
			for (int j = 0; j < i; j++) {
				cout << ' ';
			}
			cout << car[k];
		}

		Sleep(10);
	}
	system("cls");


}

#endif
