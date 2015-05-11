// Reversi_game_KaranThakker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{

	Game game_main;
	game_main.getInstance();
	game_main.getBoard().initialize();
//	game_main.getBoard().printBoard();
	

	while (!game_main.isOver)
	{
		game_main.getBoard().updateScore;
	}

	game_main.getBoard().printBoard;
	/*
	   Add UI for testing
	*/
	
}

enum class Color
{
	black, white
};


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


enum class Directions
{
	top, bottom, right, left
};

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

// Class for all the activities happening on the board
class Board
{
	int black_score = 0;
	int white_score = 0;
    Disk *board;
	
public:
	Board() { }
	
	bool placeColor(int row, int column, Color color) {
			if ( &board[row * column + column] != NULL) {
				return false;
			}

			int *results = new int[4];
			int *results_end = results + sizeof(&results) / sizeof(int);
			results[0] = flipSection(row - 1, column, color, Directions::top);
			results[1] = flipSection(row + 1, column, color, Directions::bottom);
			results[2] = flipSection(row, column + 1, color, Directions::right);
			results[3] = flipSection(row, column - 1, color, Directions::left);

			/* compute how many pieces were flipped */
			int flipped = 0;
			for (int *i = results; i!= results_end; i++) {
				if (&results > 0) {
					flipped = flipped + *results;
				}
			}

			/* if nothing was flipped, then it's an invalid move */
			if (flipped < 0) {
				return false;
			}

			/* flip the piece, and update the score */
			 board[row * column + column] = Disk(color);
			updateScore(color, flipped + 1);
			return true;
	}

	Board(int row, int column) {

		// 64 blocks, 8*8 array
				Disk*board = new Disk[64];
			};

	void initialize() {

		// Since 8*8 is the size of the board
		int middleRow = 4;
		int middleColumn = 4;

		// setting the positions

		board[middleRow * middleColumn + middleColumn] = Disk(Color::white);
		board[(middleRow + 1) * middleColumn] = Disk(Color::black);
		board[(middleRow + 1) * (middleColumn + 1)] = Disk(Color::white);
		board[middleRow * (middleColumn + 1)] = Disk(Color::black);

		// score is two each when the boards is initialized

		black_score = 2;
		white_score = 2;

	}
	int getScoreForColor(Color c) {
			if (c == Color::black) {
				return black_score;
			}
			else {
				return white_score;
			}
		}
	
	void updateScore(Color newColor, int newPieces) {
		// With every +1 of one color, there is -1 for other color
			if (newColor == Color::black) {
				white_score -= newPieces - 1;
				black_score += newPieces;
			}
			else {
				black_score -= newPieces - 1;
				white_score += newPieces;
			}
	}

	void printBoard() {
		for (int r = 0; r < 8; r++) {
			for (int c = 0; c < 8; c++) {
				if (&board[r * c + c] == NULL) {
					std::cout << "_";
				}
				else if (board[r * c + c].getColor() == Color::white) {
					std::cout << "W";
				}
				else {
					std::cout << "B";
				}
			}
			std::cout << "";
		}
	}

private:
		int flipSection(int row, int column, Color color, Directions d) {
			// Compute the delta for the row and the column. At all times, only the row or the column
			//			will have a delta, since we're only moving in one direction at a time.

			int r = 0;
			int c = 0;
			switch (d) {
			case Directions::top:
				r = -1;
				break;
			case Directions::bottom:
				r = 1;
				break;
			case Directions::right:
				c = -1;
				break;
			case Directions::left:
				c = 1;
				break;
			}

			// If out of bounds, return an error (-1) 
			if (row < 0 || row >= 8 || column < 0 || column >= 8) {
				return -1;
			}

			// Found same color - no flipping
			if (board[row * column + column].getColor() == color) {
				return 0;
			}

			// Recursively flip the rest. If -1 is returned, then we know we hit the boundary
			//	so there's nothing to flip. 

			int flipped = flipSection(row + r, column + c, color, d);
			if (flipped < 0) {
				return -1;
			}

			// flip color 
			board[row * column + column].flip();
			return flipped + 1;
		}

};

class Disk
{
	Color color;
public:
	Disk(){ }
	Disk(Color c)
	{
		color = c;
	};

public: void flip() {
	if (color == Color::black) {
		color = Color::white;
	}
	else {
		color = Color::black;
	}
}
	Color getColor() {
		return color;
	};

};

