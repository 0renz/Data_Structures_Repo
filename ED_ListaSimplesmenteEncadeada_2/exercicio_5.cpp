#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Implemente uma fun��o e inserir de forma ordenada em uma lista encadeada.
void insereOrdenado(No** lista, int valor);
Observa��o:
� � proibido o uso de listas auxiliares, percorrer os n�s da lista e ajustar os ponteiros;
� Considere que a lista est� inicialmente vazia.
Dicas:
� Use como base a fun��o removeValor, ajustando os ponteiros dos n�s e levando em
considera��o se o elemento ser� inserido no in�cio da lista, no meio ou no final.
*/

void insereOrdenado(No<int>** lista, int valor);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<int> *L; // cria o primeiro n�
    inicializaL(&L);


    insereOrdenado(&L, 4);
    insereOrdenado(&L, 2);
    insereOrdenado(&L, 1);
    insereOrdenado(&L, 8);
    insereOrdenado(&L, 3);

    mostraL(&L);

    return EXIT_SUCCESS;
}

void insereOrdenado(No<int>** lista, int valor)
{
    No<int> *n = *lista;
    No<int> *novo = new No<int>();
    novo->dado = valor;
    No<int> *aux = new No<int>();

    int valorAux;

    if(n == NULL || valor < n->dado)
    {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    while (n != NULL && novo->dado > n->dado)
    {
        aux = n;
        n = n->prox;
    }

    // Atualizar ponteiros para inserir o novo n� no meio
    aux->prox = novo;
    novo->prox = n;
}
