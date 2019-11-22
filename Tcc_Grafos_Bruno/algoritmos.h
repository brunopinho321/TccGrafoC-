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

        Grafo encontrarEstrutura5Cores(Grafo grafo);
        Grafo encontrarEstrutura4Cores(Grafo grafo);
        Grafo encontrarEstrutura3Cores(Grafo grafo);

        Grafo encontrarEstruturas(Grafo grafo);
        Grafo encontrarEstruturas1(Grafo grafo);
        //Grafo procurarP4(Grafo grafo);

        // verifica se um obijeto No esta em uma lista
        bool estaNaLista(No no, vector<No> lista);
        int* geradorDeOrdem(Grafo estrutura, Grafo grafo);
        Grafo GRAPHrand1(int N, int M, int A);
        Grafo GRAPHrand2(int N, int M, int P);
        No randV(Grafo grafo);

    private:
        void permutacaoRecusiva(int *vetor, int k, int len);
        //Grafo encontrarVermelhos(Grafo grafo, vector<No> azuis);
        int vizinhosEmComum(Grafo grafo, vector<No> lista);
        bool vizinhoEmComumVermelho(Grafo grafo, vector<No> lista);
        bool vizinhosNaLista(Grafo grafo, No n, vector<No> lista);
        vector<No> encontrarVermelhos(Grafo grafo, vector<No> azuis);
        vector<No> encontrarPretos(Grafo grafo, vector<No> azuis, vector<No> vermelhos);
        Grafo pintarEstrutura(Grafo grafo, Grafo estrutura, vector<No> azuis, vector<No> vermelhos, vector<No> pretos);
        void pintaVertice(Grafo* grafo, No vertice, int cor);
        bool vizinhoPintado(No vertice, int cor, Grafo grafo);
        vector<No> listaVizinhos(No n, Grafo grafo, vector<No> azuis);
        Grafo pintarVermelhos(Grafo grafo, Grafo estrutura, vector<No>azuis, vector<No> vermelhos);
        Grafo pintarPretos(Grafo grafo, Grafo estrutura, vector<No>azuis, vector<No> pretos);
        int pintarAzuis(Grafo *estrutura, vector<No> azuis);
        bool ehVizinho(No n1, No n2, Grafo *grafo);
        bool mesmoVizinho(No n1, No n2, Grafo *grafo);
        vector<No> pegarP4(int index,vector<No> p4, Grafo grafo);

};

#endif // ALGORITMOS_H
