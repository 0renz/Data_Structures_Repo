#include <iostream>
#include <ctime>
using namespace std;

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    char escolha = NULL;
    int *vet = NULL;

    do
    {
        system("cls");
        cout << "a. Gerar/alocar vetor de 10 posições (20/50)";
        cout << "\nb. Mostrar vetor – mostrar os elementos do vetor";
        cout << "\nc. Sair do programa" << endl << endl;

        cin >> escolha;

        switch(escolha)
        {
        case 'a':
            if (vet != NULL)
            {
                cout << "Já existia um vetor antes, deletado.";
                delete[] vet;
            }

            vet = new int[10];

            for (int i = 0; i < 10; i++)
            {
                *(vet + i) = rand() % 30 + 20;
            }
            cout << "\nVetor gerado." << endl;

            cout << endl;
            system("pause");
            break;
        case 'b':
            if (vet == NULL)
                cout << "O vetor se encontra nulo.";
            else
            {
                for (int i = 0; i < 10; i++)
                    cout << *(vet + i) << " ";
            }

            cout << endl;
            system("pause");
            break;
        }

    }
    while (escolha != 'c');

}
