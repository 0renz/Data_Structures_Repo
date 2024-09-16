#include <iostream>
using namespace std;

struct animal
{
    int codigo;
    int idade;
    float peso;
};

#include "listas/lista_dupla_generica_ex03.hpp"

void insereAnimal(Lista<animal> *listaAnimais, int *contAnimais);
void removeAnimal(Lista<animal> *listaAnimais, int *contAnimais);
void imprimeOrdenado(Lista<animal> *listaAnimais);
void imprimeUltimos3(Lista<animal> *listaAnimais);
void separaLista(Lista<animal> *L1);

int main(void)
{
    int contAnimais = 1;
    setlocale(LC_ALL, "Portuguese");
    Lista<animal> listaAnimais = Lista<animal>();
    int escolha = -1;

    do
    {
        system("cls");
        cout << "Menu:\n"
             << "1. Inserir Animal\n"
             << "2. Remover Animal\n"
             << "3. Imprimir Animais em Ordem de Chegada\n"
             << "4. Imprimir Últimos 3 Animais\n"
             << "5. Separar Lista por Peso\n"
             << "0. Sair\n"
             << "\nEscolha uma opção: ";
        cin >> escolha;

                switch (escolha)
        {
        case 1:
            insereAnimal(&listaAnimais, &contAnimais);
            break;
        case 2:
            removeAnimal(&listaAnimais, &contAnimais);
            break;
        case 3:
            imprimeOrdenado(&listaAnimais);
            break;
        case 4:
            imprimeUltimos3(&listaAnimais);
            break;
        case 5:
            separaLista(&listaAnimais);
            break;
        }
    }
    while(escolha != 0);



    destroiL(&listaAnimais);
    return EXIT_SUCCESS;
}

void insereAnimal(Lista<animal> *listaAnimais, int *contAnimais)
{
    animal animal;
    animal.codigo = *contAnimais;
    cout << "\nDigite a idade do animal: ";
    cin >> animal.idade;
    cout << "\nDigite o peso do animal: ";
    cin >> animal.peso;
    insereFinalL(listaAnimais, animal);
    (*contAnimais)++;

    cout << "\nAnimal inserido com sucesso." << endl;
    system("pause");
}

void removeAnimal(Lista<animal> *listaAnimais, int *contAnimais)
{
    if(vaziaL(listaAnimais))
    {
        cout << "\nLista vazia" << endl;
        system("pause");
        return;
    }

    int codigo;
    cout << "\nDigite o código do animal a ser removido: ";
    cin >> codigo;
    if(removeL(listaAnimais, codigo))
    {
        cout << "\nAnimal removido com sucesso." << endl;
        system("pause");
        (*contAnimais)--;
    }
    else
    {
       cout << "\nAnimal não encontrado";
       system("pause");
    }

}

void imprimeOrdenado(Lista<animal> *listaAnimais)
{
    if(vaziaL(listaAnimais))
    {
        cout << "\nLista vazia" << endl;
        system("pause");
        return;
    }

    cout << "\nAnimais ordenados por chegada: ";
    mostraOrdenadoCodigo(listaAnimais);
    cout << endl;
    system("pause");
}

void imprimeUltimos3(Lista<animal> *listaAnimais)
{
    if(vaziaL(listaAnimais))
    {
        cout << "\nLista vazia" << endl;
        system("pause");
        return;
    }

    cout << listaAnimais->fim;

    if (listaAnimais->fim->ant != nullptr)
    {
        cout << listaAnimais->fim->ant;
        if (listaAnimais->fim->ant->ant != nullptr){
             cout << listaAnimais->fim->ant->ant;
        }
    }
    cout << endl;
    system("pause");
}

void separaLista(Lista<animal> *L1)
{
    if(vaziaL(L1))
    {
        cout << "\nLista vazia" << endl;
        system("pause");
        return;
    }

    Lista<animal> L2 = Lista<animal>();
    Lista<animal> L3 = Lista<animal>();
    No<animal> *n = L1->inicio;
    animal aux;

    while(n)
    {
        aux = n->dado;
        if (aux.peso <= 50)
        {
            insereFinalL(&L2, aux);
        }
        else
        {
            insereFinalL(&L3, aux);
        }
        n = n->prox;
    }

    cout << "\nLista de animais: ";
    mostraL(L1);

    cout << "\nLista de animais 50kg ou menos: ";
    mostraL(&L2);

    cout << "\nLista de animais com mais de 50kg: ";
    mostraL(&L3);

    cout << endl;
    system("pause");
}
