#include <iostream>
#include <cstdlib>
using namespace std;

#include "pilha/pilha.hpp"

bool buscaValor(Pilha *p, int valor);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;
    int escolha = -1;
    int valor;

    inicializaP(&p, 5);
    for (int i = 0; i < 5; i++)
    {
        valor = rand() % 15;
        empilhaP(&p, valor);
    }

    do
    {
        system("cls");
        mostraP(&p);
        cout << endl;
        cout << "0 - Sair";
        cout << "\n1 - Buscar valor";
        cout << endl;
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            cout << "\nDigite um valor para buscar: ";
            cin >> valor;
            if (buscaValor(&p, valor))
                cout << "\nO valor " << valor << " está presente na pilha P";
            else
                cout << "\nO valor " << valor << " não está presente na pilha P";
            cout << endl;
            system("pause");
            break;
        }
    }
    while (escolha != 0);
}

bool buscaValor(Pilha *p, int valor)
{
    Pilha pAux;
    int v;
    inicializaP(&pAux, 5);

    bool encontrou = false;

    while(!vaziaP(p))
    {
        v = desempilhaP(p);
        empilhaP(&pAux, v);
        if (v == valor)
        {
            encontrou = true;
            break;
        }
    }

    while(!cheiaP(p))
    {
        v = desempilhaP(&pAux);
        empilhaP(p, v);
    }

    return encontrou;
}
