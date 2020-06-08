#include "NodoMatriz.h"

NodoMatriz::NodoMatriz(string n, int c,string nu,string pa)
{
    this->abajo = NULL;
    this->arriba = NULL;
    this->adelante = NULL;
    this->atras = NULL;
    this->padentro=NULL;
    this->paenfrente=NULL;
    this->name = n;
    this-> contador =c;
    this->nameuser = nu;
    this->password=pa;
}

NodoMatriz::~NodoMatriz()
{
    //dtor
}

