#include "game.h"
using namespace std;
#include "windows.h"

															// Constructor
Game::Game(){

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;

	players[0]="M.S. Dhoni     ";
	players[1]="Virat Kohli    ";
	players[2]="Dinesh Karthik ";
	players[3]="Ravindra Jadeja";
	players[4]="Rohit Sharma   ";
	players[5]="Shikhar Dhawan ";
	players[6]="Hardik Pandya  ";
	players[7]="Y. Chahal      ";
	players[8]="B. Kumar       ";
	players[9]="Jaspreet Bumrah";
	players[10]="Umesh Yadav   ";

}


													// Show welcome message on screen
void Game::welcome() {

    cout << "\t\t|-------------------------------------|" << endl;
    cout << "\t\t|====== cric-in BY Gaurav Singh ======|" << endl;
    cout << "\t\t|-------------------------------------|" << endl;
    cout << "\t\t|                                     |" << endl;
    cout << "\t\t|   Welcome to cric-in Cricket Game   |" << endl;
    cout << "\t\t|-------------------------------------|" << endl;
    Sleep(100);
    cout << endl;
    cout << "\t|-------------------------------------------------|" << endl;
    cout << "\t|+==============   INSTRUCTIONS   ===============+|" << endl;
    cout << "\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"  << endl;
    cout << "\t|                                                 |" << endl;
    cout << "\t| 1. Create two teams: TeamA and TeamB            |" << endl;
    cout << "\t|    (with 4 players each from given 11 players). |" << endl;
    cout << "\t| 2. Do the toss and decide to bat or bowl.       |" << endl;
    cout << "\t| 3. Each innings will be of 6 balls.             |" << endl;
    cout << "\t|-------------------------------------------------|" << endl;

}



													// Display complete list of players
void Game::showAllPlayers(){

	cout<<std::endl;
	cout << "\t\t|-------------------------------------|" << endl;
	cout << "\t\t|=========  Pool of Players  =========|" << endl;
	cout << "\t\t|   Choose your 4 favourite players   |" << endl;
	cout << "\t\t|-------------------------------------|" << endl;

	for(int i = 0; i < totalPlayers; i++){
		cout << "\t \t      " << "[" << i << "]  " << players[i] << endl;
		Sleep(500);
	}

}



													// Function to accept only integer input
int Game::takeIntegerInput(){

	int n;
	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input! Please try again with valid input: ";
	}

	return n;
}



													// Function to validate selected player
bool Game::validateSelectedPlayer(int index){

	int n;
	vector<Player>players;

	players = teamA.players;
	n=players.size();
	for(int i=0; i<n; i++){
		if(players[i].id==index){
			return false;
		}
	}
	players = teamB.players;
		n=players.size();
		for(int i=0; i<n; i++){
			if(players[i].id==index){
				return false;
			}
		}

	return true;
}



													// Function for player selection
void Game::selectPlayers(){

	cout<<endl;
	cout << "\t\t|--------------------------------------|" << endl;
	cout << "\t\t|== Select Team-A and Team-B players ==|" << endl;
	cout << "\t\t|--------------------------------------|" << endl;



	for(int i=0; i < playersPerTeam; i++){																	// Select players for Team-A

		teamAselection:																						// for goto statement
			cout << endl << "Choose Player " << i+1 << " for Team A : ";
			int playerIndexTeamA = takeIntegerInput();

			if (playerIndexTeamA < 0 || playerIndexTeamA > 10){

				cout << endl << "--> Please select from the given players <-- " << endl;
				goto teamAselection;

			} else if (!validateSelectedPlayer(playerIndexTeamA)){

				cout<<"--> Oops!! Player has been already taken. Please choose another player!! <--"<<endl;
				goto teamAselection;

			} else{

				Player teamAPlayer;
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);
				Sleep(500);
				cout << players[playerIndexTeamA] << "\t joins Team-A \n";
			}
		}

	for(int i=0; i<playersPerTeam; i++){																	// Select players for Team-B

		teamBselection:																						// for goto statement
			cout << endl << "Choose player " << i+1 << " for Team B : ";
			int playerIndexTeamB = takeIntegerInput();

			if (playerIndexTeamB < 0 || playerIndexTeamB > 10){

				cout << endl << "-->> Please select from the given players <<-- " << endl;
				goto teamBselection;

			} else if (!validateSelectedPlayer(playerIndexTeamB)){

				cout << "-->> Oops!! Player has been already taken. Please choose another player!! <<--" << endl;
				goto teamBselection;

			} else{

				Player teamBPlayer;
				teamBPlayer.id = playerIndexTeamB;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
				Sleep(500);
				cout << players[playerIndexTeamB] << "\t joins Team-B \n";
			}
		}
}


														// Display team players
