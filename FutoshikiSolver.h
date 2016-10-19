#ifndef FUTOSHIKISOLVER_H
#define FUTOSHIKISOLVER_H

#include "FutoshikiBoard.h"

class FutoshikiSolver{
	public:
		FutoshikiBoard *board;	
		int att;

FutoshikiSolver(int size);	// Inicializa as variavaeis da classe
	
bool solveFutoshikiBySmallerDomain();	// Encontra a solucao com Foward Checking e MRV

bool solveFutoshikiByDomain();	// ENcontra a solucao atravaes de Foward Checking
	
bool solveFutoshiki();	// Encontra a solucao atraves de backtracking

bool solveBoard(int opt);	//Inicializa o tabuleiro

};

#endif