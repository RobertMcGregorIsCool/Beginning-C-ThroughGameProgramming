// Author: RoBert McGregor	ID: C00302210
// Purpose: Small, extendable text adventure
// making use of code which has been taught in
// class.
// Start Time: 18:18	Finish Time:
// Estimate: Who fuckin' knows.	Actual: Not me!
// Problems & Bugs:
// No validation for user input - a string will throw the system.

#include <iostream>	// Input output
#include <string>	// Strings!
#include <ctime>	// Computer clock, needed for random elements.
#include <cstdlib>	// Bunch of... stuff. Includes random functions.

int roomOutsideMainHall();
int roomMainHall();
int talktoBaldGuy();
int sayStuff(std::string dialogue);
void death();

bool holdingTablet = false; // VERY rudimentary 'inventory'.

int main()
{
	srand(time(0)); // Init random number generator.

	std::cout << "\tOnly enter numbers, please! This program doesn't understand strings (yet, but sooon...!).\n\n" << std::endl;
	roomOutsideMainHall(); // Run our first 'room'.
	return 0;
}

/// <summary>
/// This function is used for short descriptions and dialogue exchanges.
/// </summary>
/// <param name="dialogue">Pass in whatever you want printed to screen.</param>
/// <returns></returns>
int sayStuff(std::string dialogue)
{
	system("CLS");			// Clears the console - so we have a fully-black screen.
	std::cout << dialogue;	// Print the dialogue passed to this function.
	system("Pause");		// Allow player to read text, then press button to end function and return to room/person while loop.
	return 0;
}

/// <summary>
/// Good demo of the 'room/encounter-function' pattern. Every function using 
/// this pattern has a while loop that runs as long as the 'inRoom' bool 
/// returns true. The while loop first prints a description of the room, then
/// offers numbered options which the player can choose and input after the 
/// menu is printed.
/// 
/// A Switch statement evaluates the player input and then runs next 
/// 'room/encounter' function, or performs some other action (eg. 'Death').
/// 
/// Note - 'Death' is only triggered if the player knows and enters the code
/// (666) AND the global boolean 'holding tablet' is set to true.
/// </summary>
/// <returns></returns>
int roomOutsideMainHall()
{
	bool inRoom = true;

	while (inRoom)
	{
		system("CLS");
		int menuInput = 0;

		std::cout << "You're standing outside some sliding doors leading to a large hall.\nIt's bucketing down out here, and you're getting wet. What would you like to do?\n" << std::endl;
		std::cout << "> 0) Stay right here." << std::endl;
		std::cout << "> 1) Go through the sliding doors." << std::endl << std::endl;
		std::cin >> menuInput;
		std::cout << std::endl << std::endl;

		switch (menuInput)
		{
		case 0:
			sayStuff("You stand around for a bit. Nothing happens, except you get a bit wetter.\n\n");
			break;
		case 1:
			inRoom = false;
			sayStuff("You shiver and head inside - surely it has to be warmer there...!\n\n");
			roomMainHall();
			return 0;
		case 666:
			if (holdingTablet)
			{
				death();
				return 0;
			}
		default:
			sayStuff("You mumble some nonsense to yourself. Nothing happens. Still pissing down.\n\n");
			break;
		}
	}
}

int roomMainHall()
{
	bool inRoom = true;

	while (inRoom)
	{
		system("CLS");
		int menuInput = 0;

		std::cout << "You've entered the reception of a modern university. The environment is well-lit and comfortably warm. \nThere's a reception, coffee shop, stairs and even more hall! There's also a bald, bearded man \nstanding here, looking at what appears to be a timetable and swearing to himself.\n" << std::endl;
		std::cout << "> 0) Look around..." << std::endl;
		std::cout << "> 1) Go back outside." << std::endl;
		std::cout << "> 2) Take a look at the reception." << std::endl;
		std::cout << "> 3) Mmm! Coffee. Yes. Coffee. That will do." << std::endl;
		std::cout << "> 4) Go further down the hall...!" << std::endl;
		std::cout << "> 5) Talk to the bald, overweight man.." << std::endl << std::endl;
		std::cin >> menuInput;
		std::cout << std::endl << std::endl;

		switch (menuInput)
		{
		case 0:
			sayStuff("Huh. I don't know what to tell, you, really. It's quite pleasant. Airy. You'd expect it's \nbustling, normally, but it seems a bit quiet right now. The bald guy suddenly looks up, smiling \n- then he frowns, looks back down at the timetable and swears.\n\n");
			break;
		case 1:
			sayStuff("Let's blow this popsicle stand! Being dry is over-rated, anyway.\n\n");
			roomOutsideMainHall();
			return 0;
		case 2:
			sayStuff("'I'll take a look at the reception!', you think to yourself, excitedly, only to find this \nroom is not yet implemented.\n\n");
			break;
		case 3:
			sayStuff("Delicious coffee! Yes, perfect, exactly what you need -- but the cafe has not been implemented \nyet! It seems that this is a survival horror game.\n\n");
			break;
		case 4:
			sayStuff("What's that you hear, echoing from further down the hall...? Why - it's the call of ACTION! \nSadly, action has not been implemented in this game, yet.\n\n");
			break;
		case 5:
			sayStuff("You walk up to the guy and start a conversation...\n\n");
			talktoBaldGuy();
			return 0;
		case 666:
			if (holdingTablet)
			{
				death();
				return 0;
			}
		default:
			sayStuff("You mumble some nonsense to yourself. It echoes faintly through the enormous hall...\n\n");
			break;
		}
	}
}

int talktoBaldGuy()
{
	bool talking = true;

	while (talking)
	{
		system("CLS");
		int menuInput = 0;

		std::cout << "'Oh, hey,' he says, 'Sorry, I'm... still a bit lost, here. Huh. Bloody timetable.'\n\nHe hands you a battered tablet computer.\n\n'Hey, why don't you try to find more info about the timetable on Blackboard?'\n\n\n\tYou have the tablet! Now you can enter option 666 to use Blackboard!\n\n" << std::endl;
		holdingTablet = true;
		std::cout << "> 0) Stop talking to this weird dude." << std::endl << std::endl;
		std::cin >> menuInput;
		std::cout << std::endl;

		switch (menuInput)
		{
		case 0:
			talking = false;
			sayStuff("You give the confused man a friendly smile and slowly walk backwards until you \nturn a corner and can no longer see him. Then you run.\n\n");
			roomMainHall();
			return 0;
		case 666:
			if (holdingTablet)
			{
				death();
				return 0;
			}
		default:
			sayStuff("You mumble some nonsense to yourself. The bald guy eyes you suspiciously.\n\n");
			break;
		}
	}
}

void death()
{
	system("CLS");
	std::cout << "\n\n\n\n\n\n\n\n\n\tYou log onto Blackboard and instantly die. You have scored (" << rand() % 8 << ") out of a possible " << rand() % 1000 + 1 << " points.\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHE END.\n\n\n\n\n\n\n\n\n\n\n\n";
	system("Pause");
}