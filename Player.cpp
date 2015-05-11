#include "stdafx.h"
#include <iostream>



class Player
{
	Color color;
	Game game;

public:
	int getScore(){
	
		return game.getInstance().getBoard().getScoreForColor;
	}

	bool play(int row, int column) {
		return game.getInstance().getBoard().placeColor;
	}

	Player() { }

	Player(Color c) 
	{
			color = c;
	}

	Color getColor() {
		return color;
	}
};


