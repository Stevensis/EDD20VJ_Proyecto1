#include "Matriz.h"
#include <bits/stdc++.h>
#include <windows.h>

Matriz::Matriz()
{
    this->root = new NodoMatriz("root",-1,"admin","admin");
    this->contadorN = 0;
}

//las empresas de insertan hacia abajo
NodoMatriz* Matriz::createEmpresa(string name){
    NodoMatriz* empresaC = new NodoMatriz(name,contadorN++,"","");

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
    NodoMatriz* departamentoC = new NodoMatriz(name,contadorN++,"","");

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
        cout<<temp->name + " * " << to_string(temp->contador) + "- ";
        while(temp2!=NULL){
            cout<<temp2->name+" v "<< to_string(temp2->contador)+" ";
            temp2=temp2->abajo;
        }
        temp=temp->adelante;
    }
    temp=this->root;
    temp=temp->abajo;
    while(temp!=NULL){
        NodoMatriz *temp2= temp;
        temp2=temp2->adelante;
        cout<<temp->name+"* "<<to_string(temp->contador)+" ";
        while(temp2!=NULL){
            cout<<to_string(temp2->contador)+" "<<temp2->name+"-> ";
            temp2=temp2->adelante;
        }
        temp=temp->abajo;
    }
}

void Matriz::insertarNodoMatriz(string name,string empresa,string departamento,string nameuser,string password,int contador){
    NodoMatriz *user;
    NodoMatriz *empresaN;
    NodoMatriz *departamentoN;
    //Esto solo sera ahorita
    user = new NodoMatriz(name,contador++,nameuser,password);
    //Verificamos si la empresa ya existe
    empresaN= this->searchEmpresa(empresa);
    departamentoN = this->searchDepartamento(departamento);
    //Verificamos si existen la empresa y el departamento porque si existen puede que este nodo ya exista
    if(empresaN!=NULL && departamentoN!=NULL){
        NodoMatriz *tempE=empresaN->adelante;
        //recorremos cada nodo siguiente de la empresa
        while(tempE!=NULL){
            //recorremos hacia arriba para verificar la empresa
            NodoMatriz *tempD=tempE->arriba;
            while(tempD->arriba!=NULL){
                tempD=tempD->arriba;
            }
            if(tempD->name==departamento){
                NodoMatriz *tempU=tempE;
                if(tempU->nameuser==user->nameuser){cout<<"usuario ya existenete\n"; return;}
                while(tempU->padentro!=NULL){
                    tempU=tempU->padentro;
                    if(tempU->nameuser==user->nameuser){cout<<"usuario ya existenete\n"; return;}
                }
                tempU->padentro=user;
                user->paenfrente=tempU;
                return;
            }
            tempE=tempE->adelante;

        }
    }
    //Verificamos si las empresas o departamentos existen
    if(empresaN==NULL){ empresaN = this->createEmpresa(empresa); }
    if(departamentoN==NULL){ departamentoN = this->createDepartamento(departamento); }

    //Insertando en la cabecera de departamentos
    if(departamentoN->abajo==NULL){
        departamentoN->abajo=user;
        user->arriba=departamentoN;
    }else if (empresaN->abajo==NULL){
        NodoMatriz* auxiliar = departamentoN->abajo;
        while(auxiliar->abajo!=NULL){
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
/**<  */
NodoMatriz* Matriz::existe(string user,string departamento,string empresa)
{
    NodoMatriz *userR=NULL;
    NodoMatriz *empresaN;
    NodoMatriz *departamentoN;
    empresaN= this->searchEmpresa(empresa);
    departamentoN = this->searchDepartamento(departamento);
    if(empresaN!=NULL && departamentoN!=NULL){
        NodoMatriz *tempE=empresaN->adelante;
        //recorremos cada nodo siguiente de la empresa
        while(tempE!=NULL){
            //recorremos hacia arriba para verificar la empresa
            NodoMatriz *tempD=tempE->arriba;
            while(tempD->arriba!=NULL){
                tempD=tempD->arriba;
            }
            if(tempD->name==departamento){
                NodoMatriz *tempU=tempE;
                if(tempU->nameuser==user){ return tempU;}
                while(tempU->padentro!=NULL){
                    tempU=tempU->padentro;
                    if(tempU->nameuser==user){ return tempU;}
                }
            }
            tempE=tempE->adelante;

        }
    }
    return userR;
}

void Matriz::graficarMatriz(string nombre){
    NodoMatriz *temp= this->root;
    string prueba="";
    ofstream grafica;
    grafica.open("Prueba.dot", ios::out);
    grafica << "digraph Sparce_Matrix { \n node [shape=box];\n";
    prueba+= to_string(temp->contador)+"[ label = \"root\", width = 1.5, style = filled, color = firebrick1, group = 1 ]; \n e0[ shape = point, width = 0 ]; \n e1[ shape = point, width = 0 ]; \n";
    //escririmos las empresas
    temp=temp->abajo;
    //Contador para nodes ficticios
    int e=0;
    while(temp!=NULL){
        prueba+= "\n /* Empresas */ \n";
        prueba+= to_string(temp->contador) + " [label = \"" + temp->name + "\"    pos = \"5.3,3.5!\" width = 1.5 style = filled, color = coral1, group = 1 ]; \n" ;
        if(temp->adelante!=NULL){
            string rankF="{ rank = same; "+to_string(temp->contador);
            NodoMatriz *tempf= temp->adelante;
            //Definir las columnas
            while(tempf!=NULL){
                rankF+=" ; "+to_string(tempf->contador);
                tempf= tempf->adelante;
            }
            rankF+=" }\n";
            prueba+=rankF;
            //Definir enlaces a la derecha
            tempf= temp->adelante;
            prueba+= to_string(temp->contador)+" -> "+to_string(tempf->contador)+"\n" ;
            prueba+= to_string(tempf-> contador)+" -> "+to_string(temp->contador)+"\n" ;
            while(tempf->adelante!=NULL){
            prueba+= to_string(tempf->contador)+" -> "+to_string(tempf->adelante->contador)+"\n" ;
            prueba+= to_string(tempf->adelante->contador)+" -> "+to_string(tempf->contador)+"\n" ;
            tempf= tempf->adelante;
            }
        }
         prueba+= "e"+to_string(e)+"[ shape = point, width = 0 ];";
         prueba+= "{ rank = same; "+to_string(temp->contador)+"; e"+to_string(e)+" }";
        e++;
        temp=temp->abajo;

    }
    //apuntadores entre las empresas
    temp=this->root;
    temp=temp->abajo;
    while(temp->abajo!=NULL){
        prueba+= "\n   /* Enlacex entre empresas */ \n";
        prueba+= to_string(temp->contador)+" -> "+to_string(temp->abajo->contador)+"\n" ;
        prueba+= to_string(temp->abajo->contador)+" -> "+to_string(temp->contador)+"\n" ;
        temp=temp->abajo;
    }

    //escririmos los departamentos
    temp=this->root;
    temp=temp->adelante;
    int contadorg=1;
    while(temp!=NULL){
        contadorg++;
        prueba+= "\n /* Departamentos */ \n";
        prueba+= to_string(temp->contador)+ " [label = \""+ temp->name +"\"   width = 1.5 style = filled, color = darkolivegreen2, group ="+to_string(contadorg) +" ];\n";
        //varificamos hacia abajo para ingresar los nodos dentro de la matriz
        if(temp->abajo!=NULL){
            NodoMatriz *tempc= temp->abajo;
            while(tempc!=NULL){
                //recorre la lista de usuarios
                string usuarios="";
                NodoMatriz *tempU = tempc;
                while(tempU!=NULL){
                usuarios+="<tr><td>"+ tempU->name +"</td></tr>";
                tempU=tempU->padentro;
                }
                prueba+=to_string(tempc->contador)+" [label = <<table border = \"0\">"+usuarios+"</table>>, width = 1.5, group = "+to_string(contadorg) +" ];\n";
                tempc= tempc->abajo;
            }
            tempc= temp->abajo;
            prueba+= to_string(temp->contador)+" -> "+to_string(tempc->contador)+"\n" ;
            prueba+= to_string(tempc->contador)+" -> "+to_string(temp->contador)+"\n" ;
            while(tempc->abajo!=NULL){
                prueba+= to_string(tempc->contador)+" -> "+to_string(tempc->abajo->contador)+"\n" ;
                prueba+= to_string(tempc->abajo->contador)+" -> "+to_string(tempc->contador)+"\n" ;
                tempc=tempc->abajo;
            }

        }
        temp=temp->adelante;
    }
    //apuntadores entre los departamentos
    temp=this->root;
    temp=temp->adelante;
    while(temp->adelante!=NULL){
        prueba+= "\n   /* Enlaces entre departamentos */ \n";
        prueba+= to_string(temp->contador)+" -> "+to_string(temp->adelante->contador) +"\n" ;
        prueba+= to_string(temp->adelante->contador)+" -> "+to_string(temp->contador) +"\n";
        temp=temp->adelante;
    }
    prueba+=to_string(temp->contador) + " -> e0 -> e1[ dir = none ];" ;
    temp=this->root;
    //raiz apunta al inicio de los departamentos y las empresas
    prueba+=to_string(temp->contador)+" -> "+to_string(temp->adelante->contador)+"\n";
    prueba+=to_string(temp->adelante->contador)+" -> "+to_string(temp->contador)+"\n";
    prueba+=to_string(temp->contador)+" -> "+to_string(temp->abajo->contador)+"\n";
    prueba+=to_string(temp->abajo->contador)+" -> "+to_string(temp->contador)+"\n";
    //decimos que la raiz junto con los departamentos son una fila
    prueba+=" { rank = same; -1; ";
    temp=temp->adelante;
    while(temp!=NULL){
        prueba+=to_string(temp->contador)+"; ";
        temp=temp->adelante;
    }
    prueba+=" }\n";
    temp=this->root;

    grafica << prueba;
    grafica << "}";

    grafica.close();

    string creacion = "dot -Tjpg " + nombre + ".dot -o " + nombre + ".jpg";
    system(creacion.c_str());
    string title = nombre  + ".jpg";
    ShellExecute(NULL, "open", title.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

NodoActivo* Matriz::serachActivo(string id){
    NodoMatriz* tempNM= this->root->adelante;
    //recoremos los departamentos, para esto nos vamos de la raiz por todos adelabte
    while(tempNM!=NULL){
        //recorremos los nodos usuarios
        NodoMatriz* tempU= tempNM->abajo;
        while(tempU!=NULL){
                //recorremos el mismo nodo pero para adentro con los demas usuarios, si es que tiene
                NodoMatriz* tempU2=tempU;
                while(tempU2!=NULL){
                    NodoActivo* activo= tempU2->treeAvl->searchroot(tempU2->treeAvl->root,id);
                    if(activo!=NULL){
                            return activo;
                    }
                    tempU2=tempU2->padentro;
                }
            tempU=tempU->abajo;
        }
        tempNM=tempNM->adelante;
    }
    return NULL;
}

//Imprimimos el catalogo de activos

void Matriz::catologo(NodoMatriz* user){
        NodoMatriz* tempNM= this->root->adelante;
    //recoremos los departamentos, para esto nos vamos de la raiz por todos adelabte
    while(tempNM!=NULL){
        //recorremos los nodos usuarios
        NodoMatriz* tempU= tempNM->abajo;
        while(tempU!=NULL){
                //recorremos el mismo nodo pero para adentro con los demas usuarios, si es que tiene
                NodoMatriz* tempU2=tempU;
                while(tempU2!=NULL){
                    if(tempU2!=user){
                        tempU2->treeAvl->enorderCatalogo(tempU2->treeAvl->root);
                    }
                    tempU2=tempU2->padentro;
                }
            tempU=tempU->abajo;
        }
        tempNM=tempNM->adelante;
    }
}

Matriz::~Matriz()
{
    //dtor
}
