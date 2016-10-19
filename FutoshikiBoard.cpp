#include "BoardSlot.h"
#include "FutoshikiBoard.h"
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

FutoshikiBoard::FutoshikiBoard(int size){
	boardSize = size;
	originalBoard = new BoardSlot*[boardSize];
	for (int i = 0; i < boardSize; ++i)
    originalBoard[i] = new BoardSlot[boardSize];

	
	for (int i = 0; i < boardSize; ++i){
		for (int j= 0; j < boardSize; ++j){
			originalBoard[i][j].domain = new int[boardSize];
			for (int k = 0; k < boardSize; ++k) originalBoard[i][j].domain[k]=0;
		}
	}
}

FutoshikiBoard::FutoshikiBoard(){
	originalBoard = NULL;
	ruleSize=0;
}

bool FutoshikiBoard::calculateProbs(){
	for (int i = 0; i < boardSize; ++i){
		for (int j = 0; j < boardSize; ++j){
			for (int k = 0; k < boardSize; ++k) originalBoard[i][j].domain[k] =0;
			for(int num = 1; num<=boardSize; num++){
				if(originalBoard[i][j].getNumber() == 0 && isValidPosition(i, j, num)){
					originalBoard[i][j].domain[num-1] =1;
				}
				if(originalBoard[i][j].getNumber()!=0){
					originalBoard[i][j].domain[originalBoard[i][j].getNumber()-1] = 1;
				}
			}
		}
	}
	return true;
}

bool FutoshikiBoard::recalcCross(int x, int y){
	for (int i = 0; i < boardSize; ++i){
		for (int k = 0; k < boardSize; ++k){
			originalBoard[i][y].domain[k] =0;
			originalBoard[x][i].domain[k] =0;
		}
		for(int num = 1; num<=boardSize; num++){
			if(i!= x){
				if(originalBoard[i][y].getNumber() == 0 && isValidPosition(i, y, num)){
					originalBoard[i][y].domain[num-1] =1;
				}
				if(originalBoard[i][y].getNumber()!=0){
					originalBoard[i][y].domain[originalBoard[i][y].getNumber()-1] =1;
				}
			}
			if(i!= y){
				if(originalBoard[x][i].getNumber() == 0 && isValidPosition(x, i, num)){
					originalBoard[x][i].domain[num-1] =1;
				}
				if(originalBoard[x][i].getNumber()!=0){
					originalBoard[x][i].domain[originalBoard[x][i].getNumber()-1] =1;
				}
			}
		}
	}
	return true;
}
bool FutoshikiBoard::checkEmpty(int x, int y){
	for (int i = 0; i < boardSize; ++i){
		if(originalBoard[x][y].domain[i] == 1){
			return false;
		}
	}
	return true;
}

int FutoshikiBoard::counter(int x, int y){
	int counter =0;
	for (int i = 0; i < boardSize; ++i){
		if(originalBoard[x][y].domain[i] == 1){
			counter++;
		}
	}
	return counter;
}

bool FutoshikiBoard::eliminateCross(int x, int y, int num){
	bool ret = true;
	for (int i = 0; i < boardSize; ++i){
		if(i!=x && !checkEmpty(i, y)){
			originalBoard[i][y].domain[num-1] =0;
		}
		if(i!= y && !checkEmpty(x, i)){
			originalBoard[x][i].domain[num-1] =0;
		} 	
		if(checkEmpty(i, y)){
			originalBoard[i][y].domain[num-1] =1;
			ret = false;
		}
		if(checkEmpty(x, i)){
			originalBoard[x][i].domain[num-1] =1;
			ret = false;
		}
	}
	return ret;
}


bool FutoshikiBoard::completeBoard(int &x, int &y){
	for (x = 0; x < boardSize; x++){
		for (y = 0; y < boardSize; y++){
			if(originalBoard[x][y].getNumber() ==0){
				return false;
			}
		}
	}
	return true;
}

bool FutoshikiBoard::findSlot(int &x, int &y){
	int smaller=10;
	int x1, y1;
	for (x1 = 0; x1 < boardSize; x1++){
		for (y1 = 0; y1 < boardSize; y1++){
			if(originalBoard[x1][y1].getNumber() == 0 && counter(x1, y1) < smaller){
				smaller = (int) counter(x1, y1);
				x = x1;
				y = y1;
			}
		}
	}
	if(smaller == 10){
		return true;	
	}
	return false;
	
}

bool FutoshikiBoard::isInCross(int x, int y, int num){
	for (int i = 0; i < boardSize; i++){
		if((originalBoard[x][i].getNumber() == num && i!= y) || originalBoard[i][y].getNumber() == num && i!= x){
			return true;
		}
	}
	return false;
}

bool FutoshikiBoard::notFollowingRule(int x, int y, int num){
	int x1, x2, y1, y2;

	for(int i = 0; i < ruleSize; i++) {
		x1 = (int) restrictions[i][0];
		y1 = (int) restrictions[i][1];
		x2 = (int) restrictions[i][2];
		y2 = (int) restrictions[i][3];
	   	if(x1 == x && y1 == y){
	   		if(originalBoard[x2][y2].getNumber() != 0 && num > originalBoard[x2][y2].getNumber()){
	   			return true;
	   		}
	   	}else if(x2 == x && y2 == y){
	   		if(originalBoard[x1][y1].getNumber() != 0 && num < originalBoard[x1][y1].getNumber()){
	   			return true;
	   		}
	   	}
	   }
	return false;
}

bool FutoshikiBoard::isValidPosition(int x, int y, int num){
	if(isInCross(x, y, num) || notFollowingRule(x, y,num)){
		return false;
	}
	return true;
}

void FutoshikiBoard::printBoard(){
	for (int i = 0; i < boardSize; i++){
	 	for (int j = 0; j < boardSize; j++){
	 		cout << originalBoard[i][j].getNumber() << " ";
	 	}
	 	cout << endl;
	}
	cout << endl;
}

void FutoshikiBoard::clearBoard(){
	if (boardSize) delete [] originalBoard[0];
	delete [] originalBoard;
}

bool FutoshikiBoard::initBoard(int rules, int option){
	int x1, x2, y1, y2, num;

	ruleSize = rules;

	if(boardSize<4 || boardSize>9) return false;

	for (int i = 0; i < boardSize; i++){
	 	for (int j = 0; j < boardSize; j++){
	 		cin >> num;
	 		originalBoard[i][j].setNumber(num);
	 	}
	}

	restrictions = new char*[rules];
	for (int i = 0; i < rules; ++i)
    restrictions[i] = new char[4];

	for (int i = 0; i < rules; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		restrictions[i][0] = x1-1;
		restrictions[i][1] = y1-1;
		restrictions[i][2] = x2-1;
		restrictions[i][3] = y2-1;
	}
	if(option != 0){
		calculateProbs();
	}

	return true;
}