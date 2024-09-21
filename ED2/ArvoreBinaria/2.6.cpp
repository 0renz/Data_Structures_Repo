#include <iostream>
using namespace std;

typedef struct arv
{
    int info;
    arv *sae;
    arv *sad;
} arvore;

int testa_vazia(arvore *t);
void inserir(arvore **t, int num);
void mostra_1(arvore *t);
void mostra_2(arvore *t);
void mostra_3(arvore *t);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int escolha = -1;
    arvore *arvore1 = NULL; // Inicia a raiz como NULL, indicando que a árvore está vazia

    do
    {
        system("cls");
        cout << "[0] - Sair" << endl;
        cout << "[1] - Incluir" << endl;
        cout << "[2] - Mostrar pré-ordem" << endl;
        cout << "[3] - Mostrar ordem simétrica" << endl;
        cout << "[4] - Mostrar pós-ordem" << endl << endl;
        cin >> escolha;

        switch(escolha)
        {
        case 1:
            int numero;
            cout << "\nDigite o número para inserir: ";
            cin >> numero;
            inserir(&arvore1, numero);
            system("pause");
            break;
        case 2:
            if (!testa_vazia(arvore1))
            {
                mostra_1(arvore1);
                cout << "\n";
            }
            else
            {
                cout << "A árvore está vazia." << endl;
            }
            system("pause");
            break;
        case 3:
            if (!testa_vazia(arvore1))
            {
                mostra_2(arvore1);
                cout << "\n";
            }
            else
            {
                cout << "A árvore está vazia." << endl;
            }
            system("pause");
            break;
        case 4:
            if (!testa_vazia(arvore1))
            {
                mostra_3(arvore1);
                cout << "\n";
            }
            else
            {
                cout << "A árvore está vazia." << endl;
            }
            system("pause");
            break;
        }
    }
    while(escolha != 0);
}

int testa_vazia(arvore *t)
{
    if(t == NULL)
        return 1;
    if(t->info == NULL)
        return 1;
    return 0;
}

void inserir(arvore **t, int num)
{
    if(*t == NULL)
    {
        *t = new arvore;
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->info = num;
    }
    else
    {
        if(num < (*t)->info)
            inserir(&(*t)->sae, num);
        else
            inserir(&(*t)->sad, num);
    }
}

void mostra_1(arvore *t)
{
    cout << "<";
    if(!testa_vazia(t))
    {
        cout << t->info;
        mostra_1(t->sae);
        mostra_1(t->sad);
    }
    cout << ">";
}

void mostra_2(arvore *t)
{
    cout << "<";
    if(!testa_vazia(t))
    {
        mostra_1(t->sae);
        cout << t->info;
        mostra_1(t->sad);
    }
    cout << ">";
}

void mostra_3(arvore *t)
{
    cout << "<";
    if(!testa_vazia(t))
    {
        mostra_1(t->sae);
        mostra_1(t->sad);
        cout << t->info;
    }
    cout << ">";
}
