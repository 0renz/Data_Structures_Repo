#include <iostream>
using namespace std;
#include "listas/lista_dupla.hpp"

/*
Implemente funções para as seguintes operações em uma lista duplamente encadeada:
    remove da lista todas as ocorrências do parâmetro valor
    void removeTodos(Lista *L, int valor);
    Retorna uma nova lista, ordenada, com os K maiores elementos de L
    Se K for maior que o tamanho de L, a lista retornada deve conter todos os
    elementos de L de forma ordenada.
    Lista* leMaiores(Lista *L, int K);
*/

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* aux = nullptr;
    Lista lista = Lista();
    Lista listadosxmaioresordenados = Lista();

    for (int i = 0; i < 5; i++)
        insereInicioL(&lista, i);

    insereInicioL(&lista, 4);
    insereInicioL(&lista, 4);
    insereFinalL(&lista, 4);
    mostraL(&lista);
    removeTodos(&lista, 4);
    mostraL(&lista);
    insereFinalL(&lista, 1);
    insereFinalL(&lista, 4);
    insereFinalL(&lista, 8);
    insereFinalL(&lista, 100);
    mostraL(&lista);
    cout << "-----------" << endl;

    listadosxmaioresordenados = leMaiores(&lista, 5);

    destroiL(&lista);
    return EXIT_SUCCESS;
}



