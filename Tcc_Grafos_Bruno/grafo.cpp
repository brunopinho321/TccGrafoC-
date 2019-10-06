#include "grafo.h"

No Grafo::pegarVertice(int v, Grafo grafo){
    No no;
    for(No n : grafo.listaDeVertices){
        if(n.vertice == v){
            no = n;
        }
    }
    return no;
}

Grafo::Grafo(int ordem){
    this->ordem = ordem;
    //this->grafo = new list<No>[ordem];
    adicionarVerticeGrafo(ordem);
}

Grafo::Grafo(){
    this->ordem = 0;
}

string Grafo::toString(){
    std :: string c = "[";
    int len = this->listaDeVertices.size();
    for(int i = 0; i < len-1; i++){
        //No n = this->listaDeVertices[i];
        int vertice = this->listaDeVertices[i].getVertice();
        int cor = this->listaDeVertices[i].getCor();
        c = c + "(vertice: "+std::to_string(vertice) +", cor: "+std::to_string(cor)+ "), ";
    }
    int vertice = this->listaDeVertices[len-1].getVertice();
    int cor = this->listaDeVertices[len-1].getCor();
    c = c + "(vertice: "+std::to_string(vertice) +", cor: "+std::to_string(cor)+ ")]";


    return c;
}

void Grafo::adicionarVerticeGrafo(int ordem){

    for(int i = 0; i < ordem; i++){
        No no(i);
        this->listaDeVertices.push_back(no);
    }
    cout<<"criado"<<endl;
}

void Grafo::adicionarAresta(No v1, No v2){
    v1.adicionarVizinho(v2.vertice);
    //v1.vizinhos.push_back(v2.vertice);
    v2.adicionarVizinho(v1.vertice);
    //v2.vizinhos.push_back(v1.vertice);
    cout<<"adcionado" << endl;
}


void Grafo::adicionarVertice(No no){
    listaDeVertices.push_back(no);
}
