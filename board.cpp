#include "board.hpp"

using namespace std;

Board::Board() {
	for (int p=0; p < 8; p++) {
		board[6][p].setPiece(new Piece("WP", 1, {6, p})); // white pawns
		board[1][p].setPiece(new Piece("BP", -1, {1, p})); // black pawns
	}

	// WHTIE PIECES:
		board[7][3].setPiece(new Piece("WQ", 1, {7, 3})); // queen
		board[7][4].setPiece(new Piece("WK", 1, {7, 4})); // king
		board[7][2].setPiece(new Piece("WB", 1, {7, 2})); // bishop
		board[7][5].setPiece(new Piece("WB", 1, {7, 5})); // bishop
		board[7][0].setPiece(new Piece("WR", 1, {7, 0})); // rook
		board[7][7].setPiece(new Piece("WR", 1, {7, 7})); // rook
		board[7][1].setPiece(new Piece("WN", 1, {7, 1})); // knight
		board[7][6].setPiece(new Piece("WN", 1, {7, 6})); // knight

	// BLACK PIECES:	
		board[0][3].setPiece(new Piece("BQ", -1, {0, 3})); // queen
		board[0][4].setPiece(new Piece("BK", -1, {0, 4})); // king
		board[0][2].setPiece(new Piece("BB", -1, {0, 2})); // bishop
		board[0][5].setPiece(new Piece("BB", -1, {0, 5})); // bishop
		board[0][0].setPiece(new Piece("BR", -1, {0, 0})); // rook
		board[0][7].setPiece(new Piece("BR", -1, {0, 7})); // rook
		board[0][1].setPiece(new Piece("BN", -1, {0, 1})); // knight
		board[0][6].setPiece(new Piece("BN", -1, {0, 6})); // knight
}

Board::~Board() { }

// Square* Board::getPiece() { };

//void Board::movePiece(coordinate currentPos, coordinate targetPos) {
//	board[currentPos.y][currentPos.x].piece.
//	board[targetPos.y][targetPos.x].piece = board[currentPos.y][currentPos.x].piece;
//	board[currentPos.y][currentPos.x] = nullptr;
//}

void Board::inputToCoor(string input) {
	string targetposX = input.substr(2, 1);
	string currentposX = input.substr(0, 1);
	
	currentPos.y = 8 - stoi(input.substr(1, 2));
	targetPos.y = 8 - stoi(input.substr(3, 4));

	if (currentposX == "a") {
		currentPos.x = 0;
	} else if (currentposX == "b") {
		currentPos.x = 1;
	} else if (currentposX == "c") {
		currentPos.x = 2;
	} else if (currentposX == "d") {
		currentPos.x = 3;
	} else if (currentposX == "e") {
		currentPos.x = 4;
	} else if (currentposX == "f") {
		currentPos.x = 5;
	} else if (currentposX == "g") {
		currentPos.x = 6;
	} else { currentPos.x = 7; }

	if (targetposX == "a") {
		targetPos.x = 0;
	} else if (targetposX == "b") {
		targetPos.x = 1;
	} else if (targetposX == "c") {
		targetPos.x = 2;
	} else if (targetposX == "d") {
		targetPos.x = 3;
	} else if (targetposX == "e") {
		targetPos.x = 4;
	} else if (targetposX == "f") {
		targetPos.x = 5;
	} else if (targetposX == "g") {
		targetPos.x = 6;
	} else { targetPos.x = 7; }
}

bool Board::validateInput(string input, int color) {
	inputToCoor(input);

	Piece* currentPiece = board[currentPos.y][currentPos.x].piece;
	Piece* targetPiece = board[targetPos.y][targetPos.x].piece;

	if (currentPiece == nullptr) {
		cout << "There's no piece at this location!" << endl << endl;
		return false;
	} else if ((*currentPiece).pieceColor != currentSide) {
		cout << "This isn't your piece!" << endl << endl;
		return false;
	} else if (targetPiece != nullptr && (*targetPiece).pieceColor == currentSide) {
		cout << "Your own piece is occupying this location!" << endl << endl;
		return false;
	} else {
		return true;
	}
}

void Board::display() {
	cout << "       Player 2 (Black)" << endl << endl;
	for (int i=0; i < 8; i++) {
		cout << 8 - i << " ｜";
		for (int j=0; j < 8; j++) {
			Piece* currPiece = board[i][j].getPiece();

			if (currPiece == nullptr) {
				cout << " · ";
			} else if ((*currPiece).name == "WQ") {
				cout << " ♛ ";
			} else if ((*currPiece).name == "WK") {
				cout << " ♚ ";
			} else if ((*currPiece).name == "WB") {
				cout << " ♝ ";
			} else if ((*currPiece).name == "WR") {
				cout << " ♜ ";
			} else if ((*currPiece).name == "WN") {
				cout << " ♞ ";
			} else if ((*currPiece).name == "WP") {
				cout << " ♟ ";
			} else if ((*currPiece).name == "BQ") {
				cout << " ♕ ";
			} else if ((*currPiece).name == "BK") {
				cout << " ♔ ";
			} else if ((*currPiece).name == "BB") {
				cout << " ♗ ";
			} else if ((*currPiece).name == "BR") {
				cout << " ♖ ";
			} else if ((*currPiece).name == "BN") {
				cout << " ♘ ";
			} else if ((*currPiece).name == "BP") {
				cout << " ♙ ";
			}
		}
		cout << endl;
	}
	cout << "――――――――――――――――――――――――――――" << endl;
	cout << "     a  b  c  d  e  f  g  h" << endl << endl;
	cout << "       Player 1 (White)" << endl << endl;
}

// CHECK FOR LEGAL MOVES!!
vector<int> Board::knightLogic(string curPos, int pieceColor) {
	inputToCoor(curPos);

	int y = currentPos.y;
	int x = currentPos.x;
	
	vector<vector<int>> legalMoves;

	vector<coordinate> knightOffsets = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0},                                      {-1, 0}, {0, 1}, {0, -1}, {0, 2}, {0, -2}};

    int color = 1; // white
    int currentPos[2] = {1, 1};

    for (int i=0; i<10; i++ ) {
		if ( y+knightOffsets.at(i).y > 8 || y+knightOffsets.at(i).y < 0 || x+knightOffsets.at(i).x > 8 || x+knightOffsets.at(i).x < 0) {
			continue;
		} else if (true) {
			// check if the value will be a piece of its own color

		} else {
			cout << "hi";
		}


    }
    //return legalMoves;
}
