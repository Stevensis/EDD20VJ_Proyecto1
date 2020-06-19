#include "ListaDobleCircular.h"

ListaDobleCircular::ListaDobleCircular()
{
    //ctor
    this->primero=NULL;
}

void ListaDobleCircular::InsertarTransaccion(string i, NodoActivo* ac, NodoMatriz* ma, string fe,string di,NodoTransaccion* n, bool v,NodoMatriz* de,NodoMatriz* emp){
    NodoTransaccion* temp = new NodoTransaccion(i,ac,ma,fe,di,de,emp);

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
    grafica << "digraph  { \n nodesep=.05; \n rankdir=LR; \n node [shape=record,width=.5,height=2.5]; \n label=\"Reporte General\"; \n";
    NodoTransaccion* temp=this->primero;
    do{
        cuerpo+="\"" + temp->id + "\" [label=\" "+ temp->id +",\\n D: " + temp->departamento->name + ",E:"+  temp->empresa->name +",\\n T: "+temp->dias +", F: "+temp->fecha+",\\n U: "+temp->usuario->name + ",\\n A: "+temp->activo->nombre + ", : "+ to_string(temp->activo->estado) + ",\\n A: "+temp->activo->id + "\"] \n";
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

NodoTransaccion* ListaDobleCircular::buscarTransicion02(string id){
    NodoTransaccion* temp=this->primero;
    if(this->primero==NULL){return NULL;}
    do{
        if(temp->id==id){
            return temp;
        }
        temp=temp->siguiente;
    }while(temp!=this->primero);
    return NULL;
}

void ListaDobleCircular::grafoporUsuario(NodoMatriz* user){
    string nombre="rentados_"+user->nameuser;
    string nombre2=nombre+".dot";
    string cuerpo="";
    ofstream grafica;
    int contador=0;
    grafica.open(nombre2, ios::out);
    grafica << "digraph  { \n nodesep=.05; \n rankdir=LR; \n node [shape=record,width=.5,height=2.5]; \n label=\"Reporte General\"; \n";
    NodoTransaccion* temp=this->primero;
    cuerpo+="label=\" Rentados de : "+user->name+"\"\n";
    do{
        if(temp->usuario==user){
        cuerpo+="\"" + to_string(contador) + "\" [label=\" "+ temp->id +",\\n D: " + temp->departamento->name + ",E:"+  temp->empresa->name +",\\n T: "+temp->dias +", F: "+temp->fecha+",\\n U: "+temp->usuario->name + ",\\n A: "+temp->activo->nombre + ", : "+ to_string(temp->activo->estado) + ",\\n A: "+temp->activo->id + "\"] \n";
        contador++;
        }
        temp=temp->siguiente;
    }while(temp!=this->primero);
    for(int i = 0; i < contador-1;i++){
        cuerpo+= "\n\"" + to_string(i) +"\" -> \""+to_string(i+1)+"\" \n";
    }
    grafica << cuerpo;
    grafica << "}";

    grafica.close();

    string creacion = "dot -Tjpg " + nombre + ".dot -o " + nombre + ".jpg";
    system(creacion.c_str());
    string title = nombre  + ".jpg";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void ListaDobleCircular::ordenaInsercion(){
    NodoTransaccion* aux;
    NodoTransaccion* i;
    NodoTransaccion* j;

    if(this->primero!=NULL && this->primero->siguiente!=this->primero){
        i=this->primero;
        do{
            j=i->siguiente;
            do{
            if(i->id>j->id){
                aux=i;
                NodoMatriz* empre=i->empresa;
                NodoMatriz* dep=i->departamento;
                NodoMatriz* use=i->usuario;
                NodoActivo* ac=i->activo;
                string di = i->dias;
                string fe = i->fecha;
                string iid = i->id;
                i->activo=j->activo;
                i->departamento=j->departamento;
                i->dias=j->dias;
                i->empresa=j->empresa;
                i->fecha=j->fecha;
                i->id=j->id;
                j->activo= ac;
                j->departamento=dep;
                j->dias=di;
                j->empresa=empre;
                j->fecha=fe;
                j->id=iid;
                j->usuario=use;
            }
            j=j->siguiente;
            }while(j!=this->primero);
            i=i->siguiente;
        }while(i!=this->primero->anterior);

    }

}

ListaDobleCircular::~ListaDobleCircular()
{
    //dtor
}
