#ifndef BOARD_H
#define BOARD_H

class Board{

public:
	int m, k;
	int **boardState;

	Board();

	~Board();

	void createInitialBoardState();

	bool haveIWon(int* move);

	bool isFull();

	bool isMoveValid(int *move);

	void addPoint(int *place, int color);

	void displayBoard();
};

#endif
