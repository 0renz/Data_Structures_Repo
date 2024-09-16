#include <iostream>
#include <cstring>
using namespace std;

#include "listas/lista_dupla_generica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista<int> lista = Lista<int>();//chama o construtor para inicilizar a lista

    insereOrdenadoL(&lista, 5);
    insereOrdenadoL(&lista, 3);
    insereOrdenadoL(&lista, 2);
    insereOrdenadoL(&lista, 4);
    insereOrdenadoL(&lista, 1);

    mostraL(&lista);

    return EXIT_SUCCESS;
}