void Game::showTeamPlayers(){

		cout << endl << endl;
		cout << "|--------------------------------|\t|--------------------------------|" << endl;
		cout << "|===========  Team-A  ===========|\t|===========  Team-B  ===========|" << endl;
		cout << "|--------------------------------|\t|--------------------------------|" << endl;
		for(int i=0; i<playersPerTeam;i++){
			cout << "|\t" << "[" << i << "]" << teamA.players[i].name << "\t |"
				 << "\t"
				 << "|\t" << "[" << i << "]" << teamB.players[i].name << "\t |" <<endl;
		}
		cout << "|--------------------------------|\t|--------------------------------|" << endl;
}



													// Function for toss
void Game::toss(){

	cout<<endl;
	cout << "========================    Let's Toss   ===========================" << endl;

	cout << "\n\n Tossing a coin... \n " << endl;

	Sleep(4500);

	int randomValue;

	srand(time(NULL));
	randomValue = rand() % 2;
	switch(randomValue){
		case 0:
			cout<<"Team-A won the Toss \n"<<endl;
			tossChoice(teamA);
			break;

		case 1:
			cout<<"Team-B won the Toss \n"<<endl;
			tossChoice(teamB);
		    break;
	}

}


void Game::tossChoice(Team tossWinnerTeam){

	 cout << "Enter 1 to Bat and 2 to Bowl first" << endl
	 	  << "\t 1. Bat" << endl
	 	  << "\t 2. Bowl" << endl;
	 int tossInput = takeIntegerInput();

	 cin.ignore(numeric_limits < streamsize > ::max(), '\n');

	 switch (tossInput){
	 	 case 1:
	 		 cout << endl << tossWinnerTeam.name << " has won the toss and elected to bat first" << endl << endl;
	 		 	 if (tossWinnerTeam.name.compare("Team-A")==0){				// Team-A is toss winner and opted to bat first
	 		 		 battingTeam=&teamA;
	 		 		 bowlingTeam=&teamB;
	 		 	  } else{													// Team-B is toss winner and opted to bat first
	 		 		 battingTeam=&teamB;
	 		 		 bowlingTeam=&teamA;
	 		 	  }
	 	 	 break;
	 	 case 2:
	 		 cout << endl << tossWinnerTeam.name << " won the toss and elected to bowl first" << endl << endl;
	 	 	 	 if (tossWinnerTeam.name.compare("Team-A")==0){				// Team-A is toss winner and opted to bowl first
	 	 	 		 bowlingTeam=&teamA;
	 	 	 		 battingTeam=&teamB;
	 		 	  } else{													// Team-B is toss winner and opted to bowl first
	 		 		 bowlingTeam=&teamB;
	 		 		 battingTeam=&teamA;
	 		 	  }
	 	 	 break;

	 	 default:
	 		 cout << endl << "Invalid choice!!! Please enter again" << endl << endl;
	 			 tossChoice(tossWinnerTeam);
	 		 break;
	 }
}



void Game::startFirstInnings(){
	cout << endl << endl;
	cout << "\t\t|||First Innings Starts|||" << endl << endl;
	isFirstInnings = true;
	initializePlayers();
	playInnings();

}


void Game::startSecondInnings(){
	cout << endl << endl;
	temp = battingTeam;
	battingTeam = bowlingTeam;
	bowlingTeam = temp;
	cout << "\t\t|||Second Innings Starts|||" << endl << endl;
	isFirstInnings = false;
	initializePlayers();
	playInnings();

}



void Game::initializePlayers(){

	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting "<< endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;

}


void Game::playInnings(){

	for(int i =0; i<maxBalls; i++){
		cout << endl << "\n Press Enter to bowl... " << endl;
		getchar();

		cout<<"Bowling..."<< endl;
		Sleep(1000);
		bat();

		if(!validateInningsScore()){
			break;
		}

	}
}


