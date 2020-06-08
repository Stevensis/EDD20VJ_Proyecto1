#ifndef INTERFACEUSER_H
#define INTERFACEUSER_H
#include "Matriz.h"
#include "NodoMatriz.h"
using namespace std;
class InterfaceUser
{
    public:
        Matriz* m;
        void menu();
        InterfaceUser(Matriz* ma);
        virtual ~InterfaceUser();

    protected:

    private:
};

#endif // INTERFACEUSER_H
