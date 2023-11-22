#include <iostream>
using namespace std;
#include "listas/lista_dupla.hpp"

/*
a. Inserir no final da lista
b. Remover o primeiro elemento
c. Remover o �ltimo elemento. � proibido percorrer alista. Para encontrar o pen�ltimo n�,
acesse o ponteiro �anterior�.
Observa��o: fa�a uso do descritor da lista para remover ou inserir um novo n�, ou seja, n�o �
necess�rio percorrer a lista.
*/

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* aux = nullptr;
    Lista lista = Lista();

    for (int i = 0; i < 5; i++)
        insereInicioL(&lista, i);

    insereFinalL(&lista, 5);
    insereFinalL(&lista, 4);
    insereFinalL(&lista, 3);
    insereInicioL(&lista, 6);

    mostraL(&lista);

    int a = removerPrimeiroNoL(&lista);
    cout << "Primeiro removido: " << a << endl;
    mostraL(&lista);
    int b = removerUltimoNoL(&lista);
    cout << "�ltimo removido: " << b << endl;
    mostraL(&lista);
    mostrarInversoL(&lista);


    destroiL(&lista);
    return EXIT_SUCCESS;
}


