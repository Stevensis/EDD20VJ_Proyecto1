#ifndef INTERFACEUSER_H
#define INTERFACEUSER_H
#include "Matriz.h"
#include "NodoMatriz.h"
#include "TreeAvl.h"
#include "ListaDobleCircular.h"
#include "NodoTransaccion.h"
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
        NodoMatriz *empre;
        NodoMatriz *depar;
        ListaDobleCircular *transacciones;
        void menu();
        void menu02();
        void agregarActivo();
        void eliminarActivo();
        void modificarActivo();
        void rentarActivo();
        void graficar(string cuerpo);
        void activosRentados();
        void activosRentados02();
        void misActivosRentados();
        string idActivo();
        InterfaceUser(Matriz* ma,ListaDobleCircular* tra);
        virtual ~InterfaceUser();

    protected:

    private:
};

#endif // INTERFACEUSER_H
