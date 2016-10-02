/**
 *  Algoritmos Avançados e Aplicações
 *  Backtracking - Futoshiki
 *
 *  - Rodrigo das Neves Bernardi 8066395
 */


#include <iostream>


typedef struct
{
	int **data, fsize;
	int **restr, nrestr;

}Futoshiki;


void createGame(Futoshiki *field);
void printGame(Futoshiki field);
void freeMemory(Futoshiki *field);


using namespace std;

int main(int argc, char **argv)
{
	int ngames;
	Futoshiki Field;

	scanf("%d\n", &ngames);

	for (int k = 0; k < ngames; ++k)
	{
		createGame(&Field);

		cout << "\nnumber of games = " << ngames << endl;
		cout << "field size = " << Field.fsize << "   number of restrictions = " << Field.nrestr << endl;

		printGame(Field);

		freeMemory(&Field);
	}

	return 0;
}


/*=================================
=            Functions            =
=================================*/

void createGame(Futoshiki *field)
{
	scanf("%d %d\n", &field->fsize, &field->nrestr);
    
	field->data = (int **) calloc(field->fsize, sizeof(int *));

	for (int i = 0; i < field->fsize; ++i)
		field->data[i] = (int *) calloc(field->fsize, sizeof(int));

	for (int i = 0; i < field->fsize; ++i)
		for (int j = 0; j < field->fsize; ++j)
			scanf("%d ", &field->data[i][j]);

	field->restr = (int **) calloc(field->nrestr, sizeof(int *));

	for (int i = 0; i < field->nrestr; ++i)
		field->restr[i] = (int *) calloc(4, sizeof(int));


	for (int i = 0; i < field->nrestr; ++i)
		for (int j = 0; j < 4; ++j)
			scanf("%d ", &field->restr[i][j]);
}

void printGame(Futoshiki field)
{
	cout << endl;
	for (int i = 0; i < field.fsize; ++i)
	{
		for (int j = 0; j < field.fsize; ++j)
			cout << " " << field.data[i][j];

		cout << endl;
	}

	cout << endl;


	for (int i = 0; i < field.nrestr; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout << " " << field.restr[i][j];

		cout << endl;
	}
}

void freeMemory(Futoshiki *field)
{
	for (int i = 0; i < field->fsize; ++i)
		free(field->data[i]);

	free(field->data);

	for (int i = 0; i < field->nrestr; ++i)
		free(field->restr[i]);

	free(field->restr);
}


/*=====  End of Functions  ======*/