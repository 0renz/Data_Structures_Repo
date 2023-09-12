#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

/*
Implemente um programa que manipule uma pilha dinâmica P. O programa deve ler o arquivo entrada.txt e
realizar as operações:
o Inserir(V) – Inserir o valor V na pilha P e imprimir “O valor V foi inserido na pilha”.
o Remover() – Remover um elemento da pilha P e imprimir “O elemento X foi removido da pilha.’
Caso a pilha esteja vazia, imprimir a mensagem “PILHA VAZIA”.
o Consultar(V) – Verificar se V está armazenado na pilha. Imprimir “O valor V está armazenado na
pilha” ou “O valor V não está armazenado na pilha”.
o Mostrar() – Mostar os elementos da pilha. Caso a pilha esteja vazia, imprimir “PILHA VAZIA”
*/

#include "Pilhas/pilha-dinamica-ex-02.hpp"

void consultaP(Pilha *p, int n);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int escolha = -1;
    string operacao;

    Pilha p;

    ifstream entrada;
    entrada.open("entrada.txt");

    if(entrada.is_open())
    {
        int n, valorPop;

        while(entrada)

            while(entrada >> operacao)
            {
                if (operacao == "MOSTRAR")
                {
                    if(vaziaP(&p))
                    {
                        cout << "PILHA VAZIA" << endl;
                        getc(stdin);
                    }
                    else
                    {
                        mostraP(&p);
                        cout << endl;
                        getc(stdin);
                    }

                }
                else if (operacao == "REMOVER")
                {
                    if(vaziaP(&p))
                    {
                        cout << "PILHA VAZIA" << endl;
                        getc(stdin);
                    }
                    else
                    {
                        valorPop = desempilhaP(&p);
                        cout << "O valor " << valorPop << " foi removido da pilha." << endl;
                        getc(stdin);
                    }

                }
                else if (operacao == "CONSULTAR")
                {
                    entrada >> n;
                    consultaP(&p, n);
                }
                else if (operacao == "INSERIR")
                {
                    entrada >> n;
                    empilhaP(&p, n);
                    cout << "O valor " << n << " foi inserido na pilha" << endl;
                    getc(stdin);
                }
                else if (operacao == "REMOVERTODOS")
                {
                    destroiP(&p);
                    cout << "Todos os elementos removidos" << endl;
                    getc(stdin);
                }
            }
    }
    else
        cout << "Erro ao abrir o arquivo";
}

void consultaP(Pilha *p, int n)
{
    Pilha aux;
    int valor;
    bool armazenado = false;

    while(!vaziaP(p))
    {
        valor = desempilhaP(p);
        empilhaP(&aux, valor);

        if (valor == n)
        {
            armazenado = true;
        }
    }

    while(!vaziaP(&aux))
    {
        valor = desempilhaP(&aux);
        empilhaP(p, valor);
    }

    if(armazenado)
    {
        cout << "O valor " << n << " está armazenado na pilha" << endl;
        getc(stdin);
    }
    else
    {
        cout << "O valor " << n << " não está armazenado na pilha" << endl;
        getc(stdin);
    }
}
