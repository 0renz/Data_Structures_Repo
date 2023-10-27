#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Crie as seguintes fun��es:

retorna o total de elementos da lista
int totalL(No **lista)

verifica se duas listas s�o iguais
bool igualL(No **lista1, No **lista2)

Insere um valor no final da lista
void insereFinalL(No **lista, int valor)

retorna o valor do �ltimo elemento da lista SEM remov�-lo
int leFinalL(No **lista)

retorna o valor do �ltimo elemento da lista e REMOVE o elemento
int removeFinalL(No **lista)

retorna o valor do dado armazenado em um n� da lista, com base na posi��o passada por par�metro
se posi��o=0, a fun��o deve retornar o valor do primeiro n� da lista
se posi��o=1, a fun��o deve retornar o valor do segundo n� da lista
int lePosicao(No **lista, int posi��o)

Uni�o de duas listas
void uniao(No **lista1, No **lista2, No **listaSaida)
*/

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    No<int> *L; // cria o primeiro n�
    No<int> *L2;
    No<int> *L3;

    inicializaL(&L);
    inicializaL(&L2);
    inicializaL(&L3);
    totalL(&L);

    insereInicioL(&L, 1);
    insereFinalL(&L, 15);
    insereInicioL(&L2, 1);
    insereInicioL(&L2, 2);
    insereInicioL(&L2, 3);
    insereInicioL(&L2, 4);


    mostraL(&L);
    mostraL(&L2);
    totalL(&L);

    if(igualL(&L, &L2))
    {
        cout << "iguais";
    }
    else
        cout << "n�o iguais";

    cout << "\n##########" << endl;
    insereFinalL(&L, 15);
    insereFinalL(&L, 14);
    insereInicioL(&L, 14);
    insereInicioL(&L, 20);
    insereFinalL(&L, 144);
    cout << endl;
    mostraL(&L);
    cout << endl;

    cout << "�ltimo valor: " << leFinalL(&L) << endl;
    cout << "\nRemove ultimo valor: " << removeFinalL(&L);
    cout << "\nRemove ultimo valor: " << removeFinalL(&L);
    cout << "\nRemove ultimo valor: " << removeFinalL(&L);
    mostraL(&L);

    cout << "\nValor na posicao 10: " << lePosicao(&L, 10);

    cout << endl;
    cout << endl;
    mostraL(&L);
    mostraL(&L2);
    uniao(&L, &L2, &L3);

    return EXIT_SUCCESS;
}


