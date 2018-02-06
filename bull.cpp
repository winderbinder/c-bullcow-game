/*this is the console executable, that makes use of the bullcow class 
this acts as the view in a mvc pattern, and is responsible for all user interaction. 
for game logic see the Fbullcowgame class*/
#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//to make syntax user friendly
using Ftext = std::string;
using int32 = int;


//function prototypes as outside a class
void printintro();
void playgame();
Ftext GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game


// the entry point for our application
int main()
{

bool bPlayAgain = false;
do {
printintro();
playgame();
bPlayAgain = AskToPlayAgain();
} 
while (bPlayAgain);

return 0; //exit the application
}

void printintro() 
{
 
std::cout << "\n\n welcome to bulls and cows, a fun word game.\n";
std::cout << "can you guess the " << BCGame.GetHiddenWordLength();
std::cout << " letter isogram that I'm thinking of?\n";
std::cout << std::endl;
return;
}
void playgame()
{
BCGame.Reset();
int32 MaxTries = BCGame.GetMaxTries();

// loop asking for guesses while the game is not won
// is NOT won there are still tries remaining
while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
Ftext guess = GetValidGuess(); // TODO make loop checking for valid


// submit valid guess to the game, and recieve counts
FBullCowCount BullCowCount = BCGame.SubmitValidGuess(guess);

// print number of bulls and cows
std::cout << "bulls = " << BullCowCount.Bulls;
std::cout << " cows = " << BullCowCount.cows << "\n\n";
}
PrintGameSummary();
return;
}
// loop continually until user gives a valid guess
Ftext GetValidGuess()
{
Ftext Guess = "";
EGuessStatus Status = EGuessStatus::invalid_Status;
do {

// get a guess from the player
int32 CurrentTry = BCGame.GetCurrentTry();
std::cout << "try " << CurrentTry << " of " << BCGame.GetMaxTries();
std::cout << ". enter your guess: ";
std::getline(std::cin, Guess);

//check status and get feedback
Status = BCGame.CheckGuessValidity(Guess);
switch (Status)
{
case EGuessStatus::Wrong_GuessLength:
std::cout << "please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
break;
case EGuessStatus::Not_isogram:
std::cout << "please enter a word without repeating letters.\n\n";
break;
case EGuessStatus::Not_Lowercase:
std::cout << "please enter all lowercase letters.\n\n";
break;
default:
// assume the guess is valid
break;
}
} while (Status != EGuessStatus::OK); //keep looping until we get no errors
return Guess;
}

bool AskToPlayAgain()
{
std::cout << "do you want to play again with the same hidden word? (y/n) ";
Ftext Response = "";
std::getline(std::cin, Response);
return (Response[0] == 'y') || (Response[0] == 'Y');
}
void PrintGameSummary()
{
if (BCGame.IsGameWon())
{
std::cout << "WELL DONE - YOU WIN\n";
}
else
{
std::cout << "oops! better luck next time!\n";
}

}