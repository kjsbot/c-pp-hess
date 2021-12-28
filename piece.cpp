#include "piece.hpp"

Piece::Piece(string identifier, int color, vector<int> position) {
	
	name = identifier;
	pieceColor = color;
	currentPosition.y = position[0];
	currentPosition.x = position[1];

	if (identifier == "WQ" || identifier == "BQ") { // QUEEN
		value = 9;
		directions.insert(directions.end(), 
		{{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}});

	} else if (identifier == "WK" || identifier == "BK") { // KING
		value = 100;
		directions.insert(directions.end(), {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
		  {0, 2}, {0, -2}});  // last 2 are for castling

	} else if (identifier == "WB" || identifier == "BB") { // BISHOP
		value = 3;
		directions.insert(directions.end(), {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, 
		  {0, -2}, {0, 3}});  // last 2 are for castling

	} else if (identifier == "WN" || identifier == "BN") { // KNIGHT
		value = 3;
		directions.insert(directions.end(), {{-2, -1}, {-2, 1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}});

	} else if (identifier == "WR" || identifier == "BR") { //ROOK
		value = 5;
		directions.insert(directions.end(), {{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

	} else if (identifier == "WP") { // WHITE PAWN
		value = 1;
		directions.insert(directions.end(), {{1, 0}, {1, 1}, {1, -1}});

	} else if (identifier == "BP") { // BLACK PAWN
		value = 1;
		directions.insert(directions.end(), {{-1, 0}, {-1, 1}, {-1, -1}});
	}
}
