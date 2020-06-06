#include "Matriz.h"

Matriz::Matriz()
{
    this->root = new NodoMatriz("root",-1);
    this->contadorN = 0;
}

//las empresas de insertan hacia abajo
NodoMatriz* Matriz::createEmpresa(string name){
    NodoMatriz* empresaC = new NodoMatriz(name,contadorN++);

    NodoMatriz* temp = this->root;
    while(temp->abajo!=NULL){
        temp=temp->abajo;
    }
    temp->abajo=empresaC;
    empresaC->arriba=temp;

    return empresaC;
}

//Los departamentos se insertan hacia adelante
NodoMatriz* Matriz::createDepartamento(string name){
    NodoMatriz* departamentoC = new NodoMatriz(name,contadorN++);

    NodoMatriz* temp = this->root;
    while(temp->adelante!=NULL){
        temp=temp->adelante;
    }
    temp->adelante=departamentoC;
    departamentoC->atras=temp;
    return departamentoC;
}

//Buscamo una empresa en base a la raiz

NodoMatriz* Matriz::searchEmpresa(string name){
    NodoMatriz *temp = this->root;
    while(temp!=NULL){
        if(temp->name==name){
            return temp;
        }
        temp=temp->abajo;
    }
    return NULL;
}
//Busca un departamento en base a la raiz
NodoMatriz* Matriz::searchDepartamento(string name){
    NodoMatriz *temp = this->root;
    while(temp!=NULL){
        if(temp->name==name){
            return temp;
        }
        temp=temp->adelante;
    }
    return NULL;
}

void Matriz::imprimir(){
    NodoMatriz *temp=this->root;

    while(temp!=NULL){
        if(temp->adelante!=NULL){
            cout<<temp->name<<" -> "<<temp->adelante->name<<endl;
        }
        temp= temp->adelante;
    }
    temp=this->root;
    while(temp!=NULL){
        if(temp->abajo!=NULL){
            cout<<temp->name<<" v "<<temp->abajo->name<<endl;
        }
        temp= temp->abajo;
    }
    temp=this->root;
    temp=temp->adelante;
    while(temp!=NULL){
        NodoMatriz *temp2= temp;
        temp2=temp2->abajo;
        cout<<temp->name+"* ";
        while(temp2!=NULL){
            cout<<temp2->name+"v";
            temp2=temp2->abajo;
        }
        temp=temp->adelante;
    }
    temp=this->root;
    temp=temp->abajo;
    while(temp!=NULL){
        NodoMatriz *temp2= temp;
        temp2=temp2->adelante;
        cout<<temp->name+"* ";
        while(temp2!=NULL){
            cout<<temp2->name+"->";
            temp2=temp2->adelante;
        }
        temp=temp->abajo;
    }
}

void Matriz::insertarNodoMatriz(string name,string empresa,string departamento,int contador){
    NodoMatriz *user;
    NodoMatriz *empresaN;
    NodoMatriz *departamentoN;
    //Esto solo sera ahorita
    user = new NodoMatriz(name,contador++);
    //Verificamos si la empresa ya existe
    empresaN= this->searchEmpresa(empresa);
    departamentoN = this->searchDepartamento(departamento);
    //Verificamos si las empresas o departamentos existen
    if(empresaN==NULL){ empresaN = this->createEmpresa(empresa); }
    if(departamentoN==NULL){ departamentoN = this->createDepartamento(departamento); }

    //Insertando en la cabecera de departamentos
    if(departamentoN->abajo==NULL){
        departamentoN->abajo=user;
        user->arriba=departamentoN;
    }else if (empresaN->abajo==NULL){
        NodoMatriz* auxiliar = departamentoN->abajo;
        while(auxiliar!=NULL){
            auxiliar = auxiliar->abajo;
        }
        auxiliar->abajo = user;
        user->arriba = auxiliar;
    }else{
        NodoMatriz* auxD = departamentoN;

        do{
            auxD = auxD->abajo;
            NodoMatriz* auxE = auxD->atras;
            while(auxE->atras!=NULL){
                auxE=auxE->atras;
            }
            while(auxE->arriba!=NULL){
                if(auxE->name==empresa){
                    user->abajo=auxD;
                    user->arriba=auxD->arriba;

                    auxD->arriba->abajo=user;
                    auxD->arriba=user;
                }
                auxE=auxE->arriba;
            }
        }while(auxD->abajo!=NULL && user->arriba==NULL);

        if(user->arriba==NULL){
            auxD->abajo=user;
            user->arriba=auxD;
        }
    }

    //Insertar en la fila de empresas
    if(empresaN->adelante==NULL){
        empresaN->adelante = user;
        user->atras =empresaN;
    }else if(departamentoN->adelante==NULL){
        NodoMatriz * auxiliar2 = empresaN->adelante;
        while(auxiliar2->adelante!=NULL){
             auxiliar2=auxiliar2->adelante;
        }
        auxiliar2->adelante=user;
        user->atras = auxiliar2;
    }else{
        NodoMatriz* auxE = empresaN;

        do{
            auxE = auxE->adelante;
            NodoMatriz* auxD = auxE->arriba;
            while(auxD->arriba!=NULL){
                auxD=auxD->arriba;
            }
            while(auxD->atras!=NULL){
                if(auxD->name==departamento){
                    user->adelante=auxE;
                    user->atras=auxE->atras;

                    auxE->atras->adelante=user;
                    auxE->atras=user;
                    break;
                }
                auxD=auxD->atras;
            }
        }while(auxE->adelante!=NULL && user->atras==NULL);
        if(user->atras==NULL){
            auxE->adelante=user;
            user->atras=auxE;
        }
    }

}

Matriz::~Matriz()
{
    //dtor
}
