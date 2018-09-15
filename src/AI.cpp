#include<iostream>

#include "Headers/Board.h"

using namespace std;
/**
 * Initially utilizes the complete minimax algorithm with depth:1 to predict the next move.
 */
class AI{

	int currentColor;
	int m,k;
	int opponentColor;
	float finalScore = 0;
	int *finalMove;

public:
	// the current turn player is the maximizer. 1 or -1
	AI(Board &b, int color){
		m = b.m;
		k = b.k;
		int **mainBoard = b.boardState;
		currentColor = color;

		if(currentColor == 1){
			opponentColor = -1;
		} else {
			opponentColor = 1;
		}

		for(int playsRow=0; playsRow < m; playsRow++){
			for(int playsColumn=0; playsColumn < m; playsColumn++){

				if(mainBoard[playsRow][playsColumn] == 0){
					int **boardState = new int *[m];
					for (int sizeOfBoard = 0; sizeOfBoard < m; sizeOfBoard++) {
						boardState[sizeOfBoard] = new int[m];
					}

					for(int x=0; x<m; x++){
						for(int y=0; y<m ; y++){
							boardState[x][y] = mainBoard[x][y];
						}
					}
					boardState[playsRow][playsColumn] = currentColor;
					int *move = new int[2];
					move[0] = playsRow;
					move[1] = playsColumn;
					calculateHeuristicEvaluation(boardState, move);
				}
			}
		}
		//int myHScore = checkHorizontalScore(boardState, currentTurn);

	}

	void calculateHeuristicEvaluation(int **boardState, int *move){
		float score;

		float myVerticalScore = checkVerticalScore(boardState, currentColor);
		float myHorizontalScore = checkHorizontalScore(boardState, currentColor);
		float myL2RScore = checkLtoRScore(boardState, currentColor);
		float myR2LScore = checkRtoLScore(boardState, currentColor);

		float oppVerticalScore = checkVerticalScore(boardState, opponentColor);
		float oppHorizontalScore = checkHorizontalScore(boardState, opponentColor);
		float oppL2RScore = checkLtoRScore(boardState, opponentColor);
		float oppR2LScore = checkRtoLScore(boardState, opponentColor);


		float myFinalScore = myVerticalScore + myHorizontalScore + myL2RScore + myR2LScore;
		float opponentFinalScore = oppVerticalScore + oppHorizontalScore + oppL2RScore + oppR2LScore;

		if(oppVerticalScore == 0 || oppHorizontalScore == 0 || myL2RScore == 0){
			score = 50000;
		} else {
			score = myFinalScore - opponentFinalScore;
		}

		if(score > finalScore){
			finalScore = score;
			finalMove = move;
		}

//
//		cout << "myvertical score here: " << myVerticalScore << endl;
//		cout << "myhorizontal score here: " << myHorizontalScore << endl;
//		cout << "opponentvertical score here: " << oppVerticalScore << endl;
//		cout << "opponentHorizontal Score here: " << oppHorizontalScore << endl;
//		cout << "For " << move[0] << " " << move[1] << " got for this shit is: " << score << endl;

	}

	int* play(){
		return finalMove;
	}


	int mkShapeScore(int consecutive, int openEnds){

//		if(openEnds == 0 && consecutive < k){
//			return 0;
//		}
		if(consecutive == k){
			return 50000000;
		} else if (consecutive >= k/2 && openEnds > 0){
			return 50*k*openEnds;
		} else if(consecutive < k/2 && openEnds > 0){
			return 5*k*openEnds;
		}

			//return consecutive*openEnds;
	}


