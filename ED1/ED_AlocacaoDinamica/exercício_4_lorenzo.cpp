#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

struct registro
{
    string CPF;
    string nome;
    int ano;

    registro()
    {
        CPF = "";
        nome = "";
        ano = 0;
    }
};

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");


    registro();
    int tam;
    cout << "Informe o número de clientes: ";
    cin >> tam;
    registro *c = new registro[tam];

    for (int i = 0; i < tam; i++)
    {
        cout << "CPF do cliente " << i+1 << ": ";
        cin.ignore(); // Limpar o buffer do teclado antes de ler a próxima linha
        getline(cin, c[i].CPF);

        cout << "Nome do cliente " << i+1 << ": ";
        getline(cin, c[i].nome);

        cout << "Ano de nascimento do cliente " << i+1 << ": ";
        cin >> c[i].ano;
    }

    system("cls");
    cout << ".....................................";
    for (int i = 0; i < tam; i++)
    {
        cout << "\nCPF do cliente " << i+1 << ": ";
        cout << c[i].CPF;

        cout << "\nNome do cliente " << i+1 << ": ";
        cout << c[i].nome;

        cout << "\nAno de nascimento do cliente " << i+1 << ": ";
        cout << c[i].ano;
        cout << "\n.....................................";
    }

    cout << c[2].ano;
    for (int i = 0; i < tam ; i++)
        {
            c[i].CPF = "";
            c[i].nome = "";
            c[i].ano = 0;
        }
    delete[] c;
}

