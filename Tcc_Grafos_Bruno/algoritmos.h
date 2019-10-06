#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "grafo.h"


class Algoritmos
{
public:
        vector<No> encontrarP4(Grafo grafo);
        int coloracaoGulosa(Grafo* grafo, int *ordem);
        void apagarCores(Grafo* grafo);
        void permutacao(int *vetor, int len);
        Grafo procurarP4(Grafo grafo);
        bool estaNaLista(No no, vector<No> lista);
    private:
        void permutacaoRecusiva(int *vetor, int k, int len);

};

#endif // ALGORITMOS_H
