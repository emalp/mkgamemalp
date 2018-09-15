#include<cstdlib>

#include "Headers/Player.h"
#include "Headers/Board.h"
#include "Headers/ComputerPlayer.h"


#include "AI.cpp"


int* ComputerPlayer::play(Board &board){
		i++;
		int size = board.m;
		int *move;

		// ai player
//		AI ai(board, color);
//		move = ai.play();



		// random player.
		for(; ;){
			move = randomize(size);

			if(board.boardState[move[0]-1][move[1]-1] == 0) {
				break;
			} else {
				continue;
			}
		}

		return move;
}

int* ComputerPlayer::randomize(int size){
	int *randomBox = new int[2];
	int row = (rand() % (size-1)) + 1;
	int column = (rand() % (size-1)) +1;

	randomBox[0] = row;
	randomBox[1] = column;

	return randomBox;
}

void ComputerPlayer::setColor(int col){
	color = col;
}

//class ComputerPlayer:public Player {
//public:
//	int color;
//	//int **boardCurrentState, int m, int k
//
//	int* play(Board &board){
//		int size = board.m;
//		//int winCondition = k;
//		int *move;
//		// currently generate just random places to put the dots.
//
//		//AI ai(boardCurrentState,m ,k, color);
//		//move = ai.play();
//
//		for(; ;){
//			move = randomize(size);
//
//			if(board.boardState[move[0]-1][move[1]-1] == 0) {
//				break;
//			} else {
//				continue;
//			}
//		}
//
//		return move;
//	}
//
//
//	void setColor(int col){
//		color = col;
//	}
//
//private:
//	int* randomize(int size){
//		int *randomBox = new int[2];
//		int row = (rand() % (size-1)) + 1;
//		int column = (rand() % (size-1)) +1;
//
//		randomBox[0] = row;
//		randomBox[1] = column;
//
//		return randomBox;
//	}
//};
