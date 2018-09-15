#include<iostream>
#include "Headers/Player.h"
#include "Headers/HumanPlayer.h"

using namespace std;

//int color;

int* HumanPlayer::play(Board &board){

	int *move = new int[2];
	cout << "Please enter the row, column where you'd like to place your dot: [x y]" << endl;
	cin >> move[0] >> move[1];

	return move;
}

void HumanPlayer::setColor(int col){
	color = col;
}

//class HumanPlayer:public Player {
//public:
//	int color;
//
//	int* play(){
//
//		int *move = new int[2];
//		cout << "Please enter the row, column where you'd like to place your dot: [x y]" << endl;
//		cin >> move[0] >> move[1];
//
//		return move;
//
//	}
//
//	void setColor(int col){
//		color = col;
//	}
//
//};
