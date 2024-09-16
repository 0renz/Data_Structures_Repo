#include <iostream>
using namespace std;


/*
Desenvolva um programa que permita gerenciar uma pista para descolagem de aviões de um aeroporto. Para o
correto funcionamento desta pista é necessário que seja implementada uma fila com as seguintes funcionalidades:
a) Nº de aviões à espera de decolar.
b) Entrada de um novo avião para decolar (incluir na fila).
c) Descolagem de um avião (retirar da fila).
d) Listar todos os aviões à espera para decolagem (mostrar fila).
e) Listar as características do próximo avião a decolar (peek).
Observação: para cada avião são necessárias as seguintes informações: código do avião, número de
passageiros, empresa.
*/

struct aviao
{
    int codigo;
    int numPassageiros;
    string empresa;
};

#include "filas/filacircular-ex-1.hpp"
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    aviao a, x;
    int tamFila=6, valor;
    bool resultado;
    int escolha = -1;
    inicializaF(&f1, 10);

    do
    {
        system("cls");
        cout << "[PROGRAMA DE DECOLAGEM DE AVIÕES]" << endl << endl;
        cout << "[0] Sair" << endl;
        cout << "[1] Número de aviões à espera de decolar" << endl;
        cout << "[2] Entrada de um novo avião para decolar" << endl;
        cout << "[3] Descolagem de um avião" << endl;
        cout << "[4] Listar todos os aviões à espera para decolagem" << endl;
        cout << "[5] Listar as características do próximo avião a decolar" << endl << endl;

        cout << "Escolha: ";
        cin >> escolha;

        switch(escolha)
        {
        case 1:
            system("cls");
            int num;
            cout << "Número de aviões à espera de decolar: ";
            cin >> num;

            if (num > 10)
            {
                cout << "Capacidade excedida." << endl;
                system("pause");
                break;
            }

            for (int i = 0; i < num; i++)
            {
                if (!cheiaF(&f1))
                {
                    system("cls");
                    cout << "Digite o código do avião: ";
                    cin >> a.codigo;
                    cout << "\nDigite a empresa do avião: ";
                    cin.ignore();
                    getline(cin, a.empresa);
                    cout << "\nDigite o número de passageiros do avião: ";
                    cin >> a.numPassageiros;

                    enfileiraF(&f1, a);
                }
                else
                {
                    cout << "Capacidade atingida, aguarde decolagem e tente novamente." << endl;
                    system("pause");
                    break;
                }

            }
            break;
        case 2:
            system("cls");

            if(cheiaF(&f1))
            {
                cout << "Capacidade excedida, aguarde decolagem e tente novamente." << endl;
                system("pause");
                break;
            }

            cout << "Digite o código do avião: ";
            cin >> a.codigo;
            cout << "\nDigite a empresa do avião: ";
            cin.ignore();
            getline(cin, a.empresa);
            cout << "\nDigite o número de passageiros do avião: ";
            cin >> a.numPassageiros;

            enfileiraF(&f1, a);
            break;
        case 3:
            x = desenfileiraF(&f1);
            cout << "O avião " << x.codigo << " da empresa " << x.empresa << " decolou com " << x.numPassageiros << " passageiros";
            cout << endl;
            system("pause");
            break;
        case 4:
            mostraF(&f1);
            cout << endl;
            system("pause");
            break;
        case 5:
            if(vaziaF(&f1))
            {
                cout << "Não há aviões para decolar." << endl;
                system("pause");
            }
            else
            {
                x = espiaF(&f1);
                cout << "O avião " << x.codigo << " da empresa " << x.empresa << " decolará com " << x.numPassageiros << " passageiros";
                cout << endl;
                system("pause");
            }
            break;
        }
    }
    while (escolha != 0);

    destroiF(&f1);
    return EXIT_SUCCESS;
}
