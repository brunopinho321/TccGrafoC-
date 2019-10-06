#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>


class No{		
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
};
No::No(){

}
No::No(int vertice){
	this->vertice = vertice;
	this->cor = 0;
	this->vizinhos = new vector<int>();
}

int No::getCor(){
	return this->cor;
}
int No::getVertice(){
	return this->vertice;
}

void No::adicionarVizinho(int vertice){
	this->vizinhos->push_back(vertice);
}
int No::getVizinho(int index){
	int cont = 0;
	vector<int>::iterator i;
	int v;
	for(i = this->vizinhos->begin(); i != this->vizinhos->end(); i++){
		if(cont == index){
			v = *i;
			break;
		}else{
			cont++;
		}
	}
	return v;
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Grafo
{
		
	public:
		int ordem;
		vector<No> listaDeVertices;
		Grafo(int ordem);
		Grafo();
		void adicionarAresta(No v1, No v2);
		void adicionarVertice(No v1);
		No pegarVertice(int v, Grafo grafo);
		string toString();
	private:
		void adicionarVerticeGrafo(int ordem);	
};

No Grafo::pegarVertice(int v, Grafo grafo){
	No no;
	for(No n : grafo.listaDeVertices){
		if(n.vertice == v){
			no = n;
		}
	}
	return no;
}

Grafo::Grafo(int ordem){
	this->ordem = ordem;
	//this->grafo = new list<No>[ordem];
	adicionarVerticeGrafo(ordem);
}
Grafo::Grafo(){
	this->ordem = 0;
}

string Grafo::toString(){
	std :: string c = "[";
	int len = this->listaDeVertices.size();
	for(int i = 0; i < len-1; i++){
		//No n = this->listaDeVertices[i];
		int vertice = this->listaDeVertices[i].getVertice();
		int cor = this->listaDeVertices[i].getCor();
		c = c + "(vertice: "+std::to_string(vertice) +", cor: "+std::to_string(cor)+ "), ";
	}
	int vertice = this->listaDeVertices[len-1].getVertice();
	int cor = this->listaDeVertices[len-1].getCor();
	c = c + "(vertice: "+std::to_string(vertice) +", cor: "+std::to_string(cor)+ ")]";
		
		
	return c;
}
void Grafo::adicionarVerticeGrafo(int ordem){
	
	for(int i = 0; i < ordem; i++){
		No no(i);
		this->listaDeVertices.push_back(no);
	}
	cout<<"criado"<<endl;
}

void Grafo::adicionarAresta(No v1, No v2){
	v1.adicionarVizinho(v2.vertice);
	//v1.vizinhos.push_back(v2.vertice);
	v2.adicionarVizinho(v1.vertice);
	//v2.vizinhos.push_back(v1.vertice);
	cout<<"adcionado" << endl;
}

void Grafo::adicionarVertice(No no){
	listaDeVertices.push_back(no);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Algoritmos{
	public: 
		vector<No> encontrarP4(Grafo grafo);
		int coloracaoGulosa(Grafo* grafo, int *ordem);
		void apagarCores(Grafo* grafo);
		void permutacao(int *vetor, int len);
		Grafo procurarP4(Grafo grafo);
		bool estaNaLista(No no, vector<No> lista);
	private:
		void permutacaoRecusiva(int *vetor, int k, int len);
		//No* getByIndex(int index, vector<No>* lista);
};

bool Algoritmos::estaNaLista(No no, vector<No> lista){
	bool valor = false;
	for(int i = 0; i < lista.size(); i++){
		if(lista[i].vertice == no.vertice){
			valor = true;
		}
	}
	return valor;
}

Grafo Algoritmos::procurarP4(Grafo grafo){
	Grafo g;
		for(No n : grafo.listaDeVertices){
			if(n.vizinhos->size() >= 3 && estaNaLista(n, g.listaDeVertices)){
				g.adicionarVertice(n);
			}
		}
	return g;
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

void Algoritmos::apagarCores(Grafo* grafo){
	int len = grafo->listaDeVertices.size();
	for(int i = 0; i < len; i++){
		grafo->listaDeVertices[i].cor = 0;
	}
}


/*No* Algoritmos::getByIndex(int index, vector<No>* lista){
	No* n;
	vector<No> :: iterator i;
	int cont = 0;
	for(i = lista->begin(); i != lista->end(); i++){
		if(cont == index){
			No n1* = &i;
		}
		else{
			cont++;
		}
	}
	return n;
}*/

int Algoritmos::coloracaoGulosa(Grafo* grafo, int *ordem){
	
	int k = 0;
	int cor;
	int len = grafo->listaDeVertices.size();
	for(int i = 0; i < len; i++){
		No *no = &grafo->listaDeVertices[ordem[i]];
		cor = 1;
		int j = 0;
		int lenVizinhos = no->vizinhos->size();
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

/*vector<No> Algoritmos::encontrarP4(Grafo grafo){
	vector<No>::iterator i;
	for(i = grafo.listaDeVertices.begin(); i != grafo.listaDeVertices.end(); i++){
		
	}
	return i;
}*/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	int n = 4;
	Grafo grafo(n);
	Algoritmos a;
	//vector<No>::iterator ptr;
	//for(ptr = grafo.grafo.begin(); ptr != grafo.grafo.end(); ptr++){
	//}
	grafo.adicionarAresta(grafo.listaDeVertices[0], grafo.listaDeVertices[1]);
	grafo.adicionarAresta(grafo.listaDeVertices[1], grafo.listaDeVertices[2]);
	grafo.adicionarAresta(grafo.listaDeVertices[2], grafo.listaDeVertices[3]);
	
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout <<grafo.listaDeVertices[1].vizinhos->size()<<endl;
	cout <<grafo.listaDeVertices[1].getVizinho(1)<<endl;
	cout << endl;
	cout << a.coloracaoGulosa(&grafo, v)<<endl;
	cout <<grafo.toString()<<endl;
	a.apagarCores(&grafo);
	cout <<grafo.toString()<<endl;
	a.permutacao(v, (int)sizeof(v)/sizeof(int));
	return 0; 
}
