#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    // random number generator 
    int num = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "===== Number Guessing Game =====" << endl;
    cout << "Take a random number guess between 1 to 100 , all the best!" << endl;

    while (true) {
        cout << "Enter your guessed number ";
        cin >> guess;
        attempts++;

        if (guess > num) {
            cout << "Too high guess , try guessing a lower number" << endl;
        }
        else if (guess < num) {
            cout << "Too low guess , try guessing a higer number" << endl;
        }
        else {
            cout << "\nCongratulations! You guessed the correct number." << endl;
            cout << "Total attempts: " << attempts << endl;
            break;
        }
    }

    return 0;
}

