
#include<iostream>
#include "Headers/Board.h"

using namespace std;

Board::Board(): m(0), k(0)  {
	while(!m || m<2){
		cout << "\nPlease enter the size of the board (m) you want to play with: [size]\n" << endl;
		cin >> m;
	}


	while(!k || k<1 || k>m){
		cout << "Please enter a winning [k] continuous condition less than the size of the board:" << endl;
		cin >> k;
	}

	cout << endl;

	Board::createInitialBoardState();

	cout << "Current board state: " << endl;
	Board::displayBoard();
}

Board::~Board() {
	for(int x=0; x<=m; x++){
		delete[] boardState[x];
	}

	delete[] boardState;
}

void Board::createInitialBoardState(){
	boardState = new int *[m];
	for (int sizeOfBoard = 0; sizeOfBoard < m; sizeOfBoard++) {
		boardState[sizeOfBoard] = new int[m];
	}

	//fill the board with 0s
	for (int boardRow = 0; boardRow < m; boardRow++) {
		for (int boardColumn = 0; boardColumn < m; boardColumn++) {
			boardState[boardRow][boardColumn] = 0;
		}
	}
}

bool Board::haveIWon(int *move){
			int nulVal = 0;
			int *previousState = &nulVal;

			// check row.
			//cout << "Checking horizontal" << endl;
			int columnCounter = 1;
			for(int column=0; column<m; column++){
				if(boardState[move[0]-1][column] == *previousState && (boardState[move[0]-1][column] == -1 || boardState[move[0]-1][column] == 1)){
					columnCounter++;
					if(columnCounter >= k){
						previousState = &nulVal;
						return true;
					}
				} else {
					columnCounter = 1;
				}
				previousState = &boardState[move[0]-1][column];
			}

			// check column.
			//cout << "Checking vertical" << endl;
			int rowCounter = 1;
			for(int row=0; row<m; row++){
				if(boardState[row][move[1]-1] == *previousState && (boardState[row][move[1]-1] == -1 || boardState[row][move[1]-1] == 1)){
					rowCounter++;
					if(rowCounter >= k){
						previousState = &nulVal;
						return true;
					}
				} else {
					rowCounter = 1;
				}
				previousState = &boardState[row][move[1]-1];
			}

			// check left to right diagonal check.
			//cout << "Checking left to right." << endl;
			int checkMoves[2];
			int leftToRightCounter = 1;
			if(move[0] >= move[1]){
				int numToMakeYOne = move[1]-1;
				checkMoves[0] = move[0] - numToMakeYOne;
				checkMoves[1] = move[1] - numToMakeYOne;

				while (checkMoves[0] <= m){
					if(*previousState == boardState[checkMoves[0]-1][checkMoves[1]-1] && (boardState[checkMoves[0]-1][checkMoves[1]-1] == -1 || boardState[checkMoves[0]-1][checkMoves[1]-1] == 1)){
						leftToRightCounter++;
						checkMoves[0]++;
						checkMoves[1]++;
						if(leftToRightCounter >= k){
							return true;
						}
					} else {
						checkMoves[0]++;
						checkMoves[1]++;
						leftToRightCounter = 1;
					}
					previousState = &boardState[checkMoves[0]-2][checkMoves[1]-2];
				}
			} else {
				int numToMakeYOne = move[0]-1;
				checkMoves[0] = move[0] - numToMakeYOne;
				checkMoves[1] = move[1] - numToMakeYOne;

				while(checkMoves[1] <= m){
					if(*previousState == boardState[checkMoves[0]-1][checkMoves[1]-1] && (boardState[checkMoves[0]-1][checkMoves[1]-1] == -1 || boardState[checkMoves[0]-1][checkMoves[1]-1] == 1)){
						leftToRightCounter++;
						checkMoves[1]++;
						checkMoves[0]++;
						if(leftToRightCounter >= k){
							return true;
						}
					} else {
						checkMoves[0]++;
						checkMoves[1]++;
						leftToRightCounter = 1;
					}
					previousState = &boardState[checkMoves[0]-2][checkMoves[1]-2];
				}
			}

			 //Check right to left diagonal check
			//cout << "checking right to left." << endl;
			int r2lCheckMoves[2];
			int rightToLeftCounter = 1;
			if((move[0]+move[1]) >= (m+1)){
				int numToMakeYLast = m-(move[1]);
				r2lCheckMoves[0] = move[0] - numToMakeYLast;
				r2lCheckMoves[1] = move[1] + numToMakeYLast;

				while(r2lCheckMoves[0] <= m){
					if(*previousState == boardState[r2lCheckMoves[0]-1][r2lCheckMoves[1]-1] && (boardState[r2lCheckMoves[0]-1][r2lCheckMoves[1]-1] == -1 || boardState[r2lCheckMoves[0]-1][r2lCheckMoves[1]-1] == 1)){
						rightToLeftCounter++;
						r2lCheckMoves[0] = r2lCheckMoves[0] + 1;
						r2lCheckMoves[1] = r2lCheckMoves[1] - 1;
						if(rightToLeftCounter >= k){
							return true;
						}
					} else {
						r2lCheckMoves[0] = r2lCheckMoves[0] + 1;
						r2lCheckMoves[1] = r2lCheckMoves[1] - 1;
						rightToLeftCounter = 1;
					}
					previousState = &boardState[r2lCheckMoves[0]-2][r2lCheckMoves[1]];
				}
			} else if(move[0] + move[1] < m){
				int numToMakeXOne = move[0]-1;
				r2lCheckMoves[0] = move[0] - numToMakeXOne;
				r2lCheckMoves[1] = move[1] + numToMakeXOne;

				while(r2lCheckMoves[1] >= 1){
					//cout << "In the while loops." << endl;
					if(*previousState == boardState[r2lCheckMoves[0]-1][r2lCheckMoves[1]-1] && (boardState[r2lCheckMoves[0]-1][r2lCheckMoves[1]-1] == -1 || boardState[r2lCheckMoves[0]-1][r2lCheckMoves[1]-1] == 1)){
						rightToLeftCounter++;
						r2lCheckMoves[0] = r2lCheckMoves[0] + 1;
						r2lCheckMoves[1] = r2lCheckMoves[1] - 1;
						if(rightToLeftCounter >= k){
							return true;
						}
					} else {
						r2lCheckMoves[0] = r2lCheckMoves[0] + 1;
						r2lCheckMoves[1] = r2lCheckMoves[1] - 1;
						rightToLeftCounter = 1;
					}
					previousState = &boardState[r2lCheckMoves[0]-2][r2lCheckMoves[1]];
				}
			}

			return false;
}

