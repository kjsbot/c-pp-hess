#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include<vector>
#include "square.hpp"
#include "piece.hpp"

using namespace std;

class Board {
	
  public:
		Board();
		~Board();

		Square board[8][8];

		struct coordinate {
			int y;
			int x;
		};

		int currentSide {-1}; // -1 = white, 1 = black

		void display();
		void newGame();
		void inputToCoor(string input);

		bool validateInput(string input, int color);
		bool pseudoMovesChecker(string input);
		bool legalMovesChecker(string input, int color);
		
		bool isCheck();
		bool isCheckmate();
		bool isStalemate();

	private:
		Square* getPiece();

		void movePiece(string input);
		coordinate targetPos {0, 0};
		coordinate currentPos {0, 0};

		vector<vector<int>> opponentMoves(); // checking for stalemate, checkmate

		vector<vector<int>> diagonalMovement(int pieceColor);
		vector<vector<int>> updownMovement(int pieceColor);
		vector<vector<int>> kingLogic(int pieceColor);
		vector<vector<int>> pawnLogic(int pieceColor);
		vector<vector<int>> knightLogic(int pieceColor);

		bool enPassant();
		bool canCastle();
};

#endif

/*
int board[8][8] = 
	{ {0, 1, 2, 3, 4, 5, 6, 7}, // Black
	  {0, 1, 2, 3, 4, 5, 6, 7},
	  {0, 1, 2, K, 4, 5, 6, 7},
	  {0, 1, 2, 3, 4, 5, 6, 7},
	  {0, 1, 2, 3, 4, 5, 6, 7},
	  {0, 1, 2, 3, 4, 5, 6, 7},
	  {0, 1, 2, 3, 4, 5, 6, 7},
	  {0, 1, 2, 3, 4, 5, 6, 7} } // R K B Q KING B K R
	};
*/
