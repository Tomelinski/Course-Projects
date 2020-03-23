#pragma once 			// Avoid redefinition of the class Console
#include "iostream"
#include "string"
#include "windows.h" // For colours, Beep(), and Sleep()
#include "Random.cpp"
#include "Console.cpp"

using namespace std;

class Horse
{
private:

	float distanceCovered = 0;

public:
	string name;

	//set horse name
	Horse(string name) {
		this->name = name;
	}

	//a method to generate distance for the horse
	void Run(){

		//random number between 0 and 1
		 float number = Random::Next(10) / 10.0;
		 //float randomNumber = (rand() % 10)/ 10.0;
		 this->distanceCovered += number;

		 //call distance method
		 PrintDistance();
	}

	//print distance method
	void PrintDistance() {
		//forloop to display each horses distance
		for (int i = 0; i < GetDistanceCovered(); i++)
		{
			//check to see if winner
			if (distanceCovered == 20)
			{
				Console::Write("=",10);
			}
			else
			{
				cout << "=";
			}
		}
		//display the horse name after their distance and check if winner
		if (distanceCovered == 20)
		{

			Console::Write(" " + name + " is the winner \n", 10);
		}
		else
		{
			cout << " " << name << " \n";
		}
	}

	//round and return the distance
	int GetDistanceCovered() {

		this->distanceCovered = round(distanceCovered);
		return distanceCovered;
	}

};
