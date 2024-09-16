
#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Construa uma função para ordenar uma lista simplesmente encadeada.
void ordenarL(No** lista);
Observação:
• É proibido o uso de listas auxiliares, percorrer os nós da lista.
• A lista não pode estar vazia.
Dicas:
• Percorrer os nós da lista, verificando o dado do nó atual e do próximo (caso ele exista),
trocando os valores dos dados dos nós caso necessário.
• Uma lista está completamente ordenada quando não há mais trocas de dados entre os
nós, ou seja, ao percorrer uma lista, se nenhuma troca foi realizada, a lista está ordenada.
*/

void ordenarL(No<int>** lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<int> *L; // cria o primeiro nó
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
