#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "listas/lista_descritor_generica.hpp"

void mostraDif(Lista<int> *L1, Lista<int> *L2);
void mediana(Lista<int> *L);
void moda(Lista<int> *L);

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    ifstream entrada;
    entrada.open("entrada.txt");
    string operacao = "";

    Lista<int> L1 = Lista<int>();
    Lista<int> L2 = Lista<int>();

    Lista<int> LAux = Lista<int>();


    if (entrada.is_open())
    {
        string lista;
        string ordem;
        int valor;

        while(entrada >> operacao)
        {
            if (operacao == "mostra")
            {
                entrada >> lista;
                entrada >> ordem;

                if (lista == "L1")
                {
                    if (ordem == "I")
                    {
                        cout << "L1 (I): ";
                        if (!vaziaL(&L1))
                        {
                            mostraL(&L1);
                        }
                        else
                        {
                            cout << "VAZIA" << endl;
                        }

                    }
                    else if (ordem == "D")
                    {
                        cout << "L1 (D): ";
                        if (!vaziaL(&L1))
                        {
                            LAux = copiaLista(&L1);
                            ordenaDecrescente(&LAux);
                            mostraL(&LAux);
                        }
                        else
                        {
                            cout << "VAZIA" << endl;
                        }
                    }
                    else if (ordem == "C")
                    {
                        cout << "L1 (C): ";
                        if (!vaziaL(&L1))
                        {
                            LAux = copiaLista(&L1);
                            ordenaCrescente(&LAux);
                            mostraL(&LAux);
                        }
                        else
                        {
                            cout << "VAZIA" << endl;
                        }
                    }
                }
                else if (lista == "L2")
                {
                    if (ordem == "I")
                    {
                        cout << "L2 (I): ";
                        if (!vaziaL(&L2))
                        {
                            mostraL(&L2);
                        }
                        else
                        {
                            cout << "VAZIA" << endl;
                        }

                    }
                    else if (ordem == "D")
                    {
                        cout << "L2 (D): ";
                        if (!vaziaL(&L2))
                        {
                            LAux = copiaLista(&L2);
                            ordenaDecrescente(&LAux);
                            mostraL(&LAux);
                        }
                        else
                        {
                            cout << "VAZIA" << endl;
                        }
                    }
                    else if (ordem == "C")
                    {
                        cout << "L2 (C): ";
                        if (!vaziaL(&L2))
                        {
                            LAux = copiaLista(&L2);
                            ordenaCrescente(&LAux);
                            mostraL(&LAux);
                        }
                        else
                        {
                            cout << "VAZIA" << endl;
                        }
                    }
                }

            }
            else if (operacao == "adiciona")
            {
                entrada >> lista;
                entrada >> valor;

                if (lista == "L1")
                {
                    insereFimL(&L1, valor);
                    cout << "O número " << valor << " foi adicionado na lista L1" << endl;
                }
                else if (lista == "L2")
                {
                    insereFimL(&L2, valor);
                    cout << "O número " << valor << " foi adicionado na lista L2" << endl;
                }

            }
            else if (operacao == "mostraDif")
            {
                string lista2;
                entrada >> lista;
                entrada >> lista2;

                if (lista == "L1")
                {
                    cout << "L1 - L2: ";
                    mostraDif(&L1, &L2);
                }

                else
                {
                    cout << "L2 - L1: ";
                    mostraDif(&L2, &L1);
                }

            }
            else if (operacao == "removeTodos")
            {
                entrada >> lista;

                if (lista == "L1")
                {
                    removeTodos(&L1);
                    cout << "Todos os valores de L1 foram removidos" << endl;
                }
                else if (lista == "L2")
                {
                    removeTodos(&L2);
                    cout << "Todos os valores de L2 foram removidos" << endl;
                }
            }
            else if (operacao == "mediana")
            {
                entrada >> lista;

                if (lista == "L1")
                {
                    cout << "Mediana L1: ";
                    mediana(&L1);

                }
                else if (lista == "L2")
                {
                    cout << "Mediana L2: ";
                    mediana(&L2);

                }
            }
            else if (operacao == "moda")
            {
                if (lista == "L1")
                {
                    if (!vaziaL(&L1))
                    {
                        cout << "Moda L1: ";
                        moda(&L1);
                    }
                    else
                    {
                        cout << "Moda L1: VAZIA" << endl;
                    }

                }
                else if (lista == "L2")
                {
                    if (!vaziaL(&L2))
                    {
                        cout << "Moda L2: ";
                        moda(&L2);
                    }
                    else
                    {
                        cout << "Moda L2: VAZIA" << endl;
                    }
                }
            }
        }

    }
    else
        cout << "Unable to open file";

    return EXIT_SUCCESS;
}