void Game::bat(){

	srand(time(NULL));
	int runsScored = rand() % 7;

	// Batting team and batsman score
	batsman->runsScored += runsScored;
	battingTeam->totalRunsScored += runsScored;
	batsman->ballsPlayed += 1;

	// Bowling team and ball count
	bowler->ballsBowled += 1;
	bowlingTeam->totalBallsBowled += 1;
	bowler->runsGiven += runsScored;


	if(runsScored!=0){

		cout << endl << bowler->name << " to \t" << batsman->name << " " << runsScored << " runs!!" <<endl;
		showGameScorecard();

	} else{

		cout << endl << bowler->name << " to \t" << batsman->name << " !!!  OUT  !!!" <<endl;

		battingTeam->wicketsLost += 1;
		bowler->wicketsTaken += 1;

		showGameScorecard();

		int nextPlayerIndex = battingTeam->wicketsLost;
		batsman = &battingTeam->players[nextPlayerIndex];
	}

}



bool Game::validateInningsScore(){

	  if(isFirstInnings){											// 1st innings
		  if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){


			  cout << "\t\t ||| First Innings Ends ||| " << endl << endl;
			  Sleep(1000);
			  cout << battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "
				   << battingTeam->wicketsLost<< " (" << bowlingTeam->totalBallsBowled
				   << ") " << endl;
			  cout << bowlingTeam->name<<" needs " << battingTeam->totalRunsScored+1
				   << " runs to win the match " << endl << endl;

			  return false;
		  }
	  } else{														// 2nd innings

		  if(battingTeam->wicketsLost==playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls){

		  	  cout<<"\t\t ||| Second Innings Ends ||| "<<endl<<endl;
		  	  Sleep(1000);
		  	  cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "
		  		  <<battingTeam->wicketsLost<< " ("<<bowlingTeam->totalBallsBowled
		  		  <<") "<<endl;

		  	  return false;
		  }

	  }

	  return true;

}



void Game::showGameScorecard(){
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "
		<<battingTeam->wicketsLost<< " ("<<bowlingTeam->totalBallsBowled<<")   | "<<batsman->name
		<< "   " <<batsman->runsScored <<" ("<<batsman->ballsPlayed<<")\t"
		<<bowler->name<<"  "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "<<bowler->wicketsTaken << endl;
	cout<<"--------------------------------------------------------------"<<endl;

}


void Game::decideWinner() {
	cout << endl << endl << endl;
	cout << "----------------------------------------------------" << endl;

    if (teamA.totalRunsScored > teamB.totalRunsScored) {
    	cout << "|---------------------------------------------------------|" << endl;
    	Sleep(2000);
        cout << "\t\t Team A is the Winner" << endl;
    } else if (teamA.totalRunsScored < teamB.totalRunsScored) {
    	cout << "|---------------------------------------------------------|" << endl;
    	Sleep(2000);
        cout<< "\t\t Team B is the Winner" << endl;
    } else {
    	cout << "|---------------------------------------------------------|" << endl;
    	Sleep(2000);
        cout << "\t\t Match Draw" << endl;
    }

    cout << "----------------------------------------------------" << endl << endl;
    Sleep(2000);
    cout << "\t\t||  Match Ends  ||" << endl << endl;
}



void Game::matchSummary(){
		cout << endl;
		cout << "|---------------------------------------------------------|" << endl;
		cout << "|======================= Team-A ==========================|" << endl;
		cout << "|---------------------------------------------------------|" << endl;
		cout << "|Player \t\t | Batting\t\t | Bowling|" << endl;
		for(int i=0; i<playersPerTeam;i++){
			cout << "|" << teamA.players[i].name << "\t | "<<teamA.players[i].runsScored<<" ("<<teamA.players[i].ballsPlayed
				 <<")"<<"\t\t | "<<teamA.players[i].ballsBowled << "-"<<teamA.players[i].runsGiven<<"-"<<teamA.players[i].wicketsTaken << " |" << endl;

		}
		cout << "|---------------------------------------------------------|" << endl;

		cout<<endl;
		cout << "|---------------------------------------------------------|" << endl;
		cout << "|======================= Team-A ==========================|" << endl;
		cout << "|---------------------------------------------------------|" << endl;
		cout << "|Player \t\t | Batting\t\t | Bowling|" << endl;
		for(int i=0; i<playersPerTeam;i++){
			cout << "|" << teamB.players[i].name<<"\t | "<<teamB.players[i].runsScored<<" ("<<teamB.players[i].ballsPlayed
				 <<")"<<"\t\t | "<<teamB.players[i].ballsBowled<<"-"<<teamB.players[i].runsGiven<<"-"<<teamB.players[i].wicketsTaken << " |" <<endl;

		}
		cout << "|---------------------------------------------------------|" << endl;

}


