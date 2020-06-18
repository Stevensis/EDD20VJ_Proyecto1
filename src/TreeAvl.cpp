#include "TreeAvl.h"

TreeAvl::TreeAvl()
{
    this->root=NULL;
    this->cuerpoArbolDot="";
}

NodoActivo* TreeAvl::searchroot(NodoActivo* raizr,string dato){
    if(raizr==NULL || raizr->id ==dato ){
        return raizr;
    }
    if(raizr->id > dato){
        return searchroot(raizr->izquierda,dato);
    }
    return searchroot(raizr->derecha,dato);
}
//Metodo para insertar al arbol, este mismo equilibra, recibe la raiz del arbol
NodoActivo* TreeAvl::insertar(NodoActivo* raiz, string dato,string nombre,string descripcion){
    //Si el arbol esta vacio
    if (raiz==NULL){
        raiz = new NodoActivo(nombre,descripcion,dato);
    } else if(dato<raiz->id){
        raiz->izquierda= this->insertar(raiz->izquierda,dato,nombre,descripcion);
        //1
        //altura es para valancear
        if((Altura(raiz->izquierda) - Altura(raiz->derecha))==2){
            if(dato<raiz->izquierda->id){
                raiz= simplederechaizquierda(raiz);
            }else{
                raiz= doblederechaizquierda(raiz);
            }
        }
    } else if (dato>raiz->id){
        raiz->derecha = this->insertar(raiz->derecha,dato,nombre,descripcion);
        //2
        //altura es para valancear
        int der,izq;
        der=Altura(raiz->derecha);
        izq=Altura(raiz->izquierda);
        if( (der - izq)==2){
            if(dato>raiz->derecha->id){
                raiz= simplederechaderecha(raiz);
            }else{
                raiz= doblederechaderecha(raiz);
            }
        }
    }else{
        cout<<"No se puede insertar datos duplicados"<<endl;
    }
    int maximo,de,iz;
    de= this->Altura(raiz->derecha);
    iz= this->Altura(raiz->izquierda);
    if(de>iz){maximo=de;}else{maximo=iz;}
    raiz->altura=maximo+1;
    return raiz;
}

//Calcula la altura de algun nodo que se le envia
int TreeAvl::Altura(NodoActivo* raiz){
    if(raiz==NULL){return -1;}
    int alturaD,alturaI;
    alturaI = Altura(raiz->izquierda);
    alturaD = Altura(raiz->derecha);
    if(alturaI==-1 && alturaD==-1){return 0;}
    if(alturaI>alturaD){ return alturaI+1; }else{ return alturaD+1; }
}

NodoActivo* TreeAvl::simplederechaizquierda(NodoActivo *temp){
    NodoActivo* temp2;
    temp2= temp->izquierda;
    temp->izquierda=temp2->derecha;
    temp2->derecha=temp;
    temp2->altura = this->AlturaAux2(temp2);
    return temp2;
}
NodoActivo* TreeAvl::simplederechaderecha(NodoActivo *temp){
    NodoActivo* temp2;
    temp2= temp->derecha;
    temp->derecha=temp2->izquierda;
    temp2->izquierda=temp;
    temp2->altura=this->AlturaAux2(temp2);
    return temp2;
}
NodoActivo* TreeAvl::doblederechaizquierda(NodoActivo *temp){
    temp->izquierda=this->simplederechaderecha(temp->izquierda);
    return simplederechaizquierda(temp);
}
NodoActivo* TreeAvl::doblederechaderecha(NodoActivo *temp){
    temp->derecha=this->simplederechaizquierda(temp->derecha);
    return simplederechaderecha(temp);
}

int TreeAvl :: AlturaAux2(NodoActivo* raiz){
    if(raiz==NULL){return -1;}
    int alturaD0,alturaI0;
    alturaI0 = AlturaAux2(raiz->izquierda);
    alturaD0 = AlturaAux2(raiz->derecha);
    if(alturaI0==-1 && alturaD0==-1){raiz->altura=0; return 0;}
    if(alturaI0>alturaD0){ raiz->altura=alturaI0+1; return alturaI0+1; }else{ raiz->altura=alturaD0+1; return alturaD0+1; }
}

string TreeAvl::graficarArbol(){
    this->cuerpoArbolDot="";
    this->cuerpoArbolDot+="node [height=0.5, width=1.2];\n";
    this->cuerpoArbol(this->root);
    return this->cuerpoArbolDot;
}

