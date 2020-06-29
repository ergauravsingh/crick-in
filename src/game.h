#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"		// "player.h", <string>, <vector>



class Game{

	public:
		Game();
		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam, *temp;
		Player *batsman, *bowler;
		int playersPerTeam, maxBalls, totalPlayers;
		std::string players[11];

		void welcome();
		void showAllPlayers();
		int takeIntegerInput();
		void selectPlayers();
		bool validateSelectedPlayer(int);
		void showTeamPlayers();
		void toss();
		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScorecard();
		void startSecondInnings();
		void decideWinner();
		void matchSummary();
};

