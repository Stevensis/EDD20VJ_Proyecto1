#include "InterfaceAdmin.h"
#include <iostream>
#include <string>
using namespace std;
InterfaceAdmin::InterfaceAdmin(Matriz* ma)
{
    this->m=ma;
    //ctor
}

InterfaceAdmin::~InterfaceAdmin()
{
    //dtor
}

void InterfaceAdmin::menu(){
    bool menu1=true;
    int opcion;

    do{
        cout << "**-----         Administrador        --------**!" << endl;
        cout << "----- Ingrese usuario --------!" << endl;
        string user;
        cin.ignore();
        getline(cin,user);
        cout << "----- Ingrese password --------!" << endl;
        string password;
        getline(cin,password);
        if((user==this->m->root->nameuser) && (password==this->m->root->password)){
            this->menu2();
        }else{
            cout << "----- Error con las credenciales --------!" << endl;
            cout << "----- 1. para intentar de nuevo | 2. para regresar al menu principal --------!" << endl;
            cin>>opcion;
            switch(opcion){
            case 1:
                break;
            case 2:
                menu1=false;
                break;
            }
        }
    }while(menu1);
}

void InterfaceAdmin::menu2(){
    cout<<"---Welcome admin--"<<endl;
    int opcion;
    bool menu02=true;
    do{
            cout << "----- 1. Registro Usuario --------!" << endl;
            cout << "----- 2. Registro de Matriz --------!" << endl;
            cout << "----- 3. Reporte Activos Disponibles de un Departamento --------!" << endl;
            cout << "----- 4. Reporte Activos Disponibles de una Empresa--------!" << endl;
            cout << "----- 5. Reporte Transacciones --------!" << endl;
            cout << "----- 6. Reporte Activos de usuarios --------!" << endl;
            cout << "----- 7. Activos rentados por un usuario --------!" << endl;
            cout << "----- 8. Ordenar Transacciones --------!" << endl;
            cout << "----- 9. Exit --------!" << endl;
            cin>>opcion;
            switch(opcion){
            case 1:
                this->adduser();
                break;
            case 2:
                this->m->graficarMatriz("Prueba");
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                menu02=false;
                break;
            default:
                break;
            }
    }while(menu02);
}

void InterfaceAdmin::adduser(){
    cin.ignore();
    string user,name,password,departamento,empresa;
    cout<<"---Agregar Usuario--"<<endl;
    cout<<"... Ingresar user ..."<<endl;
    getline(cin,user);
    cout<<"... Ingresar nombre de usuario ..."<<endl;
    getline(cin,name);
    cout<<"... Ingresar password ..."<<endl;
    getline(cin,password);
    cout<<"... Ingresar departamento ..."<<endl;
    getline(cin,departamento);
    cout<<"... Ingresar Empresa ..."<<endl;
    getline(cin,empresa);
    this->m->insertarNodoMatriz(name,empresa,departamento,user,password,this->m->contadorN++);
}
