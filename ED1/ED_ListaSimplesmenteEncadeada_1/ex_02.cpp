#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Considere uma lista encadeada L1 representando uma sequência de caracteres. Construa uma função
para imprimir a sequência de caracteres da lista L1 na ordem inversa.
Exemplo: para a lista L1={A,E,I,O,U}, a função deve imprimir “UOIEA”.
Observação: faça uso de uma lista auxiliar e as funções removeFinalL e insereFinalL do exercício
anterior.
 */

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<char> *L;
    No<char> *L2;

    inicializaL(&L);
    inicializaL(&L2);

    insereFinalL(&L, 'A');
    insereFinalL(&L, 'E');
    insereFinalL(&L, 'I');
    insereFinalL(&L, 'O');
    insereFinalL(&L, 'U');

    insereFinalL(&L2, removeFinalL(&L));
    insereFinalL(&L2, removeFinalL(&L));
    insereFinalL(&L2, removeFinalL(&L));
    insereFinalL(&L2, removeFinalL(&L));
    insereFinalL(&L2, removeFinalL(&L));

    mostraL(&L);
    mostraL(&L2);

    return EXIT_SUCCESS;
}
