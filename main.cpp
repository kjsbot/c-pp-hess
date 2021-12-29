#include <iostream>
#include <string>
#include <vector>
#include "board.hpp"
#include "piece.hpp"

using namespace std;

void player_player();
void player_computer();
void print_board();
void input_validation();

Board board;

int main() {
    int mode {0};
	int diffculty {0};
	string current_pos {""};
    string target_pos {""};

    cout << "\nWelcome to command line Chess!\n\n";

	cout << "Before starting, make sure the background of the console is dark, otherwise the colors will be inverted" << endl << endl << "To move, type the position of the desired piece followed by the coordinate of the target location (ex. b2c3, f4d4)";
	
	cout<< endl << endl << "Press [D] to draw, [R] to restart, or [Q] to quit at any time." << endl << endl << "Select your game mode:\n [0] Player vs. Player\n [1] Player vs. Computer" << endl;

	//cin >> mode;

    if (mode == 0) {
		cout << endl << endl << "You chose PvP: Player 1 is white and player 2 is black. Have fun!" << endl << endl;
      	player_player();
    } else {
		cout << endl << endl << "You chose PvC: Select the diffculty of your computer opponent:" << endl << "[1] Easy" << endl << "[2] Medium" << endl << "[3] Hard" << endl;
		cout << endl << "You chose hard mode. " << "Have fun!" << endl << endl;
    	player_computer();
    }
    return 0;
}

bool input_parser(string input) {
    if (input.length() != 4) {
        cout << "Invalid input! Make sure your input is in the form \"b5c7\"" << endl;
		return false;
    } else if ((int(tolower(input.at(0))) < 97 || int(tolower(input.at(0))) > 104) || (int(tolower(input.at(2))) < 97 || int(tolower(input.at(2))) > 104)) {
        cout << "Invalid input! Make sure you're entering a character between a and h, inclusive" << endl;
		return false;
    } else if (!isdigit(input.at(1)) || !isdigit(input.at(3))) {
        cout << "Invalid input! Make sure you input a number and that your input is in the form \"b5c7\"!" << endl;
		return false;
    } else if (int(input.at(1)) > 56 || int(input.at(1)) < 48 || int(input.at(3)) > 56 || int(input.at(3)) < 48) {
        cout << "Invalid input! Make sure your numeric values are between 0 and 8!" << endl;
		return false;
    } else {
		return true;
	}
}

void player_player() {
	
	Board board;
	string input;

	//while (true) {
		board.display();

		//if (board.isCheckmate()) { get current side }
		//if (board.isStalemate()) { get current side }
		
		if (board.currentSide == -1) {
			while (true) {
				cout << "WHTIE's move: ";
				cin >> input;
				if (input == "Q" || input == "q") { break; }
				
				// Input string checker, Basic input checker, Pseudo Legal move checker
				if (input_parser(input) && board.validateInput(input, board.currentSide) && board.pseudoMovesChecker(input)) {
					cout << "move success!";
					break; 
				}
				// Legal moves checker
			}
			//board.movePiece();
			board.currentSide = 1;

		} else {
			while (true) {
				cout << "BLACK's move: ";
				cin >> input;
				if (input == "Q" || input == "q") { break; }

				// Input string checker, Basic input checker, Pseudo Legal move checker
				if (input_parser(input) && board.validateInput(input, board.currentSide) && board.pseudoMovesChecker(input)) {
					break; 
				}
				// Legal moves checker
			}
			//board.movePiece();
			board.currentSide = -1;
		}
	//if (input == "Q" || input == "q") { break; }
	//}

}

void player_computer() {
  cout << "sike";
}
