#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "./Player.h"
#include "./Board.h"

class ComputerPlayer: public Player {
public:
	int i;
	//int color;
	int* play(Board &board);

	void setColor(int col);

private:
	int *randomize(int size);

};

#endif
