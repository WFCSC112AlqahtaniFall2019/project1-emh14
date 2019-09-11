/* Ethan Harrison
 * CSC 112
 * Project 1
 * Battleship
 * */

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
    int shipX = rand() % 3;//Ship's x-coordinate location (Where on the row?)
    int shipY = rand() % 3;//Ship's y-coordinate location (Where on the column?)

    //Begin playing game
    int guesses = 0;
    bool hit = false;

    //Creates game board if user misses
    while (!hit) {
        for (int i = 0; i < 3; i++) {
            if (i > 0) {
                cout << endl << "~~~~~" << endl;//Row Border
            }
            for (int j = 0; j < 3; j++) {
                if (j > 0) {
                    cout << "!";//Column border
                }
                if (grid.at(i).at(j) == false) {
                    cout << " ";
                } else {
                    cout << "O"; //Denotes "miss"
                }
            }
        }

        //Prompt for guesses
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

        //Check if Guessed Location is a Hit
        if (guessRow == shipX && guessCol == shipY) {
            hit = true;
        } else {
            grid.at(guessRow).at(guessCol) = true;
        }

    }

    //Prints game board revealing the ship's location
    bool printedX = false;//Keeps track of whether the X to mark "hit" has been printed
    for (int i = 0; i < 3; i++) {
        if (i > 0) {
            cout << endl << "~~~~~" << endl;//Row Border
        }
        for (int j = 0; j < 3; j++) {
            if (j > 0) {
                cout << "!";//Column border
            }
            if (i == shipX && j == shipY) {
                cout << "X";//Denotes "hit"
                printedX = true;
            }
            if (grid.at(i).at(j) == false && printedX == false){//Only print space if there is no X
                cout << " ";
            } else if (printedX == false) {
                cout << "O";//Denotes "miss"
            }

            printedX = false;//Resets variable so loop starts fresh
        }
    }
    //Finish game
    cout << endl << " You sunk my battleship! Number of guesses: " << guesses;
    return 0;
}