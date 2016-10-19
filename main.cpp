
#include <iostream>
#include <vector>
#include <ctime>
#include "FutoshikiSolver.h"


using namespace std;

bool solveMultipleBoards(int boardQnt, int opt){
	int size;

	FutoshikiSolver *futoshiki;
	for (int i = 0; i < boardQnt; i++){

		cin >> size;
		futoshiki = new FutoshikiSolver(size);
		cout << i+1 << endl;
		futoshiki->solveBoard(opt);

		delete futoshiki;
	}
}

int main(int argc, char **argv){
	int boardQnt;
	int opt;

	clock_t tin, tout;

	if(argc != 2){
		cout << "Selecione a opção desejada:\n(1) Backtracking\n(2) Foward Checking\n(3) Foward Checking e MRV" << endl;
		cout << "Exemplo: ./game 2 < futoshiki.dat\n" << endl;

		return 0;
	}

	opt = atoi(argv[1]);
	cin >> boardQnt;

	tin = clock();
	solveMultipleBoards(boardQnt, opt);
	tout = clock();
	cout << endl << (double)(tout-tin)/CLOCKS_PER_SEC<< endl;
}
