/*
 * The is ENGG1340 project from Group 24 (individual work).
 *
 * This is a modified version of Connect Four, serving as a connection game in which two, three or four players take turns
 * dropping discs into a (r x c) board, i.e., 4-30 rows x 4-30 columns adjustable.
 * The pieces fall straight down, occupying the lowest available space within the column.
 * The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs.
 *
 * In this game, a main menu is available for the choice of single players against computer (automated), or 2-4 real-person players.
 * Random board option generates a (r x c) board by random, while customized board allows any board size not smaller than 4
 * and not large than 30.
 *
 * Saving game state option is aailable for later restoring of game by entering "s" as command.
 * With the help of dynamic memory allocation, the game can be reset at any time whithout re-running by entering "e" as command.
 *
 * Version: 1.0
 * Last Modified: 6th May 2022
 *
 *
 *
 *
 * This program is free software: you can redistribute it and / or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but without any warranty; without even the implied warranty of
 * merchantability or fitness for a specific purpose.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
 
#include <iostream>		// for standard I/O
#include <fstream>		// for file I/O
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <iomanip>		// for calling setw()
#include "menu.h"
#include "board.h"
#include "player.h"

using namespace std;

int main () {
	bool initialized=false;
	cout << "───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───" << endl;
	cout << "───█▒▒░░░░░░░░░▒▒█───" << endl;
	cout << "────█░░█░░░░░█░░█────" << endl;
	cout << "─▄▄──█░░░▀█▀░░░█──▄▄─" << endl;
	cout << "█░░█─▀▄░░░░░░░▄▀─█░░█" << endl;
	cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
	cout << "█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█" << endl;
	cout << "█░░║║║╠─║─║─║║║║║╠─░░█" << endl;
	cout << "█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█" << endl;
	cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█" << endl << endl;
	while (true) {		//Initialization at start-up
		int r,c;
		int option = -1;
		bool won=false;
		int playercount = 0;
		int playernow = 0;
		int step=0;
		string *playeralias = new string[4];
		option = showMenu();
		string ** board = NULL;
		string *player = NULL;
		if (option == 9) {		//Saving
			player = new string[4];
			board = loadGame(player, playeralias, r, c, initialized, step, playernow, playercount);
		} else if (option == 0) {		//Exiting
			cout << endl << "Bye" << endl;
			exit(0);
		} else {		//Initialization of new board
			player = createPlayer(option, playercount, playeralias);
			board = createBoard(r,c, option);
		}
		if (board!=NULL) {		//Starting game
			printBoard(board, playernow, playeralias, r ,c, won);		//Printing board
			initialized=true;
		}
		while (initialized) {		//Running of game
			bool status=false;
			string command;
			int move;
			if (player[playernow] == "Computer") {		//Automated input by computer
				srand(time(0));
				move = (rand() % c);
				cout << "Computer choice: " << move << endl;
			} else {
				while (true) {		//Asking for next player input
					cout << "Player " << playeralias[playernow] << " (" << player[playernow] << ") (Enter col #; e = exit; s = save and exit): ";
					cin >> command;
					if (isdigit(command[0])) {
						if ((stoi(command) >= 0) && (stoi(command) < c)) break;
						else cout << "Incorrect input" << endl << endl;
					} else if (command=="e") {
						restartGame(board, player, playeralias, r, c, initialized);
						break;
					}
					else if (command == "s") {
						saveGame(board, player, playeralias, r, c, initialized, step, playernow, playercount);
						break;
					}
					else cout << "Incorrect input" << endl << endl;
				}
			}
			
			if (!((command == "e") || (command == "s"))) {
				if (player[playernow] != "Computer") move = stoi(command);
				status = makeMove(board, playernow, playeralias, r, c, move);		//Making Movement
				printBoard(board, playernow, playeralias, r, c, won);		//Printing board
				won = checkMove(board, r ,c);
				if (won==true) {
					if (player[playernow] != "Computer") {		//If winner is computer, do not show "Congratulations" logo
						cout << "╔═══╗─────────────╔╗───╔╗───╔╗" << endl;
						cout << "║╔═╗║────────────╔╝╚╗──║║──╔╝╚╗" << endl;
						cout << "║║─╚╬══╦═╗╔══╦═╦═╩╗╔╬╗╔╣║╔═╩╗╔╬╦══╦═╗╔══╗" << endl;
						cout << "║║─╔╣╔╗║╔╗╣╔╗║╔╣╔╗║║║║║║║║╔╗║║╠╣╔╗║╔╗╣══╣" << endl;
						cout << "║╚═╝║╚╝║║║║╚╝║║║╔╗║╚╣╚╝║╚╣╔╗║╚╣║╚╝║║║╠══║" << endl;
						cout << "╚═══╩══╩╝╚╩═╗╠╝╚╝╚╩═╩══╩═╩╝╚╩═╩╩══╩╝╚╩══╝" << endl;
						cout << "──────────╔═╝║" << endl;
						cout << "──────────╚══╝" << endl << endl;
					} else cout << endl;
					printBoard(board, playernow, playeralias, r, c, won);
					cout << "player " << playeralias[playernow] << " (" + player[playernow] + ") has won!" << endl; 
					endGame(board, player, playeralias, r, c, initialized);
				}

				if (status!=true) {		//Switching to next player
					switchPlayer(playercount, playernow, playeralias);
					step+=1;
					if (step==r*c) {		//Ending game without winner
						cout << "Draw!" << endl;
						endGame(board, player, playeralias, r, c, initialized);
					}
				} else {
					cout << "Invalid movement, please try again." << endl;
				}
			}
		}
	}
}