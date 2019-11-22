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

bool No::ehVizinho(int vertice){
    bool valor = false;
    for(int i : *this->vizinhos){
       // cout<<i<<endl;
        if(i == vertice){
            valor = true;
        }
    }
    return valor;
}


string No :: toStirng(){
    string s = "vertice "+ std::to_string(this->vertice);
    if(this->vizinhos->size() < 1){
        s = s+" [ ]";
        return s;
    }
    s = s+" [";
    int cont  = 0;
    for(int i : *this->vizinhos){
        if(cont == vizinhos->size()-1){
            s = s+""+std::to_string(i)+"]";
        }else{
            s = s+""+std::to_string(i)+", ";
        }
        cont++;
    }
    return s;
}
