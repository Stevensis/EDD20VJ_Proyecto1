#ifndef INTERFACEADMIN_H
#define INTERFACEADMIN_H
#include "Matriz.h"

#include <string>
#include <iostream>
using namespace std;

class InterfaceAdmin
{
    public:
        Matriz* m;
        void menu();
        void menu2();
        void adduser();
        InterfaceAdmin(Matriz* ma);
        virtual ~InterfaceAdmin();

    protected:

    private:
};

#endif // INTERFACEADMIN_H
