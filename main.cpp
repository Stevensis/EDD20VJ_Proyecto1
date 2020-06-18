#include <iostream>
#include "Matriz.h"
#include "InterfaceAdmin.h"
#include "InterfaceUser.h"
#include "ListaDobleCircular.h"
#include "NodoMatriz.h"
#include <string>
#include "AletorioP.h"
using namespace std;



int main()
{
    cout << "-----Renta de activos--------!" << endl;
    Matriz *matriz = new Matriz();
    ListaDobleCircular *transacciones = new ListaDobleCircular();
    AletorioP* a= new AletorioP(matriz);
    matriz->insertarNodoMatriz("steven","max","Guatemala","steven","steven098",matriz->contadorN++);
    matriz->insertarNodoMatriz("pedro","intelaf","Xela","pedro","pedro098",matriz->contadorN++);
    matriz->insertarNodoMatriz("juan","chiquita","Xela","juan","juan098",matriz->contadorN++);
    matriz->insertarNodoMatriz("jose","max","Guatemala","jose","joses098",matriz->contadorN++);
    matriz->insertarNodoMatriz("pepe","chiquita","Xela","pepe","pepe098",matriz->contadorN++);
    NodoMatriz* user1 = matriz->existe("steven","Guatemala","max");
    NodoMatriz* user2 = matriz->existe("pedro","Xela","intelaf");
    NodoMatriz* user3 = matriz->existe("juan","Xela","chiquita");
    NodoMatriz* user4 = matriz->existe("jose","Guatemala","max");
    int conta=0;
    user1->treeAvl->root= user1->treeAvl->insertar(user1->treeAvl->root,a->idActivo(),"leche","lacteo"); conta++;
    user1->treeAvl->root=user1->treeAvl->insertar(user1->treeAvl->root,a->idActivo(),"cafe","negro");conta++;
    user1->treeAvl->root=user1->treeAvl->insertar(user1->treeAvl->root,a->idActivo(),"te","limon");conta++;
    user1->treeAvl->root=user1->treeAvl->insertar(user1->treeAvl->root,a->idActivo(),"te frio","es frio");conta++;
    user1->treeAvl->root=user1->treeAvl->insertar(user1->treeAvl->root,a->idActivo(),"Chai","es cafe");conta++;
    user2->treeAvl->root=user2->treeAvl->insertar(user2->treeAvl->root,a->idActivo(),"acer","computadora");conta++;
    user2->treeAvl->root=user2->treeAvl->insertar(user2->treeAvl->root,a->idActivo(),"dell","mas o menos");conta++;
    user2->treeAvl->root=user2->treeAvl->insertar(user2->treeAvl->root,a->idActivo(),"hp","na nel");conta++;
    user2->treeAvl->root=user2->treeAvl->insertar(user2->treeAvl->root,a->idActivo(),"azus","depende dijo pepito");conta++;
    user2->treeAvl->root=user2->treeAvl->insertar(user2->treeAvl->root,a->idActivo(),"lenovo","tal vez");conta++;
    user3->treeAvl->root=user3->treeAvl->insertar(user3->treeAvl->root,a->idActivo(),"mac","si queda");conta++;
    user3->treeAvl->root=user3->treeAvl->insertar(user3->treeAvl->root,a->idActivo(),"panda","por sano");conta++;
    user3->treeAvl->root=user3->treeAvl->insertar(user3->treeAvl->root,a->idActivo(),"Go green","nel");conta++;
    user3->treeAvl->root=user3->treeAvl->insertar(user3->treeAvl->root,a->idActivo(),"taco","si no hay billete");conta++;
    user3->treeAvl->root=user3->treeAvl->insertar(user3->treeAvl->root,a->idActivo(),"chuco","yeap");conta++;
    user4->treeAvl->root=user4->treeAvl->insertar(user4->treeAvl->root,a->idActivo(),"Azul","color");conta++;
    user4->treeAvl->root=user4->treeAvl->insertar(user4->treeAvl->root,a->idActivo(),"naranja","la fruta o el color");conta++;
    user4->treeAvl->root=user4->treeAvl->insertar(user4->treeAvl->root,a->idActivo(),"rojo","el color");conta++;
    user4->treeAvl->root=user4->treeAvl->insertar(user4->treeAvl->root,a->idActivo(),"cafe","el color");conta++;
    user4->treeAvl->root=user4->treeAvl->insertar(user4->treeAvl->root,a->idActivo(),"negra","tengo la camisa");conta++;


    InterfaceUser *user = new InterfaceUser(matriz,transacciones);
    InterfaceAdmin *admin = new InterfaceAdmin(matriz,transacciones);

    string dato,empresa,departamento,nameuser,password;
    cout << " " << endl;
    bool menu1=true;
    //Menu para saber si es usuario o administrador
    do{
        cout << "----- 1. Usuario  --------!" << endl;
        cout << "----- 2. Administrador --------!" << endl;
        cout << "----- 3. Exit --------!" << endl;
        int opcion=0;
        try { cin>>opcion; } catch (...) { cout<<"no es una opcion\n"; }

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


