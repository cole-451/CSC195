#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned int randomNumber = 0;
unsigned int playerGuess = 0;
bool correctAnswer = false;

void assignRandomNumber() {
    srand(time(0));
    randomNumber = rand() % 10 + 1;
}

void checkGuess(int playerGuess) {
    if (playerGuess < randomNumber) {
        cout << "Too low!"<<endl;
    }
    else if (playerGuess > randomNumber) {
        cout << "Too high!" << endl;
    }
    else {
        cout << "Correct! You win!"<<endl;
        correctAnswer = true;
    }

}







int main()
{
    // choose random number
    assignRandomNumber();
    // while answer is wrong, guess
    while (!correctAnswer) {
        cout << "Give me a number between 1 and 10!" << endl;
        cin >> playerGuess;
        checkGuess(playerGuess);
    }
    
    //if too high, state too high and repeat
    //if too low, state too low and repeat
    // if correct, end game
}
