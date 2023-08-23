#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
Uma transportadora precisa de um sistema para gerenciar o carregamento de caixas nos caminhões da empresa.
Implemente um programa que atenda a necessidade da empresa, empregando uma pilha para definir a ordem do
carregamento e descarregamento das caixas em um caminhão.
• O programa deve possuir um menu com as opções:
o Definir quantidade de caixa – Criar uma pilha que suporte a quantidade de caixas informada.
o Carregar caixa - empilhar
o Descarregar caixa - desempilhar
o Mostar carga – mostrar pilha
o Sair do programa

*/

#include "pilhas/pilhaCaixa.hpp"

struct Caixa
{
    int codigo;
    float peso;
};


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int escolha = -1;
    Pilha pl;
    int tamPilha, valor;

    do
    {
        system("cls");
        cout << "0 - Sair";
        cout << "\n1 - ";
        cout << "\n2 - ";
        cout << "\n3 - ";
        cout << "\n4 - ";
        cout << "\n5 - ";
        cout << endl << endl;

        cin >> escolha;

        switch(escolha)
        {
        case 1:

            system("pause");
            break;
        case 2:

            system("pause");
            break;
        case 3:

            system("pause");
            break;
        case 4:

            system("pause");
            break;
        case 5:

            system("pause");
            break;
        }
    }
    while (escolha != 0);
}

