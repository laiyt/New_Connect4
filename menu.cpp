#include <iostream>		// for standard I/O
#include <fstream>		// for file I/O
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <iomanip>		// for calling setw()
#include "menu.h"
#include "board.h"
#include "player.h"

using namespace std;

int showMenu() {		//Dsiplaying menu
	int input;
	cout << "Select Game Mode:" << endl;
	cout << "1. Random board (? x ?) - Single player against computer" << endl;
	cout << "2. Random board (? x ?) - Two players" << endl;
	cout << "3. Random board (? x ?) - Three players" << endl;
	cout << "4. Random board (? x ?) - Four players" << endl;
	cout << "5. Customized board (r x c) - Single player against computer" << endl;
	cout << "6. Customized board (r x c) - Two players" << endl;
	cout << "7. Customized board (r x c) - Three players" << endl;
	cout << "8. Customized board (r x c) - Four players" << endl;
	cout << "9. Load Saved State" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter: ";
	while (true) {
		cin >> input;
		if ((cin) && (input == 0)) {
			cout << endl << "Bye" << endl;
			exit(0);
		}
		if ((cin) && (input >= 1) && (input <= 9)) return input;
		else cout << "Incorrect input" << endl << endl;
	}
}

string ** loadGame(string * player, string * playeralias, int &r, int &c, bool &initialized, int &step, int &playernow, int &playercount) {
	//Loading saved state from file
	ifstream inputfile("save.txt");
	if(!inputfile.is_open()) {		//Error handling
		cout << "Error: No game save found" << endl;
	} else {
		inputfile >> r >> c >> step >> playernow >> playercount;
		inputfile >> player[0] >> player[1] >> player[2] >> player[3];
		inputfile >> playeralias[0] >> playeralias[1] >> playeralias[2] >> playeralias[3];
		string**arrays = new string*[r];		//Dynamic array (pointer to pointer)
		for (int i=0; i<r; i++) {
			arrays[i] = new string[c];
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				inputfile >> arrays[i][j];
			}
		}
		inputfile.close();
		cout << "Game restored" << endl;
		cout << playernow <<endl;
		return arrays;
	}
	return NULL;
}

void restartGame(string ** board, string * player, string * playeralias, int &r, int &c, bool &initialized) {
	//Erasing current game state
	for (int i=0; i<r; i++) delete [] board[i];
	delete [] board;
	delete [] player;
	delete [] playeralias;
	initialized = false;
	cout << "Game reset" << endl << endl;
}

void saveGame(string ** board, string * player, string * playeralias, int &r, int &c, bool &initialized, int &step, int &playernow, int &playercount) {
	//Saving game state to file
	ofstream outputfile("save.txt", ios::trunc);
	outputfile << r << " " << c << " " << step << " " << playernow << " " << playercount << endl;
	outputfile << player[0] << " " << player[1] << " " << player[2] << " " << player[3] << endl;
	outputfile << playeralias[0] << " " << playeralias[1] << " " << playeralias[2] << " " << playeralias[3] << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			outputfile << board[i][j] << " ";
		}
		outputfile << endl;
	}
	outputfile.close();
			
	for (int i=0; i<r; i++) delete [] board[i];
	delete [] board;
	delete [] player;
	delete [] playeralias;
	initialized = false;
	cout << "Game saved" << endl << endl;
}

void endGame(string ** board, string * player, string * playeralias, int &r, int &c, bool &initialized) {
	//Asking whether to retry or to quit
	string retry;
	cout << "Restart game (y/n)? ";
	while (true) {
		cin >> retry;
		if (retry == "y") {
			for (int i=0; i<r; i++) delete [] board[i];
			delete [] board;
			delete [] player;
			delete [] playeralias;
			initialized = false;
			cout << "Game reset" << endl << endl;
			return;
		} else if (retry == "n") {
			for (int i=0; i<r; i++) delete [] board[i];
			delete [] board;
			delete [] player;
			delete [] playeralias;
			cout << "Bye" << endl;
			exit(0);
		} else {
			cout << "Invalid input. Restart game (y/n)? ";
		}
	}
}