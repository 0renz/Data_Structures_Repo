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

    /// TESTE INSERE FINAL
    /*
    insereFinalL(&lista, 150);
    mostraL(&lista);
    insereFinalL(&lista, 151);
    mostraL(&lista);
    for (int i = 0; i < 5; i++)
        insereFinalL(&lista, i);

    mostraL(&lista);
    mostrarInversoL(&lista);
    */

    /// TESTE REMOVE PRIMEIRO
    /*
    insereFinalL(&lista, 150);
    mostraL(&lista);
    removerPrimeiroNoL(&lista);
    mostraL(&lista);
    */

    ///TESTE REMOVE FINAL
    /*
    for (int i = 0; i < 5; i++)
        insereFinalL(&lista, i);

    mostraL(&lista);
    removerUltimoNoL(&lista);
    removerUltimoNoL(&lista);
    removerUltimoNoL(&lista);
    removerUltimoNoL(&lista);
    removerUltimoNoL(&lista);
    removerUltimoNoL(&lista);
    removerUltimoNoL(&lista);
    mostraL(&lista);
    */

    destroiL(&lista);
    return EXIT_SUCCESS;
}


