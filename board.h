//board.h
#ifndef BOARD_H
#define BOARD_H

#include <iostream>		// for standard I/O
#include <fstream>		// for file I/O
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <iomanip>		// for calling setw()
using namespace std;

string ** createBoard(int &r, int &c, int &option);
void printBoard(string ** board, int &playernow, string * player, int &r, int &c, bool &won);
bool makeMove(string ** board, int &playernow, string * player, int &r, int &c, int col);
bool checkMove(string ** board, int &r, int &c);

#endif