#pragma once //Kõik mis imporditakse (kuhu?) imporditakse aint ühe korra
#include <string>

using FString = std::string; //FString is changeable, used more for game logic
using int32 = int;

//all values initialised 0, F-prefix because it's a struct
struct FBCNumber 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	OK,
	Not_Isogram,
	Invalid_Char,
	Wrong_Length
};

class FBullCowGame {							// Classes and structs have a F prefix
public:
	FBullCowGame();
	
	void Reset();

	int32 GetHiddenWordLength() const;
	int32 GetMaxTries() const;
	int32 CurrentTry() const;

	FString SetWord(FString);

	EWordStatus CheckGuessValidity(FString) const;
	bool IsCorrectGuess(FString) const;

	//count bulls and cows and increase Try# if valid guess
	FBCNumber SubmitGuess (FString Guess);
	

private:
	//initialisation in constructor
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
};
 