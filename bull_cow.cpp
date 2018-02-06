class FBullCowGame
{
public:
FBullCowGame(); // constructor

int32  GetMaxTries() const;
int32 GetCurrentTry() const;
int32 GetHiddenWordLength()const;
bool IsGameWon() const;
EGuessStatus CheckGuessValidity(FString) const;


void Reset(); // TODO make a more rich return value
FBullCowCount SubmitValidGuess(FString);

// please try and ignore this and focus on the interface above ^^
private:
// see constructor for initialization
int32 MyCurrentTry;
FString MyHiddenWord;
bool bGameIsWon;

bool IsIsogram(FString) const;
bool IsLowercase(FString) const;
};