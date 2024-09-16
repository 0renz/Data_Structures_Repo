#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Construa uma função que recebe como parâmetros uma Lista L de valores inteiros e um valor X. A
função deve retirar os primeiros X valores da lista L, inserindo-os no fim de L. Use as funções de
inserção e remoção separadas.
Exemplo:
L: [3,5,8,9,12,11,7,10]
x: 4
L após a função: [12,11,7,10,3,5,8,9]
*/

void retiraInicioColocaFinal(No<int> **L, int num);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<int> *L; // cria o primeiro nó
    inicializaL(&L);

    for (int i = 0; i < 10; i++)
        insereFinalL(&L, i);

    mostraL(&L);

    int num = 5;

    retiraInicioColocaFinal(&L, num);

    return EXIT_SUCCESS;
}

void retiraInicioColocaFinal(No<int> **L, int num)
{
    int aux;
    for(int i = 0; i < num; i++)
    {
        aux = removeInicioL(L);
        insereFinalL(L, aux);
    }
    mostraL(L);
}



