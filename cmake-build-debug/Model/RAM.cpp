
#include <cstdio>
#include <iostream>
#include <fstream>
#include "RAM.h"

using namespace std;
RAM* RAM::instance = 0;
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
    for (int j = n+1; j < 100; ++j) {
        this->codigo[j]= 0;
    }
}

int RAM::getQtCodigo() const {
    return qtCodigo;
}

void RAM::setQtCodigo(int qtCodigo) {
    RAM::qtCodigo = qtCodigo;
}

void RAM::printCodigo() {

    for (int i = 0; i < 100; ++i) {
        cout << "[" << i << "] " << this->codigo[i] << endl;
    }
}

int RAM::getcodigo(int n)  {
    return codigo[n];
}

int RAM::getdado(int n) {
    return dados[n-1];
}

RAM *RAM::getInstance() {
    return instance;
}

void RAM::setInstance(RAM *ins) {
    instance = ins;

}

void RAM::setDadoAt(int n, int valor) {
    dados[n] = valor;
}
