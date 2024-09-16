#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    ifstream entrada;
    string operacao;

    entrada.open("entrada.txt", ios::in);

    if (entrada.is_open())
    {
        float n1, n2, resultado = 0;

        while(entrada >> operacao >> n1 >> n2)
        {
            if (operacao == "SOMA")
            {
                resultado = n1 + n2;
                cout << resultado << endl;
            }
            else if (operacao == "SUBTRACAO")
            {
                resultado = n1 - n2;
                cout << resultado << endl;
            }
            else if (operacao == "DIVISAO")
            {
                resultado = n1 / n2;
                cout << resultado << endl;
            }
            else if (operacao == "MULTIPLICACAO")
            {
                resultado = n1 * n2;
                cout << resultado << endl;
            }
        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo" << endl;
        system("pause");
    }
}
