#ifndef ALETORIOP_H
#define ALETORIOP_H
//Para aleatorio
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Matriz.h"
#include "NodoActivo.h"
using namespace std;
class AletorioP
{
    public:
        Matriz* ma;
        AletorioP(Matriz* matriz);
        string idActivo();
        virtual ~AletorioP();


    protected:

    private:
};

#endif // ALETORIOP_H
