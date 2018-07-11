
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
        for (int i = 0; i <= 31; ++i) {
            a <<= 1;
            int mask = line.at(i) - '0';
            a = mask | a;
        }
        this->codigo[n]= a;
        n++;
    }
}

void RAM::printCodigo() {

    //TODO por algum motivo da tando erro nessa parte na hora do print
    for (int i = 0; i < 100; ++i) {
        cout << "[" << i << "] " << this->codigo[i] << endl;
    }
}