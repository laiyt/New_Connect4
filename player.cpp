#include <iostream>		// for standard I/O
#include <fstream>		// for file I/O
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <iomanip>		// for calling setw()
#include "menu.h"
#include "board.h"
#include "player.h"

using namespace std;

string * createPlayer(int &option, int &playercount, string * playeralias) {\
	//Asking for name of player(s) and create dynamic array
	string *array = new string[4];
	if ((option == 1) || (option == 5)) {		//Single against computer
		playercount=2;
		cout << "Enter Player 1 (X) Name: ";
		cin >> array[0];
		array[1] = "Computer";
		array[2] = "-";
		array[3] = "-";
		playeralias[0] = "X";
		playeralias[1] = "O";
		playeralias[2] = "-";
		playeralias[3] = "-";
		cout << "Player O is computer." << endl;
		return array;
	}
	
	if ((option == 2) || (option == 6)) {		//Two players
		playercount=2;
		cout << "Enter Player 1 (X) Name: ";
		cin >> array[0];
		cout << "Enter Player 2 (O) Name: ";
		cin >> array[1];
		array[2] = "-";
		array[3] = "-";
		playeralias[0] = "X";
		playeralias[1] = "O";
		playeralias[2] = "-";
		playeralias[3] = "-";
		return array;
	}
	
	if ((option == 3) || (option == 7)) {		//Three players
		playercount=3;
		cout << "Enter Player A Name: ";
		cin >> array[0];
		cout << "Enter Player B Name: ";
		cin >> array[1];
		cout << "Enter Player C Name: ";
		cin >> array[2];
		array[3] = "-";
		playeralias[0] = "A";
		playeralias[1] = "B";
		playeralias[2] = "C";
		playeralias[3] = "-";
		return array;
	}
	
	if ((option == 4) || (option == 8)) {		//Four players
		playercount=4;
		cout << "Enter Player A Name: ";
		cin >> array[0];
		cout << "Enter Player B Name: ";
		cin >> array[1];
		cout << "Enter Player C Name: ";
		cin >> array[2];
		cout << "Enter Player D Name: ";
		cin >> array[3];
		playeralias[0] = "A";
		playeralias[1] = "B";
		playeralias[2] = "C";
		playeralias[3] = "D";
		return array;
	}
	return array;
}

void switchPlayer(int &playercount, int &playernow, string * playeralias) {
	//Switching to next player
	playernow+=1;
	if (playernow==playercount) playernow=0;
}