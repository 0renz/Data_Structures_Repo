#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Faça uma função que verifica se uma lista encadeada está ordenada:
int verificaOrdem(No** lista);
Retorno da função:
0 – Ordem crescente
1 – Ordem decrescente;
2 – Não está ordenada.
Observação: É proibido o uso de listas auxiliares, percorrer os nós da lista.
*/

int verificaOrdem(No<int>** lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<int> *L; // cria o primeiro nó
    inicializaL(&L);

    for(int i = 10; i > 0; i--)
        insereInicioL(&L, i);

    mostraL(&L);

    if (verificaOrdem(&L) == 0)
    {
        cout << "Ordem crescente" << endl;
    }
    else if (verificaOrdem(&L) == 1)
    {
        cout << "Ordem decrescente" << endl;
    }
    else
    {
        cout << "Não está ordenada" << endl;
    }
}

int verificaOrdem(No<int>** lista)
{
    No<int> *n = *lista;

    if (n->dado <= n->prox->dado)
    {
        for (int i = 0; i < totalL(lista)-1; i++)
        {
            if (n->dado > n->prox->dado)
            {
                return 2;
            }
            n = n->prox;
        }
        return 0;
    }

    if (n->dado >= n->prox->dado)
    {
        for (int i = 0; i < totalL(lista)-1; i++)
        {
            if (n->dado < n->prox->dado)
            {
                return 2;
            }
            n = n->prox;
        }
        return 1;
    }

    cout << " ";
    return 2;
}



