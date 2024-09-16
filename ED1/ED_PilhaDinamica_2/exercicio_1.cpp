#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

/*
O banco BanPasso possui diversos clientes. O cadastro de novos clientes do banco é realizado perante o
preenchimento de uma ficha, a qual possui os seguintes dados: código, nome, idade, saldo em conta (valor do
depósito inicial). Com a ficha de um cliente preenchida, o cadastro é concluído empilhando na pilha CADASTRO.
Não pode haver clientes com o mesmo código cadastrado e a ficha é empilhada sempre mantendo a ordem
alfabética dos clientes.
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
    cout << "Digite o código: ";
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
       cout << "Cliente com mesmo código detectado, tente outro" << endl;
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

