#include <iostream>
#include <cstdlib>
using namespace std;

#include "pilha/pilha.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int escolha = -1;
    Pilha pl;
    Pilha plImpares;
    Pilha plPares;
    int tamPilha = 6, valor;

    do
    {
        system("cls");
        cout << "0 - Sair";
        cout << "\n1 - Gera pilha inicial";
        cout << "\n2 - Mostra pilha inicial";
        cout << "\n3 - Desempilha pilha inicial";
        cout << "\n4 - Mostra pilhas de pares/ímpares";
        cout << "\n5 - Zerar pilhas";
        cout << endl << endl;


        cin >> escolha;

        switch(escolha)
        {
        case 1:
            inicializaP(&pl, tamPilha);
            for (int i = 0; i < tamPilha; i++)
            {
                valor = rand() % 15;
                empilhaP(&pl, valor);
            }
            inicializaP(&plImpares, tamPilha);
            inicializaP(&plPares, tamPilha);
            system("pause");
            break;
        case 2:
            mostraP(&pl);
            cout << endl;
            system("pause");
            break;
        case 3:
            valor = desempilhaP(&pl);
            if (valor % 2 == 0)
            {
              empilhaP(&plPares, valor);
            }
            else
              empilhaP(&plImpares, valor);
            system("pause");
            break;
        case 4:
            cout << "Pilha de ímpares:" << endl;
            mostraP(&plImpares);
            cout << endl;
            cout << "Pilha de pares:" << endl;
            mostraP(&plPares);
            cout << endl;
            system("pause");
            break;
        case 5:
            destroiP(&pl);
            destroiP(&plPares);
            destroiP(&plImpares);
            inicializaP(&pl, tamPilha);
            inicializaP(&plPares, tamPilha);
            inicializaP(&plImpares, tamPilha);
            cout << endl;
            system("pause");
            break;
        }
    }
    while (escolha != 0);
}
