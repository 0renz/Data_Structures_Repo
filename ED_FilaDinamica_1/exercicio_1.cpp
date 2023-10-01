#include <iostream>
using namespace std;

/*
Dada uma fila dinâmica F, implemente uma função para inverter a ordem dos elementos F. Para inverter a ordem
dos elementos, faça uso de uma pilha dinâmica P.
O menu deve conter as seguintes opções:
− Incluir na fila
− Remover da fila
− Mostrar fila
− Inverter fila
*/

#include "filas/fila-dinamica.hpp"
#include "pilhas/pilha-dinamica.hpp"

bool inverteF(Fila *f);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int escolha = -1;
    Fila f;

    do
    {
        system("cls");
        cout << "Menu de opções";
        cout << "\n\n0 - Sair";
        cout << "\n1 - Incluir na fila";
        cout << "\n2 - Remover da fila";
        cout << "\n3 - Mostrar fila";
        cout << "\n4 - Inverter fila";

        cout << "\n\nEscolha: ";
        cin >> escolha;

        switch(escolha)
        {
        case 1:
            int valor;
            cout << "\nDigite um valor: ";
            cin >> valor;
            enfileiraF(&f, valor);
            break;
        case 2:
            desenfileiraF(&f);
            cout << "Desenfileirado.";
            system("pause");
            break;
        case 3:
            mostraF(&f);
            system("pause");
            break;
        case 4:
            if(inverteF(&f))
                mostraF(&f);
            system("pause");
            break;
        }

    } while (escolha != 0);
}

bool inverteF(Fila *f)
{
    Pilha p;

    if(vaziaF(f))
    {
        cout << "Fila vazia!" << endl;
        return false;
    }
    else
    {
        while(!vaziaF(f))
        {
            empilhaP(&p, desenfileiraF(f));
        }
        while(!vaziaP(&p))
        {
            enfileiraF(f, desempilhaP(&p));
        }
    }
    return true;
}
