#include "InterfaceUser.h"

InterfaceUser::InterfaceUser(Matriz* ma)
{
    this->m=ma;
    this->userE=NULL;
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
        this->userE=this->m->existe(user,departamento,empresa);
        if(userE!=NULL && userE->password==password){
            cout<<"Welcome "+userE->name<<endl;
            this->menu02();
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

void InterfaceUser::menu02(){
    bool option02=true;
    do{
        cout << "... 1. Agregar activo  --------!" << endl;
        cout << "... 2. Eliminaractivo --------!" << endl;
        cout << "... 3. Modificar Activo --------!" << endl;
        cout << "... 4. Rentar Activo  --------!" << endl;
        cout << "... 5. Activos Rentados --------!" << endl;
        cout << "... 6. Mis Activos Rentados --------!" << endl;
        cout << "... 7. Cerrar Sesion --------!" << endl;
        int option12=0;
        cin>>option12;
        switch(option12){
        case 1:
            this->agregarActivo();
            break;
        case 2:
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
            option02=false;
            break;
        }
    }while(option02);
}

void InterfaceUser::agregarActivo(){
    cin.ignore();
    string nombre,descripcion,id;
    cout << ">> Ingresar Nombre  --------!" << endl;
    getline(cin,nombre);
    cout << ">> Ingresar Descripcion --------!" << endl;
    getline(cin,descripcion);
    id=this->idActivo();
    this->userE->treeAvl->root=this->userE->treeAvl->insertar(this->userE->treeAvl->root,id,nombre,descripcion);
    this->graficar(this->userE->treeAvl->graficarArbol());
    this->userE->treeAvl->preorder(this->userE->treeAvl->root);
}

void InterfaceUser::graficar(string cuerpo){
    string nombre="PruebaArbol";
    ofstream grafica;
    grafica.open("PruebaArbol.dot", ios::out);
    grafica << "digraph Sparce_Matrix { \n";
    grafica << cuerpo;
    grafica << "}";

    grafica.close();

    string creacion = "dot -Tjpg " + nombre + ".dot -o " + nombre + ".jpg";
    system(creacion.c_str());
    string title = nombre  + ".jpg";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

string InterfaceUser::idActivo(){
    int num, c;
    srand(time(NULL));
    string id="";
    string alphanum="0123456789abcdefghijklmnopqrstuvwxyz";
    for(c = 0; c < 15; c++)
    {
        num = 0 + rand() % (alphanum.length() - 0);
        id+=alphanum[num];
    }
    return id;
}
InterfaceUser::~InterfaceUser()
{
    //dtor
}
