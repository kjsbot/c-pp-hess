#ifndef SQUARE_H
#define SQUARE_H
#include "piece.hpp"

class Square {
	public:
		Square();
		~Square();
		Piece* piece; // points to memory address of a piece
		Piece* getPiece();
		void setPiece(Piece *newPiece);
};

#endif
