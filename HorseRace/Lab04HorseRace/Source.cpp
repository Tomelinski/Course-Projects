
/*
Author: Tom Zielinski
Date: /2020
Program:
Program Description:
*/

#include "iostream"
#include "string"
#include "windows.h" // For colours, Beep(), and Sleep()
#include "Console.cpp"
#include "Random.cpp"
#include "Horse.cpp"


using namespace std;

// Program execution begins and ends here.
int main()
{
	//create the track distance
	const int theRace = 20;

	bool noWinners = true;
	string track = "====================\n";

	//generate a new random seed
	Random::Seed();

	//set console title
	Console::SetTitle("Horse Race");

	//create horses using horse.cpp
	Horse horse1 = Horse("FastBoi");
	Horse horse2 = Horse("Franklin");
	Horse horse3 = Horse("Baxter");
	Horse horse4 = Horse("Augusta");
	Horse horse5 = Horse("Woogly");

	//Horse horses[5] = { Horse("Fast"), Horse("Woogles"), Horse("Guy"), Horse("Speed"), Horse("Boyo") };


	//loop while there are no winners
	while (noWinners)
	{
		
		//check to see if any horses have comepleted the race
		if (horse1.GetDistanceCovered() >= theRace || horse2.GetDistanceCovered() >= theRace || horse3.GetDistanceCovered() >= theRace || horse4.GetDistanceCovered() >= theRace || horse5.GetDistanceCovered() >= theRace)
		{
			//if a horse has made it to the end, stop the while loop
			noWinners = false;
		}
		else
		{
			//clear console to display new distances
			Console::Clear();
			//display banner
			cout << Console::FormatBanner("Horse Race");

			cout << track;

			//use the run function to generate the horses distance
			horse1.Run();
			horse2.Run();
			horse3.Run();
			horse4.Run();
			horse5.Run();
			
			cout << track;
		}
		//pause program for x milliseconds
		Sleep(300);
	}

	// Press any key to continue . . .
	system("pause");
	// Main() needs to return an int
	return 0; // 0 means normal program exit
}
