#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

struct veiculo
{
    string placa;
    int ano;
    string fabricante;
    string modelo;
};

#include "listas/lista_descritor_ex3.hpp"

void ordenaAno(Lista<veiculo> *lista);
void ordenaModelo(Lista<veiculo> *lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    ifstream entrada;
    entrada.open("cadastro.txt");

    int valor, pos;
    Lista<veiculo> listaVeiculos = Lista<veiculo>();

    if (entrada.is_open())
    {
        string linha;
        while (getline(entrada, linha))
        {
            // Usa stringstream para separar os dados da linha
            stringstream ss(linha);
            string placa, fabricante, modelo;
            int ano;

            // Lê os dados da linha separados por '#'
            getline(ss, placa, '#'); //ss >> placa
            ss >> ano;
            ss.ignore(); // Ignora o caractere '#'
            getline(ss, fabricante, '#');
            getline(ss, modelo);

            // Cria um objeto Veiculo com os dados lidos
            veiculo v = {placa, ano, fabricante, modelo};

            // Insere o veículo no início da lista
            insereInicioL(&listaVeiculos, v);
        }
        entrada.close();
    }


    if (vaziaL(&listaVeiculos))
    {
        cout << "A lista está vazia." << endl;
        return 0;
    }

    int escolha = -1;
    do
    {
        system("cls");
        if (vaziaL(&listaVeiculos))
        {
            cout << "A lista está vazia." << endl;
            return 0;
        }

        cout << "Menu: " << endl << endl;
        cout << "1 - Mostrar lista " << endl;
        cout << "2 - Ordenar lista de veículos " << endl;
        cout << "3 - Remover um veículo da lista " << endl;
        cout << "4 - Remover veículos com base no fabricante e no ano (2000)" << endl;
        cout << "5 - Filtrar veículo " << endl;

        cout << "\nEscolha: ";
        cin >> escolha;

        switch(escolha)
        {
        case 1:
            cout << endl;
            mostraL(&listaVeiculos);
            system("pause");
            break;
        case 2:
        {
            int escolhaOrdena = -1;
            cout << "Ordenar pelo ano (1) / Ordenar pelo modelo(2)" << endl;
            cin >> escolhaOrdena;

            if(escolhaOrdena == 1)
            {
                ordenaAno(&listaVeiculos);
                mostraL(&listaVeiculos);
            }
            else if(escolhaOrdena == 2)
            {
                ordenaModelo(&listaVeiculos);
                mostraL(&listaVeiculos);
            }
            else
            {
                cout << "\nEscolha inválida, tente novamente.";
            }
            system("pause");
            break;
        }
        case 3:
        {
            veiculo vAux;
            cout << "\nDigite o nome da placa: ";
            cin >> vAux.placa;

            if (removePlacaL(&listaVeiculos, vAux))
            {
                cout << "Veículo de placa " << vAux.placa << " removido da lista.";
            }
            else
                cout << "Placa de veículo não encontrada.";

            system("pause");
            break;
        }
        case 4:
        {
            veiculo vAux;
            cout << "\nDigite o nome do fabricante: ";
            cin >> vAux.fabricante;

            if (!removeFabricanteAnoL(&listaVeiculos, vAux))
                cout << "Veículo de fabricante mais novo que 2000 não encontrado." << endl;
            else
            {
                do
                {
                    cout << "Veículo de fabricante: " << vAux.fabricante << " mais novo que 2000 removido da lista." << endl;
                }
                while (removeFabricanteAnoL(&listaVeiculos, vAux));
            }

            system("pause");
            break;
        }
        case 5:
            veiculo vAux;
            cout << "\nDigite o nome do fabricante: ";
            cin >> vAux.fabricante;

            if (!buscaFabricanteL(&listaVeiculos, vAux))
            {
               cout << "Não há veículos do fabricante " << vAux.fabricante << "." << endl;
            }
            system("pause");
            break;
        };

    }
    while (escolha != 0);
    return EXIT_SUCCESS;
}

void ordenaAno(Lista<veiculo> *lista)
{
    No<veiculo> *n = lista->inicio;
    veiculo fAux; ///
    int trocas;

    if(n == NULL)
        cout << "Lista vazia";

    do
    {
        trocas = 0;
        while(n->prox != NULL)
        {
            if (n->dado.ano > n->prox->dado.ano)
            {
                fAux = n->dado;
                n->dado = n->prox->dado;
                n->prox->dado = fAux;
                trocas++;
            }
            n = n->prox;
        }
        n = lista->inicio;
    }
    while (trocas != 0);
}

void ordenaModelo(Lista<veiculo> *lista)
{
    No<veiculo> *n = lista->inicio;
    veiculo fAux; ///
    int trocas;

    if(n == NULL)
        cout << "Lista vazia";

    do
    {
        trocas = 0;
        while(n->prox != NULL)
        {
            if (n->dado.modelo > n->prox->dado.modelo)
            {
                fAux = n->dado;
                n->dado = n->prox->dado;
                n->prox->dado = fAux;
                trocas++;
            }
            n = n->prox;
        }
        n = lista->inicio;
    }
    while (trocas != 0);
}
