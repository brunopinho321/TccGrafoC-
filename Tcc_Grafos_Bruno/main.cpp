#include "algoritmos.h"

int main(){
    int n = 4;
        Grafo grafo(n);
        Algoritmos a;
        //vector<No>::iterator ptr;
        //for(ptr = grafo.grafo.begin(); ptr != grafo.grafo.end(); ptr++){
        //}
        grafo.adicionarAresta(grafo.listaDeVertices[0], grafo.listaDeVertices[1]);
        grafo.adicionarAresta(grafo.listaDeVertices[1], grafo.listaDeVertices[2]);
        grafo.adicionarAresta(grafo.listaDeVertices[2], grafo.listaDeVertices[3]);

        int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        cout <<grafo.listaDeVertices[1].vizinhos->size()<<endl;
        cout <<grafo.listaDeVertices[1].getVizinho(1)<<endl;
        cout << endl;
        cout << a.coloracaoGulosa(&grafo, v)<<endl;
        cout <<grafo.toString()<<endl;
        a.apagarCores(&grafo);
        cout <<grafo.toString()<<endl;
        a.permutacao(v, (int)sizeof(v)/sizeof(int));
        return 0;
}