bool Board::isFull(){
	bool full;
	for(int row=0; row< m; row++){
		for(int column = 0; column< m; column++){
			if(boardState[row][column] == 0){
				full = false;
				break;
			} else {
				full = true;
				continue;
			}
		}

		if(full == false){
			break;
		}
	}
	return full;
}

bool Board::isMoveValid(int *move){
	if(move[0]<= m && move[1] <= m) {
		if(boardState[move[0]-1][move[1]-1] == 0){
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}


void Board::addPoint(int *place, int color){
	boardState[place[0]-1][place[1]-1]= color;
	//displayBoard();
}

void Board::displayBoard(){
	// left 2 right number representation.
	for(int header=0; header<m; header++){
		if(header+1 < 10){
			cout << "    " << header+1;
		} else {
			cout << "   " << header+1;
		}

	}
	cout << endl;
	for (int boardRow = 0; boardRow < m; boardRow++) {
		// top down number representation.
		if(boardRow+1 < 10){
			cout << boardRow+1 << "   ";
		}  else {
			cout << boardRow+1 << "  ";
		}

		for (int boardColumn = 0; boardColumn < m; boardColumn++) {
			if(boardState[boardRow][boardColumn] == 1) {
				cout << "X";
			} else if(boardState[boardRow][boardColumn] == -1) {
				cout << "O";
			} else {
				cout << " ";
			}

			if(boardColumn < m-1){
				cout << "----";
			} else {
				cout << "";
			}
		}
		cout << endl;

		if(boardRow < m-1){
			for(int columnHeader=0; columnHeader<m; columnHeader++){
				cout << "    |";
			}
		}

		cout << endl;
	}
	cout << endl;
	cout << "X = Black Player" << endl;
	cout << "O = White Player" << endl;
	cout << "  = Not filled." << endl;
	cout << endl;
}
