#include "board.hpp"

using namespace std;

Board::Board() {
	for (int p=0; p < 8; p++) {
		board[6][p].setPiece(new Piece("WP", -1, {6, p})); // white pawns
		board[1][p].setPiece(new Piece("BP", 1, {1, p})); // black pawns
	}

	// WHTIE PIECES:
		board[7][3].setPiece(new Piece("WQ", -1, {7, 3})); // queen
		board[7][4].setPiece(new Piece("WK", -1, {7, 4})); // king
		board[7][2].setPiece(new Piece("WB", -1, {7, 2})); // bishop
		board[7][5].setPiece(new Piece("WB", -1, {7, 5})); // bishop
		board[7][0].setPiece(new Piece("WR", -1, {7, 0})); // rook
		board[7][7].setPiece(new Piece("WR", -1, {7, 7})); // rook
		board[7][1].setPiece(new Piece("WN", -1, {7, 1})); // knight
		board[7][6].setPiece(new Piece("WN", -1, {7, 6})); // knight

	// BLACK PIECES:	
		board[0][3].setPiece(new Piece("BQ", 1, {0, 3})); // queen
		board[0][4].setPiece(new Piece("BK", 1, {0, 4})); // king
		board[0][2].setPiece(new Piece("BB", 1, {0, 2})); // bishop
		board[0][5].setPiece(new Piece("BB", 1, {0, 5})); // bishop
		board[0][0].setPiece(new Piece("BR", 1, {0, 0})); // rook
		board[0][7].setPiece(new Piece("BR", 1, {0, 7})); // rook
		board[0][1].setPiece(new Piece("BN", 1, {0, 1})); // knight
		board[0][6].setPiece(new Piece("BN", 1, {0, 6})); // knight
}

Board::~Board() { }
/*
// coordinate currentPos, coordinate targetPos
void Board::movePiece(string input) {

	inputToCoor(input);
	Piece* movingPiece = board[targetPos.y][targetPos.x].piece;

	// If targetPos has a piece on it, destroy that piece
	if (board[targetPos.y][targetPos.x].piece != nullptr) {
		delete board[targetPos.y][targetPos.x].piece;
		board[targetPos.y][targetPos.x].piece = nullptr;
	}

	// Update the position of the piece you're moving
	(*movingPiece).currentPosition.y = targetPos.y;
	(*movingPiece).currentPosition.x = targetPos.x;
	board[targetPos.y][targetPos.x].piece = board[currentPos.y][currentPos.x].piece;
	
	// Set old position to Null
	board[currentPos.y][currentPos.x].piece = nullptr;
}
*/
void Board::inputToCoor(string input) {
	string targetposX = input.substr(2, 1);
	string currentposX = input.substr(0, 1);
	currentPos.y = 8 - stoi(input.substr(1, 2));
	targetPos.y = 8 - stoi(input.substr(3, 4));

	if (currentposX == "a") { currentPos.x = 0; } 
	else if (currentposX == "b") { currentPos.x = 1; } 
	else if (currentposX == "c") { currentPos.x = 2; } 
	else if (currentposX == "d") { currentPos.x = 3; } 
	else if (currentposX == "e") { currentPos.x = 4; } 
	else if (currentposX == "f") { currentPos.x = 5; } 
	else if (currentposX == "g") { currentPos.x = 6; } 
	else { currentPos.x = 7; }

	if (targetposX == "a") { targetPos.x = 0; } 
	else if (targetposX == "b") { targetPos.x = 1; } 
	else if (targetposX == "c") { targetPos.x = 2; } 
	else if (targetposX == "d") { targetPos.x = 3; } 
	else if (targetposX == "e") { targetPos.x = 4; } 
	else if (targetposX == "f") { targetPos.x = 5; } 
	else if (targetposX == "g") { targetPos.x = 6; } 
	else { targetPos.x = 7; }
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
			Piece* currPiece = board[i][j].getPiece(); // memory of piece at Square

			if (currPiece == nullptr) { cout << " · "; } 
			else if ((*currPiece).name == "WQ") { cout << " ♛ "; } 
			else if ((*currPiece).name == "WK") { cout << " ♚ "; } 
			else if ((*currPiece).name == "WB") { cout << " ♝ "; } 
			else if ((*currPiece).name == "WR") { cout << " ♜ "; } 
			else if ((*currPiece).name == "WN") { cout << " ♞ "; } 
			else if ((*currPiece).name == "WP") { cout << " ♟ "; } 
			else if ((*currPiece).name == "BQ") { cout << " ♕ "; } 
			else if ((*currPiece).name == "BK") { cout << " ♔ "; } 
			else if ((*currPiece).name == "BB") { cout << " ♗ "; } 
			else if ((*currPiece).name == "BR") { cout << " ♖ "; } 
			else if ((*currPiece).name == "BN") { cout << " ♘ "; } 
			else if ((*currPiece).name == "BP") { cout << " ♙ "; }
		}
		cout << endl;
	}
	cout << "――――――――――――――――――――――――――――" << endl;
	cout << "     a  b  c  d  e  f  g  h" << endl << endl;
	cout << "       Player 1 (White)" << endl << endl;
}

