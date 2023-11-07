
#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Construa uma fun��o para ordenar uma lista simplesmente encadeada.
void ordenarL(No** lista);
Observa��o:
� � proibido o uso de listas auxiliares, percorrer os n�s da lista.
� A lista n�o pode estar vazia.
Dicas:
� Percorrer os n�s da lista, verificando o dado do n� atual e do pr�ximo (caso ele exista),
trocando os valores dos dados dos n�s caso necess�rio.
� Uma lista est� completamente ordenada quando n�o h� mais trocas de dados entre os
n�s, ou seja, ao percorrer uma lista, se nenhuma troca foi realizada, a lista est� ordenada.
*/

void ordenarL(No<int>** lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<int> *L; // cria o primeiro n�
    inicializaL(&L);

    insereInicioL(&L, 2);
    insereInicioL(&L, 3);
    insereInicioL(&L, 1);
    insereInicioL(&L, 5);
    insereInicioL(&L, 4);
    insereFinalL(&L, 6);
    insereFinalL(&L, 7);
    insereFinalL(&L, 15);
    insereFinalL(&L, 0);
    insereFinalL(&L, -5);
    insereFinalL(&L, 100);

    mostraL(&L);
    ordenarL(&L);
    mostraL(&L);
}

void ordenarL(No<int>** lista)
{
    No<int> *n = *lista;
    int numAux;
    int trocas;

    if(vaziaL(lista))
    {
        cout << "Lista vazia." << endl;
        return;
    }

    do
    {
        trocas = 0;
        while (n != NULL)
        {
            if (n->prox != NULL)
            {
                if (n->dado < n->prox->dado)
                {
                    numAux = n->dado;
                    n->dado = n->prox->dado;
                    n->prox->dado = numAux;
                    trocas++;
                }
            }
            n = n->prox;
        }
        n = *lista; // reiniciar o ponteiro
    }
    while (trocas > 0);

}
