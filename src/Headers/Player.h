#ifndef PLAYER_H
#define PLAYER_H

#include "./Board.h"

class Player{

public:

	int color;

	//virtual int* play() = 0;

	virtual int *play(Board &board) = 0;

	void setColor(int color);

};


#endif
