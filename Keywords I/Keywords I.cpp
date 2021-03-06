// Keywords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	//variable where we determine of the player wants o run the program again
	int playAgain = 0;
	//string variable that can have the 2 values from the 10 sets of 2 strings as it's value, 1st is the word, other is the hint
	string Codes[10][2] =
	{
		{ "soil", "earth" },{ "forge", "make" },{ "intense","hard" },{ "compete","tournament" },{ "adventure","quest" },
	{ "dark","dim" },{ "catch","grab" },{ "humor","funny" },{ "fire","flame" },{ "ice","cold" }
	};
	//seeds a random number
	srand(static_cast<unsigned int>(time(0)));
	cout << "There are 3 words you need to guess! \n\n" << endl;
	//loop that'll repeat 3 times
	for (int i = 0; i < 3; i++)
	{
		//a random number is set to randNum, no greater than 10
		int randNum = rand() % 10;
		//this is where a random word is assigned to randWord. getting a random number(which gives it a random value from the 10)
		//assigning it the 1st value from the list of codes
		string randWord = Codes[randNum][0];
		//From the same random number, it assigns the 2nd value for the list of codes that goes with the previous number
		string wordHint = Codes[randNum][1];
		//this is where the radon word gets jumbled up
		string jumble = randWord;
		//variable equal to the characters in the word we're gonig to scramble
		int length = jumble.size();
		//the process will repeat equal to the characters in the word we're gonig to scramble
		for (int l = 0; l < length; l++)
		{
			//here i generated 2 random positions and and swapped the charaters in those positions
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		//the jumbled word is displayed ot the player
		cout << "The word you need to guess is:\n\n" << jumble << "\n" << endl;
		//created a variable for the player's answer
		string guess;
		cout << "What is your guess for the word:\n\nIf you're having trouble, type hint\nIf you want to exit, type quit\n" << endl;
		cout << "" << endl;
		cin >> guess;
		//loop where their guess isnt the correct answer
		while ((guess != randWord))
		{
			//here it checks to see if the player wanted a hint, and runs it if they do. 
			if (guess == "hint")
			{
				//displays the hint, or the 2nd value to the pair of strings
				cout << "You have asked for a hint!\nThe hint is: " << wordHint << "\n" << endl;
			}
			//here it kills the program if the player decided to quit the game
			else if (guess == "quit")
			{
				cout << "Thank you for playing!" << endl;
				exit(0);
			}
			else
			{
				//this displays if the player guesses the word incorrectly.
				cout << "Nope! Try again!\n\nThe clue is " << jumble << endl;
			}
			cout << "What is your next guess\n";
			cin >> guess;
			cout << "" << endl;
			//these lines of code run if the player guesses the word correctly
			if (guess == randWord)
			{
				cout << "Awesome job!\n\n";
			}
		}
	}
	//asks the player if they want to play again.
	cout << "Would you like to try again?\n\n1 for yes.\n\n";
	cin >> playAgain;
	//kills the program if their input isn't a 1 
	if (playAgain != 1)
	{
		exit(0);
	}
	//runs the progam again if the player wishes to play again. 
	else if (playAgain == 1)
	{
		main(); 
	}
	system("pause");
	return 0;
}