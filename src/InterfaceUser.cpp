#include "InterfaceUser.h"

InterfaceUser::InterfaceUser(Matriz* ma)
{
    this->m=ma;
    //ctor
}

void InterfaceUser::menu(){
    cin.ignore();
    bool menu01=true;
    do{
        cout << "**-----         Login        --------**!" << endl;
        cout << "----- Ingrese usuario --------!" << endl;
        string user,password,departamento,empresa;
        getline(cin,user);
        cout << "----- Ingrese password --------!" << endl;
        getline(cin,password);
        cout << "----- Ingrese departamento --------!" << endl;
        getline(cin,departamento);
        cout << "----- Ingrese empresa --------!" << endl;
        getline(cin,empresa);
        NodoMatriz *userE=this->m->existe(user,departamento,empresa);
        if(userE!=NULL && userE->password==password){
            cout<<"Welcome "+userE->name<<endl;
        }else{
            cout << "----- Error con las credenciales --------!" << endl;
            cout << "----- 1. para intentar de nuevo | 2. para regresar al menu principal --------!" << endl;
            int opcion;
            cin>>opcion;
            switch(opcion){
            case 1:
                break;
            case 2:
                menu01=false;
                break;
            }
        }
    }while(menu01);
}

InterfaceUser::~InterfaceUser()
{
    //dtor
}
