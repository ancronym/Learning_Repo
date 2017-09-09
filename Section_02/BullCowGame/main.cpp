/* 
This is the console executable, that makes use of the BullCowGame class
This acts as the view in MVC pattern, and is responsible for all user interaction. 

For game logic see the Bull Cow class

*/


// nurksulgudes on #include asjad, mis on standardselt juba olemas ehk siis <iostream> on library. Enda viidatud failid oleks jutumärkides ""
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string; //Ftext is mainly for user interaction, selle asemel FString on midagi, mis on muudetav
using int32 = int;

// See std namespace on iostream sees. Kui siin mitte deklareerida, tuleb koodis pidevalt std:: kirjutada seal leiduva meetodi jaoks.
// Kui aga kahes libraris nagu <iostream> vs <rando> on sama nimega namespace ja meetod, läheb kompilaator segadusse - namespace clash!
// Hetkel saan nii aru: Library -> Namespace -> Method

void PrintIntro();																		// Siin deklareerib funktsiooni, mis on hiljem defineeritud
void Feedback();																		// Funktsioonide, nimed on CamelCase
void PlayGame();
bool AskToPlayAgain();
void Outro();
FText GetGuess();

FBullCowGame BCGame;																	//instantiate i.e create an instance of a new game 

FBCNumber BCCount;		//Struct

FText Guess = "";																	// muutuja algustäht on suur - Unity standard

//The entry point for our application
int main()
{
	do
	{
		PrintIntro(); // TODO add ASCII graphics
		PlayGame();
		BCGame.Reset();
	} while (AskToPlayAgain());
	
	Outro();
	return 0;
}


//Introduce the game
void PrintIntro()
{
	std::cout << "\n Welcome to Bulls and Cows!\n";											// cout on meetod std namespace seest, mis on iostream library SEES
	std::cout << "Oh please guess the isogram, it has " << BCGame.GetHiddenWordLength() << " letters!";		// alternatiiv \n on: cout << endl, endl tühjendab ka mingi puhvri
	std::cout << std::endl;
	std::cout << std::endl;
	return;
}


// Runs guess and feedback cycle as many times as constant MAX_TRIES dictates
void PlayGame()
{	
	
	int32 MaxTries = BCGame.GetMaxTries();

	std::cout << "Max tries: " << MaxTries << std::endl;

	// TODO change to while loop once guess validation is in place
	for (int32 i = 1; i <= MaxTries; i++)
	{		
		GetGuess();
		//Check Validity
		BCCount = BCGame.SubmitGuess(Guess);				//Submit valid guess to game and recieve count
		Feedback();
		//TODO summarise game
	};
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again? (y or n): ";
	FText Answer = "";
	std::getline(std::cin, Answer);

	return (Answer[0] == 'y') || (Answer[0] == 'Y');
}


//Gets guess from user
FText GetGuess()
{		
	int32 CurrentTry = BCGame.CurrentTry();

	std::cout << "Try Nr "<< CurrentTry << ". Make a word guess now! Type here: ";		// nurksulgude suund näitab info liikumise suunda
	std::getline(std::cin, Guess); 
	return Guess; // TODO return valid guess
}


//Feedback about the guess to the player
void Feedback()
{
	std::cout << "Bulls: " << BCCount.Bulls;
	std::cout << ". Cows: " << BCCount.Cows;	
	std::cout << std::endl;
	//TODO print how many Bulls or Cows the player guessed
	return;
}


 //Prints to state the end of game
void Outro()
{
	std::cout << std::endl;
	std::cout << "Le done!" << std::endl << std::endl;
	return;
}