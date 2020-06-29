#include <vector>
#include "player.h"				// <string>

class Team{

	public:
		Team();
		std::string name;
		int totalRunsScored, wicketsLost, totalBallsBowled;
		std::vector<Player>players;

};
