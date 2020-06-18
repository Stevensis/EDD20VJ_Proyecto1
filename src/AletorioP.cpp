#include "AletorioP.h"

AletorioP::AletorioP(Matriz* matriz)
{
    this->ma=matriz;
    //ctor
}

string AletorioP::idActivo(){
    int num, c;
    NodoActivo* verificar;
    srand(time(NULL));
    string id2="";
    string alphanum="0123456789abcdefghijklmnopqrstuvwxyz";
    do{
            id2="";
       for(c = 0; c < 15; c++)
    {
        num = 0 + rand() % (alphanum.length() - 0);
        id2+=alphanum[num];
    }
       verificar=this->ma->serachActivo(id2);
    }while(verificar!=NULL);


    return id2;
}

AletorioP::~AletorioP()
{
    //dtor
}
