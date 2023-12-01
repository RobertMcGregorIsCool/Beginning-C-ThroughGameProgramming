// Author: RoBert McGregor	ID: C00302210
// Purpose: Small, extendable text adventure
// making use of code which has been taught in
// class.
// Start Time: 18:18	Finish Time:
// Estimate: Who fuckin' knows.	Actual: Not me!
// Problems & Bugs:
// No validation for user input - a string will throw the system.
// There seems to be an error in setting up the random function, look into that.
// The rooms are having problems with not returning a value. Possibly need to turn these into VOID? Is there another way?

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int roomOutsideMainHall();
int fightLeprechaun(int t_playerStamina = 5, int t_enemyStamina = 3, int t_upperLimit = 100, int t_chancesToAttack = 5);
int roomMainHall();
int talktoBaldGuy();
int sayStuff(std::string dialogue);
void death();

bool holdingTablet = false;

int main()
{
	srand(time(0));

	std::cout << "\tOnly enter numbers, please! This program doesn't understand strings (yet, but sooon...!).\n\n" << std::endl;
	roomOutsideMainHall();
	return 0;
}

int sayStuff(std::string dialogue)
{
	system("CLS");
	std::cout << dialogue;
	system("Pause");
	return 0;
}

int sayStaminaUpdate(int t_playerStamina, int t_enemyStamina)
{
	system("CLS");
	std::cout << "You have " << t_playerStamina << " stamina remaining.\n";
	std::cout << "The opponent has " << t_enemyStamina << " stamina remaining!\n";
	system("Pause");
	return 0;
}

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
		std::cout << "> 2) Fight a Leprechaun.\n\n";
		std::cin >> menuInput;
		std::cout << std::endl << std::endl;

		switch (menuInput)
		{
		case 0:
			sayStuff("You stand around for a bit. Nothing happens, except you get a bit wetter.\n\n");
			break;
		case 1:
			inRoom = false;
			sayStuff("You shiver and head inside - surely it has to be warmer in there...!\n\n");
			roomMainHall();
			return 0;
		case 2:
			inRoom = false;
			sayStuff("A short fairy in green clothes with a strange 'Irish' accent attacks you with a Shillelagh!\nYou grab a sturdy branch and try to remember your training in Bataireacht!\n\n");
			fightLeprechaun();
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

// Bunch of problems here - you're told you have 0 attack chances (but you should never see that, you should just be hit). Also, you don't seem to get hit - is it hanging?
int fightLeprechaun(int t_playerStamina, int t_enemyStamina, int t_upperLimit, int t_chancesToAttack)
{
	bool inRoom = true;
	int targetNumber = rand() % t_upperLimit + 1; // Random number between 1 and t_upperLimit

	while (inRoom)
	{
		system("CLS");
		
		bool fighting = true;
		
		while (fighting)
		{
			int attackNumber = 0;
			int attemptsToAttack = t_chancesToAttack;

			do
			{
				std::cout << "\nChoose a number between 1 and " << t_upperLimit << " to try and strike the Leprechaun!\n";
				std::cout << "You have " << attemptsToAttack << " attacks left before they hit you. Type '0' to leave this dumb fight.\n";
				std::cin >> attackNumber;
				std::cout << std::endl << std::endl;

				if (attackNumber == 0)
				{
					sayStuff("You throw your stick at the Leprechaun, stunning him temporarily and allowing you to make your heroic escape!\n\n");
					fighting = false;
					break;
				}

				if (attackNumber > targetNumber)
				{
					sayStuff ("You hit him too high! He blocks, and giggles at you!\n\n");
					attemptsToAttack--;
				}

				if (attackNumber < targetNumber)
				{
					sayStuff ("You hit him too low! He dodges your attack, and screams 'Better to be quarreling than lonesome!'\n\n");
					attemptsToAttack--;
				}
			} while (attackNumber != targetNumber || attemptsToAttack > 1);

			if (attackNumber == targetNumber) // Player has struck the Leprechaun!
			{
				t_enemyStamina--;
				if (t_enemyStamina <= 0)
				{
					sayStuff("You won the fight! Swiftly, you loot the unconscious fairy and smugly march away\nwith your pockets full of chocolate coins wrapped in gold foil. Ehh, it'll do.\n");
					fighting = false;
				}
				else
				{
					sayStuff("You've struck the Leprechaun! He staggers back and grimaces!\n");
					sayStaminaUpdate(t_playerStamina, t_enemyStamina);
					targetNumber = rand() % t_upperLimit + 1; // Random number between 1 and t_upperLimit
				}
			}
			else if(attemptsToAttack <= 0)
			{
				t_playerStamina--;
				if (t_playerStamina <= 0)
				{
					sayStuff("Somehow, you lost the fight.\n");
					sayStuff("In a heap on the floor, you are only dimly aware of the Leprechaun robbing you blind.\n");
					fighting = false;
				}
				else
				{
					sayStuff("OW! The Leprechaun has hit you hard on your shins!\n");
					sayStaminaUpdate(t_playerStamina, t_enemyStamina);
					targetNumber = rand() % t_upperLimit + 1; // Random number between 1 and t_upperLimit
				}
			}
		}
		roomOutsideMainHall();
		return 0;

		/*switch (menuInput)
		{
		case 0:
			
			roomOutsideMainHall();
			return 0;
		case 1:
			sayStuff("Let's blow this popsicle stand! Being dry is over-rated, anyway.\n\n");
			roomOutsideMainHall();
			return 0;
		case 2:
			t_playerStamina = 3;
			break;
		case 666:
			if (holdingTablet)
			{
				death();
				return 0;
			}
		default:
			sayStuff("You mumble some nonsense to yourself. It echoes faintly through the enormous hall...\n\n");
			break;
		}*/
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
			sayStuff("Huh. I don't know what to tell you, really. It's quite pleasant. Airy. You'd expect it's \nbustling, normally, but it seems a bit quiet right now. The bald guy suddenly looks up, smiling \n- then he frowns, looks back down at the timetable and swears.\n\n");
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