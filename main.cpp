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







/**

bool backtracking(board *newBoard)
{
    if (newBoard->isCorrect()) return true;
    
    else
    {
        int size = newBoard->getBoardSize();
        pair<int,int> coords;
        cell newCell;
        
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                coords = make_pair(i,j);
                newCell.setPosition(coords);

                for (int k = 1; k <= size; ++k)
                {
                    newCell.setValue(k);

                    if (newBoard->isValid(newCell))
                    {
                        newBoard->changeCell(k,false,coords);
                        backtracking(newBoard);
                        newBoard->changeCell(0,false,coords);
                    }
                    
                    else return false;
                }
            }
        }

        return false;
    }
}


void teste_fc(int **tabuleiro, int D);

int main(int argc, char *argv[]){
    // N - numero de casos
    // D - tamanho da matriz/tabuleiro
    // R - numero de restricoes

    int **tabuleiro, **restricoes;
    int i, j, k;
    int N, D, R;

    // Leitura de N
    cin >> N;
    cout << "N:\t" << N << endl;

    // Leitura dos casos de teste
    for(i = 0; i < N; i++) {
        // Leitura de D e R
        cin >> D >> R;
        cout << "D:\t" << D << endl;
        cout << "R:\t" << R << endl;

        // Alocacao da matriz quadrada de tamanho D
        tabuleiro = (int **) calloc(D, sizeof(int *));
        for(j = 0; j < D; j++)
            tabuleiro[j] = (int *) calloc(D, sizeof(int));

        // Alocacao da matriz de tamanho Rx4
        restricoes = (int **) calloc(R, sizeof(int *));
        for(j = 0; j < 4; j++)
            restricoes[j] = (int *) calloc(4, sizeof(int));

        // Leitura do tabuleiro
        for(j = 0; j < D; j++) {
            for(k = 0; k < D; k++) {
                cin >> tabuleiro[j][k];
            }
        }

        cout << endl;

        // Checagem de leitura do tabuleiro
        for(j = 0; j < D; j++) {
            for(k = 0; k < D; k++) {
                cout << tabuleiro[j][k] << " ";
            }
            cout << endl;
        }

        // Leitura das restricoes
        for(j = 0; j < R; j++) {
            for(k = 0; k < 4; k++) {
                cin >> restricoes[j][k];
            }
        }

        cout << endl;

        // Checagem de leitura das restricoes
        for(j = 0; j < R; j++) {
            for(k = 0; k < 4; k++) {
                cout << restricoes[j][k] << " ";
            }
            cout << endl;
        }

        teste_fc(tabuleiro, D);

    }

}

// Params:
//  - Matriz tabuleiro
//  - Tamanho D
//  
//  1) Funcao criada para definir os valores 
//     das variaveis de acordo com o estado
//     em que o tabuleiro se encontra
//     na hora em que a funcao foi chamada
void teste_fc(int **tabuleiro, int D) {

    // Alocacao da matriz de tamanho D*D*D
    int ***matriz3d;
    matriz3d = (int ***) calloc(D, sizeof(int **));
    for(int i = 0; i < D; i++) {
        matriz3d[i] = (int **) calloc(D, sizeof(int *));
        for(int j = 0; j < D; j++)
            matriz3d[i][j] = (int *) calloc(D, sizeof(int));
    }

    // Inicializa a matriz com 1
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < D; j++) {
            for (int k = 0; k < D; k++) {
                matriz3d[i][j][k] = 1;
            }
        }
    }

    // Seta os valores iniciais possíveis
    // de acordo com os valores que foram
    // recebidos como parametro (tabuleiro)
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < D; j++) {
            if (tabuleiro[i][j] != 0) {
                int valor = tabuleiro[i][j];
                for (int k = 0; k < D; k++)
                {
                    matriz3d[i][k][valor-1] = 0;
                }
                for (int k = 0; k < D; k++)
                {
                    matriz3d[k][j][valor-1] = 0;
                }
                for (int k = 0; k < D; k++)
                {
                    matriz3d[i][j][k] = 0;
                }
                matriz3d[i][j][valor-1] = 1;
            }
        }
    }

    // Teste para checagem de valores
    cout << "Linha 1:" << endl;
    for (int j = 0; j < D; j++) {
        for (int k = 0; k < D; k++) {
            cout << matriz3d[0][j][k] << " ";
        }
        cout << endl;
    }

    // Teste para checagem de valores
    cout << "Coluna 3:" << endl;
    for (int i = 0; i < D; i++) {
        for (int k = 0; k < D; k++) {
            cout << matriz3d[i][2][k] << " ";
        }
        cout << endl;
    }

}

 */