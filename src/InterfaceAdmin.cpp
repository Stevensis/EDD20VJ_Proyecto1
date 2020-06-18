#include "InterfaceAdmin.h"
#include <iostream>
#include <string>
using namespace std;
InterfaceAdmin::InterfaceAdmin(Matriz* ma,ListaDobleCircular* lstCircular)
{
    this->m=ma;
    this->lstDCircular=lstCircular;
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
            cout << "----- 2. Reporte de Matriz --------!" << endl;
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
                this->activosxdepartemento();
                break;
            case 4:
                this->acitivosXempresa();
                break;
            case 5:
                this->transaccionesR();
                break;
            case 6:
                this->activosxUsuario();
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

void InterfaceAdmin::acitivosXempresa(){
    cout<<"---Ingrese empresa a ver activos--"<<endl;
    string empresaS,graficaxE;
    int contador=0;
    cin.ignore();
    getline(cin,empresaS);
    NodoMatriz* tempE= this->m->searchEmpresa(empresaS);
    if(tempE!=NULL){
        graficaxE="\n label=\"Empresa "+tempE->name+" \" \n";
        NodoMatriz* tempU=tempE->adelante;
        while(tempU!=NULL){
            NodoMatriz* tempU2=tempU;
            while(tempU2!=NULL){
                graficaxE+="\n subgraph cluster_"+ to_string(contador) +" { \n";
                graficaxE+="\n label=\"Usuario "+tempU2->name+" \\n "+ tempU2->nameuser +" \" \n";
                graficaxE+=tempU2->treeAvl->graficarArbol();
                graficaxE+="}";
                tempU2=tempU2->padentro;
                contador++;
            }
            tempU=tempU->adelante;
        }
        this->graficar(graficaxE,"ReporteActivos"+tempE->name);
    }
}

void InterfaceAdmin::activosxdepartemento(){
    cout<<"---Ingrese departamento a ver activos--"<<endl;
    string empresaS,graficaxE;
    int contador=0;
    cin.ignore();
    getline(cin,empresaS);
    NodoMatriz* tempE= this->m->searchDepartamento(empresaS);
    if(tempE!=NULL){
        graficaxE="\n label=\"Departamento: "+tempE->name+" \" \n";
        NodoMatriz* tempU=tempE->abajo;
        while(tempU!=NULL){
            NodoMatriz* tempU2=tempU;
            while(tempU2!=NULL){
                graficaxE+="\n subgraph cluster_"+to_string(contador)+" { \n";
                graficaxE+="\n label=\"Usuario "+tempU2->name+" \\n "+ tempU2->nameuser +" \" \n";
                graficaxE+=tempU2->treeAvl->graficarArbol();
                graficaxE+="}";
                tempU2=tempU2->padentro;
                contador++;
            }
            tempU=tempU->abajo;
        }
        this->graficar(graficaxE,"ReporteActivos"+tempE->name);
    }
}

void InterfaceAdmin::graficar(string cuerpo,string nombre){
    string nameA=nombre+".dot";
    ofstream grafica;
    grafica.open(nameA, ios::out);
    grafica << "digraph G { \n";
    grafica << cuerpo;
    grafica << "}";

    grafica.close();

    string creacion = "dot -Tjpg " + nombre + ".dot -o " + nombre + ".jpg";
    system(creacion.c_str());
    string title = nombre  + ".jpg";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void InterfaceAdmin::activosxUsuario(){
    cin.ignore();
            cout << "----- Ingrese usuario --------!" << endl;
        string user,password,departamento,empresa;
        getline(cin,user);
        cout << "----- Ingrese departamento --------!" << endl;
        getline(cin,departamento);
        cout << "----- Ingrese empresa --------!" << endl;
        getline(cin,empresa);
        NodoMatriz* userE=this->m->existe(user,departamento,empresa);
        if(userE!=NULL){
            string graficaxU="\n label=\" User: "+userE->name+"\"\n";
            graficaxU+=userE->treeAvl->graficarArbol();
            this->graficar(graficaxU,"ActivosDe_"+userE->nameuser);
            cout<<"Se grafico el arbol de "<<userE->name<<endl;
        }else{
            cout << "----- Error con las credenciales --------!" << endl;
        }
}

void InterfaceAdmin::transaccionesR(){
    this->lstDCircular->grafoGeneral();
}
