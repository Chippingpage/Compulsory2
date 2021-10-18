#include "Declear.h"




int main() {

	Login(); // Username = player, Password = password

	return 0;
}

void Login() {


	

	do {
		std::cout << "Username : ";
		std::cin >> User;
		std::cout << "Password : ";
		std::cin >> PassW;
		tries++;
	
		if (tries == 3) {
			break;
		}


		if (password == PassW && username == User) { // Check if password and username is the same
			Bet();
			break;
		}
		else 
			std::cout << "Try Again" << std::endl;



	} while (tries < 3);
}

void Bet() {

	int RightAnswear = 1;

	std::cout << "How Much do you want to bet?  Minimum 10" << std::endl;
	std::cout << "You have " << PlayerBetAmount << std::endl;
	std::cout << "AI have " << AIBetAmount << std::endl;
	std::cin >> PlayerBet;
	while (RightAnswear == 1) {

		if (PlayerBet < 10 || PlayerBet > PlayerBetAmount || PlayerBet > AIBetAmount) { // if the player bets lower than 10 or lower than the amount the player or AI have you try again
			std::cout << "Try Again" << std::endl;
			std::cin >> PlayerBet;
		}
		if (PlayerBet >= 10 && PlayerBet <= PlayerBetAmount && PlayerBet <= AIBetAmount) { // if the player bets higher or 10 and lower or equal to the amount the player or AI have
			RightAnswear++;
			BlackJack();
		}
	}
}

void BlackJack() {


	srand(time(0)); 
	

	playernumber = (rand() % max) + 1;
	
	std::cout << std::endl;
	std::cout << "Player Turn" << std::endl;
	std::cout << playernumber << std::endl;


	do {
		int randomnum = (rand() % max) + 1;
	std::cout << std::endl;
	std::cout << "Draw Another Card?" << std::endl;
	std::cout << "Write 1 = Yes" << std::endl;
	std::cout << "Wirte 2 = No" << std::endl;
	std::cin >> Playerdraw;
	std::cout << std::endl;

	
		if (Playerdraw == 1) {
			playernumber;
			if (randomnum == 1) { // the player got a 1 and gets to choose if the player wants the value 1 or 11
				std::cout << "You Got an Ace" << std::endl;
				std::cout << "Choose 1 for 1 and 2 for 11" << std::endl;
				std::cin >> AceChoosePlayer;
				if (AceChoosePlayer == 2) { 
				
					playernumber = playernumber + 10;
		
				}
			}
			playernumber = playernumber + randomnum; // adds the randomnumber to the playernumber
			std::cout << playernumber << std::endl;
			
			if (playernumber > 21) {
				std::cout << "AI Wins the round" << std::endl;
				
				AIBetAmount = PlayerBet + AIBetAmount; 
				PlayerBetAmount = PlayerBetAmount - PlayerBet;
				
				if (PlayerBetAmount == 0) {
					std::cout << "AI Wins the game";
					break;
				}
				Bet();
			 
				break;
			}

		}

		if (Playerdraw == 2) {
			AI();
		}
		

	} while (Playerdraw == 1);

	
}

void AI() {
	
	
	int AInumber = (rand() % max) + 1;
	

	srand(time(0));

	
	std::cout << "AI Turn" << std::endl;
	std::cout << AInumber << std::endl;
	while (AInumber < playernumber) {
		int randomnum = (rand() % max) + 1;

		if (randomnum == 1) { // if the randomnumber is 1 the AI chooses the value 1 or 11
			std::cout << "You Got an Ace" << std::endl;

			if (AInumber <= 10) { // the AI Chooses 11 if the AInumber is lower or equal to 10
				
				AInumber = AInumber + 10;
				
			}


		}
			AInumber = AInumber + randomnum;
			std::cout << AInumber << std::endl;
			
		
	
		if (AInumber > 21) {
			
			std::cout << "Player Wins the round" << std::endl;

			AIBetAmount =  AIBetAmount - PlayerBet;
			PlayerBetAmount = PlayerBetAmount + PlayerBet;
			
			if (AIBetAmount == 0) {
				std::cout << "Player Wins the game";
				break;
			}
			Bet();

			break;
			
		}

		else if (AInumber == playernumber) {
			std::cout << "Tie" << std::endl;
			BlackJack();
		}
		else if (AInumber > playernumber) {
			std::cout << "AI Wins wins the round" << std::endl;

			
			AIBetAmount = PlayerBet + AIBetAmount;
			PlayerBetAmount = PlayerBetAmount - PlayerBet;
			
			if (PlayerBetAmount == 0) {
				std::cout << "AI Wins the game";
				break;
			}
			Bet();

			break;
		}
	}
	

}

