
#include<iostream>
#include "Headers/Board.h"

using namespace std;

class BoardDriver {
public:
	Board board;

	BoardDriver(){
		cout << "M,K GAME BOARD DRIVER INITIALIZED. Checking all conditions." << endl;
		board.m = 20;
		board.k = 10;
		cout << "Initial m,k = 20,10 for testing purposes." << endl;
		board.createInitialBoardState();
		cout << endl;

		cout << "----------------------------------------------------------------------------------------------" << endl;
		cout << "TESTING BOARD STONES VALIDITY." << endl;
		checkValid();
		cout << endl;

		cout << "----------------------------------------------------------------------------------------------" << endl;
		cout << "TESTING WINNING CONDITIONS." << endl;
		checkWin();
		cout << endl;

		cout << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "TESTING BOARD FULL." << endl;
		checkBoardFull();
		cout << endl;

		cout << "----------------------------------------------------------------------------------------------------" << endl;
		cout << "TESTING BOARD DISPLAY" << endl;
		checkDisplayBoard();
		cout << endl;
	}

	void checkDisplayBoard(){
		cout << "Checking the board display..." << endl;
		board.displayBoard();
		cout << endl;
	}

	void checkBoardFull(){
		//fill the board with 1s
		cout << "Checking if board is full." << endl;
		if(board.isFull() == false){
			cout << "The board is not full." << endl;
		}
		board.displayBoard();

		cout << "Filling the board with all 1s. // Empty board values is 0." << endl;
		int *move = new int[2];
		for (int boardRow = 0; boardRow < board.m; boardRow++) {
			for (int boardColumn = 0; boardColumn < board.m; boardColumn++) {
				move[0] = boardRow+1;
				move[1] = boardColumn+1;
				board.addPoint(move, 1);
			}
		}

		cout << "Board filled with 1s. Checking if board is full." << endl;

		if(board.isFull() == true){
			cout << "The board is full." << endl;
		}
		board.displayBoard();
		cout << endl;
	}

	void checkValid(){
		int *move = new int[2];

		cout << "Checking move validity." << endl;
		cout << "Initial move 100,100 for a board of size 20x20" << endl;
		move[0] = 100;
		move[1] = 100;

		cout << "Calling board.isMoveValid(*move)" << endl;
		if(board.isMoveValid(move) == false){
			cout << "Move: " << move[0] << " " << move[1] << " is not valid." << endl;
		}

		cout << "Again, valid move 10,10 for a board of size 20x20" << endl;
		move[0] = 10;
		move[1] = 10;

		cout << "Calling board.isMoveValid(*move)" << endl;
		if(board.isMoveValid(move) == true){
			cout << "Move: " << move[0] << " " << move[1] << " is perfectly valid." << endl;
		}
		cout<< endl;
		cout << "Placing a stone in 20,20 initially." << endl;
		move[0] = 20;
		move[1] = 20;
		board.addPoint(move,1);
		board.displayBoard();

		cout << "Checking validity for the same place. Calling board.isMoveValid(*move)" << endl;
		if(board.isMoveValid(move) == false){
			cout << "Move: " << move[0] << " " << move[1] << " is not valid." << endl;
		}

		cout << endl;

	}

	void checkWin(){
		cout << "Checking winning conditions." << endl;
		// CHECK WINNING CONDITIONS.
			//1. check row winning conditions. i.e horizontal.
			int *move = new int[2];
			cout << "Checking horizontal winning condition by placing 10 points adjacent to each other." << endl;
			for(int initialK=1; initialK <= 10; initialK++){
				move[0] = 1;
				move[1] = initialK;

				board.addPoint(move, 1);
				if(board.haveIWon(move)){
					cout << "Won by placing " << move[1] << "adjacent horizontal stones." << endl;
				}
			}
			board.displayBoard();

			//2. Check column winning conditions. i.e vertical.
			cout << "Checking vertical winning condition by placing 10 points adjacent to each other." << endl;
			for(int initialK=1; initialK <= 10; initialK++){
				move[0] = initialK;
				move[1] = 1;

				board.addPoint(move, 1);
				if(board.haveIWon(move)){
					cout << "Won by placing " << move[1] << "adjacent vertical stones." << endl;
				}
			}
			board.displayBoard();

			//3. Check left to right diagonal checking.
			// do this tomorrow.
			cout << endl;

	}


};
