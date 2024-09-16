#include <iostream>
#include <ctime>
using namespace std;

void geraMatriz(int ***mat, int l, int c);
void soma(int ***mat, int ***mat2, int l, int c);
void deletaMatriz(int ***mat, int l, int c);
void mostraMatriz(int ***mat, int l, int c);

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    int l, c;

    cout << "Digite as dimensões da matriz:" << endl;
    cout << "linha: ";
    cin >> l;
    cout << "coluna: ";
    cin >> c;
    cout << endl;

    int **mat = new int*[l];
    for (int i = 0; i < l; i++)
        mat[i] = new int[c];

    int **mat2 = new int*[l];
    for (int i = 0; i < l; i++)
        mat2[i] = new int[c];


    geraMatriz(&mat, l, c);
    mostraMatriz(&mat, l, c);

    geraMatriz(&mat2, l, c);
    mostraMatriz(&mat2, l, c);

    soma(&mat, &mat2, l, c);
    deletaMatriz(&mat, l, c);
    deletaMatriz(&mat2, l, c);
}

void geraMatriz(int ***mat, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            (*mat)[i][j] = rand() % 50;
        }
    }
}

void soma(int ***mat, int ***mat2, int l, int c)
{
    int **mat3 = new int*[l];
    for (int i = 0; i < l; i++)
        mat3[i] = new int[c];

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mat3[i][j] = (*mat)[i][j] + (*mat2)[i][j];
        }
    }
    mostraMatriz(&mat3, l, c);
    deletaMatriz(&mat3, l, c);
}

void deletaMatriz(int ***mat, int l, int c)
{
    for (int i = 0; i < l ;i++)
        delete[] (*mat)[i];

    delete[] (*mat);

    *mat = NULL;
}

void mostraMatriz(int ***mat, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << (*mat)[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
