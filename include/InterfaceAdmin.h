#ifndef INTERFACEADMIN_H
#define INTERFACEADMIN_H
#include "Matriz.h"
#include "ListaDobleCircular.h"
#include "NodoMatriz.h"

#include <string>
#include <iostream>

//Para graficar
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class InterfaceAdmin
{
    public:
        Matriz* m;
        ListaDobleCircular* lstDCircular;
        void menu();
        void menu2();
        void adduser();
        void acitivosXempresa();
        void activosxdepartemento();
        void transaccionesR();
        void activosxUsuario();
        void graficar(string cuerpo,string nombre);
        InterfaceAdmin(Matriz* ma,ListaDobleCircular* lstCircular);
        virtual ~InterfaceAdmin();

    protected:

    private:
};

#endif // INTERFACEADMIN_H
