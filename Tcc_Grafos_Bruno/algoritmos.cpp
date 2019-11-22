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


Grafo Algoritmos::encontrarEstrutura(Grafo grafo){
    Grafo g;
    vector<No> azuis;
    vector<No> vermelhos;
    vector<No> pretos;
    int vetor[grafo.listaDeVertices.size()];
    for(int i = 0; i < grafo.listaDeVertices.size(); i++ ){
        vetor[i] = 0;
    }
    for(No n:grafo.listaDeVertices){
        if(n.vizinhos->size() >= 3){
             azuis.push_back(n);

            for(int n1 : *n.vizinhos){
                No no1 = grafo.pegarVertice(n1);

                if(no1.vizinhos->size() == 4 && !estaNaLista(no1, azuis)){
                   azuis.push_back(no1);

                    for(int n2 : *no1.vizinhos){
                        No no2 = grafo.pegarVertice(n2);

                        if(no2.vizinhos->size() == 4 && !estaNaLista(no2, azuis)){
                            azuis.push_back(no2);

                            for(int n3 : *no2.vizinhos){
                                No no3 = grafo.pegarVertice(n3);

                                if(no3.vizinhos->size() >= 3 && !estaNaLista(no3, azuis) && !no3.ehVizinho(n.vertice)){
                                    azuis.push_back(no3);
                                    g.listaDeVertices = azuis;
                                    g.ordem = azuis.size();
                                    //return g;
                                     cout<<g.toString()<<endl;

                                    azuis.pop_back();

                                }
                            }
                            azuis.pop_back();
                        }
                    }
                    azuis.pop_back();
                }
            }
            azuis.pop_back();
        }
    }

    return NULL;
}


bool Algoritmos::vizinhosEmComum(No n1, No n2, Grafo grafo){
    bool valor = false;
    for(int i : *n1.vizinhos){
        for(int j : *n2.vizinhos){
            if(i == j && grafo.pegarVertice(j).vertice == -1){
                valor = true;
            }
        }
    }
    return valor;
}

bool Algoritmos::vizinhoEmComumVermelho(Grafo grafo, vector<No> lista){
    for(No n1 : grafo.listaDeVertices){
        for(No n2 : grafo.listaDeVertices){
            if(n1.vertice != n2.vertice){
                if(vizinhosEmComum(n1, n2, grafo)){
                    return true;
                }
            }
        }
    }
    return false;
}




/*vector<No> Algoritmos::encontrarP4(Grafo grafo){
    vector<No>::iterator i;
    for(i = grafo.listaDeVertices.begin(); i != grafo.listaDeVertices.end(); i++){

    }
    return i;
}*/


