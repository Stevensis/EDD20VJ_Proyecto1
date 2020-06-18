#include "NodoTransaccion.h"

NodoTransaccion::NodoTransaccion(string i, NodoActivo* ac, NodoMatriz* ma, string fe,string di,NodoMatriz* de,NodoMatriz* emp)
{
    this->id=i;
    this->activo=ac;
    this->activo->estado=false;
    this->usuario=ma;
    this->fecha=fe;
    this->dias=di;

    this->departamento=de;

    this->empresa=emp;
}

NodoTransaccion::~NodoTransaccion()
{
    //dtor
}
