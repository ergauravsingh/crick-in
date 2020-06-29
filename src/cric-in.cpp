//============================================================================
// Name        : cric-in.cpp
// Author      : Gaurav Singh
// Version     :
// Copyright   : Cric-In : Made By Gaurav Singh
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "game.h"
using namespace std;


int main() {

	Game game;
	game.welcome();
	cout << "\n \t\t    ARE YOU READY ??? Hit ENTER !!" << endl;
	getchar();

	game.showAllPlayers();

	cout << "\n\t Select your Players. Press ENTER Key..." << endl;
	getchar();
	game.selectPlayers();
	game.showTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\n\t   !! Toss the coin by pressing ENTER key !! " << endl;
	getchar();
	game.toss();



	game.startFirstInnings();
	game.startSecondInnings();
	game.decideWinner();
	game.matchSummary();
	getchar();
	cout << "\n";
	return 0;
}
