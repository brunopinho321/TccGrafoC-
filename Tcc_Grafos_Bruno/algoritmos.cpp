#include "algoritmos.h"

bool Algoritmos::estaNaLista(No no, vector<No> lista){
    bool valor = false;
    for(No n : lista){
        if(n.vertice == no.vertice){
            valor = true;
            return valor;
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


//////////////////////////////////////////////////////
void Algoritmos::apagarCores(Grafo* grafo){
    int len = grafo->listaDeVertices.size();
    for(int i = 0; i < len; i++){
        grafo->listaDeVertices[i].cor = 0;
    }
}

/////////////////////////////////////////////////////////
int Algoritmos::coloracaoGulosa(Grafo* grafo, int *ordem){

    int k = 0;
    int cor;
    int len = int(grafo->listaDeVertices.size());
    for(int i = 0; i < len; i++){
        No *no = &grafo->listaDeVertices[ordem[i]];
        cor = 1;
        int j = 0;
        int lenVizinhos = int(no->vizinhos->size());
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


///////////////////////////////////////////////////////////////
Grafo Algoritmos::encontrarEstrutura5Cores(Grafo grafo){
    cout<<"Procurando estrutura de 5 cores"<<endl;
    Grafo estrutura;
    vector<No> azuis;
    vector<No> vermelhos;
    vector<No> pretos;
    for(No n:grafo.listaDeVertices){
        if(n.vizinhos->size() >= 3){
             azuis.push_back(n);

            for(int n1 : *n.vizinhos){
                No no1 = grafo.listaDeVertices[n1];//grafo.pegarVertice(n1);

                if(no1.vizinhos->size() == 4 && !estaNaLista(no1, azuis) ){
                   azuis.push_back(no1);

                    for(int n2 : *no1.vizinhos){
                        No no2 = grafo.listaDeVertices[n2];//grafo.pegarVertice(n2);

                        if(no2.vizinhos->size() == 4 && !estaNaLista(no2, azuis)){
                            azuis.push_back(no2);

                            for(int n3 : *no2.vizinhos){
                                No no3 = grafo.listaDeVertices[n3];//grafo.pegarVertice(n3);

                                if(no3.vizinhos->size() >= 3 && !estaNaLista(no3, azuis) && !no3.ehVizinho(n.vertice)  && n3 > n.vertice){
                                    azuis.push_back(no3);
                                    estrutura.listaDeVertices = azuis;
                                    estrutura.ordem = int(azuis.size());

                                     vermelhos = encontrarVermelhos(grafo, azuis);
                                     pretos = encontrarPretos(grafo, azuis, vermelhos);
                                     Grafo  estrutura2;
                                    for(No no : vermelhos){
                                      estrutura.listaDeVertices.push_back(no);
                                    }
                                    for(No no : pretos){
                                        if(!estaNaLista(no, vermelhos)){
                                            estrutura.listaDeVertices.push_back(no);
                                         }
                                   }
                                   estrutura2 =  pintarEstrutura(grafo, estrutura, azuis, vermelhos, pretos);
                                   int x = pintarAzuis(&estrutura2, azuis);
                                    if(x == 1){
                                        return estrutura2;
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
            azuis.pop_back();
        }
    }

    return NULL;
}

int Algoritmos::pintarAzuis(Grafo *estrutura, vector<No> azuis){
    int cont = 0;
   // cout<<azuis.size()<<endl;
    if(vizinhoPintado(azuis[0], 2, *estrutura) && vizinhoPintado(azuis[0], 1, *estrutura) && !vizinhoPintado(azuis[0], 3, *estrutura)){
        pintaVertice(estrutura, azuis[0], 3);
        cont++;
        if(vizinhoPintado(azuis[3], 2, *estrutura) && vizinhoPintado(azuis[3], 1, *estrutura) && !vizinhoPintado(azuis[3], 3, *estrutura)){
            pintaVertice(estrutura, azuis[3], 3);
            cont++;
            if(vizinhoPintado(azuis[2], 2, *estrutura) && vizinhoPintado(azuis[2], 1, *estrutura) && !vizinhoPintado(azuis[2], 4, *estrutura) && vizinhoPintado(azuis[2], 3, *estrutura)){
                pintaVertice(estrutura, azuis[2], 4);
                cont++;
                if(vizinhoPintado(azuis[1], 2, *estrutura) && vizinhoPintado(azuis[1], 1, *estrutura) && !vizinhoPintado(azuis[1], 5, *estrutura) && vizinhoPintado(azuis[1], 3, *estrutura) && vizinhoPintado(azuis[1], 4, *estrutura)){
                    pintaVertice(estrutura, azuis[1], 5);
                    cont++;
                }
             }
         }
    }

    if(cont == 4){
        return 1;
    }
    else{
        return 0;
    }

}

int Algoritmos::vizinhosEmComum(Grafo grafo, vector<No> lista){
        for(No no : lista){
            for(No no1 : lista){
                if(no.vertice != no1.vertice){
                    for(int i : *no1.vizinhos){
                        if(no.ehVizinho(i) && !estaNaLista(grafo.pegarVertice(i), lista)){
                            return i;
                        }
                    }

                }
            }
        }
        return 0;
}

vector<No> Algoritmos::encontrarVermelhos(Grafo grafo, vector<No> azuis){
    vector<No> vermelhos;
    for(No n : azuis){
       for(int v : *n.vizinhos){
           No no = grafo.pegarVertice(v);
           if(/*no.vizinhos->size() >= 2 &&*/ !estaNaLista(no, vermelhos) && !estaNaLista(no, azuis)){
               vermelhos.push_back(no);

           }
//           else if(/*no.vizinhos->size() >= 2 &&*/ estaNaLista(no, vermelhos) && !estaNaLista(no, azuis)){

//           }
        }
    }
//    for(No n : azuis){
//       for(int v : *n.vizinhos){
//           No no = grafo.pegarVertice(v);
//           if(no.vizinhos->size() >= 1 && !estaNaLista(no, vermelhos) && !estaNaLista(no, azuis)){
//               vermelhos.push_back(no);
//               break;
//           }
//        }
//    }
    return vermelhos;
}

vector<No> Algoritmos::encontrarPretos(Grafo grafo, vector<No> azuis, vector<No> vermelhos){
    vector<No> pretos;
    for(No no : vermelhos){
        if(no.vizinhos->size() >= 2){
            for(int v : *no.vizinhos){
               No no1 = grafo.pegarVertice(v);
              if(!estaNaLista(no1, azuis) ){
                if(!estaNaLista(no1, pretos)){
                    pretos.push_back(no1);
//                    break;
                }
                else{
//                    break;
                }
              }
            }
        }
    }

    return pretos;
}

Grafo Algoritmos :: pintarEstrutura(Grafo grafo, Grafo estrutura, vector<No> azuis, vector<No> vermelhos, vector<No> pretos){
    for(No no : vermelhos){
            pintaVertice(&estrutura, no, 1);
            estrutura = pintarVermelhos(grafo, estrutura, azuis, vermelhos);
            estrutura = pintarPretos(grafo, estrutura, azuis, pretos);
        if(estrutura.listaDeVertices.size() <= 0){
            apagarCores(&estrutura);
            pintaVertice(&estrutura, no, 2);
            estrutura = pintarVermelhos(grafo, estrutura, azuis, vermelhos);
            estrutura = pintarPretos(grafo, estrutura, azuis, pretos);
            if(estrutura.listaDeVertices.size() >= 1){
                return estrutura;
            }

        }
        else{
            return estrutura;
        }

    }




    return NULL;
}

Grafo Algoritmos::pintarPretos(Grafo grafo, Grafo estrutura, vector<No> azuis, vector<No> pretos){
    for(No n : pretos){
       if(estrutura.pegarVertice(n.vertice).cor == 0){
            if(!vizinhoPintado(n, 1, estrutura) && vizinhoPintado(n, 2, estrutura)){
                pintaVertice(&estrutura, n, 1);
            }
            else if(!vizinhoPintado(n, 2, estrutura) && vizinhoPintado(n, 1, estrutura)){
                pintaVertice(&estrutura, n, 2);
            }
            else if(vizinhoPintado(n, 2, estrutura) && vizinhoPintado(n, 1, estrutura)){
                for(int i : *n.vizinhos){
                    No no = estrutura.pegarVertice(i);
                    if(no.cor == 2 && !vizinhoPintado(no, 1, estrutura)){
                        pintaVertice(&estrutura, n, -1);
                        return NULL;
                    }
                }
            }
       }
    }
    return estrutura;
}

Grafo Algoritmos::pintarVermelhos(Grafo grafo, Grafo estrutura, vector<No> azuis, vector<No> vermelhos){
    int cont  = 0;
    No no1;
    //vector<No> nVermelhos;
    vector<No> listaVizinho;

    for(No n : azuis){
        listaVizinho = listaVizinhos(n, estrutura, azuis);
        for(int i = 0; i < int(listaVizinho.size()) ; i++){
            no1 = listaVizinho[i];
            if(no1.vizinhos->size() > 1 && estaNaLista(no1, vermelhos) && no1.cor == 0 && !vizinhoPintado(no1, 2, estrutura) && !vizinhoPintado(n, 2, estrutura) && !vizinhosNaLista(grafo, no1, azuis) ){
                pintaVertice(&estrutura, no1, 2);
                cont++;
            }
            else if(estaNaLista(no1, vermelhos) && no1.cor == 0 && !vizinhoPintado(no1, 1, estrutura)){
                pintaVertice(&estrutura, no1, 1);
                cont++;
            }
            if(cont == 2){
                cont = 0;
                break;
            }

        }
        cont = 0;
    }
    return estrutura;

}

void Algoritmos :: pintaVertice(Grafo *grafo, No vertice, int cor){
    for(int i = 0; i < grafo->listaDeVertices.size(); i++){
        if(grafo->listaDeVertices[i].vertice == vertice.vertice){
            grafo->listaDeVertices[i].cor = cor;
            break;
        }
    }
}

bool Algoritmos :: vizinhoPintado(No vertice, int cor, Grafo grafo){
    for(int i : *vertice.vizinhos){
        if(grafo.pegarVertice(i, grafo).cor == cor){
            return true;
        }
    }
    return false;
}

vector<No> Algoritmos :: listaVizinhos(No n, Grafo grafo, vector<No> azuis){
    vector<No> listaVizinho;
    for(int i : *n.vizinhos){
        No no = grafo.pegarVertice(i);
        if(!estaNaLista(no, azuis)){
            listaVizinho.push_back(no);
        }

    }
    return listaVizinho;
}

bool Algoritmos::vizinhosNaLista(Grafo grafo, No n, vector<No> lista){
    for(int i : *n.vizinhos){
        if(!estaNaLista(grafo.listaDeVertices[i], lista)){
            return false;
        }
    }
    return true;
}

vector<No> Algoritmos :: pegarP4(int index, vector<No> p4, Grafo grafo){
    vector<No> p;
    if(p4[index].vizinhos->size() >= 3){
        for(int i : *p4[index].vizinhos){
            No n = grafo.listaDeVertices[i];
            if(!estaNaLista(n, p4) && n.vizinhos->size() >= 3){
                p.push_back(n);
                for(int j : *n.vizinhos){
                    No n2 = grafo.listaDeVertices[j];
                    if(!estaNaLista(n2, p4) && !estaNaLista(n2, p) && n2.vizinhos->size() >= 1){
                        p.push_back(n2);
                          for(int k : *n2.vizinhos){
                              No n3 = grafo.listaDeVertices[k];
                              if(!estaNaLista(n3, p)){
                                  p.push_back(n3);
                                  for(int l : *n.vizinhos){
                                      No n1 = grafo.listaDeVertices[l];
                                      if(!estaNaLista(n1, p) && n1.vertice != p4[index].vertice){
                                          p.push_back(n1);
                                          p[0] = 3;
                                          p[1] = 2;
                                          p[2] = 1;
                                          p[3] = 1;
                                          Grafo g;
                                          g.listaDeVertices = p4;
                                           // cout<<g.toString()<<endl;
                                          for(No no : p){
                                              if(!estaNaLista(no, p4)){
                                                  p4.push_back(no);
                                              }
                                          }

                                          return p4;
                                      }
                                  }
                                  p.pop_back();
                              }
                          }
                          p.pop_back();
                    }
                }
                p.pop_back();
            }
        }
    }
    return p;
}

//Grafo Algoritmos :: encontrarEstrutura4Cores(Grafo grafo){
//    cout<<"Procurando estrutura de 4 cores"<<endl;
//    vector<No> estru;
//    for(No n : grafo.listaDeVertices){
//        if(n.vizinhos->size() >= 3){
//           for(int i : *n.vizinhos){
//               No n2  = grafo.listaDeVertices[i];
//               if(n2.vizinhos->size() >= 3 && n2.vertice > n.vertice){
//                   for(int j : *n.vizinhos){
//                       No n_l = grafo.listaDeVertices[j];
//                       if(n_l.vertice != n2.vertice && n_l.vizinhos->size() >= 2){
//                           for(int k : *n_l.vizinhos){
//                               No n_ll = grafo.listaDeVertices[k];
//                               if(n_ll.vertice != n.vertice){
//                                   for(int l : *n.vizinhos){
//                                       No n_r = grafo.listaDeVertices[l];
//                                       if(n_r.vertice != n2.vertice && n_r.vertice != n_l.vertice){
//                                           for(int m : *n2.vizinhos){
//                                               No n2_l = grafo.listaDeVertices[m];
//                                               if(n2_l.vizinhos->size() >= 2 && n2_l.vertice != n_ll.vertice && n2_l.vertice != n.vertice){
//                                                   for(int o : *n2_l.vizinhos){
//                                                       No n2_ll = grafo.listaDeVertices[o];
//                                                       if(n2_ll.vertice != n2.vertice && n2_ll.vertice != n_l.vertice){
//                                                            for(int p : *n2.vizinhos){
//                                                                No n2_r = grafo.listaDeVertices[p];
//                                                                if(n2_r.vertice != n2_l.vertice && n2_r.vertice != n.vertice){
//                                                                    n.cor = 4;
//                                                                    n_l.cor = 2;
//                                                                    n_ll.cor = 1;
//                                                                    n_r.cor = 1;
//                                                                    n2.cor = 3;
//                                                                    n2_l.cor = 2;
//                                                                    n2_ll.cor = 1;
//                                                                    n2_r.cor = 1;
//                                                                    estru.push_back(n);
//                                                                    estru.push_back(n2);
//                                                                    estru.push_back(n_l);
//                                                                    estru.push_back(n2_l);
//                                                                    if(n_r.vertice == n2_ll.vertice){
//                                                                        estru.push_back(n_r);
//                                                                    }
//                                                                    else{
//                                                                        estru.push_back(n_r);
//                                                                        estru.push_back(n2_ll);
//                                                                    }
//                                                                    if(n2_r.vertice == n_ll.vertice){
//                                                                        estru.push_back(n2_r);
//                                                                    }
//                                                                    else{
//                                                                        estru.push_back(n2_r);
//                                                                        estru.push_back(n_ll);
//                                                                    }

//                                                                    Grafo g;
//                                                                    g.listaDeVertices = estru;
//                                                                    estru.clear();
//                                                                    g.ordem = g.listaDeVertices.size();
//                                                                    return g;
//                                                                }
//                                                            }
//                                                       }
//                                                   }
//                                               }
//                                           }
//                                       }
//                                   }
//                               }
//                           }
//                       }
//                   }
//               }
//           }
//        }
//    }
//   estru.clear();
//    return NULL;
//}

Grafo Algoritmos::encontrarEstrutura4Cores(Grafo grafo){
    cout<<"Procurando estrutura de 4 cores"<<endl;

    No n1, n2, n3, n4, n5, n6;

    for(No v1 : grafo.listaDeVertices){
        if(v1.vizinhos->size() > 0){
            n1 = v1;
            for(int i : *n1.vizinhos){
                n2 = grafo.listaDeVertices[i];
                if(n2.vizinhos->size() > 1){
                    for(int j : *n2.vizinhos){
                        n3 = grafo.listaDeVertices[j];
                        if(n3.vizinhos->size() > 2 && n3.vertice != n1.vertice){
                            for(int k : *n3.vizinhos){
                                n4 = grafo.listaDeVertices[k];
                                if(n4.vizinhos->size() > 2 && n4.vertice != n2.vertice){
                                    for(int l : *n4.vizinhos){
                                        n5 = grafo.listaDeVertices[l];
                                        if(n5.vizinhos->size() > 1 && n5.vertice != n3.vertice && n5.vertice != n1.vertice){
                                            for(int m : *n5.vizinhos){
                                                n6 = grafo.listaDeVertices[m];
                                                if(n6.vertice != n4.vertice && n6.vertice > n1.vertice){
                                                    No n3_a, n4_a;
                                                    for(int n : *n3.vizinhos){
                                                        n3_a = grafo.listaDeVertices[n];
                                                        if(n3_a.vertice != n4.vertice && n3_a.vertice != n2.vertice){
                                                            break;
                                                        }
                                                    }
                                                    for(int n : *n4.vizinhos){
                                                        n4_a = grafo.listaDeVertices[n];
                                                        if(n4_a.vertice != n5.vertice && n4_a.vertice != n3.vertice){
                                                            break;
                                                        }

                                                    }

                                                    n1.cor = 1;
                                                    n2.cor = 2;
                                                    n3.cor = 3;
                                                    n4.cor = 4;
                                                    n5.cor = 2;
                                                    n6.cor = 1;
                                                    n3_a.cor = 1;
                                                    n4_a.cor = 1;
                                                    Grafo estrutura;
                                                    estrutura.listaDeVertices.push_back(n1);
                                                    estrutura.listaDeVertices.push_back(n2);
                                                    estrutura.listaDeVertices.push_back(n3);
                                                    estrutura.listaDeVertices.push_back(n4);
                                                    estrutura.listaDeVertices.push_back(n5);
                                                    estrutura.listaDeVertices.push_back(n6);
                                                    if(n3_a.vertice != n6.vertice){
                                                        estrutura.listaDeVertices.push_back(n3_a);
                                                    }
                                                    if(n4_a.vertice != n1.vertice){
                                                        estrutura.listaDeVertices.push_back(n4_a);
                                                     }
                                                    estrutura.ordem = estrutura.listaDeVertices.size();
                                                    return estrutura;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return NULL;
}

Grafo Algoritmos::encontrarEstrutura3Cores(Grafo grafo){
    cout<<"Procurando estrutura de 3 cores"<<endl;
    vector<No> p4;
    for(No n1 : grafo.listaDeVertices){
        if(n1.vizinhos->size() >= 1){
            n1.cor = 1;
            p4.push_back(n1);
            for(int i : *n1.vizinhos){
                No n2 = grafo.listaDeVertices[i];
                if(n2.vizinhos->size() >= 2 && !estaNaLista(n2, p4)){
                    n2.cor = 3;
                    p4.push_back(n2);
                    for(int j : *n2.vizinhos){
                        No n3 = grafo.listaDeVertices[j];
                        if(n3.vizinhos->size() >= 2 && !estaNaLista(n3, p4)){
                            n3.cor = 2;
                            p4.push_back(n3);
                            for(int k : *n3.vizinhos){
                                No n4 = grafo.listaDeVertices[k];
                                if(n4.vizinhos->size() >= 1 && !estaNaLista(n4, p4) && n4.vertice > n1.vertice && !n4.ehVizinho((n1.vertice))){
                                    n4.cor = 1;
                                    p4.push_back(n4);
                                    Grafo estrutura;
                                    estrutura.listaDeVertices = p4;
                                    estrutura.ordem = estrutura.listaDeVertices.size();
                                    p4.clear();
                                    return estrutura;

                                }
                            }
                            p4.pop_back();

                        }
                    }
                    p4.pop_back();
                }
            }
            p4.pop_back();
        }
    }
    return NULL;
}


int* Algoritmos:: geradorDeOrdem(Grafo estrutura, Grafo grafo){
    vector<No> ordem_vertices;
    int *vetor = new int[grafo.listaDeVertices.size()];
    for(No v : estrutura.listaDeVertices){
        if(v.cor == 1){
           ordem_vertices.push_back(v);
        }
    }
    for(No v : estrutura.listaDeVertices){
        if(v.cor == 2){
           ordem_vertices.push_back(v);
        }
    }
    for(No v : estrutura.listaDeVertices){
        if(v.cor == 3){
           ordem_vertices.push_back(v);
        }
    }
    for(No v : estrutura.listaDeVertices){
        if(v.cor == 4){
           ordem_vertices.push_back(v);
        }
    }
    for(No v : estrutura.listaDeVertices){
        if(v.cor == 5){
           ordem_vertices.push_back(v);
        }
    }
    for(No v : estrutura.listaDeVertices){
        if(v.cor == 0){
           ordem_vertices.push_back(v);
        }
    }

    for(int i = 0; i < grafo.listaDeVertices.size(); i++){
        if(!estaNaLista(grafo.listaDeVertices[i], estrutura.listaDeVertices)){
            ordem_vertices.push_back(grafo.listaDeVertices[i]);
        }
    }

    for(int i = 0; i < grafo.listaDeVertices.size(); i++){
        vetor[i] = ordem_vertices[i].vertice;
    }
    return vetor;
}






































Grafo Algoritmos::encontrarEstruturas(Grafo grafo){
    cout<<"Procurando estruturas"<<endl;
    int b1[] = {0, 1, 2, 2, 1, 0};
    int b2[] = {0, 2, 3, 3, 2, 0};
    int a1;
    a1 = 0;


    int *b = b1;
    No n1, n2, n3, n4, n5, n6;
    int cont  = 0;
    Grafo gadget3;
    Grafo gadget4;
    Grafo gadget5;
    vector<No> listaDeVertices;

    for(No v1 : grafo.listaDeVertices){
        cont = cont+1;
        if(v1.vizinhos->size() > b[0]){
            n1 = v1;
            for(int i : *n1.vizinhos){
                n2 = grafo.listaDeVertices[i];

                if(n1.vizinhos->size()< b[0]){
                    break;
                }

                if(n2.vizinhos->size() > b[1]){
                    for(int j : *n2.vizinhos){
                        n3 = grafo.listaDeVertices[j];

                        if(n1.vizinhos->size()< b[0] || n2.vizinhos->size()< b[1]){
                            break;
                        }

                        //Gadget 3 cores
                        if(n3.vizinhos->size()  > 1){
                            if(a1 == 0){
                                for(int k1 : *n3.vizinhos){
                                    No nx = grafo.listaDeVertices[k1];
                                    if(!(n1.ehVizinho(nx.vertice)) && nx.vertice != n2.vertice){
                                        a1 = 1;
                                        n1.cor = 1;
                                        n2.cor = 3;
                                        n3.cor = 2;
                                        nx.cor = 1;

                                        listaDeVertices.push_back(n1);
                                        listaDeVertices.push_back(n2);
                                        listaDeVertices.push_back(n3);
                                        listaDeVertices.push_back(nx);
                                       // gadget3.listaDeVertices = listaDeVertices;
                                        gadget3.ordem = listaDeVertices.size();

                                        break;
                                    }
                                 }
                           }
                        }

                        if(n3.vizinhos->size() > b[2] && n3.vertice != n1.vertice){
                            for(int k : *n3.vizinhos){
                                n4 = grafo.listaDeVertices[k];
                                if(n1.vizinhos->size()< b[0] || n2.vizinhos->size()< b[1] || n3.vizinhos->size()< b[2]){
                                    break;
                                }
                                if(n4.vizinhos->size() > b[3] && n4.vertice != n2.vertice){
                                    for(int l : *n4.vizinhos){
                                        n5 = grafo.listaDeVertices[l];

                                        if(n1.vizinhos->size()< b[0] || n2.vizinhos->size()< b[1] || n3.vizinhos->size()< b[2] || n4.vizinhos->size()< b[3]){
                                            break;
                                        }

                                        if(n5.vizinhos->size() > b[4] && n5.vertice != n3.vertice && n5.vertice != n1.vertice){
                                            for(int m : *n5.vizinhos){
                                                n6 = grafo.listaDeVertices[m];


                                                if(n1.vizinhos->size()< b[0] || n2.vizinhos->size()< b[1] || n3.vizinhos->size()< b[2] || n4.vizinhos->size()< b[3] || n5.vizinhos->size()< b[4]){
                                                    break;
                                                }
                                                //Gadget 4 cores

                                                if(n6.vertice != n4.vertice && n6.vertice > n1.vertice){
                                                    if(gadget4.listaDeVertices.size() == 0){
                                                        No n3_a, n4_a;
                                                        for(int n : *n3.vizinhos){
                                                            n3_a = grafo.listaDeVertices[n];
                                                            if(n3_a.vertice != n4.vertice && n3_a.vertice != n2.vertice){
                                                                break;
                                                            }
                                                        }
                                                        for(int n : *n4.vizinhos){
                                                            n4_a = grafo.listaDeVertices[n];
                                                            if(n4_a.vertice != n5.vertice && n4_a.vertice != n3.vertice){
                                                                break;
                                                            }

                                                        }

                                                        n1.cor = 1;
                                                        n2.cor = 2;
                                                        n3.cor = 3;
                                                        n4.cor = 4;
                                                        n5.cor = 2;
                                                        n6.cor = 1;
                                                        n3_a.cor = 1;
                                                        n4_a.cor = 1;
                                                        gadget4.listaDeVertices.push_back(n1);
                                                        gadget4.listaDeVertices.push_back(n2);
                                                        gadget4.listaDeVertices.push_back(n3);
                                                        gadget4.listaDeVertices.push_back(n4);
                                                        gadget4.listaDeVertices.push_back(n5);
                                                        gadget4.listaDeVertices.push_back(n6);

                                                        if(n3_a.vertice != n6.vertice){
                                                            gadget4.listaDeVertices.push_back(n3_a);
                                                        }
                                                        if(n4_a.vertice != n1.vertice){
                                                            gadget4.listaDeVertices.push_back(n4_a);
                                                         }
                                                        gadget4.ordem = gadget4.listaDeVertices.size();
                                                        b = b2;

                                                   }

                                               }


                                                //Gadget 5 cores
                                              if(n2.vertice < n5.vertice){
                                                    vector<No> azuis;
                                                    azuis.push_back(n2);
                                                    azuis.push_back(n3);
                                                    azuis.push_back(n4);
                                                    azuis.push_back(n5);
                                                    Grafo gadget_temp;
                                                    gadget_temp.listaDeVertices = azuis;
                                                    gadget_temp.ordem = int(azuis.size());
                                                    vector<No> vermelhos;

                                                    vector<No> pretos;

                                                    vermelhos = encontrarVermelhos(grafo, azuis);
                                                     pretos = encontrarPretos(grafo, azuis, vermelhos);
                                                     Grafo  estrutura2;
                                                    for(No no : vermelhos){
                                                      gadget_temp.listaDeVertices.push_back(no);
                                                    }
                                                    for(No no : pretos){
                                                        if(!estaNaLista(no, vermelhos)){
                                                            gadget_temp.listaDeVertices.push_back(no);
                                                         }
                                                   }
                                                   gadget5 =  pintarEstrutura(grafo, gadget_temp, azuis, vermelhos, pretos);
                                                   int x = pintarAzuis(&gadget5, azuis);
                                                    if(x == 1){
                                                        cout<<"Gadget de 5 cores"<<endl;
                                                        return gadget5;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(cont >= grafo.listaDeVertices.size()){
            if(!(gadget4.listaDeVertices.empty())){
                cout<<"Gadget de 4 cores"<<endl;
                return gadget4;
            }
            break;
        }
    }
    gadget3.listaDeVertices = listaDeVertices;
    if(!(gadget3.listaDeVertices.size() < 1)){
        cout<<"Gadget de 3 cores"<<endl;
        return gadget3;
    }
    return NULL;
}


bool Algoritmos :: ehVizinho(No n1, No n2, Grafo *grafo){
    for(int i : *n2.vizinhos){
        No n = grafo->listaDeVertices[i];
        if(n.vertice == n1.vertice){
            return true;
        }
    }
    return false;
}
bool Algoritmos :: mesmoVizinho(No n1, No n2, Grafo *grafo){
    for(int i : *n1.vizinhos){
        No v1 = grafo->listaDeVertices[i];
        for(int j : *n2.vizinhos){
            No v2 = grafo->listaDeVertices[j];
            if(v1.vertice == v2.vertice){
                return true;
            }
        }

    }
    return false;
}

Grafo Algoritmos::GRAPHrand1(int N, int M, int A){
    int V = N * M;
    Grafo grafo(V);
    while (grafo.numeroDeArestas < A) {
        No n1, n2;
        n1 = randV(grafo);
        n2 = randV(grafo);

        if(n1.vertice != n2.vertice && n1.vizinhos->size() < 5 && n2.vizinhos->size() < 5 && !n1.ehVizinho(n2.vertice)){
            if(n2.vertice == n1.vertice + 1 && (n2.vertice) % N != 0){
                grafo.adicionarAresta(n1, n2);
            }
            else if(n2.vertice == n1.vertice - 1  && n1.vertice % N != 0){
                grafo.adicionarAresta(n1, n2);
            }
            else if(n2.vertice == n1.vertice + M){
                grafo.adicionarAresta(n1, n2);
            }
            else if(n2.vertice == n1.vertice - M){
                grafo.adicionarAresta(n1, n2);
            }
        }
    }
    return grafo;
}

Grafo Algoritmos :: GRAPHrand2(int N, int M, int P){
    int V  = M * N;
   // double prob = (double) A /(V*(V-1));
    double prob = (double) P / 100.0;
    if(prob < 0 || prob > 1){
       cout<<"valor errado"<<endl;
       return NULL;
    }
    cout<<prob<<endl;
    Grafo grafo(V);

    srand(time(0));
    for(int v = 0; v < grafo.listaDeVertices.size() - 1; ++v){
        for(int w = v+1 ; w < grafo.listaDeVertices.size(); ++w){
            No n1 = grafo.listaDeVertices[v];
            No n2 = grafo.listaDeVertices[w];
            if(n1.vertice != n2.vertice && n1.vizinhos->size() < 5 && n2.vizinhos->size() < 5 && !n1.ehVizinho(n2.vertice)){
                    if(n2.vertice == n1.vertice + 1 && (n2.vertice) % N != 0){
                      //  cout<<rand()<<endl;
                      //  cout<<prob * (RAND_MAX+1.0)<<endl;
                        if(rand() < prob * (RAND_MAX + 1.0)){
                            grafo.adicionarAresta(n1, n2);
                         }
                    }
                    else if(n2.vertice == n1.vertice - 1  && n1.vertice % N != 0){
                       if(rand() < prob * (RAND_MAX + 1.0)){
                            grafo.adicionarAresta(n1, n2);
                        }
                    }
                    else if(n2.vertice == n1.vertice + M){
                        if(rand() < prob * (RAND_MAX + 1.0)){
                            grafo.adicionarAresta(n1, n2);
                         }
                    }
                    else if(n2.vertice == n1.vertice - M){
                        if(rand() < prob * (RAND_MAX + 1.0)){
                            grafo.adicionarAresta(n1, n2);
                         }
                    }
            }

        }
    }
    return grafo;
}






No Algoritmos :: randV(Grafo grafo){
    double r;
    r = rand() / (RAND_MAX + 1.0);
    int i = r * grafo.ordem;
    return grafo.listaDeVertices[i];
}






















Grafo Algoritmos :: encontrarEstruturas1(Grafo g){
    Grafo estrutura = encontrarEstrutura5Cores(g);
    //cout<<estrutura.toString()<<endl;
    if(estrutura.listaDeVertices.size()<= 0){
        cout<<"  Nao existe estrutura de 5 cores"<<endl;
        estrutura.listaDeVertices.clear();
        estrutura = encontrarEstrutura4Cores(g);
        if(estrutura.listaDeVertices.empty()){
            cout<<"  Nao existe estrutura de 4 cores"<<endl;
            estrutura.listaDeVertices.clear();
            estrutura = encontrarEstrutura3Cores(g);
            if(estrutura.listaDeVertices.empty()){
                cout<<"  Nao existe estrutura de 3 cores"<<endl;
            }
            else{
                //cout<<estrutura.toString()<<endl;
                return estrutura;
            }
        }
        else{
           // cout<<estrutura.toString()<<endl;
            return estrutura;
        }
    }
    else{
       // cout<<"funcionou"<<endl;
      // cout<<estrutura.toString()<<endl;
       return estrutura;
    }
    //cout<<grafo.toString();
    //cout<<endl;
    return NULL;
}
