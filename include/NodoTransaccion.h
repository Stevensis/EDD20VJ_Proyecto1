#ifndef NODOTRANSACCION_H
#define NODOTRANSACCION_H
#include "NodoMatriz.h"
#include "NodoActivo.h"

class NodoTransaccion
{
    public:

        string id;
        NodoActivo* activo;
        NodoMatriz* usuario;
        string fecha;
        string dias;
        NodoMatriz*  empresa;
        NodoMatriz*  departamento;
        NodoTransaccion* siguiente;
        NodoTransaccion* anterior;
        NodoTransaccion(string i, NodoActivo* ac, NodoMatriz* ma, string fe,string di,NodoMatriz* de,NodoMatriz* emp);
        virtual ~NodoTransaccion();

    protected:

    private:
};

#endif // NODOTRANSACCION_H
