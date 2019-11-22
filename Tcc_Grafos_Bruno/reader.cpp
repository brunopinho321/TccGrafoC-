#include "reader.h"
using namespace std;
Reader::Reader(){

}

Grafo Reader::leitor(){
    string linha;
    ifstream file;
    file.open("grafo1.txt");
    Grafo grafo;
    if(file.is_open()){
        getline(file, linha);
        cout<<"Quantidade de vertices: ";
        cout<<linha<<endl;
        cout<<"lendo arquivo"<<endl;
        Grafo g(atoi(linha.c_str()));
        while (!file.eof()) {
            getline(file, linha);
            if(linha == ""){
                break;
            }
            string v1 = separarString(linha,'[', ',');
            string v2 = separarString(linha, ',', ']');
           int x = int(atoi(v1.c_str()));
           int y = int(atoi(v2.c_str()));
           g.adicionarAresta(g.listaDeVertices[x], g.listaDeVertices[y]);

        }
        file.close();
        grafo = g;
    }else{
        return NULL;
        cout<<"erro"<<endl;
    }

    return grafo;

}



string Reader::separarString(string frase, char inicio, char fim){
    string saida = "";
    int cont = 0;
    while(frase[cont] != inicio){
        cont++;
    }
    for(int i = cont; i<frase.length(); i++){
        if(frase[i] != inicio && frase[i] != fim && frase[i] != ' '){
            saida = saida+frase[i];
        }
        if(frase[i] == fim){
            break;
        }
    }
    return saida;
}
