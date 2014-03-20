#include <cstdlib>
#include <sstream>
#include <iostream>

int diceRoll();

int main(int argc, char* argv[]) {
	using namespace std;
	bool continueGame = true;
	int dice1 = 0;
	int dice2 = 0;
	int diceTotal = 0;
	int userNumber = 13;

	// Initiliaze seed
	srand(time(NULL));

	// Rules of the game
	cout << "+-----------------+\n"
		 << "| Dice Roll game! |\n"
		 << "+-----------------+\n"
		 << "Rules: \n"
		 << "-------------------\n"
		 << "You must roll two dice.\n"
		 << "The total value is \"your number.\"\n"
		 << "If your first role totals 7 or 11, you win!\n"
		 << "BUT, if your first role totals 2, you lose. :(\n"
		 << "Otherwise, roll until you match \"your number\" and win,\n"
		 << "or hit a total of 7 or 11, and lose.\n"
		 << "Roll? [press ENTER]" << endl;

	cin.ignore();
	
	// Make initial dice roll
	dice1 = diceRoll();
	dice2 = diceRoll();
	diceTotal = dice1 + dice2;
	userNumber = diceTotal;

	cout << "You rolled a " << to_string(dice1)
		 << " and " << to_string(dice2) << ".\n" << endl;
	// Handle 2 digit and 1 digit numbers:
	if (userNumber > 9) {
		cout << "+--------------------+\n"
			 << "| Your number is: " << to_string(userNumber) << " |\n"
			 << "+--------------------+" << endl;
	} else {
		cout << "+-------------------+\n"
			 << "| Your number is: " << to_string(userNumber) << " |\n"
			 << "+-------------------+" << endl;
	}
		 
	// Initial roll results:
	if (diceTotal == 2) {
		cout << "Sorry, your first roll was a 2. You lost." << endl;
		continueGame = false;
	} else if (diceTotal == 7 || diceTotal == 11) {
		cout << "Yay! Your first roll was a " << to_string(diceTotal) << "! You Win!!" << endl;
		continueGame = false;
	}
	
	// Keep rolling until Win or Lose
	while (continueGame) {
		cout << "Roll again? [press ENTER]" << endl;
		cin.ignore();

		dice1 = diceRoll();
		dice2 = diceRoll();
		diceTotal = dice1 + dice2;

		cout << "You rolled a " << to_string(dice1)
			 << " and " << to_string(dice2) << ".\n"
			 << "For a total of " << to_string(diceTotal) << "." << endl;
		if (diceTotal == userNumber) {
			cout << "You rolled your number! You win!!" << endl;
			continueGame = false;
		} else if (diceTotal == 7 || diceTotal == 11) {
			cout << "Oh no, you rolled the forbidden number " << to_string(diceTotal)
				 << ". You lose. :(" << endl;
			continueGame = false;
		}
	}

	return EXIT_SUCCESS;
}

int diceRoll() {
	int roll = rand() % 6 + 1;
	return roll;
}