#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Considere uma lista encadeada L1 representando uma sequ�ncia de caracteres. Construa uma fun��o
para imprimir a sequ�ncia de caracteres da lista L1 na ordem inversa.
Exemplo: para a lista L1={A,E,I,O,U}, a fun��o deve imprimir �UOIEA�.
Observa��o: fa�a uso de uma lista auxiliar e as fun��es removeFinalL e insereFinalL do exerc�cio
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
