#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "./Player.h"


class HumanPlayer: public Player{

public:
	//int color;

	int* play(Board &board);

	void setColor(int col);

};

#endif
