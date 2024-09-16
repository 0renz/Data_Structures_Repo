#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "listas/lista_dupla_generica.hpp"

void inserirCaractereApos(Lista<char> *L, char valor, char caractereApos);
void contarOcorrencia(Lista<char> *L1, Lista<char> *L2);
void inserirAntesPrimeiraOcorrencia (Lista<char> *L1, Lista<char> *L2, Lista<char> *L3);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    ifstream entrada;
    entrada.open("entrada1.txt");
    string operacao = "";

    Lista<char> L1 = Lista<char>();
    Lista<char> L2 = Lista<char>();
    Lista<char> L3 = Lista<char>();


    if (entrada.is_open())
    {
        string lista;
        string ordem;
        int quantidade;
        char valor;

        while(entrada >> operacao)
        {
            if (operacao == "mostrar")
            {
                entrada >> lista;
                entrada >> valor;

                if (lista == "L1")
                {
                    if (!vaziaL(&L1))
                    {
                        cout << lista;
                        if (valor == 'N')
                        {
                            cout << " " << valor << ": ";
                            mostraL(&L1);
                        }
                        else if (valor == 'I')
                        {
                            cout << " " << valor << ": ";
                            mostrarInversoL(&L1);
                        }
                    }
                    else
                    {
                        cout << lista << "-" << valor << ": VAZIA" << endl;
                    }
                }
                else if (lista == "L2")
                {
                    if (!vaziaL(&L2))
                    {
                        cout << lista;
                        if (valor == 'N')
                        {
                            cout << " " << valor << ": ";
                            mostraL(&L2);
                        }
                        else if (valor == 'I')
                        {
                            cout << " " << valor << ": ";
                            mostrarInversoL(&L2);
                        }
                    }
                    else
                    {
                        cout << lista << "-" << valor << ": VAZIA" << endl;
                    }
                }
                else if (lista == "L3")
                {
                    if (!vaziaL(&L2))
                    {
                        cout << lista;
                        if (valor == 'N')
                        {
                            cout << " " << valor << ": ";
                            mostraL(&L3);
                        }
                        else if (valor == 'I')
                        {
                            cout << " " << valor << ": ";
                            mostrarInversoL(&L3);
                        }
                    }
                    else
                    {
                        cout << lista << "-" << valor << ": VAZIA" << endl;
                    }
                }
            }
            else if (operacao == "inserir")
            {
                entrada >> lista;
                entrada >> quantidade;

                if (lista == "L1")
                {
                    cout << "Os caracteres <";
                    for (int i = 0; i < quantidade; i++)
                    {
                        entrada >> valor;
                        cout << valor;
                        insereFinalL(&L1, valor);
                    }
                    cout << "> foram inseridos na lista " << lista << endl;
                }
                else if (lista == "L2")
                {
                    cout << "Os caracteres <";
                    for (int i = 0; i < quantidade; i++)
                    {
                        entrada >> valor;
                        cout << valor;
                        insereFinalL(&L2, valor);
                    }
                    cout << "> foram inseridos na lista " << lista << endl;
                }
                else if (lista == "L3")
                {
                    cout << "Os caracteres <";
                    for (int i = 0; i < quantidade; i++)
                    {
                        entrada >> valor;
                        cout << valor;
                        insereFinalL(&L3, valor);
                    }
                    cout << "> foram inseridos na lista " << lista << endl;
                }
            }
            else if (operacao == "substituir")
            {
                entrada >> lista;
                entrada >> quantidade;

                if (lista == "L1")
                {
                    removeTudo(&L1);
                    cout << "Substituição de "<< lista << " pelos caracteres <";

                    for (int i = 0; i < quantidade; i++)
                    {
                        entrada >> valor;
                        cout << valor;
                        insereFinalL(&L1, valor);
                    }
                    cout << ">" << endl;
                }
                else if (lista == "L2")
                {
                    removeTudo(&L2);
                    cout << "Substituição de "<< lista << " pelos caracteres <";

                    for (int i = 0; i < quantidade; i++)
                    {
                        entrada >> valor;
                        cout << valor;
                        insereFinalL(&L2, valor);
                    }
                    cout << ">" << endl;
                }
                else if (lista == "L3")
                {
                    removeTudo(&L3);
                    cout << "Substituição de "<< lista << " pelos caracteres <";

                    for (int i = 0; i < quantidade; i++)
                    {
                        entrada >> valor;
                        cout << valor;
                        insereFinalL(&L3, valor);
                    }
                    cout << ">" << endl;
                }
            }
            else if (operacao == "inserirCaractereApos")
            {
                char caractereApos;
                entrada >> lista;
                entrada >> valor;
                entrada >> caractereApos;

                if (lista == "L1")
                {
                    inserirCaractereApos(&L1, valor, caractereApos);
                    cout << "L1" << endl;
                }
                else if (lista == "L2")
                {
                    inserirCaractereApos(&L2, valor, caractereApos);
                    cout << "L2" << endl;
                }
                else if (lista == "L3")
                {
                    inserirCaractereApos(&L3, valor, caractereApos);
                    cout << "L3" << endl;
                }
            }
            else if (operacao == "contarOcorrencia")
            {
                contarOcorrencia(&L1, &L2);
            }
            else if (operacao == "inserirAntesPrimeiraOcorrencia")
            {
                inserirAntesPrimeiraOcorrencia (&L1, &L2, &L3);
            }
        }

    }
    else
        cout << "Unable to open file";

    return EXIT_SUCCESS;
}

