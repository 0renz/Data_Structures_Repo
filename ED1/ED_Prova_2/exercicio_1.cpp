#include <iostream>
using namespace std;

#include "lista/lista - Copia.hpp"

void mesclar(No** L1, No** L2, No** L3, int k);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *L1; // cria o primeiro nó
    inicializaL(&L1);

    No *L2; // cria o primeiro nó
    inicializaL(&L2);

    No *L3; // cria o primeiro nó
    inicializaL(&L3);

    insereInicioL(&L1, 40);
    insereInicioL(&L1, 30);
    insereInicioL(&L1, 20);
    insereInicioL(&L1, 10);

    insereInicioL(&L2, 500);
    insereInicioL(&L2, 400);
    insereInicioL(&L2, 300);
    insereInicioL(&L2, 200);
    insereInicioL(&L2, 100);

    mesclar(&L1, &L2, &L3, 2);

    cout << "L1: ";
    mostraL(&L1);
    cout << "L2: ";
    mostraL(&L2);
    cout << "L3: ";
    mostraL(&L3);

    destroiL(&L1);
    destroiL(&L2);

    cout << "L3: ";
    mostraL(&L3);

    destroiL(&L3);
    return EXIT_SUCCESS;
}

void mesclar(No** L1, No** L2, No** L3, int k)
{
    int cont = 0;

    if (k < 0)
    {
        cout << "Erro: K deve ser de 0 a N" << endl;
        return;
    }

    if (k > totalL(L1))
    {
        cout << "Erro: K maior que L1" << endl;
        return;
    }

    No *n = *L1;
    No *n2 = *L2;

    while(n)
    {
        if (cont == k)
        {
            while(n2)
            {
                insereFinalL(L3, n2->dado);
                n2 = n2->prox;
            }
        }
        insereFinalL(L3, n->dado);
        cont++;

        n = n->prox;
    }

    if (k == totalL(L1))
    {
        while(n2)
        {
            insereFinalL(L3, n2->dado);
            n2 = n2->prox;
        }
    }

}