// MAKE VECTOR OF ALL PSEUDO LEGAL MOVES
bool Board::pseudoMovesChecker(string input) {
	inputToCoor(input);
	Piece* currPiece = board[currentPos.y][currentPos.x].getPiece();

	if ((*currPiece).name == "WQ") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "WK") {
		return true; // return result of validating moves on piece at currentlocation
		
	} else if ((*currPiece).name == "WB") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "WR") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "WN") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "WP") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "BQ") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "BK") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "BB") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "BR") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "BN") {
		return true; // return result of validating moves on piece at currentlocation

	} else if ((*currPiece).name == "BP") {
		return true; // return result of validating moves on piece at currentlocation
	}
	return false;
}

vector<vector<int>> Board::updownMovement(int pieceColor) {
	vector<vector<int>> legalMoves;
	vector<coordinate> updownOffsets = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	for (int i=0; i<5; i++) {
		for (int j=1; j<8; j++) {
			int yVal = currentPos.y + j * updownOffsets.at(i).y;
			int xVal = currentPos.x + j * updownOffsets.at(i).x;

			if ( yVal > 8 || yVal < 0 || xVal > 8 || xVal < 0 ) {
				continue;
			} else if (pieceColor == (*board[yVal][xVal].piece).pieceColor) {
				continue;
			} else {
				legalMoves.push_back( {yVal, xVal} );
			}
		}
	}
    return legalMoves;
}

vector<vector<int>> Board::diagonalMovement(int pieceColor) {
	vector<vector<int>> legalMoves;
	vector<coordinate> diagonalOffsets = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

	for (int i=0; i<5; i++) {
		for (int j=1; j<8; j++) {
			int yVal = currentPos.y + j * diagonalOffsets.at(i).y;
			int xVal = currentPos.x + j * diagonalOffsets.at(i).x;
			
			if ( yVal > 8 || yVal < 0 || xVal > 8 || xVal < 0 ) {
				continue;
			} else if (pieceColor == (*board[yVal][xVal].piece).pieceColor) {
				continue;
			} else {
				legalMoves.push_back( {yVal, xVal} );
			}
		}
	}
    return legalMoves;
}

vector<vector<int>> Board::kingLogic(int pieceColor) {
	vector<vector<int>> legalMoves;
	vector<coordinate> kingOffsets = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i=0; i<10; i++ ) {
		int yVal = currentPos.y + kingOffsets.at(i).y;
		int xVal = currentPos.x + kingOffsets.at(i).x;

		if ( yVal > 8 || yVal < 0 || xVal > 8 || xVal < 0 ) {
			continue;
		} else if (pieceColor == (*board[yVal][xVal].piece).pieceColor) {
			continue;
		} else {
			legalMoves.push_back( {yVal, xVal} );
		}
    }
    return legalMoves;
}

vector<vector<int>> Board::knightLogic(int pieceColor) {
	vector<vector<int>> legalMoves;
	vector<coordinate> knightOffsets = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 2}, {0, -2}};

    for (int i=0; i<10; i++ ) {
		int yVal = currentPos.y + knightOffsets.at(i).y;
		int xVal = currentPos.x + knightOffsets.at(i).x;

		if ( yVal > 8 || yVal < 0 || xVal > 8 || xVal < 0 ) {
			continue;
		} else if (pieceColor == (*board[yVal][xVal].piece).pieceColor) {
			continue;
		} else {
			legalMoves.push_back( {yVal, xVal} );
		}
    }
    return legalMoves;
}

vector<vector<int>> Board::pawnLogic(int pieceColor) {
	int y = currentPos.y;
	int x = currentPos.x;
	vector<vector<int>> legalMoves;

	vector<coordinate> blackPawnOffsets = {{1, 0}, {1, -1}, {1, 1}}; // multiply by pieceColor

	// First move

	// Moving
	int moveUp = pieceColor * blackPawnOffsets.at(0).y;

	if (board[moveUp][currentPos.x].getPiece() == nullptr) {
		legalMoves.push_back( {currentPos.y + moveUp, currentPos.x} );
	}

	// Capturing diagonally
	int moveRight = pieceColor * blackPawnOffsets.at(1).x;
	int moveLeft = pieceColor * blackPawnOffsets.at(2).x;

	if ( true ) { // Opponent piece exists on left diagonal
		legalMoves.push_back( {currentPos.y + moveUp, currentPos.x + moveLeft} );
	} else if (true) { // Opponent piece exists on right diagonal
		legalMoves.push_back( {currentPos.y + moveUp, currentPos.x + moveRight} );
	}

	// first move can either move up one or two times


    // en passent
      // capturing pawn: exactly at rank/row 5
      // captured pawn: in the first move have moved -16 (2 squares up)
      // must be performed exactly after the captured pawn moves
      // so they must both be at row 5 and be next to each other (+1 or -1 offsets)

	return legalMoves;
}
