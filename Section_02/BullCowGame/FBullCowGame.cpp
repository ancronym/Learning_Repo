#include "FBullCowGame.h"

using int32 = int;

//--------------------
// Constructor - sets runtime variables/parameters for FBullCowGame
FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "plant";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}


int32 FBullCowGame::GetHiddenWordLength() const
{
	return (MyHiddenWord.length());
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::CurrentTry () const
{
	return MyCurrentTry;
}


std::string FBullCowGame::SetWord(std::string) //TODO Declare a database and select a random word from it
{
	return std::string();
}


EWordStatus FBullCowGame::CheckGuessValidity(std::string) const //TODO Check if Guess is of proper lenght
{


	return EWordStatus::OK; // TODO make actual error
}

bool FBullCowGame::IsCorrectGuess(std::string) const //TODO Check if the player has guessed the word
{
	return false;
}


//compares guess to hidden word and counts bulls and cows
FBCNumber FBullCowGame::SubmitGuess(FString Guess)
{
	//setup a return variable
	MyCurrentTry++;					// increases the Try number
	FBCNumber BCNumber;				// declares struct BCNumber
	int32 HiddenWordLength = MyHiddenWord.length();

	//loop through all the letters in the guess
	for (int32 i = 0;i < HiddenWordLength;i++)					// cycle for checking Bulls
	{
		for (int32 j = 0; j < HiddenWordLength;j++)
		{
			if (Guess[i] == MyHiddenWord[j])
			{
				if (i == j)
				{
					BCNumber.Bulls++;
				}
				else
				{
					BCNumber.Cows++;
				}

			}
			else {}
		}
	}

	return BCNumber;
}