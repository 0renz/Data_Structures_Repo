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



struct Caixa
{
    int codigo;
    float peso;
};

#include "pilhas/pilhaCaixa.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int escolha = -1;
    Pilha p;
    int tamPilha, valor;
    Caixa c;

    do
    {
        system("cls");
        cout << "0 - Sair";
        cout << "\n1 - Definir qtd/caixa";
        cout << "\n2 - Carregar caixa";
        cout << "\n3 - Descarregar caixa";
        cout << "\n4 - Mostrar carga";
        cout << endl << endl;

        cin >> escolha;

        switch(escolha)
        {
        case 1:
            int qtdCaixas;
            cout << "Digite a quantidade de caixas: ";
            cin >> qtdCaixas;
            inicializaP(&p, qtdCaixas);
            system("pause");
            break;
        case 2:
            cout << "Digite o código da caixa: ";
            cin >> c.codigo;
            cout << "\nDigite o peso da caixa: ";
            cin >> c.peso;

            empilhaP(&p, c);
            system("pause");
            break;
        case 3:
            desempilhaP(&p);
            system("pause");
            break;
        case 4:
            mostraP(&p);
            system("pause");
            break;
        }
    }
    while (escolha != 0);
    destroiP(&p);
}

