#ifndef PIECE_H
#define PIECE_H
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Piece {
  	public:
	  Piece(string identifier, int color, vector<int> position);
	  ~Piece();

	  string name;
	  int pieceColor; // 1 = WHITE, -1 = BLACK

		struct coordinate {
			int y;
			int x;
		};

    	int value {0}; // for the computer opponent

    	coordinate currentPosition = {0, 0};
		
    	vector<coordinate> directions;
		void assignValues();
};

#endif
