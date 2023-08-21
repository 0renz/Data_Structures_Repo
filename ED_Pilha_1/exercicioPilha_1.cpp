#include <iostream>
using namespace std;

#include "pilha/pilha.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int escolha = -1;
    Pilha pl;
    int tamPilha, valor;

    do
    {
        system("cls");
        cout << "0 - Sair";
        cout << "\n1 - Cria pilha";
        cout << "\n2 - Inserir valor";
        cout << "\n3 - Remover valor";
        cout << "\n4 - Consultar valor";
        cout << "\n5 - Mostrar pilha";
        cout << endl << endl;

        cin >> escolha;

        if (!verificaInicializacaoP(&pl) && (escolha == 2 ||escolha == 3 ||escolha == 4 ||escolha == 5))
        {
            cout << "A pilha ainda não existe" << endl;
            system("pause");
            escolha = -1;
        }

        switch(escolha)
        {
        case 1:
            if (verificaInicializacaoP(&pl))
            {
                destroiP(&pl);
            }

            cout << "\nDigite o tamanho da pilha: ";
            cin >> tamPilha;

            inicializaP(&pl, tamPilha);
            system("pause");
            break;
        case 2:
            if (cheiaP(&pl))
            {
                cout << "A pilha está cheia" << endl;
            }
            else
            {
                cout << "Insira um valor: ";
                cin >> valor;

                if (buscaP(&pl, valor))
                {
                    cout << "O valor já existe dentro da pilha." << endl;
                }
                else
                {
                    empilhaP(&pl, valor);
                }
            }
            system("pause");
            break;
        case 3:
            if (vaziaP(&pl))
            {
                cout << "A pilha está vazia" << endl;
            }
            else
            {
                desempilhaP(&pl);
            }
            system("pause");
            break;
        case 4:
            cout << "Insira um valor: ";
            cin >> valor;

            if(buscaP(&pl, valor))
            {
               cout << "O valor " << valor << " está contido na pilha" << endl;
            }
            else
                cout << "O valor " << valor << " não está contido na pilha" << endl;
            system("pause");
            break;
        case 5:
            mostraP(&pl);
            cout << endl;
            system("pause");
            break;
        }


    }
    while (escolha != 0);
}
