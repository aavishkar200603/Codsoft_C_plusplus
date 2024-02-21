
#include <bits/stdc++.h>
using namespace std;

class randomGuessing {
private:
    int randomNum;
    int guess;
    int tries;

public:
    randomGuessing() {
          srand(time(0)); //seed random number generator that generates different number every time
	   randomNum = rand() % 100 + 1; // generates random number between 1 and 100
        guess = 0;
        tries = 0;
    }

    void game_on() {
        do {
            cout << "Enter a guess between 1 and 100: ";
            cin >> guess;
            tries++;

            if (guess > randomNum)
                cout << "Too high!\n\n";
            else if (guess < randomNum)
               cout << "Too low!\n\n";
            else
                cout << "\nCorrect! You got it in " << tries << " guesses!\n";
        } while (guess != randomNum);
    }
};

int main() {
  randomGuessing game;

    cout << "Guess My Number Game\n\n";
    game.game_on();

    return 0;
}
