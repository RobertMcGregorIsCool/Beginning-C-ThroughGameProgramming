// Author: RoBert McGregor	ID: C00302210
// Purpose: Launch menu for projects in this Repo
// Start Time: 18:18	Finish Time:
// Estimate: 20 mins	Actual:
// Problems & Bugs:

#include <iostream>

int roomOutsideMainHall();
int roomMainHall();
int talktoBaldGuy();

int main()
{
	std::cout << "\tOnly enter numbers, please! This program doesn't understand strings (yet, but sooon...!).\n\n" << std::endl;
	roomOutsideMainHall();

	system("Pause");
	return 0;
}

int roomOutsideMainHall()
{
	bool inRoom = true;

	while (inRoom)
	{
		int menuInput = 0;

		std::cout << "You're standing outside some sliding doors leading to a large hall.\nIt's bucketing down out here, and you're getting wet. What would you like to do?\n" << std::endl;
		std::cout << "> 0) Stay right here." << std::endl;
		std::cout << "> 1) Go through the sliding doors." << std::endl;
		std::cin >> menuInput;
		std::cout << std::endl << std::endl;

		switch (menuInput)
		{
		case 0:
			std::cout << "You stand around for a bit. Nothing happens, except you get a bit wetter.\n" << std::endl;
			break;
		case 1:
			inRoom = false;
			std::cout << "You shiver and head inside - surely it has to be warmer there...!\n\n" << std::endl;
			roomMainHall();
			break;
		default:
			std::cout << "You mumble some nonsense to yourself. Nothing happens. Still pissing down.\n" << std::endl;
			break;
		}
	}
	return 0;
}

int roomMainHall()
{
	bool inRoom = true;

	while (inRoom)
	{
		int menuInput = 0;

		std::cout << "You've entered the reception of a modern university. The environment is well-lit and fairly warm. There's a reception, coffee shop, stairs and even more hall! There's also a bald, bearded man standing here, looking at what appears to be a timetable and swearing to himself.\n" << std::endl;
		std::cout << "> 0) Look around..." << std::endl;
		std::cout << "> 1) Go back outside." << std::endl;
		std::cout << "> 2) Take a look at the reception." << std::endl;
		std::cout << "> 3) Mmm! Coffee. Yes. Coffee. That will do." << std::endl;
		std::cout << "> 4) Go further down the hall...!" << std::endl;
		std::cout << "> 5) Talk to the bald, overweight man.." << std::endl;
		std::cin >> menuInput;
		std::cout << std::endl << std::endl;

		switch (menuInput)
		{
		case 0:
			std::cout << "Huh. I don't know what to tell, you, really. It's quite pleasant. Airy. You'd expect it's bustling, normally, but it seems quite quiet right now. The bald guy suddenly looks up, smiling - then he frowns, looks back down at the timetable and swears.\n" << std::endl;
			break;
		case 1:
			std::cout << "Let's blow this popsicle stand! Being dry is over-rated, anyway.\n" << std::endl;
			roomOutsideMainHall();
			return 0;
		case 2:
			std::cout << "'I'll take a look at the reception!', you think to yourself, excitedly, only to find this room is not yet implemented.\n" << std::endl;
			break;
		case 3:
			std::cout << "Delicious coffee! Yes, perfect, exactly what you need -- but the cafe has not been implemented yet! It seems that this is a survival horror game.\n" << std::endl;
			break;
		case 4:
			std::cout << "What's that you hear, echoing from further down the hall...? Why - it's the call of ACTION! Sadly, action has not been implemented in this game, yet.\n" << std::endl;
			break;
		case 5:
			std::cout << "You walk up to the guy and start a conversation...\n\n";
			talktoBaldGuy();
			return 0;
		default:
			break;
		}
	}
}

int talktoBaldGuy()
{
	bool talking = true;

	while (talking)
	{
		int menuInput = 0;

		std::cout << "\n'Oh, hey,' he says, 'Sorry, I'm... still a bit lost, here. Huh. Bloody timetable.'\n\nHe hands you a tablet computer.\n\n'Hey, why don't you try to find more info about the timetable on Blackboard?'" << std::endl;
		std::cout << "> 0) Log onto Blackboard." << std::endl;
		std::cout << "> 1) Stop talking to this weird dude." << std::endl;
		std::cin >> menuInput;
		std::cout << std::endl << std::endl;

		switch (menuInput)
		{
		case 0:
			std::cout << "You log onto Blackboard and instantly die. You have scored (4) out of a possible 900 points. THE END.\n" << std::endl;
			return 0;
		case 1:
			talking = false;
			std::cout << "You give the confused man a friendly smile and slowly walk backwards until you turn a corner and can no longer see him. Then you run.\n\n" << std::endl;
			roomMainHall();
			return 0;
		default:
			std::cout << "You mumble some nonsense to yourself. Nothing happens. Still pissing down.\n" << std::endl;
			break;
		}
	}

	return 0;
}