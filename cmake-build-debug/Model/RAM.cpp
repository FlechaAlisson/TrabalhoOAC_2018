
#include <cstdio>
#include <iostream>
#include <fstream>
#include "RAM.h"

using namespace std;
#define TAM 33

RAM::RAM(char* nome)
{
    string line;
    ifstream file (nome);
    if(!file.is_open())
    {
        cout << "Erro na abertura do arquivo" << endl;
        return;
    }
    int n = 0;
    while (getline(file,line))
    {
        //transformar a string em um inteiro
        int a = 0;
        for (int i = 0; i < 32; ++i) {

            a <<= 1;
            int mask = line.at(i) - '0';
            a = mask | a;
        //    cout << "[" << 32 - i << "]" << line.at(i) << endl;
        }


        this->codigo[n]= a;
        n++;
    }
    this->qtCodigo = n;
}

void RAM::printCodigo() {

    for (int i = 0; i < this->qtCodigo; ++i) {
        cout << "[" << i << "] " << this->codigo[i] << endl;
    }
}

int RAM::getcodigo(int n)  {
    return codigo[n];
}

int RAM::getdado(int n) {
    return dados[n];
}
