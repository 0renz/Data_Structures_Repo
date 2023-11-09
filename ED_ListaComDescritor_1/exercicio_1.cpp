#include <iostream>
using namespace std;

#include "funcionario.hpp"
#include "listas/lista_descritor_ex1.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    int valor, pos;
    No* aux = nullptr;
    Lista lista = Lista();//chama o cosntrutor para inicilizar a lista

    Funcionario f;
    f.codigo = 1;
    f.nome = "AAAAAA";
    f.idade = 15;
    f.salario = 100.95;
    insereInicioL(&lista, f);

    f.codigo = 2;
    f.nome = "BBBBB";
    f.idade = 20;
    f.salario = 300.05;

    insereInicioL(&lista, f);
    cout << lista << endl;

    Funcionario fTeste = leInicio(&lista);
    cout << "\nFUNCIONARIO INICIO: " << fTeste << endl;
    cout << lista << endl;

    fTeste = removeInicio(&lista);
    cout << "\n\nFUNCIONARIO INICIO REMOVIDO: " << fTeste << endl;
    cout << lista << endl;

    f.codigo = 23;
    f.nome = "CCCCCC";
    f.idade = 24;
    f.salario = 205.05;

    insereInicioL(&lista, f);

    f.codigo = 2;
    f.nome = "DDDDD";
    f.idade = 22;
    f.salario = 5.45;

    insereInicioL(&lista, f);

    f.codigo = 2;
    f.nome = "ZZZZZ";
    f.idade = 22;
    f.salario = 5.45;

    insereInicioL(&lista, f);

    f.codigo = 2;
    f.nome = "JJJJJ";
    f.idade = 22;
    f.salario = 5.45;

    insereInicioL(&lista, f);

    f.codigo = 2;
    f.nome = "BBBBB";
    f.idade = 22;
    f.salario = 5.45;

    insereInicioL(&lista, f);


    fTeste = leFim(&lista);
    cout << "\nFUNCIONARIO FIM: " << fTeste << endl;
    cout << lista << endl;

    cout << "\nMEDIA DO SALARIO: " << mediaFuncionario(&lista) << endl;

    cout << "\nNomes com salario abaixo da media: ";
    nomeMenorMedia(&lista);


    cout << "\n\nLista normal: ";
    cout << lista;
    cout << "\n\nLista ordenada: ";
    ordena(&lista);
    cout << lista;

    cout << "\n\nLista inversa: ";
    inverteLista(&lista);
    cout << lista;

    /*
    cout << "\n\nLista ordenada pela idade: ";
    inverteLista(&lista);
    cout << lista;
    */

    Lista lista2 = Lista();
    for (int i = 0; i < 5; i++)
        insereInicioL(&lista2, f);

    Lista listaUniao = Lista();

    cout << "\n\nUnião: ";
    listaUniao = uniao(&lista, &lista2);
    cout << listaUniao << endl;
    cout << lista << endl;
    cout << lista2 << endl;


    Lista listaIntersec = Lista();
    cout << "\nIntersecção: ";
    listaIntersec = intersec(&lista, &lista2);
    cout << listaIntersec << endl;
    cout << lista << endl;
    cout << lista2 << endl;

    destroiL(&lista);
    destroiL(&lista2);
    destroiL(&listaUniao);
    return EXIT_SUCCESS;
}

