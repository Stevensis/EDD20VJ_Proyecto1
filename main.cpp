#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Matriz *matriz = new Matriz();
    string dato,empresa,departamento;
    getline(cin, dato);
    do{
        cin>>empresa;
        cin>>departamento;
        cout<<"----";
        matriz->insertarNodoMatriz(dato,empresa,departamento,matriz->contadorN++);
        cin>>dato;
    }while(dato!="p");
    matriz->imprimir();
    cout<<"Empresa a buscar"<<endl;
    cin>>dato;
    cout<<(matriz->searchEmpresa(dato)->name)<<endl;
    return 0;
}
