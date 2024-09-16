#include <iostream>
#include <ctime>
using namespace std;

void geraVetor(int **vet, int tam);
void mostraVetor(int **vet, int tam);

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    int escolha = -1;
    int tam;
    int *vet = NULL;

    do
    {
        system("cls");
        cout << "0. Sair";
        cout << "\n1. Gerar vetor";
        cout << "\n2. Mostrar vetor" << endl << endl;

        cin >> escolha;

        switch(escolha)
        {
        case 1:
            cout << "Tamanho do vetor: ";
            cin >> tam;
            geraVetor(&vet, tam);
            system("pause");
            break;
        case 2:
            mostraVetor(&vet, tam);
            system("pause");
            break;
        }

    }
    while (escolha != 0);
}

void geraVetor(int **vet, int tam)
{
    if (*(vet) != NULL)
    {
        cout << "Vetor já alocado, liberando memória." << endl;
        delete[] (*vet);
        *vet = NULL;
    }

    *vet = new int[tam];
    for (int i = 0; i < tam; i++)
    {
        *(*vet + i) = rand() % 20;
    }
}

void mostraVetor(int **vet, int tam)
{
    if (*(vet) == NULL)
    {
        cout << "O vetor está nulo" << endl;
    }
    else
    {
        for (int i = 0; i < tam; i++)
        {
            cout << *(*vet + i) << " ";
        }
    }
}
