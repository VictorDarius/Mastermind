#include <cstdlib>

#include <iomanip>

#include <iostream>

using namespace std;

int main(int argc, char ** argv) {

    int guess1, guess2, guess3, guess4, rcrp, rcwp, option,
            rightColorRightPlace, rightColorWrongPlace, numberOfSlots,
            masterCodeInt, blackPegs, whitePegs;

    bool gameOver = false;

    cout << "Welcome to Mastermind.\n";
    cout << "1. Easy (4 Slots)\n"
            "2. Medium (6 Slots)\n"
            "3. Hard (8 Slots)\n"
            "Choose an Option. (1-3): ";

    cin >> option;

    switch (option) {
        case 1:
            numberOfSlots = 4;
            break;
        case 2:
            numberOfSlots = 6;
            break;
        case 3:
            numberOfSlots = 8;
            break;
    }

    //Create Arrays for the master code and player guesses based on difficulty
    int masterCode[numberOfSlots], playerGuess[numberOfSlots];

    cout << "\nDifficulty set. NOTE: Colors have a number representation.\n\n"
            "1. Red\n"
            "2. Green\n"
            "3. Blue\n"
            "4. Yellow\n"
            "5. Brown\n"
            "6. Orange\n"
            "7. Black\n"
            "8. White\n\n";

    cout << "Player 2: (CodeMaker) Enter an as a color representation of "
            "the Master Code.\n";

    for (int i = 0; i < numberOfSlots; i++) {

        cout << "Slot# " << i + 1 << endl;
        cin >> masterCode[i];
    }

    while (blackPegs != numberOfSlots) {

        cout << "Player 1: (CodeBreaker) Enter a number as a color "
                "representation for the corresponding slot.\n";

        for (int i = 0; i < numberOfSlots; i++) {

            cout << "Slot# " << i + 1 << endl;
            cin >> playerGuess[i];
        }

        //Determine number of correct colors in the correct spot

        for (int i = 0; i < numberOfSlots; i++) {
            if (playerGuess[i] == masterCode[i]) {
                blackPegs++;
            }
        }

        cout << "Black Pegs: " << blackPegs << endl;

        //Determine number of correct colors in the incorrect spot
        //How many elements in the players guess are found in the master code

        for (int i = 0; i < numberOfSlots; i++) {

            for (int j = 0; j < numberOfSlots; j++) {

                if (playerGuess[i] == masterCode[j]) {

                    whitePegs++;

                }

            }

        }

        whitePegs = whitePegs - blackPegs;

        cout << "White Pegs: " << whitePegs << endl;


        whitePegs = 0; // reset white pegs for next guess

        //Test Win Condition
        if (blackPegs == numberOfSlots) {
            cout << "You Win! ";
            return 0;

        } else

            blackPegs = 0; //reset pegs for next guess
    }

    return 0;
}