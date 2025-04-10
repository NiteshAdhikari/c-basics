#include <iostream>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int maxRange = 0;
    int secretNumber, guess;
    char difficulty;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Choose your difficulty: Easy (e), Medium (m), Hard (h): ";
    cin >> difficulty;
    if (difficulty == 'e' || difficulty == 'E') {
        maxRange = 8;
    } else if (difficulty == 'm' || difficulty == 'M') {
        maxRange = 30;
    } else if (difficulty == 'h' || difficulty == 'H') {
        maxRange = 50;
    } else {
        cout << "Invalid input! Please restart the game and choose a valid difficulty." << endl;
        return 1;
    }
    secretNumber = rand() % maxRange + 1;
    cout << "Guess a number between 1 and " << maxRange << ": ";
    cin >> guess;
    if (guess == secretNumber) {
        cout << "Congratulations! You guessed the correct number." << endl;
    } else {
        cout << "Wrong guess! The correct number was " << secretNumber << "." << endl;
    }
    return 0;
}
