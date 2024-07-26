#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

int main()
{
    // Initialize random seed
    srand(time(0));

    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;
    int userGuess = 0;
    int numberOfTries = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it!" << endl;

    while (userGuess != numberToGuess)
    {
        cout << "Enter your guess: ";
        cin >> userGuess;
        numberOfTries++;

        if (userGuess > numberToGuess)
        {
            cout << "Too high! Try again." << endl;
        }
        else if (userGuess < numberToGuess)
        {
            cout << "Too low! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You've guessed the number in " << numberOfTries << " tries." << endl;
        }
    }

    return 0;
}
