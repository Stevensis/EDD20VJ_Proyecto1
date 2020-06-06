#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>
#include <iostream>
using namespace std;

class NodoMatriz
{
    public:
        NodoMatriz *atras;
        NodoMatriz *adelante;
        NodoMatriz *arriba;
        NodoMatriz *abajo;
        string name;
        int contador;
        NodoMatriz(string n, int c);
        virtual ~NodoMatriz();


    protected:

    private:
};

#endif // NODOMATRIZ_H
