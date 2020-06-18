#ifndef MATRIZ_H
#define MATRIZ_H
#include "NodoMatriz.h"
#include "NodoActivo.h"
#include <string>
#include <iostream>
using namespace std;

class Matriz
{
    public:
        NodoMatriz *root;
        Matriz();

        int contadorN;
        virtual ~Matriz();

        void imprimir();
        void insertarNodoMatriz(string name,string empresa,string departamento,string nameuser,string password,int contador);
        void graficarMatriz(string nombre);
        void catologo(NodoMatriz* users);
        NodoMatriz* existe(string user,string departamento,string empresa);
        NodoMatriz* createEmpresa(string name);
        NodoMatriz* createDepartamento(string name);
        NodoMatriz* searchEmpresa(string name);
        NodoMatriz* searchDepartamento(string name);
        NodoActivo* serachActivo(string id);
    protected:

    private:
};

#endif // MATRIZ_H
