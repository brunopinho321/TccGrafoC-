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
    if(listaDeVertices.empty()){
        return "";
    }
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
}

void Grafo::adicionarAresta(No v1, No v2){
    this->numeroDeArestas = this->numeroDeArestas + 1;
    v1.adicionarVizinho(v2.vertice);
    if(v2.vertice == v1.vertice-1){
       v1.vetor[0] = v2.vertice;
    }
    else if(v2.vertice == v1.vertice+1){
        v1.vetor[1] = v2.vertice;
    }
    else if(v2.vertice < v1.vertice - 1){
        v1.vetor[2] = v2.vertice;
    }
    else if(v2.vertice > v1.vertice+1){
        v1.vetor[3] = v2.vertice;
    }

    //v1.vizinhos.push_back(v2.vertice);
    v2.adicionarVizinho(v1.vertice);
    if(v1.vertice == v2.vertice-1){
       v2.vetor[0] = v1.vertice;
    }
    else if(v1.vertice == v2.vertice+1){
        v2.vetor[1] = v1.vertice;
    }
    else if(v1.vertice < v2.vertice - 1){
        v2.vetor[2] = v1.vertice;
    }
    else if(v1.vertice > v2.vertice+1){
        v2.vetor[3] = v1.vertice;
    }


    //v2.vizinhos.push_back(v1.vertice);
    //cout<<"adcionado" << endl;
}

void Grafo::adicionarVertice(No no){
    listaDeVertices.push_back(no);
    this->ordem = this->ordem + 1;
}

No Grafo::pegarVertice(int vertice){
    No no(-1);
//    if(listaDeVertices[vertice].vertice == vertice){
//        No n = listaDeVertices[vertice];
//        return n;
//    }
    for(No n : this->listaDeVertices){
       if(n.vertice == vertice){
                return n;
       }

    }
    return no;

}


