//Jesus Uribe 
// Assignment  - Skynet HK-Aerial- Wargames

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//play again variable
	char playAgain;


	int searchGridLowNumber = 1; // Set the searchGridLowNumber as an integer so that it may be used later
	int searchGridHighNumber = 64; // Set the searchGridHighNumber as an integer so that it may be used later

	int targetLocation = rand() % 64 + 1; // Create a random number for targetLocation between 1 and 64
	int pingNumber = 0; // Set the current ping count to zero so that it will be accurate on the first run

	cout << "Making a 8X8 grid" << endl;
	cout << "The enemy is located at location #" << targetLocation << "  1-64 sectors." << endl;
	cout << "System loading............" << endl;

	//human variables and game loop

	//printing sequence
	cout << "Sequence start up of Skynet Hk-Areial player search" << endl;

	//amount of tries by human 
	int humanTries = 0;

	//Players guess
	int humanGuess = 0;

	//Game loop 
	do
	{
		//Players guess
		cout << "Please enter a Gridspace between 1 and 64, then press [enter] to guess enemy's location:";

		//Guess into variable
		cin >> humanGuess;

		//amount of tries
		++humanTries;

		//if Statement for human answer thats invalid
		if (humanGuess > 64 or humanGuess < 1)
		{
			cout << "-------------------------------------";
			cout << "Error Guess out of grid range.......";

		}

		//Else if statment if humand guesses too high 
		else if (humanGuess > targetLocation)
		{
			//Guess to low 
			cout << "------------------------------";
			cout << "Gridspace number " << humanGuess << " this gridspace is a lower number than the enemys location.";

		}
		//Else if humand guesses too low
		else if (humanGuess < targetLocation)
		{
			//Guess to high
			cout << "--------------------------------";
			cout << "Gridspace number " << humanGuess << " this gridspace is a higher number than the enemys location";

		}
		//Else statment regarding successfull enemy guess
		else
		{
			cout << "Gridspace number " << humanGuess << " enemy located at gridspace number " << targetLocation;

			//Break to exit loop 
			break;
		}

	}
	//While loop to re-initilze game loop
	while (humanGuess != targetLocation);

	// // // // // // // // // // // // // // // // // 
	//
	// Random Guess Variable
	//

	//Printing Sequence
	cout << "Start up of skynet random search software commencing";

	//Amount of tries from generator
	int randomTries = 0;

	//Random guess variable
	int randomGuess = 0;

	//Game loop
	do
	{
		//Generating the random number
		int randomNumber = rand();

		//Generating the random guess
		int randomGuess = (randomNumber % 64) + 1;

		//Addition to amount of tries
		++randomTries;

		//If statement is greater than random guess
		if (randomGuess > targetLocation)
		{
			//print out random guess is low
			cout << "Gridspace guess " << randomGuess << " This Gridspace is lower than the enemys location";
		}
		//Else statement regarding susccessful enemy location 
		else
		{
			//Show successful enemy location 
			cout << "Gridspace guess " << randomGuess << " located enemy at gridspace number " << targetLocation;

			//break statement
			break;
		}
	}
	//while loop to re-initialize do loop
	while (randomGuess != targetLocation);

	/////////////////////////////////////
	///
	/// Linear search variables & game loop 
	///

	//Printing sequence
	cout << "Startup of linear search variables";

	//Compiling the amount of tries
	int linearTries = 0;

	//Linear guess variable
	int linearGuess = 0;

	//Game loop
	do
	{
		//addition to the amount of tries
		++linearTries;

		//linear guess
		++linearGuess;

		//Random guess status  
		if (linearGuess != targetLocation)
		{
			//print that linear guess is too low 
			cout << "Gridspace guess " << linearGuess << " The gridspace is a lower number than the enemys location";
		}

		else
		{
			//Print the successful location 
			cout << "Gridspace guess " << linearGuess << " The enemy was located at gridspace number " << targetLocation;

			//break statement
			break;
		}
	}

	//While loop to re-initialize do 
	while (linearGuess != targetLocation);

	// /// // // // /////////////////////
	//
	//Binary search variables & game loop
	//

	//Printing sequence 
	cout << "Startup of binary search variabes and game loop";

	// Compiling the amount of tries
	int binaryTries = 0;

	// Grid high number
	int searchGridHighNumbe = 64;

	// Grid low number
	int searchGridLowNumbe = 1;

	// Binary search algorithm
	int targetLocationPrediction = 0;

	// Game loop
	do
	{
		// Binary search algorithm
		int targetLocationPrediction = ((searchGridHighNumbe - searchGridLowNumbe) / 2) + searchGridLowNumbe;

		// Addition to the amount of tries
		++binaryTries;

		// If statement regarding the greater than status of the target location prediction
		if (targetLocationPrediction > targetLocation)
		{
			// Re-initializing the high number within the binary search algorithm
			searchGridHighNumbe = targetLocationPrediction;

			// Printing that enemy location guess is too high
			cout << "Analyzation resulted in a search of gridspace # " << targetLocationPrediction << " . This gridspace is a higher number than the enemy's location. \nCommencing another analyzation...\n ------------------" << endl;
		}

		// Else if statement regarding the less than status of the target location prediction
		else if (targetLocationPrediction < targetLocation)
		{
			// Re-initializing the low number within the binary search algorithm
			searchGridLowNumbe = targetLocationPrediction;

			// Printing that enemy location guess is too low
			cout << "Analyzation resulted in a search of gridspace # " << targetLocationPrediction << " . This gridspace is a lower number than the enemy's location. \nCommencing another analyzation...\n ------------------" << endl;
		}

		// Else statement regarding successful enemy location
		else
		{
			// Printing the successful enemy location sequence
			cout << "Analyzation resulted in a search of gridspace # " << targetLocationPrediction << "\nThe enemy was located at gridspace # " << targetLocationPrediction << "\nIt took Skynet HK-Aerial approximately " << binaryTries << " analyzation sequences to find the enemy within the grid.\n\n" << endl;

			// Break statement to exit do loop
			break;
		}
	}

	// While loop to re-initialize game loop
	while (targetLocationPrediction != targetLocation);

	///////////////////////////////////////////////
	//
	// Display results
	//

	cout << "Sequences have been completed.\nThe enemy has been eliminated";
	cout << "Ememy was located at gridspace number " << targetLocation << "\n\n";
	cout << "The human player took " << humanTries << " tries to find enemy location.\n";
	cout << "The random search took " << randomTries << " tries to find enemy location.\n";
	cout << "The linear search took " << linearTries << " tries to find the enemy location.\n";
	cout << "The binary search took " << binaryTries << " tries to find the enemy location.\n -------------\n";

	cout << "Would you like to re-initialize Skynet HK-Aerial to find another enemy?\nIf so, enter 'y' then press 'enter', if not enter 'n' then press 'enter'";
	cin >> playAgain;

	while (playAgain == 'y');
	cout << "\nThank you for using Skynet HK-Aerial software.\n";
	return 0;
}
