#include <iostream>
#include <cstring>
using namespace std;

#include "funcionario.hpp"
#include "listas/lista_descritor_ex1e2.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    //testes envolvendo lista com descritor e a scruct funcionário
    int valor, pos;
    No* aux = nullptr;
    Lista lista = Lista();//chama o construtor para inicilizar a lista

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
    cout << "\n ## FUNCIONARIO INICIO: " << fTeste << endl;
    cout << lista << endl;

    fTeste = removeInicio(&lista);
    cout << "\n\n ## FUNCIONARIO INICIO REMOVIDO: " << fTeste << endl;
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
    cout << "\n ## FUNCIONARIO FIM: " << fTeste << endl;
    cout << lista << endl;

    cout << "\n ## MEDIA DO SALARIO: " << mediaFuncionario(&lista) << endl;

    cout << "\n ## Nomes com salario abaixo da media: ";
    nomeMenorMedia(&lista);


    cout << "\n\n ## Lista normal: " << endl;
    cout << lista;
    cout << "\n\n ## Lista ordenada: " << endl;
    ordena(&lista);
    cout << lista;

    cout << "\n\n ## Lista inversa: " << endl;
    inverteLista(&lista);
    cout << lista;

    cout << "\n\n ## Lista ordenada pela idade: " << endl;
    mostraOrdenadoIdade(&lista);
    cout << lista << endl;

    Lista lista2 = Lista();
    for (int i = 0; i < 5; i++)
        insereInicioL(&lista2, f);

    Lista listaUniao = Lista();
    cout << "\nUnião " << endl;
    listaUniao = uniao(&lista, &lista2);
    cout << listaUniao << endl;
    cout << lista << endl;
    cout << lista2 << endl;

    f.codigo = 2;
    f.nome = "DDDDD";
    f.idade = 22;
    f.salario = 5.45;
    insereInicioL(&lista2, f);

    Lista listaIntersec = Lista();
    cout << "\nIntersecção: " << endl;
    listaIntersec = intersec(&lista, &lista2);
    cout << listaIntersec << endl;
    cout << lista << endl;
    cout << lista2 << endl;

    destroiL(&lista);
    destroiL(&lista2);
    destroiL(&listaUniao);
    return EXIT_SUCCESS;
}

