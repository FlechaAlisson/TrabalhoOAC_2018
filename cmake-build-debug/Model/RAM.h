//
// Created by Alisson on 09/07/2018.
//

#ifndef TRABOAC_RAM_H
#define TRABOAC_RAM_H
using namespace std;


class RAM {
private:
    int dados[100];
    int codigo[100];
    int qtCodigo;
    int qtDados;

public:
    RAM(char* nome);
    void printCodigo();
};


#endif //TRABOAC_RAM_H