	int checkHorizontalScore(int **boardState, int color){
		//int nulVal = 0;
		//int *previousState = &nulVal;
		int score=0;
		int rowCounter = 0;
		int openEnds = 0;

		for(int row=0; row < m; row++){
			for(int column=0; column < m; column++){
				if(boardState[row][column] == color){
					rowCounter++;
				} else if (boardState[row][column] == 0 && rowCounter > 0){
					openEnds++;
					score += mkShapeScore(rowCounter, openEnds);
					rowCounter = 0;
					openEnds = 1;
				} else if(boardState[row][column] == 0){
					openEnds = 1;
				} else if(rowCounter > 0){
					score+= mkShapeScore(rowCounter, openEnds);
					rowCounter = 0;
					openEnds = 0;
				} else {
					openEnds = 0;
				}
			}
			if(rowCounter > 0){
				score += mkShapeScore(rowCounter, openEnds);
				rowCounter = 0;
				openEnds = 0;
			}
		}
		//previousState = &nulVal;

		return score;
	}

	int checkVerticalScore(int **boardState, int color){
		int score=0;
		int columnCounter = 0;
		int openEnds = 0;


		for(int column=0; column < m; column++){
			for(int row=0; row < m; row++){
				if(boardState[row][column] == color){
					columnCounter++;
				} else if (boardState[row][column] == 0 && columnCounter > 0){
					openEnds++;
					score += mkShapeScore(columnCounter, openEnds);
					columnCounter = 0;
					openEnds = 1;
				} else if(boardState[row][column] == 0){
					openEnds = 1;
				} else if(columnCounter > 0){
					score+= mkShapeScore(columnCounter, openEnds);
					columnCounter = 0;
					openEnds = 0;
				} else {
					openEnds = 0;
				}
			}
			if(columnCounter > 0){
				score += mkShapeScore(columnCounter, openEnds);
				columnCounter = 0;
				openEnds = 0;
			}
		}

		return score;
	}

	float checkLtoRScore(int **boardState, int color){
		float score = 0;
		int l2rCounter = 0;
		int openEnds = 0;

		for(int column = 0; column < m; column++){
			 for(int row = 0; row < m; row++){

					for(int i = 0; i < m; i++){

						if(row + i >= m-1){
							break;
						}
						if(column + i >= m-1){
							break;
						}

						if(boardState[row + i][column + i] == color){
							l2rCounter++;
						} else if(boardState[row+i][column+i] == 0 && l2rCounter > 0){
							openEnds++;
							score += mkShapeScore(l2rCounter, openEnds);
							l2rCounter = 0;
							openEnds = 1;
						} else if(boardState[row][column] == 0) {
							score+= mkShapeScore(l2rCounter, openEnds);
							l2rCounter = 0;
							openEnds = 0;
						} else if(l2rCounter > 0){
							score+= mkShapeScore(l2rCounter, openEnds);
							l2rCounter = 0;
							openEnds = 0;
						} else {
							openEnds = 0;
						}
					}

					if(l2rCounter > 0){
						score += mkShapeScore(l2rCounter, openEnds);
						l2rCounter = 0;
						openEnds = 0;
					}

				}

		}
		return score;
	}

	int checkRtoLScore(int **boardState, int color){
		float score = 0;
		int r2lCounter = 0;
		int openEnds = 0;

		for(int column = 0; column < m; column++){
			 for(int row = 0; row < m; row++){

					for(int i = 0; i < m; i++){

						if(row + i >= m-1){
							break;
						}
						if(column + i >= m-1){
							break;
						}

						if(boardState[column + i][row + i] == color){
							r2lCounter++;
						} else if(boardState[column+i][row+i] == 0 && r2lCounter > 0){
							openEnds++;
							score += mkShapeScore(r2lCounter, openEnds);
							r2lCounter = 0;
							openEnds = 1;
						} else if(boardState[column][row] == 0) {
							score+= mkShapeScore(r2lCounter, openEnds);
							r2lCounter = 0;
							openEnds = 0;
						} else if(r2lCounter > 0){
							score+= mkShapeScore(r2lCounter, openEnds);
							r2lCounter = 0;
							openEnds = 0;
						} else {
							openEnds = 0;
						}
					}

					if(r2lCounter > 0){
						score += mkShapeScore(r2lCounter, openEnds);
						r2lCounter = 0;
						openEnds = 0;
					}

				}

			}
			return score;
	}



};
