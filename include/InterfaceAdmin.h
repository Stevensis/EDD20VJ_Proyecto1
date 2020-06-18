#ifndef INTERFACEADMIN_H
#define INTERFACEADMIN_H
#include "Matriz.h"

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
        void menu();
        void menu2();
        void adduser();
        void acitivosXempresa();
        void activosxdepartemento();
        void graficar(string cuerpo,string nombre);
        InterfaceAdmin(Matriz* ma);
        virtual ~InterfaceAdmin();

    protected:

    private:
};

#endif // INTERFACEADMIN_H
