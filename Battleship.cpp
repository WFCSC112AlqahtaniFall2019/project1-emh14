#include <iostream>
#include <vector>

#include <time.h>

using namespace std;

int main() {
    //Welcome
    cout << "Let's play battleship!" << endl << endl;

    //Initialize vector to represent grid
    vector<vector<bool>> grid{{false, false, false},
                              {false, false, false},
                              {false, false, false}};

    //Randomly select location for battle ship
    srand(time(NULL));
    int shipX = rand() % 3;
    int shipY = rand() % 3;

    //Begin playing game
    int guesses = 0;
    bool hit = false;

    //Creates game board if user misses
    while (!hit) {
        for (int i = 0; i < 3; i++) {
            if (i > 0) {
                cout << endl << "~~~~~" << endl;
            }
            for (int j = 0; j < 3; j++) {
                if (j > 0) {
                    cout << "!";
                }
                if (grid.at(i).at(j) == false) {
                    cout << " ";
                } else {
                    cout << "O";
                }
            }
        }
        cout << endl << endl << "Location (Row[1-3] Column[1-3]): " << endl;
        int guessRow;
        int guessCol;

        //User enters guess
        cin >> guessRow;
        cin >> guessCol;

        //Check to make sure input is within range
        while (guessRow < 1 || guessRow > 3 || guessCol < 1 || guessCol > 3) {
            cout << "Error! Invalid entry, guess again" << endl << "Location (Row[1-3] Column[1-3]): " << endl;
            cin >> guessRow;
            cin >> guessCol;
        }

        // Scales input so user can enter numbers 1-3
        guessRow--;
        guessCol--;

        //Increment guess number
        guesses++;

        //Check Location for Hit
        if (guessRow == shipX && guessCol == shipY) {
            hit = true;
        } else {
            grid.at(guessRow).at(guessCol) = true;
        }

    }

    //Prints game board revealing the ship's location
    for (int i = 0; i < 3; i++) {
        if (i > 0) {
            cout << endl << "~~~~~" << endl;
        }
        for (int j = 0; j < 3; j++) {
            if (j > 0) {
                cout << "!";
            }
            if (i == shipX && j == shipY) {
                cout << "X";
            }
            if (grid.at(i).at(j) == false) {
                cout << " ";
            } else {
                cout << "O";
            }
        }
    }
    cout << endl << " You sunk my battleship! Number of guesses: " << guesses;
    return 0;
}