void TreeAvl::cuerpoArbol(NodoActivo *temp){
    if(temp!=NULL){
        this->cuerpoArbol(temp->izquierda);
        if(temp->estado){
            this->cuerpoArbolDot+= "\""+ temp->id + "\" [label=\" "+ temp->id +",\\n" + temp->nombre + "\",color=green] \n";
        }else{
            this->cuerpoArbolDot+= "\""+ temp->id + "\" [label=\" "+ temp->id +",\\n" + temp->nombre + "\",color=red] \n";
        }

        if(temp->derecha!=NULL){
           this->cuerpoArbolDot+= "\""+ temp->id + "\" -> \""+ temp->derecha->id+"\" \n";
        }
        if(temp->izquierda!=NULL){
           this->cuerpoArbolDot+="\""+temp->id+"\" -> \""+temp->izquierda->id+"\" \n";
        }
        this->cuerpoArbol(temp->derecha);
    }
}

void TreeAvl::preorder(NodoActivo *raiz){
    if(raiz==NULL){ return; }

    cout<<raiz->nombre<<"),";
    preorder(raiz->izquierda);
    preorder(raiz->derecha);
}

void TreeAvl::enorder(NodoActivo *raiz){
    if(raiz==NULL){return;}

    enorder(raiz->izquierda);
    if(raiz->estado){
        cout<<"-*- Id: "<<raiz->id<<"; nombre: "<<raiz->nombre<<endl;
    }
    enorder(raiz->derecha);
}

//Para eliminar
NodoActivo* TreeAvl::eliminar(NodoActivo* raiz,string dato){
    if(raiz == NULL){
        return raiz;
    }

    if(dato<raiz->id){
        raiz->izquierda = eliminar(raiz->izquierda,dato);
    }else if(dato>raiz->id){
        raiz ->derecha = eliminar(raiz->derecha,dato);
    }else{
        if(raiz->izquierda==NULL){
            return raiz->derecha;
        }else if(raiz->derecha==NULL){
            return raiz->izquierda;
        }else{
            NodoActivo* ordenar0=inorderE(raiz->derecha);
            raiz->id= ordenar0->id;
            raiz->descripcion=ordenar0->descripcion;
            raiz->estado=ordenar0->estado;
            raiz->nombre=ordenar0->nombre;
            raiz->derecha=eliminar(raiz->derecha,raiz->id);
        }

    }
    raiz=this->valancear(raiz,dato);
    return raiz;
}

NodoActivo* TreeAvl::valancear(NodoActivo *raiz,string datoE){
    if((Altura(raiz->izquierda) - Altura(raiz->derecha))==2){
            if(raiz->id>raiz->izquierda->id){
                    //va rotar a la izquierda
                raiz= simplederechaizquierda(raiz);
            //si sigue des equilibrado va rotar doble
                if( (Altura(raiz->derecha) - Altura(raiz->izquierda))==2){
                raiz= doblederechaderecha(raiz);
                }
            }else{
                raiz= doblederechaizquierda(raiz);
            }
    }else if( (Altura(raiz->derecha) - Altura(raiz->izquierda))==2){
            if(raiz->id<raiz->derecha->id){
                raiz= simplederechaderecha(raiz);
                if((Altura(raiz->izquierda) - Altura(raiz->derecha))==2){
                    raiz= doblederechaizquierda(raiz);
                }
            }else{
                raiz= doblederechaderecha(raiz);
            }
        }
    return raiz;
}

NodoActivo* TreeAvl::inorderE(NodoActivo* right){
    while(right->izquierda!=NULL){
        right= right->izquierda;
    }
    return right;
}

void TreeAvl::enorderCatalogo(NodoActivo *raiz){
    if(raiz==NULL){return;}

    enorderCatalogo(raiz->izquierda);
    if(raiz->estado){
        string imprimir="-*- Id: "+raiz->id+"; nombre: "+raiz->nombre+"; descripcion: "+ raiz->descripcion+"\n";
        cout<< imprimir;
    }
    enorderCatalogo(raiz->derecha);
}

void TreeAvl::enorderMisAcR(NodoActivo *raiz){
    if(raiz==NULL){return;}

    enorderMisAcR(raiz->izquierda);
    if(!raiz->estado){
        string imprimir="-*- Id: "+raiz->id+"; nombre: "+raiz->nombre+"; descripcion: "+ raiz->descripcion+"\n";
        cout<< imprimir;
    }
    enorderMisAcR(raiz->derecha);
}

TreeAvl::~TreeAvl()
{
    //dtor
}
