#ifndef GRAFO_H
#define GRAFO_H
#include "no.h"

class Grafo
{
public:
    int ordem;
    int numeroDeArestas = 0;
    vector<No> listaDeVertices;

    Grafo(int ordem);
    Grafo();
    void adicionarAresta(No v1, No v2);
    void adicionarVertice(No v1);
    No pegarVertice(int v, Grafo grafo);
    No pegarVertice(int vertice);
    string toString();
private:
    void adicionarVerticeGrafo(int ordem);
};

#endif // GRAFO_H
