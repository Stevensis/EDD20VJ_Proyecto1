#ifndef NODOACTIVO_H
#define NODOACTIVO_H
#include <iostream>
#include <string>
using namespace std;

class NodoActivo
{
    public:
        NodoActivo* izquierda;
        NodoActivo* derecha;
        string nombre;
        string id;
        string descripcion;
        int altura;
        bool estado;
        NodoActivo(string n,string d,string i);
        virtual ~NodoActivo();

    protected:

    private:
};

#endif // NODOACTIVO_H
