//menu.h
#ifndef MENU_H
#define MENU_H

#include <iostream>		// for standard I/O
#include <fstream>		// for file I/O
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <iomanip>		// for calling setw()
using namespace std;

int showMenu();
string ** loadGame(string * player, string * playeralias, int &r, int &c, bool &initialized, int &step, int &playernow, int &playercount);
void restartGame(string ** board, string * player, string * playeralias, int &r, int &c, bool &initialized);
void saveGame(string ** board, string * player, string * playeralias, int &r, int &c, bool &initialized, int &step, int &playernow, int &playercount);
void endGame(string ** board, string * player, string * playeralias, int &r, int &c, bool &initialized);

#endif