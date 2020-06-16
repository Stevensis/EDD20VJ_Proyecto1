#ifndef TREEAVL_H
#define TREEAVL_H
#include "NodoActivo.h"
#include <iostream>
#include <string>
using namespace std;
class TreeAvl
{
    public:
        TreeAvl();
        string cuerpoArbolDot;
        NodoActivo* root;
        NodoActivo* searchroot(NodoActivo* raizr,string dato);
        NodoActivo* insertar(NodoActivo* raiz, string dato,string nombre,string descripcion);
        NodoActivo* modificar(NodoActivo* raiz, string dato,string datoNew);
        NodoActivo* simplederechaizquierda(NodoActivo *temp);
        NodoActivo* simplederechaderecha(NodoActivo *temp);
        NodoActivo* doblederechaizquierda(NodoActivo *temp);
        NodoActivo* doblederechaderecha(NodoActivo *temp);
        NodoActivo* valancear(NodoActivo *raiz,string datoE);
        void preorder(NodoActivo *raiz);
        void enorder(NodoActivo *raiz);
        string graficarArbol();
        void cuerpoArbol(NodoActivo *temp);
        int Altura(NodoActivo* raiz);
        int AlturaAux2(NodoActivo* raiz);
        NodoActivo* eliminar(NodoActivo* raiz, string dato);
        NodoActivo* inorderE(NodoActivo* right);

        virtual ~TreeAvl();

    protected:

    private:
};

#endif // TREEAVL_H
