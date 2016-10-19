// BOARDSLOT: classe que representa a casa de um tabuleiro

#ifndef BOARDSLOT_H
#define BOARDSLOT_H

#include <list>

using namespace std;
class BoardSlot{
   public:
		int num;	// Numero do tabuleiro
		int *domain;	// Vetor de inteiros contendo o dominio

	BoardSlot();

	void setNumber(int numero);

	int getNumber();
};

#endif