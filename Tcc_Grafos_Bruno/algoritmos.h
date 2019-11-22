#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "grafo.h"


class Algoritmos
{
public:

        int coloracaoGulosa(Grafo* grafo, int *ordem);

        //Apaga as cores do grafo
        void apagarCores(Grafo* grafo);

        //gera todas as permutaçõe de um vetor de inteiros
        void permutacao(int *vetor, int len);

        Grafo encontrarEstrutura(Grafo grafo);

        //Grafo procurarP4(Grafo grafo);

        // verifica se um obijeto No esta em uma lista
        bool estaNaLista(No no, vector<No> lista);


    private:
        void permutacaoRecusiva(int *vetor, int k, int len);
        Grafo encontrarVermelhos(Grafo grafo, vector<No> azuis);
        bool vizinhosEmComum(No n1, No n2, Grafo grafo);
        bool vizinhoEmComumVermelho(Grafo grafo, vector<No> lista);

};

#endif // ALGORITMOS_H
