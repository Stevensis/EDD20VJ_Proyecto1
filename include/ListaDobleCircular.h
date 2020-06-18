#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#include "NodoTransaccion.h"
//Para graficar
#include <bits/stdc++.h>
#include <windows.h>
class ListaDobleCircular
{
    public:
        ListaDobleCircular();
        NodoTransaccion*  primero;
        void InsertarTransaccion(string i, NodoActivo* ac, NodoMatriz* ma, string fe,string di,NodoTransaccion* n, bool v);
        void grafoGeneral();
        NodoTransaccion* buscarTransicion(string id);
        virtual ~ListaDobleCircular();

    protected:

    private:
};

#endif // LISTADOBLECIRCULAR_H
