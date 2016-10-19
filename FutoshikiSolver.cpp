#include "FutoshikiBoard.h"
#include "FutoshikiSolver.h"
#include <iostream>

using namespace std;

FutoshikiSolver::FutoshikiSolver(int size){
	board = new FutoshikiBoard(size);
}

bool FutoshikiSolver::solveFutoshikiBySmallerDomain(){
	int x, y;

	if(board->findSlot(x, y)){
		return true;
	}

	for (int i = 0; i < board->boardSize; ++i){
		if(board->originalBoard[x][y].domain[i]){
			int num = i+1;
			if(board->isValidPosition(x, y, num)){
				board->originalBoard[x][y].setNumber(num);
				board->calculateProbs();
				att++;
				if(att >= 1e6) return false;
				if(solveFutoshikiBySmallerDomain()){
					return true;
				}
				board->originalBoard[x][y].setNumber(0);
				board->calculateProbs();
				board->originalBoard[x][y].domain[num-1]=0;
			}
		}

	}
	return false;
}

bool FutoshikiSolver::solveFutoshikiByDomain(){
	int x, y;

	if(board->completeBoard(x, y)){
		return true;
	}

	for (int i = 0; i < board->boardSize; ++i){
		if(board->originalBoard[x][y].domain[i]){
			int num = i+1;
			if(board->isValidPosition(x, y, num)){
				board->originalBoard[x][y].setNumber(num);
				board->calculateProbs();
				att++;
				if(att >= 1e6) return false;
				if(solveFutoshikiByDomain()){
					return true;
				}
				board->originalBoard[x][y].setNumber(0);
				board->calculateProbs();
				board->originalBoard[x][y].domain[num-1]=0;
			}
		}

	}
	return false;
}

bool FutoshikiSolver::solveFutoshiki(){
	int x, y;
	
	if(board->completeBoard(x, y)){
		return true;
	}
	for (int num = 1; num <= board->boardSize; num++){
		if(board->isValidPosition(x, y, num)){
			board->originalBoard[x][y].setNumber(num);
			att++;
			if(att>= 1e6) return false;
			if(solveFutoshiki()){
				return true;
			}
		board->originalBoard[x][y].setNumber(0);
		}
	}
	return false;
}

bool FutoshikiSolver::solveBoard(int opt){
	int rules;
	cin >> rules;
	if(opt == 1){
		if(board->initBoard(rules, 0)){
			att = 0;
			if(solveFutoshiki()){
				board->printBoard();
			}else{
				cout<< "Excede o limite de atribuições.\n";
			}

			board->clearBoard();
			return true;
		}
		cout << "Tabuleiro fora de especificação.\n";		
	}else if(opt == 2){
		if(board->initBoard(rules, 1)){
			att = 0;
			if(solveFutoshikiByDomain()){
				board->printBoard();
			}else{
				cout<< "Excede o limite de atribuições.\n";
			}

			board->clearBoard();
			return true;
		}
		cout << "Tabuleiro fora de especificação.\n";
	}else if(opt == 3){
		if(board->initBoard(rules, 1)){
			att = 0;
			if(solveFutoshikiBySmallerDomain()){
				board->printBoard();
			}else{
				cout<< "Excede o limite de atribuições.\n";
			}

			board->clearBoard();
			return true;
		}
		cout << "Tabuleiro fora de especificação.\n";
	}


	return false;
}