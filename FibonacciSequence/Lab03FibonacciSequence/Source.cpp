
/*
Author: Tom Zielinski and Rose Nguyen
Date: 02/13/2020
Program: Fibonacci sequence
Program Description: A program that prompts the user for 2 numbers and displays the fibonacci sequence values in that range
*/

#include "iostream"
#include "string"
#include "windows.h" // For colours, Beep(), and Sleep()

using namespace std;

const int MAX = 30;
const int MIN = 0;

// Receives the title and description of the program by VALUE
// Clear the Console screen
// Set the title of the program as “Program name – Your Name”.
//Note that system() takes a C string(char array) as argument, you will
//have to use string.c_str() to convert your string title into a C string
// Format and prints the banner based on the received title
// Print out the program description
void WriteTitleBannerDescription(string title, string description) {
	
	system(("title " + title + " - Tom Zielinski - Rose Nguyen").c_str());
	system("cls");

		string line = "";

		//create line for banner
		for (size_t i = 0; i < title.length() + 4; i++)
		{
			line += "=";
		}

		//return concatenated banner
		cout << line << "\n= " << title << " =\n" << line << "\n\n" << description << "\n\n";

}

// Writes the prompt received by value
// Assign the 2 integers BY REFERENCE
// Validate 2 integers
// If input is invalid, print the appropriate error messages and loop
// Max must be greater than min and vice versa
// Numbers must be greater than 0 and less than 30
// Max is inclusive
void PromptValidateRange(string prompt, int& number1, int& number2) {
		int result;
		bool isInvalid;

		do // Ask for the user's age until getting a valid input
		{
			cout << prompt;
			// Will try to convert input
			cin >> number1 >> number2;
			// Validation – Failed to assign a numeric value to the variable? (true/false)
			isInvalid = cin.fail();
			cin.clear(); // clear the fail state of cin
			// Error message in case input is invalid
			if (isInvalid){
				cout << "Error - Input must be numeric.\n\n";
			}
			//error if number 1 is greater then number 2
			else if (number1 >= number2)
			{
				cout << "Error - Max must be greater than Min\n\n";
				isInvalid = true;
			}
			//error if number one is less then zero
			else if (number1 <= MIN)
			{
				cout << "Error - Numbers must be greater than 0\n\n";
				isInvalid = true;
			}
			//error if number 2 is greater then 30
			else if (number2 >= MAX)
			{
				cout << "Error - Numbers must be less than 30\n\n";
				isInvalid = true;
			}

			// Ignore leftover input until newline [enter]
			cin.ignore(256, '\n'); // 256 is how many chars to ignore
		} while (isInvalid);

}


// Calculates the Nth number in the Fibonacci sequence
// MUST BE a RECURSIVE function
int Fibonacci(int index) {
	//calculate fibonacci sequence 
	if (index <= 1) {
		return index;
	}
	else {
		return Fibonacci(index - 2) + Fibonacci(index - 1);
	}

}

//creates a line
void line() {
	cout << "\n===================================\n";
}

// Prints the Fibonacci Sequence in table format
// Min and max passed by value
// Min and max must be positive numbers
// Max is inclusive
void PrintSequenceAsTable(int min, int max) {
	//creat a table and call fibonacci from the range the user input
	line();

	for (int i = min; i <= max; i++)
	{
		//line up the table
		if (i < 10) 
			cout << i << "       |       " << Fibonacci(i);
		else 
			cout << i << "      |       " << Fibonacci(i);
		line();
	}

}



// Program execution begins and ends here.
int main()
{
	int number1, number2;
	char yesNo;

	do
	{
		//call banner
		WriteTitleBannerDescription("Fibonacci Sequence", "Program that write the fibonacci Sequence starting and ending at the numbers given by the user");
		//call validation
		PromptValidateRange("Enter min and max numbers: ", number1, number2);
		//redraw banner
		WriteTitleBannerDescription("Fibonacci Sequence", "Fibonacci Sequence from " + to_string(number1) + " to " + to_string(number2));
		//display table
		PrintSequenceAsTable(number1, number2);

		//prompt user to repeat 
		do
		{
			cout << "\nWould you like to repeat? [y/n] ";
			cin >> yesNo;
		} while (yesNo != 'y' && yesNo != 'n');
	} while (yesNo == 'y');
}
