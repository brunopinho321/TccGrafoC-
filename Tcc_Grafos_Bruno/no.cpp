#include "no.h"

No::No(){

}
No::No(int vertice){
    this->vertice = vertice;
    this->cor = 0;
    this->vizinhos = new vector<int>();
}

int No::getCor(){
    return this->cor;
}
int No::getVertice(){
    return this->vertice;
}

void No::adicionarVizinho(int vertice){
    this->vizinhos->push_back(vertice);
}
int No::getVizinho(int index){
    int cont = 0;
    vector<int>::iterator i;
    int v;
    for(i = this->vizinhos->begin(); i != this->vizinhos->end(); i++){
        if(cont == index){
            v = *i;
            break;
        }else{
            cont++;
        }
    }
    return v;

}
