#include "stdafx.h"
#include <iostream>


// Class for handling the entire game events
// Usually interacts a lot with Board class to get the updates
class Game
{
	Player players;
	Board board;
	Color color;
	int rows = 8;
	int columns = 8;
public:

	static Game instance ;

	
	static Game getInstance() {
	return instance;

	}
	
	Board getBoard() {
		return board;
	}


	Game(){
		Board *board = new Board(rows, columns);
		Player *players = new Player[2];

		// black and white players
		players[0] =  Player(Color::black);
		players[1] =  Player(Color::white);

	
	}

		bool isOver() {
		if ( players.getScore() == 0 || (Player(Color::black).getScore + Player(Color::white).getScore) == 64) {
			return true;
		}
		return false;
	}

};

