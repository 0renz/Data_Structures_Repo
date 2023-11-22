#include <iostream>
using namespace std;
#include "listas/lista_dupla.hpp"

/*
a. Inserir no final da lista
b. Remover o primeiro elemento
c. Remover o último elemento. É proibido percorrer alista. Para encontrar o penúltimo nó,
acesse o ponteiro “anterior”.
Observação: faça uso do descritor da lista para remover ou inserir um novo nó, ou seja, não é
necessário percorrer a lista.
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
    cout << "Último removido: " << b << endl;
    mostraL(&lista);
    mostrarInversoL(&lista);


    destroiL(&lista);
    return EXIT_SUCCESS;
}


