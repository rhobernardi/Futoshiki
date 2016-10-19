// FUTOSHIKIBOARD: classe que representa o tabuleiro

#ifndef FUTOSHIKIBOARD_H
#define FUTOSHIKIBOARD_H

#include "BoardSlot.h"
#include "FutoshikiBoard.h"
#include <list>

class FutoshikiBoard{
   public:
		int boardSize;	// Tamanho N do tabuleiro NxN
		int ruleSize;	// Numero de restricoes
		BoardSlot **originalBoard;	// Tabueiro do jogo com cada casa representada por BoardSlot
		char **restrictions;

FutoshikiBoard(int size);

FutoshikiBoard();

bool calculateProbs();

bool recalcCross(int x, int y);
bool checkEmpty(int x, int y);

int counter(int x, int y);

bool eliminateCross(int x, int y, int num);

bool completeBoard(int &x, int &y);

bool findSlot(int &x, int &y);

bool isInCross(int x, int y, int num);

bool notFollowingRule(int x, int y, int num);

bool isValidPosition(int x, int y, int num);

void printBoard();

void clearBoard();

bool initBoard(int rules, int option);

};

#endif