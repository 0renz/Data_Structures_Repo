#include <iostream>
#include <cstdlib>
using namespace std;

#include "pilha/pilhaString.hpp"


int main(void)
{
     setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Pilha p;
    int escolha = -1;
    string valor;

    inicializaP(&p, 5);

    do
    {
        system("cls");
        mostraP(&p);
        cout << endl;
        cout << "0 - Sair";
        cout << "\n1 - Escreve valor";
        cout << endl;
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            cout << "\nDigite um valor para escrever: ";
            cin.ignore();
            getline(cin, valor);
            (empilhaP(&p, valor));
            system("pause");
            break;
        case 2:
            mostraP(&p);
            system("pause");
            break;
        }
    }
    while (escolha != 0);
}
