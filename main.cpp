/****************************************************************
*        Projeto 1 - Algoritmos Avançados e Aplicações          *
*             Futoshiki - Backtracking solution                 *
*																*
*         Rodrigo das Neves Bernardi    - 8066395               *
*                                                               *
****************************************************************/

#include <iostream>


typedef struct {
	int x;
	int y;
} coord;

typedef struct space {
    int value;
    int *domain;
    int forward_check;
    coord *pos;
    coord greater[4];
    coord less[4];
}Space;

typedef struct {
	Space **grid;
	int fsize;
	int **restr;
	int rsize;
}Futoshiki;


typedef struct
{
	
}Restriction_M;

void createGame(Futoshiki *field, FILE *);
void printGame(Futoshiki field);
void freeMemory(Futoshiki *field);


using namespace std;

int main(int argc, char **argv)
{
	int ngames;
	Futoshiki Field;

	if (argc != 3) {
		cout << "Usage: ./futoshiki [flag forward check] [flag MRV] \n" << endl;
		cout << "Example: ./futoshiki 1 0 (only forward check ON)\n" << endl;
	} else {
		
		FILE *fp = fopen("futoshiki.dat","r");

		fscanf(fp, "%d\n", &ngames);

		for (int k = 0; k < ngames; ++k)
		{
			createGame(&Field, fp);

			cout << "\nnumber of games = " << ngames << endl;
			cout << "field size = " << Field.fsize << "   number of restrictions = " << Field.rsize << endl;

			printGame(Field);

			//freeMemory(&Field);
		}

		return 0;
	}
}


/*=================================
=            Functions            =
=================================*/

void createGame(Futoshiki *field, FILE *fp)
{
	fscanf(fp, "%d %d\n", &field->fsize, &field->rsize);
    
	field->grid = (Space **) calloc(field->fsize, sizeof(Space *));
	for (int i = 0; i < field->fsize; ++i)
		field->grid[i] = (Space *) calloc(field->fsize, sizeof(Space));

	for (int i = 0; i < field->fsize; ++i)
		for (int j = 0; j < field->fsize; ++j)
			fscanf(fp, "%d ", &field->grid[i][j].value);

	field->restr = (int **) calloc(field->rsize, sizeof(int *));
	for (int i = 0; i < field->rsize; ++i)
		field->restr[i] = (int *) calloc(4, sizeof(int));

	for (int i = 0; i < field->rsize; ++i)
		for (int j = 0; j < 4; ++j)
			fscanf(fp, "%d ", &field->restr[i][j]);

	// for (int i = 0; i < rsize; ++i)
	// {
	// 	for (int j = 0; j < 4; j+2)
	// 	{
	// 		field->grid[field->restr[i][j]][field->restr[i][j+1]]. = 
	// 	}
	// }

}

void printGame(Futoshiki field)
{
	cout << endl;
	for (int i = 0; i < field.fsize; ++i)
	{
		for (int j = 0; j < field.fsize; ++j)
			cout << " " << field.grid[i][j].value;

		cout << endl;
	}

	cout << endl;


	for (int i = 0; i < field.rsize; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout << " " << field.restr[i][j];

		cout << endl;
	}
}

// void freeMemory(Futoshiki *field)
// {
// 	for (int i = 0; i < field->fsize; ++i)
// 		free(field->data[i]);

// 	free(field->data);

// 	for (int i = 0; i < field->nrestr; ++i)
// 		free(field->restr[i]);

// 	free(field->restr);
// }


/*=====  End of Functions  ======*/