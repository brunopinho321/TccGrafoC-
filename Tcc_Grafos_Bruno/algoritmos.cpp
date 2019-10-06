#include "algoritmos.h"

bool Algoritmos::estaNaLista(No no, vector<No> lista){
    bool valor = false;
    for(No n : lista){
        if(n.vertice == no.vertice){
            valor = true;
        }

    }
    return valor;
}

Grafo Algoritmos::procurarP4(Grafo grafo){
    Grafo g;
        for(No n : grafo.listaDeVertices){
            if(n.vizinhos->size() >= 3 && estaNaLista(n, g.listaDeVertices)){
                g.adicionarVertice(n);
            }
        }
    return g;
}

void Algoritmos::permutacao(int *vetor, int len){
    permutacaoRecusiva(vetor, 0, len);
}

void Algoritmos::permutacaoRecusiva(int *vetor, int k, int len){
    if(k == len){
        std:: string c = "[";
        for(int i = 0; i<len-1; i++){
            c = c + std::to_string(vetor[i])+", ";
        }
        c = c + std::to_string(vetor[len-1])+"] ";
        cout << c <<endl;
    }
    else{
        for(int i = k; i<len; i++){
            swap(vetor[k], vetor[i]);
            permutacaoRecusiva(vetor, k+1, len);
            swap(vetor[i], vetor[k]);
        }
    }
}

void Algoritmos::apagarCores(Grafo* grafo){
    int len = grafo->listaDeVertices.size();
    for(int i = 0; i < len; i++){
        grafo->listaDeVertices[i].cor = 0;
    }
}


/*No* Algoritmos::getByIndex(int index, vector<No>* lista){
    No* n;
    vector<No> :: iterator i;
    int cont = 0;
    for(i = lista->begin(); i != lista->end(); i++){
        if(cont == index){
            No n1* = &i;
        }
        else{
            cont++;
        }
    }
    return n;
}*/

int Algoritmos::coloracaoGulosa(Grafo* grafo, int *ordem){

    int k = 0;
    int cor;
    int len = grafo->listaDeVertices.size();
    for(int i = 0; i < len; i++){
        No *no = &grafo->listaDeVertices[ordem[i]];
        cor = 1;
        int j = 0;
        int lenVizinhos = no->vizinhos->size();
        while(j < lenVizinhos){
            No *v = &grafo->listaDeVertices[no->getVizinho(j)];
            if(cor == v->cor){
                cor++;
                j = 0;
            }
            else{
                j++;
            }
        }
        grafo->listaDeVertices[ordem[i]].cor = cor;
        if(k < cor){
            k = cor;
        }

    }
    return k;
}

/*vector<No> Algoritmos::encontrarP4(Grafo grafo){
    vector<No>::iterator i;
    for(i = grafo.listaDeVertices.begin(); i != grafo.listaDeVertices.end(); i++){

    }
    return i;
}*/


