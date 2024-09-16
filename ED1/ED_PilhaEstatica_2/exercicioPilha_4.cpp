#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Fa�a um programa que usa uma pilha para armazenar o c�digo das cidades que fazem parte de um caminho.

� Inicialmente, o usu�rio deve informar o n�mero de cidades;
� Depois, o usu�rio deve informar o c�digo de cada cidade e incluir na pilha;
� Criar uma funcionalidade de busca de um c�digo na pilha: para fazer a busca deve usar uma pilha auxiliar;
a cada item verificado na pilha principal que for diferente do c�digo procurado, deve incluir na pilha
auxiliar; ap�s encontrar o valor, deve retornar os valores da pilha auxiliar para a pilha principal.

*/

#include "pilhas/pilha.hpp"

bool busca(Pilha *p, int valor, int numCidades);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;

    int numCidades, valor;

    cout << "Informe o n�mero de cidades: ";
    cin >> numCidades;

    inicializaP(&p, numCidades);

    cout << "[Digite o c�digo das cidades]" << endl;
    for (int i = 0; i < numCidades; i++)
    {
        cin >> valor;
        empilhaP(&p, valor);
    }

    cout << "Digite um c�digo de cidade para buscar: ";
    cin >> valor;

    if(busca(&p, valor, numCidades))
        cout << "Valor encontrado";
    else
        cout << "Valor n�o encontrado";

}

bool busca(Pilha *p, int valor, int numCidades)
{
    Pilha pAux;
    inicializaP(&pAux, numCidades);
    bool achou = false;
    int v;

    while(!vaziaP(p))
    {
        v = desempilhaP(p);
        empilhaP(&pAux, v);

        if (v == valor)
        {
            achou = true;
            break;
        }
    }

    while(!cheiaP(p))
    {
        v = desempilhaP(&pAux);
        empilhaP(p, v);
    }

    return achou;
}
