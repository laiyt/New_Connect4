#include <iostream>		// for standard I/O
#include <fstream>		// for file I/O
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <iomanip>		// for calling setw()
#include "menu.h"
#include "board.h"
#include "player.h"

using namespace std;

string ** createBoard(int &r, int &c, int &option) {
	//Initialization of new board
	string input;
	srand(time(0));
	if ((option >=1) && (option <=4)) {
		r=(rand() % 25) + 6;
		c=(rand() % 25) + 6;
	}
	
	if ((option >=5) && (option <=8)) {
		while (true) {
			cout << "r? (4 - 30)" << endl;
			cin >> r;
			if ((cin) && (r > 3) &&(r < 31)) break;
			else cout << "Incorrect input" << endl << endl;
		}
		while (true) {
			cout << "c? (4 - 30)" << endl;
			cin >> c;
			if ((cin) && (c > 3) && (c < 31)) break;
			else cout << "Incorrect input" << endl << endl;
		}
	}
	
	string**arrays = new string*[r];		//Dynamic array (pointer to pointer)
	for (int i=0; i<r; i++) {
		arrays[i] = new string[c];
		for (int j=0; j<c; j++) {
			arrays[i][j] = "*";
		}
	}
	return arrays;
}

void printBoard(string ** board, int &playernow, string * player, int &r, int &c, bool &won) {
	//Printing out current board
    int spaces = 1;
    if (r>9 || c>9) spaces = 2; //Using big board
    string x = "";
    for (int i=r-1; i>-1; i--) {
        cout << setw(spaces) << i;
        string ss = " ";
        if (spaces==2) ss = "  ";
        for (int j=0; j<c; j++) {
			if (won) {		//For simplified board displaying winner's movements
				if (board[i][j]==player[playernow]) {
					cout << ss << "♦";
				}
				else {
					cout << ss << "░";
				}
			} else {
				cout << ss << board[i][j];
			}
		}
        cout << " " << endl;
	}
    cout << " ";
	if (spaces==1) cout << " "; else cout << "  ";
    for (int j=0; j<c; j++) {
        cout << setw(spaces) << j;
        if (j==9) cout << "  "; else cout << " ";
    }
	cout << endl;
	return;
}

bool makeMove(string ** board, int &playernow, string * player, int &r, int &c, int col) {
	//Writing movement to array
    for (int i=0; i<r-1; i++) {
        if ((board[i][col]!="*") && (board[i+1][col]=="*")) {
            board[i+1][col] = player[playernow];
            break;
		}
        else if (board[i][col]=="*") {
            board[i][col] = player[playernow];
            break;
		}
        if (i==r-2) {
            return true;
		}
	}
	return false;
}

bool checkMove(string ** board, int &r, int &c) {
	//Checking if winner exists
	
	//Vertical
    for (int i=0; i<c; i++) {
        for (int j=0; j<r-3; j++) {
            if (((board[j][i]==board[j+1][i]) && (board[j+1][i]==board[j+2][i]) && (board[j+2][i]==board[j+3][i])) && (board[j][i]!="*") && (board[j+1][i]!="*") && (board[j+2][i]!="*") && (board[j+3][i]!="*")) {
				return true;
			}
		}
	}

	//Horizontal
    for (int j=0; j<r; j++) {
        for (int i=0; i<c-3; i++) {
            if (((board[j][i]==board[j][i+1]) && (board[j][i+1]==board[j][i+2]) && (board[j][i+2]==board[j][i+3])) && (board[j][i]!="*") && (board[j][i+1]!="*") && (board[j][i+2]!="*") && (board[j][i+3]!="*")) {
				return true;
			}
		}
	}

	//Diagonal
    for (int i=0; i<c-3; i++) {
        for (int j=0; j<r-3; j++) {
            if (((board[j][i]==board[j+1][i+1]) && (board[j+1][i+1]==board[j+2][i+2]) && (board[j+2][i+2]==board[j+3][i+3])) && (board[j][i]!="*") && (board[j+1][i+1]!="*") && (board[j+2][i+2]!="*") && (board[j+3][i+3]!="*")) {
				return true;
			}
		}
	}

	//Diagonal
    for (int i=3; i<c; i++) {
        for (int j=0; j<r-3; j++) {
            if (((board[j][i]==board[j+1][i-1]) && (board[j+1][i-1]==board[j+2][i-3]) && (board[j+2][i-3]==board[j+3][i-3])) && (board[j][i]!="*") && (board[j+1][i-1]!="*") && (board[j+2][i-2]!="*") && (board[j+3][i-3]!="*")) {
				return true;
			}
		}
	}
	return false;
}