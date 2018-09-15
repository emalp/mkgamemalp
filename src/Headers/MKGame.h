#ifndef MKGAME_H
#define MKGAME_H

//#include "Board.h"
//#include "../src/Player.cpp"
#include "Board.h"
#include "Player.h"


class MKGame{
public:
	Board board;
	Player *players[2];

	MKGame();

	void setPlayerColors();

	void normalPlay();

	void gameCompleted();

};


#endif
