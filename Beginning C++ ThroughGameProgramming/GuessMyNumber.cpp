// Author: RoBert McGregor (after Mike Dawson)
// User Code: C00302210
// Date: 11 / 11 / 23
// Estimate: 10 minutes
// Start Time: 23:33
// Purpose: 
//		Guess My Number V.01
//		The classic number guessing game
// End Time: 23:57
// Actual Time: 24 mins~
// Known Bugs:
//	No validation of user input - no checking for strings!

#include <iostream>
#include <cstdlib>
#include <ctime> // "It's C time!" XD ... =(

int main()
{
	srand(time(0)); // Seed random number generator. Bernadette uses 'srand(time(nullptr));'

	int theNumber = rand() % 100 + 1; // Random number between 1 and 100
	int tries = 0, guess; // The comma seems to create an uninitialised integer variable? Basically, int tries = 0; int guess;

	std::cout << "\tWelcome to Guess My Number\n\n"; // '\t' is escape code for  'tab'. '\n' is escape code for 'new line' (instead of std::endl;)

	do
	{
		std::cout << "Enter a guess: ";
		std::cin >> guess;
		++tries;

		if (guess > theNumber)
		{
			std::cout << "Too high!\n\n";
		}

		if (guess < theNumber)
		{
			std::cout << "Too low!\n\n";
		}
	} while (guess != theNumber);

	std::cout << "\nThat's it! You got it in " << tries << " guesses!\n";

	return 0;
} // Just testing I've setup Notepad++ as my text editor...