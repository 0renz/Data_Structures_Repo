#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "listas/lista_descritor_generica.hpp"

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

        }

    }
    else
        cout << "Unable to open file";

    return EXIT_SUCCESS;
}

