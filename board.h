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

		int currentSide {1}; // 1 = white, -1 = black

		void display();
		void newGame();

		bool validateInput(string input, int color);
		void inputToCoor(string input);
		//string coorToString(coordinate output);
		
		bool isCheck();
		bool isCheckmate();
		bool isStalemate();

	private:
		Square* getPiece();

		void movePiece(coordinate currentPos, coordinate targetPos);
		coordinate targetPos {0, 0};
		coordinate currentPos {0, 0};

		vector<vector<int>> legalMoves();
		vector<vector<int>> opponentMoves();

		//<vector<vector<int>> diagonalMovement();
		//<vector<vector<int>> updownMovement();
		vector<int> knightLogic(string curPos, int pieceColor);
		//<vector<vector<int>> pawnLogic();

		//bool enPassant();
		//bool canCastle();
};

#endif
