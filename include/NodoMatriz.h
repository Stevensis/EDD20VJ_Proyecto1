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
        NodoMatriz *paenfrente;
        NodoMatriz *padentro;
        string name;
        string nameuser;
        string password;
        int contador;
        NodoMatriz(string n, int c,string nu,string pa);
        virtual ~NodoMatriz();


    protected:

    private:
};

#endif // NODOMATRIZ_H
