#include <iostream>
using namespace std;

#include "listas/lista.hpp"

/*
Fa�a uma fun��o que verifica se uma lista encadeada est� ordenada:
int verificaOrdem(No** lista);
Retorno da fun��o:
0 � Ordem crescente
1 � Ordem decrescente;
2 � N�o est� ordenada.
Observa��o: � proibido o uso de listas auxiliares, percorrer os n�s da lista.
*/

int verificaOrdem(No<int>** lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<int> *L; // cria o primeiro n�
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
        cout << "N�o est� ordenada" << endl;
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