void mostraDif(Lista<int> *L1, Lista<int> *L2)
{

    // elementos da lista 1 que não pertencem a 2
    No<int> *n1 = L1->inicio;
    No<int> *n2 = L2->inicio;
    Lista<int> listaAux = Lista<int>();
    bool encontrou;

    while(n1)
    {
        encontrou = false;
        while(n2)
        {
            if (n1->dado == n2->dado)
            {
                encontrou = true;
            }
            n2 = n2->prox;
        }

        if (encontrou == false)
            insereInicioL(&listaAux, n1->dado);

        n2 = L2->inicio;
        n1 = n1->prox;
    }

    if(!vaziaL(&listaAux))
        mostraL(&listaAux);
    else
        cout << "VAZIA" << endl;
}

void mediana(Lista<int> *L)
{
    int lugar;
    int cont = 0;

    if (vaziaL(L))
    {
        cout << "Erro ao calcular mediana, lista vazia!" << endl;
        return;
    }


    Lista<int> listaAux = Lista<int>();
    listaAux = copiaLista(L);
    ordenaDecrescente(&listaAux);
    No<int> *n = listaAux.inicio;

    if (listaAux.tamanho % 2 == 0)
    {
        int m1, m2;
        float mfinal;
        lugar = L->tamanho / 2;
        while (cont != listaAux.tamanho)
        {
            if (cont == lugar - 1)
            {
                m1 = n->dado;
            }
            else if (cont == lugar)
            {
                m2 = n->dado;
            }
            n = n->prox;
            cont++;
        }
        mfinal = ((float)m1 + (float)m2) / 2;
        cout << mfinal << endl;
    }
    else
    {
        lugar = L->tamanho / 2;

        while (cont != lugar)
        {
            n = n->prox;
            cont++;
        }
        cout << n->dado << endl;
    }
}

int contaElementos(Lista<int> *L, int valor)
{
    No<int> *n = L->inicio;
    int cont = 0;

    while(n)
    {
        if (n->dado == valor)
            cont++;

        n = n->prox;
    }
    return cont;

}

int maiorFrequencia(Lista<int> *lFrequencia)
{
    No<int> *n = lFrequencia->inicio;
    int maior = 0;

    while(n)
    {
        if (n->dado > maior)
            maior = n->dado;

        n = n->prox;
    }
    return maior;
}

void moda(Lista<int> *L)
{
    No<int> *n = L->inicio;
    int valor = 0;
    int qtdElementos;
    int maiorFreq;

    Lista<int> listaFrequencia = Lista<int>();
    Lista<int> listaModas = Lista<int>();

    while(n)
    {
        valor = n->dado;
        qtdElementos = contaElementos(L, valor);
        insereFimL(&listaFrequencia, qtdElementos);

        n = n->prox;
    }
    n = L->inicio;

    maiorFreq = maiorFrequencia(&listaFrequencia);

    if (maiorFreq <= 1)
    {
        cout << "Lista vazia";
        return;
    }

    No<int> *n2 = listaFrequencia.inicio;

    while(n2)
    {
        if (n2->dado == maiorFreq && !buscaL(&listaModas, n->dado))
        {
            insereFimL(&listaModas, n->dado);
        }
        n2 = n2->prox;
        n = n->prox;
    }

    mostraL(&listaModas);
}

