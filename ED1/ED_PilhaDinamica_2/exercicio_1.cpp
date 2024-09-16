#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
O banco BanPasso possui diversos clientes. O cadastro de novos clientes do banco � realizado perante o
preenchimento de uma ficha, a qual possui os seguintes dados: c�digo, nome, idade, saldo em conta (valor do
dep�sito inicial). Com a ficha de um cliente preenchida, o cadastro � conclu�do empilhando na pilha CADASTRO.
N�o pode haver clientes com o mesmo c�digo cadastrado e a ficha � empilhada sempre mantendo a ordem
alfab�tica dos clientes.
*/

struct Cadastro
{
    string nome;
    int codigo;
    int idade;
    float saldo;
};

#include "Pilhas/pilha-dinamica-ex-01.hpp"

void cadastrar(Pilha *p, Cadastro c);
void mostrar(Pilha *p, Cadastro c);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int escolha = -1;

    Pilha p;
    Cadastro c;

    do
    {
        system("cls");
        cout << "[CADASTRO]" << endl;
        cout << "\n[0] Sair";
        cout << "\n[1] Cadastrar";
        cout << "\n[2] Mostrar cadastros" << endl << endl;
        cin >> escolha;

        switch(escolha)
        {
        case 1:
            cadastrar(&p, c);
            break;
        case 2:
            mostrar(&p, c);
            break;
        }

    }
    while (escolha != 0);
}

void cadastrar(Pilha *p, Cadastro c)
{
    Pilha pAux;
    Cadastro cOrd, cAux;
    bool mesmoCodigo = false;

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, c.nome);
    cout << "Digite o c�digo: ";
    cin >> c.codigo;


    while(!vaziaP(p))
    {
        cAux = desempilhaP(p);

        empilhaP(&pAux, cAux);
        if ((cAux.codigo) == c.codigo)
        {
            mesmoCodigo = true;
        }
    }
    while(!vaziaP(&pAux))
    {
        cAux = desempilhaP(&pAux);
        empilhaP(p, cAux);
    }

    if(mesmoCodigo)
    {
       cout << "Cliente com mesmo c�digo detectado, tente outro" << endl;
       system("pause");
       return;
    }


    cout << "Digite a idade: ";
    cin >> c.idade;
    cout << "Digite o saldo em conta: ";
    cin >> c.saldo;

    empilhaP(p, c);



    while(!vaziaP(p))
    {
        cOrd = desempilhaP(p);

        while(!vaziaP(&pAux) && espiaPNome(&pAux) > cOrd.nome)
        {
            cAux = desempilhaP(&pAux);
            empilhaP(p, cAux);
        }
        empilhaP(&pAux, cOrd);

    }

    while(!vaziaP(&pAux))
    {
        cAux = desempilhaP(&pAux);
        empilhaP(p, cAux);
    }
}

void mostrar(Pilha *p, Cadastro c)
{
    system("cls");
    mostraP(p);
    system("pause");
}

