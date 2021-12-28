#include "square.hpp"

Square::Square() {
	piece = nullptr;
}

Square::~Square() { };

Piece* Square::getPiece() {
	return piece;
}

void Square::setPiece(Piece *newPiece) {
	this->piece = newPiece;
}
