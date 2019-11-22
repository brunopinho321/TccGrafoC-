#include "algoritmos.h"

int main(){
    int n = 12;
        Grafo grafo(n);
        Algoritmos a;
        //vector<No>::iterator ptr;
        //for(ptr = grafo.grafo.begin(); ptr != grafo.grafo.end(); ptr++){
        //}
        grafo.adicionarAresta(grafo.listaDeVertices[0], grafo.listaDeVertices[1]);
        grafo.adicionarAresta(grafo.listaDeVertices[0], grafo.listaDeVertices[4]);
        grafo.adicionarAresta(grafo.listaDeVertices[1], grafo.listaDeVertices[2]);
        grafo.adicionarAresta(grafo.listaDeVertices[1], grafo.listaDeVertices[5]);
        grafo.adicionarAresta(grafo.listaDeVertices[2], grafo.listaDeVertices[3]);
        grafo.adicionarAresta(grafo.listaDeVertices[2], grafo.listaDeVertices[6]);
        grafo.adicionarAresta(grafo.listaDeVertices[3], grafo.listaDeVertices[7]);
        grafo.adicionarAresta(grafo.listaDeVertices[4], grafo.listaDeVertices[5]);
        grafo.adicionarAresta(grafo.listaDeVertices[4], grafo.listaDeVertices[8]);
        grafo.adicionarAresta(grafo.listaDeVertices[5], grafo.listaDeVertices[9]);
        grafo.adicionarAresta(grafo.listaDeVertices[5], grafo.listaDeVertices[6]);
        grafo.adicionarAresta(grafo.listaDeVertices[6], grafo.listaDeVertices[7]);
        grafo.adicionarAresta(grafo.listaDeVertices[6], grafo.listaDeVertices[10]);
        grafo.adicionarAresta(grafo.listaDeVertices[7], grafo.listaDeVertices[11]);
        grafo.adicionarAresta(grafo.listaDeVertices[8], grafo.listaDeVertices[9]);
        grafo.adicionarAresta(grafo.listaDeVertices[9], grafo.listaDeVertices[10]);
        grafo.adicionarAresta(grafo.listaDeVertices[10], grafo.listaDeVertices[11]);


        int v[] = {0, 1, 3, 2, 4, 5, 6, 7, 8, 9, 10, 11};
        cout <<grafo.listaDeVertices[1].vizinhos->size()<<endl;
        cout <<grafo.listaDeVertices[1].getVizinho(1)<<endl;
        cout << endl;
        cout << a.coloracaoGulosa(&grafo, v)<<endl;
       // cout <<grafo.toString()<<endl;
        a.apagarCores(&grafo);
       // cout <<grafo.toString()<<endl;
       // a.permutacao(v, (int)sizeof(v)/sizeof(int));
        string st = a.encontrarEstrutura(grafo).toString();
        cout<<st<<endl;
        bool valor = grafo.listaDeVertices[1].ehVizinho(2);
        cout << valor;
        return 0;
}
