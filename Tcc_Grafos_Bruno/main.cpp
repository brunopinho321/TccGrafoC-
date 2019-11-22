#include "algoritmos.h"
#include "grafo.h"
#include "no.h"
#include "reader.h"

int main(){
    int n = 17;
        Grafo grafo(n);
        Algoritmos a;

        //vector<No>::iterator ptr;
        //for(ptr = grafo.grafo.begin(); ptr != grafo.grafo.end(); ptr++){
        //}

//        grafo.adicionarAresta(grafo.listaDeVertices[0], grafo.listaDeVertices[1]);
//        grafo.adicionarAresta(grafo.listaDeVertices[0], grafo.listaDeVertices[4]);
//        grafo.adicionarAresta(grafo.listaDeVertices[1], grafo.listaDeVertices[2]);
//        grafo.adicionarAresta(grafo.listaDeVertices[1], grafo.listaDeVertices[5]);
//        grafo.adicionarAresta(grafo.listaDeVertices[2], grafo.listaDeVertices[3]);
//        grafo.adicionarAresta(grafo.listaDeVertices[2], grafo.listaDeVertices[6]);
//        grafo.adicionarAresta(grafo.listaDeVertices[3], grafo.listaDeVertices[7]);
//        grafo.adicionarAresta(grafo.listaDeVertices[4], grafo.listaDeVertices[5]);
//        grafo.adicionarAresta(grafo.listaDeVertices[4], grafo.listaDeVertices[8]);
//        grafo.adicionarAresta(grafo.listaDeVertices[5], grafo.listaDeVertices[9]);
//        grafo.adicionarAresta(grafo.listaDeVertices[5], grafo.listaDeVertices[6]);
//        grafo.adicionarAresta(grafo.listaDeVertices[6], grafo.listaDeVertices[7]);
//        grafo.adicionarAresta(grafo.listaDeVertices[6], grafo.listaDeVertices[10]);
//        grafo.adicionarAresta(grafo.listaDeVertices[7], grafo.listaDeVertices[11]);
//        grafo.adicionarAresta(grafo.listaDeVertices[8], grafo.listaDeVertices[9]);
//        grafo.adicionarAresta(grafo.listaDeVertices[9], grafo.listaDeVertices[10]);
//        grafo.adicionarAresta(grafo.listaDeVertices[10], grafo.listaDeVertices[11]);

//        grafo.adicionarAresta(grafo.listaDeVertices[11], grafo.listaDeVertices[12]);
//        grafo.adicionarAresta(grafo.listaDeVertices[12], grafo.listaDeVertices[13]);

        //cout<<grafo.toString()<<endl;

//        int v[] = {0, 1, 3, 2, 4, 5, 6, 7, 8, 9, 10, 11};
//        cout <<grafo.listaDeVertices[1].vizinhos->size()<<endl;
//        cout <<grafo.listaDeVertices[1].getVizinho(1)<<endl;
//        cout << endl;
//        cout << a.coloracaoGulosa(&grafo, v)<<endl;
//       // cout <<grafo.toString()<<endl;
//        a.apagarCores(&grafo);
       // cout <<grafo.toString()<<endl;
       // a.permutacao(v, (int)sizeof(v)/sizeof(int));

       grafo.adicionarAresta(grafo.listaDeVertices[0], grafo.listaDeVertices[1]);

        grafo.adicionarAresta(grafo.listaDeVertices[0], grafo.listaDeVertices[4]);
        grafo.adicionarAresta(grafo.listaDeVertices[1], grafo.listaDeVertices[5]);
        grafo.adicionarAresta(grafo.listaDeVertices[2], grafo.listaDeVertices[6]);
        grafo.adicionarAresta(grafo.listaDeVertices[3], grafo.listaDeVertices[7]);

        grafo.adicionarAresta(grafo.listaDeVertices[4], grafo.listaDeVertices[8]);
        grafo.adicionarAresta(grafo.listaDeVertices[5], grafo.listaDeVertices[9]);
        grafo.adicionarAresta(grafo.listaDeVertices[6], grafo.listaDeVertices[10]);
        grafo.adicionarAresta(grafo.listaDeVertices[7], grafo.listaDeVertices[11]);

        grafo.adicionarAresta(grafo.listaDeVertices[8], grafo.listaDeVertices[12]);
        grafo.adicionarAresta(grafo.listaDeVertices[9], grafo.listaDeVertices[13]);
        grafo.adicionarAresta(grafo.listaDeVertices[10], grafo.listaDeVertices[14]);
        grafo.adicionarAresta(grafo.listaDeVertices[11], grafo.listaDeVertices[15]);

        grafo.adicionarAresta(grafo.listaDeVertices[8], grafo.listaDeVertices[9]);
        grafo.adicionarAresta(grafo.listaDeVertices[9], grafo.listaDeVertices[10]);
        grafo.adicionarAresta(grafo.listaDeVertices[10], grafo.listaDeVertices[11]);

        grafo.adicionarAresta(grafo.listaDeVertices[12], grafo.listaDeVertices[16]);



       // Grafo g = a.encontrarEstrutura(grafo);
       // string st = a.encontrarEstrutura(grafo).toString();
       // cout<<st<<endl;
//        bool valor = grafo.listaDeVertices[1].ehVizinho(2);
//        cout << valor;
        //Reader leitor;
        //Grafo g =leitor.leitor();
        Grafo g = a.GRAPHrand2(90, 100, 0);
       cout<<g.toString()<<endl;
       cout<<g.numeroDeArestas<<endl;
//       for(No n : g.listaDeVertices){
//            cout<<n.toStirng()<<endl;
//       }

       cout<<endl;
       clock_t t1[2], t2[2];
       t1[0] = clock();
       Grafo estrutura = a.encontrarEstruturas1(g);
       t1[1] = clock();
       float tempo = (t1[1] - t1[0]) /(double)CLOCKS_PER_SEC;
       cout<<"Tempo gasto:";
       printf("%f", tempo);
       cout<<"s";
       cout<<endl;
       cout<<estrutura.toString()<<endl;
       estrutura.listaDeVertices.clear();
       cout<<endl;

       cout<<"Novo algoritmos"<<endl;
       t2[0] = clock();
       estrutura = a.encontrarEstruturas(g);
       t2[1] = clock();
       tempo = (t2[1] - t2[0])/(double)CLOCKS_PER_SEC;
       cout<<"Tempo gasto:";
       printf("%f", tempo);
       cout<<"s";
       cout<<endl;
       cout<<estrutura.toString()<<endl;


       cout<<endl;


//       estrutura = a.GRAPHrand1(10, 10, 50);


//       cout<<estrutura.toString()<<endl;
//       cout<<"qtd Arestas: "+std::to_string(estrutura.numeroDeArestas)<<endl;
//       for(No n : estrutura.listaDeVertices){
//            cout<<n.toStirng()<<endl;
//       }


//       cout<<endl;


//       estrutura = a.GRAPHrand2(4, 5, 200);

//       cout<<estrutura.toString()<<endl;
//       cout<<"qtd Arestas: "+std::to_string(estrutura.numeroDeArestas)<<endl;
//       for(No n : estrutura.listaDeVertices){
//            cout<<n.toStirng()<<endl;
//       }


        return 0;
}
