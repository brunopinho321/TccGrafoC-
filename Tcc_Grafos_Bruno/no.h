#ifndef NO_H
#define NO_H

#include <iostream>
//#include <list>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>

class No
{
public:
        int vertice;
        int cor;
        vector<int> *vizinhos;
        No(int vertice);
        No();
        int getVertice();
        void adicionarVizinho(int vertice);
        int getVizinho(int index);
        int getCor();
        bool ehVizinho(int vertice);
};

#endif // NO_H
