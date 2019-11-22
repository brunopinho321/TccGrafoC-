#ifndef NO_H
#define NO_H

#include<time.h>
#include <iostream>
//#include <list>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include<stdlib.h>

class No
{
public:
        int vertice;
        int cor;
        vector<int> *vizinhos;
        int vetor[4] = {-1, -1, -1, -1};
        No(int vertice);
        No();
        int getVertice();
        void adicionarVizinho(int vertice);
        int getVizinho(int index);
        int getCor();
        bool ehVizinho(int vertice);
        string toStirng();

};

#endif // NO_H
