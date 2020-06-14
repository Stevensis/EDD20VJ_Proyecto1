#include <iostream>
#include "Matriz.h"
#include "InterfaceAdmin.h"
#include "InterfaceUser.h"

using namespace std;

int main()
{
    cout << "-----Renta de activos--------!" << endl;
    Matriz *matriz = new Matriz();
    matriz->insertarNodoMatriz("steven","max","Guatemala","steven","steven098",matriz->contadorN++);
    InterfaceUser *user = new InterfaceUser(matriz);
    InterfaceAdmin *admin = new InterfaceAdmin(matriz);
    string dato,empresa,departamento,nameuser,password;
    cout << " " << endl;
    bool menu1=true;
    //Menu para saber si es usuario o administrador
    do{
        cout << "----- 1. Usuario  --------!" << endl;
        cout << "----- 2. Administrador --------!" << endl;
        cout << "----- 3. Exit --------!" << endl;
        int opcion;
        cin>>opcion;
        switch(opcion){
        case 1:
            user->menu();
            cout<<"opcion 1"<<endl;

            break;
        case 2:
            admin->menu();
           cout<<"opcion 2"<<endl;
            break;
        case 3:
            cout<<"adios"<<endl;
            menu1=false;
            break;

        }

    }while(menu1);


    return 0;
}
