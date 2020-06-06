#include "NodoMatriz.h"

NodoMatriz::NodoMatriz(string n, int c)
{
    this->abajo = NULL;
    this->arriba = NULL;
    this->adelante = NULL;
    this->atras = NULL;
    this->name = n;
    this-> contador =c;
}

NodoMatriz::~NodoMatriz()
{
    //dtor
}

