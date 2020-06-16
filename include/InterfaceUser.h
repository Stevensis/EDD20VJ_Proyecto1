#ifndef INTERFACEUSER_H
#define INTERFACEUSER_H
#include "Matriz.h"
#include "NodoMatriz.h"
#include "TreeAvl.h"
//Para aleatorio
#include <stdlib.h>
#include <time.h>
//Para graficar
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class InterfaceUser
{
    public:
        Matriz* m;
        NodoMatriz *userE;
        void menu();
        void menu02();
        void agregarActivo();
        void eliminarActivo();
        void modificarActivo();
        void graficar(string cuerpo);
        string idActivo();
        InterfaceUser(Matriz* ma);
        virtual ~InterfaceUser();

    protected:

    private:
};

#endif // INTERFACEUSER_H
