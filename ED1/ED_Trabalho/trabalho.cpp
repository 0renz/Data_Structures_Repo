#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>

using namespace std;

struct FichaCliente
{
    int codigo;
    string nome;
    int idade;
    float saldoEmConta;

    FichaCliente()
    {
    }
};

#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"

bool Entradaduplicada (int num, Pilha *Cadastro);
void ordemAlfabetica(Pilha *Cadastro);
void AdicionaFila(int num, Pilha *Cadastro, Fila *P, Fila *N, Fila *D);
bool verificaFila (int *fAux, Fila **fila);
void saque(int num, float valor, Pilha *Cadastro);
void deposito(int num, float valor, Pilha *Cadastro);
bool limiteSaque(Pilha *Cadastro, float valor);
void dadosBanco(Pilha *Cadastro);


int main()
{
    setlocale(LC_ALL, "Portuguese");

    Fila P, N, D;
    Pilha Cadastro;

    string operacao = "";

    ifstream entrada;
    entrada.open("entrada.txt");

    if(entrada.is_open())
    {
        int num;
        string nome;
        float saldo, valor;
        char c;
        FichaCliente ficha;

        while(entrada >> operacao)
        {
            if (operacao == "CADASTRAR")
            {
                entrada >> num;
                if (Entradaduplicada(num, &Cadastro))
                {
                    cout << "ERRO: Código duplicado" << endl;
                    getc(stdin);
                }
                else
                {
                    ficha.codigo = num;
                    entrada >> nome >> num >> saldo;
                    ficha.nome = nome;
                    ficha.idade = num;
                    ficha.saldoEmConta = saldo;

                    empilhaP(&Cadastro, ficha);
                    ordemAlfabetica(&Cadastro);
                    cout << "Cadastro de " << nome << " realizado com sucesso" << endl;
                    getc(stdin);
                }
            }
            else if (operacao == "ADDFILA")
            {
                entrada >> num;
                AdicionaFila(num, &Cadastro, &P, &N, &D);
            }
            else if (operacao == "MOSTRAR")
            {
                entrada >> c;
                {
                    if (c == 'P')
                    {
                        if (!vaziaP(&Cadastro))
                        {
                            mostraP(&Cadastro);
                            getc(stdin);
                        }
                        else
                        {
                            cout << "Pilha vazia" << endl;
                            getc(stdin);
                        }
                    }
                    else if (c == 'F')
                    {
                        if (vaziaF(&P) && vaziaF(&N) && vaziaF(&D))
                        {
                            cout << "Filas vazias" << endl;
                            getc(stdin);
                        }
                        else
                        {
                            mostraF(&P);
                            mostraF(&N);
                            mostraF(&D);
                            cout << endl;
                            getc(stdin);
                        }
                    }
                }
            }
            else if (operacao == "ATENDERCLIENTE")
            {
                entrada >> c >> valor; // c = Saque/Depósito

                if (c == 'S')
                {
                    if (!vaziaF(&P))
                    {
                        num = desenfileiraF(&P);
                        if (!limiteSaque(&Cadastro, valor))
                        {
                            saque(num, valor, &Cadastro);
                        }
                    }
                    else
                    {
                        if (!vaziaF(&N))
                        {
                            num = desenfileiraF(&N);
                            if (!limiteSaque(&Cadastro, valor))
                            {
                                saque(num, valor, &Cadastro);
                            }
                        }
                        else
                        {
                            if (!vaziaF(&D))
                            {
                                num = desenfileiraF(&D);
                                if (!limiteSaque(&Cadastro, valor))
                                {
                                    saque(num, valor, &Cadastro);
                                }
                            }
                            else
                            {
                                cout << "Erro: não há clientes nas filas" << endl;
                                getc(stdin);
                            }
                        }
                    }
                }
                else if (c == 'D')
                {
                    if (!vaziaF(&P))
                    {
                        num = desenfileiraF(&P);
                        deposito(num, valor, &Cadastro);
                    }
                    else
                    {
                        if (!vaziaF(&N))
                        {
                            num = desenfileiraF(&N);
                            deposito(num, valor, &Cadastro);
                        }
                        else
                        {
                            if (!vaziaF(&D))
                            {
                                num = desenfileiraF(&D);
                                deposito(num, valor, &Cadastro);
                            }
                            else
                            {
                                cout << "Erro: não há clientes nas filas" << endl;
                                getc(stdin);
                            }
                        }
                    }
                }
            }
            else if (operacao == "DADOSBANCO")
            {
                dadosBanco(&Cadastro);
            }
        }
    }
    else
        cout << "erro";
}

bool Entradaduplicada (int num, Pilha *Cadastro)
{
    int numAux;
    bool duplicado = false;
    Pilha pAux;
    FichaCliente fAux;


    while(!vaziaP(Cadastro))
    {
        fAux = desempilhaP(Cadastro);

        if (fAux.codigo == num)
        {
            duplicado = true;
        }
        empilhaP(&pAux, fAux);
    }

    while(!vaziaP(&pAux))
        empilhaP(Cadastro, desempilhaP(&pAux));

    return duplicado;
}

void ordemAlfabetica(Pilha *Cadastro)
{
    FichaCliente cOrd, cAux, cAux2;
    Pilha pAux;

    while(!vaziaP(Cadastro))
    {
        cOrd = desempilhaP(Cadastro);

        while(!vaziaP(&pAux) && cAux2.nome > cOrd.nome)
        {
            cAux = desempilhaP(&pAux);
            empilhaP(Cadastro, cAux);
        }
        empilhaP(&pAux, cOrd);
        cAux2 = espiaP(&pAux);
    }

    while(!vaziaP(&pAux))
    {
        cAux = desempilhaP(&pAux);
        empilhaP(Cadastro, cAux);
    }
}

