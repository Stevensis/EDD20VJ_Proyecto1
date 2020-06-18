#include "ListaDobleCircular.h"

ListaDobleCircular::ListaDobleCircular()
{
    //ctor
    this->primero=NULL;
}

void ListaDobleCircular::InsertarTransaccion(string i, NodoActivo* ac, NodoMatriz* ma, string fe,string di,NodoTransaccion* n, bool v){
    NodoTransaccion* temp = new NodoTransaccion(i,ac,ma,fe,di);

    if(this->primero==NULL){
        this->primero=temp;
        this->primero->siguiente=this->primero;
        this->primero->anterior=this->primero;
    }else{
        n->anterior->siguiente=temp;
        temp->anterior=n->anterior;
        n->anterior=temp;
        temp->siguiente=n;
    }

    if(v){
        primero=temp;
    }
}

void ListaDobleCircular::grafoGeneral(){
    string nombre="PruebaListaCircular";
    string cuerpo="";
    ofstream grafica;
    grafica.open("PruebaListaCircular.dot", ios::out);
    grafica << "digraph  { \n nodesep=.05; \n rankdir=LR; \n node [shape=record,width=.5,height=2.5]; \n";
    NodoTransaccion* temp=this->primero;
    do{
        cuerpo+="\"" + temp->id + "\" [label=\" "+ temp->id +",\\n D: " + temp->departamento + ",E:"+  temp->empresa +",\\n T: "+temp->dias +", F: "+temp->fecha+",\\n U: "+temp->usuario->name + ",\\n A: "+temp->activo->nombre + "\"] \n";
        cuerpo+= "\"" + temp->id +"\" -> \""+temp->siguiente->id+"\"";
        cuerpo+= "\"" + temp->id +"\" -> \""+temp->anterior->id+"\"";
        temp=temp->siguiente;
    }while(temp!=this->primero);
    grafica << cuerpo;
    grafica << "}";

    grafica.close();

    string creacion = "dot -Tjpg " + nombre + ".dot -o " + nombre + ".jpg";
    system(creacion.c_str());
    string title = nombre  + ".jpg";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

NodoTransaccion* ListaDobleCircular::buscarTransicion(string id){
    NodoTransaccion* temp=this->primero;
    do{
        if(temp->activo->id==id){
            return temp;
        }
        temp=temp->siguiente;
    }while(temp!=this->primero);
    return NULL;
}

ListaDobleCircular::~ListaDobleCircular()
{
    //dtor
}
