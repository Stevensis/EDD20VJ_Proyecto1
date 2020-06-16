#include "NodoTransaccion.h"

NodoTransaccion::NodoTransaccion(string i, NodoActivo* ac, NodoMatriz* ma, string fe,string di)
{
    this->id=i;
    this->activo=ac;
    this->activo->estado=false;
    this->usuario=ma;
    this->fecha=fe;
    this->dias=di;

    NodoMatriz* temp= this->usuario->arriba;
    while(temp->arriba!=NULL){
        temp= temp->arriba;
    }
    this->departamento=temp->name;
    temp=this->usuario->atras;
    while(temp->atras!=NULL){
        temp= temp->atras;
    }
    this->empresa=temp->name;
}

NodoTransaccion::~NodoTransaccion()
{
    //dtor
}
