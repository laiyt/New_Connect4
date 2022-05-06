//player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>		// for standard I/O
#include <fstream>		// for file I/O
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <iomanip>		// for calling setw()
using namespace std;

string * createPlayer(int &option, int &playercount, string * playeralias);
void switchPlayer(int &playercount, int &playernow, string * playeralias);

#endif