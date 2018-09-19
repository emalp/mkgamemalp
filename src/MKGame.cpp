// MKGame.cpp : Defines the entry point for the console application.
//

#include<iostream>

#include "Headers/Player.h"
#include "Headers/ComputerPlayer.h"
#include "Headers/HumanPlayer.h"
#include "Headers/Board.h"
#include "Headers/MKGame.h"
//#include "Driver.cpp"

using namespace std;

MKGame::MKGame(){

	players[0] = new ComputerPlayer;
	players[1] = new HumanPlayer;
	setPlayerColors();
	normalPlay();
}

void MKGame::setPlayerColors(){
	cout << endl;
	int humanColor;

	while(humanColor != 1 && humanColor != 1){
		cout << "Which color would you like to play as, black or white? (1 = black, -1 = white): " << endl;
		cin >> humanColor;
	}
	
	players[1]->setColor(humanColor);
	if(humanColor == 1){
		players[0]->setColor(-1);
	} else {
		players[0]->setColor(1);
	}
}

void MKGame::normalPlay(){
	int *move;
	int turn = 1; // initially human's turn.

	while(true){
		move = players[turn]->play(board);
		if(board.isMoveValid(move)){
				// place the color, i.e -1 or 1 in the place.
				board.addPoint(move, players[turn]->color);
				board.displayBoard();
				// and then, now check if the current placement wins.
				if(board.haveIWon(move)){
					cout << (players[turn]->color == 1 ? "Black player" : "White Player")  << " wins!" << endl;
					gameCompleted();
					break;
				} else {
					// now check if the board is full.
					if(board.isFull()){
						cout << "The board is full and no players won. It's a draw." << endl;
						gameCompleted();
						break;
					} else {
						cout << "Opponent's turn." << endl;
						if(turn == 1){
							turn = 0;
						} else {
							turn = 1;
						}
					}
				}
			} else {
				cout << "Your current move is invalid, please look at the board and select the empty spots." << endl;
			}

	}
}


void MKGame::gameCompleted(){
	cout << "The m,k game has been completed." << endl;
	cout << "Thanks for playing 19485485 m,k game." << endl;
}