void inserirCaractereApos(Lista<char> *L, char valor, char caractereApos)
{
    Lista<char> LAux = Lista<char>();
    char aux;
    int cont = 0;

    while (!vaziaL(L))
    {
        aux = removerPrimeiroNoL(L);
        if (aux == caractereApos)
        {
            insereFinalL(&LAux, aux);
            insereFinalL(&LAux, valor);
            cont++;
            continue;
        }
        insereFinalL(&LAux, aux);
    }

    while (!vaziaL(&LAux))
    {
        insereInicioL(L, removerUltimoNoL(&LAux));
    }

    if (cont > 0)
        cout << "Foram inseridos " << cont << " caracteres <" << valor << "> após o caractere <" << caractereApos << "> na lista ";
    else
        cout << "Não existem caracteres <" << caractereApos << "> na lista ";
}

bool verifica(No<char> *n1, Lista<char> *L2)
{
    No<char> *n2 = L2->inicio;

    int tamanhoN2 = 0;

    while(n2)
    {
        if (n1->dado != n2->dado)
        {
            return false;
        }

        //cout << "TAMANHO contador 2 " << tamanhoN2 << endl;
        //cout << "TAMANHO LISTA 2 " << L2->tamanho << endl;

        n2 = n2->prox;
        n1 = n1->prox;
    }
    n2 = L2->inicio;
    return true;
}

void contarOcorrencia(Lista<char> *L1, Lista<char> *L2)
{
    No<char> *n1 = L1->inicio;

    int contOcorrencias = 0;

    while (n1)
    {
        if (verifica(n1, L2))
        {
            contOcorrencias++;
        }
        n1 = n1->prox;
    }


    No<char> *n2 = L2->inicio;
    cout << "Total de ocorrencias <";
    while (n2)
    {
        cout << n2;
        n2 = n2->prox;
    }
    cout << "> " << " na lista L1: " << contOcorrencias << endl;
    n2 = L2->inicio;

    if (contOcorrencias == 0)
    {
        cout << "A ocorrência <";
        while (n2)
        {
            cout << n2->dado;
            n2 = n2->prox;
        }
        cout << "> não foi encontrado na lista L1" << endl;
    }
}

int verificaPosicao(No<char> *n1, Lista<char> *L2)
{
    No<char> *n2 = L2->inicio;

    int posicao = 0;
    bool primeiro = true;

    while(n2)
    {
        if (n2->dado != n1->dado)
        {
            posicao++;
        }

        n2 = n2->prox;
        n1 = n1->prox;
    }
    n2 = L2->inicio;
    return posicao;
}

void inserirAntesPrimeiraOcorrencia (Lista<char> *L1, Lista<char> *L2, Lista<char> *L3)
{
    No<char> *n1 = L1->inicio;
    No<char> *n3 = L3->inicio;

    char aux;
    int posicao;
    int cont = 0;

    posicao = (verificaPosicao(n1, L2));


    Lista<char> LAux = Lista<char>();
    while (!vaziaL(L1))
    {
        aux = removerPrimeiroNoL(L1);
        if (posicao == cont)
        {
            while (n3)
            {
                insereFinalL(&LAux, n3->dado);
                n3 = n3->prox;
            }
        }
        cont++;
        insereFinalL(&LAux, aux);
    }

    n3 = L3->inicio;
    No<char> *n2 = L2->inicio;

    while (!vaziaL(&LAux))
    {
        insereInicioL(L1, removerUltimoNoL(&LAux));
    }

    cout << "Os caracteres <";
    while (n3)
    {
        cout << n3;
        n3 = n3->prox;
    }
    cout << "> foram inseridos antes da ocorrência <";
    while (n2)
    {
        cout << n2;
        n2 = n2->prox;
    }
    cout << ">!" << endl;
}
