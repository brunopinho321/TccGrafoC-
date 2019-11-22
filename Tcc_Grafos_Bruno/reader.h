#ifndef READER_H
#define READER_H
#include<iostream>
#include<fstream>
#include<string>
#include "grafo.h"
using namespace std;


class Reader
{
public:
    Reader();
    Grafo leitor();
private:
    string separarString(string frase, char inicio, char fim);
};
#endif // READER_H