void AdicionaFila(int num, Pilha *Cadastro, Fila *P, Fila *N, Fila *D)
{
    FichaCliente fAux;
    Pilha pAux;
    bool achouCodigo = false;

    while(!vaziaP(Cadastro))
    {
        fAux = desempilhaP(Cadastro);

        if (fAux.codigo == num)
        {
            achouCodigo = true;
            if (fAux.idade > 60)
            {
                if(!verificaFila(&fAux.codigo, &P))
                {
                    enfileiraF(P, fAux.codigo);
                    cout << fAux.nome << " (cod " << fAux.codigo << ") adicionado na fila P com sucesso." << endl;
                    getc(stdin);
                }
                else
                {
                    cout << "Erro: " << fAux.nome << " já está na fila aguardando atendimento." << endl;
                    getc(stdin);
                }
            }
            else if (fAux.idade < 60 && fAux.saldoEmConta > 0)
            {
                if(!verificaFila(&fAux.codigo, &N))
                {
                    enfileiraF(N, fAux.codigo);
                    cout << fAux.nome << " (cod " << fAux.codigo << ") adicionado na fila N com sucesso." << endl;
                    getc(stdin);
                }
                else
                {
                    cout << "Erro: " << fAux.nome << " já está na fila aguardando atendimento." << endl;
                    getc(stdin);
                }
            }
            else if (fAux.idade < 60 && fAux.saldoEmConta < 0)
            {
                if(!verificaFila(&fAux.codigo, &D))
                {
                    enfileiraF(D, fAux.codigo);
                    cout << fAux.nome << " (cod " << fAux.codigo << ") adicionado na fila D com sucesso." << endl;
                    getc(stdin);
                }
                else
                {
                    cout << "Erro: " << fAux.nome << " já está na fila aguardando atendimento." << endl;
                    getc(stdin);
                }
            }
        }
        empilhaP(&pAux, fAux);
    }

    while(!vaziaP(&pAux))
        empilhaP(Cadastro, desempilhaP(&pAux));

    if (!achouCodigo)
    {
        cout << "ERRO: Código inexistente" << endl;
        getc(stdin);
    }
}

bool verificaFila (int *fAux, Fila **fila)
{
    int numAux;
    Fila filaAux;
    bool duplicadoFila = false;


    while(!vaziaF(*fila))
    {
        numAux = desenfileiraF(*fila);

        if (numAux == *fAux)
        {
            duplicadoFila = true;
        }
        enfileiraF(&filaAux, numAux);
    }

    while(!vaziaF(&filaAux))
        enfileiraF(*fila, desenfileiraF(&filaAux));

    return duplicadoFila;
}

void saque(int num, float valor, Pilha *Cadastro)
{
    Pilha pAux;
    FichaCliente fichaAux2;

    while(!vaziaP(Cadastro))
    {
        fichaAux2 = desempilhaP(Cadastro);

        if (fichaAux2.codigo == num)
        {
            fichaAux2.saldoEmConta -= valor;
            cout << fichaAux2.nome << " sacou R$" << valor << endl;
            getc(stdin);
        }
        empilhaP(&pAux, fichaAux2);
    }

    while(!vaziaP(&pAux))
    {
        empilhaP(Cadastro, desempilhaP(&pAux));
    }
}

void deposito(int num, float valor, Pilha *Cadastro)
{
    Pilha pAux;
    FichaCliente fichaAux2;

    while(!vaziaP(Cadastro))
    {
        fichaAux2 = desempilhaP(Cadastro);

        if (fichaAux2.codigo == num)
        {
            fichaAux2.saldoEmConta += valor;
            cout << fichaAux2.nome << " depositou R$" << valor << endl;
            getc(stdin);
        }
        empilhaP(&pAux, fichaAux2);
    }

    while(!vaziaP(&pAux))
    {
        empilhaP(Cadastro, desempilhaP(&pAux));
    }
}

bool limiteSaque(Pilha *Cadastro, float valor)
{
    Pilha pAux;
    FichaCliente fichaAux;
    float LimiteAtual;

    while(!vaziaP(Cadastro))
    {
        fichaAux = desempilhaP(Cadastro);
        LimiteAtual += fichaAux.saldoEmConta;
        empilhaP(&pAux, fichaAux);
    }

    LimiteAtual = (LimiteAtual * 0.8);

    while(!vaziaP(&pAux))
    {
        empilhaP(Cadastro, desempilhaP(&pAux));
    }

    if (valor < LimiteAtual)
    {
        return false;
    }
    else
    {
        cout << "Erro: Não foi possível realizar o saque do valor informado. O limite atual de saque é de " << LimiteAtual << endl;
        getc(stdin);
        return true;
    }
}

void dadosBanco(Pilha *Cadastro)
{
    Pilha pAux;
    FichaCliente fichaAux;
    int numClientes = 0, numClientesNegativos = 0;
    float salarioMedio = 0.0, somaSaldos = 0.0;

    while(!vaziaP(Cadastro))
    {
        fichaAux = desempilhaP(Cadastro);
        numClientes++;

        if(fichaAux.saldoEmConta < 0)
            numClientesNegativos++;

        salarioMedio += fichaAux.saldoEmConta;
        somaSaldos += fichaAux.saldoEmConta;
        empilhaP(&pAux, fichaAux);
    }

    salarioMedio = salarioMedio / numClientes;

    while(!vaziaP(&pAux))
    {
        empilhaP(Cadastro, desempilhaP(&pAux));
    }

    cout << "Total clientes: " << numClientes << "; Clientes com saldo negativo: "
    << numClientesNegativos << "; Saldo médio: " << salarioMedio
    << "; Soma dos saldos: " << somaSaldos << endl;
    getc(stdin);
}
