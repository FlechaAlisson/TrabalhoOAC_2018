//
// Created by Alisson on 09/07/2018.
//

#ifndef TRABOAC_RAM_H
#define TRABOAC_RAM_H

class RAM {
private:
    int dados[100];
    int codigo[100];
    int qtCodigo;
    int qtDados;
     static RAM* instance;

public:

    static RAM* getInstance();
    void setInstance(RAM* instance);
    int getcodigo(int n);
    RAM(char* nome);
    int getdado(int n);
    void printCodigo();
    void setDadoAt(int n, int valor);
    int getQtCodigo() const;
    void setQtCodigo(int qtCodigo);

    void printDado();
};


#endif //TRABOAC_RAM_H
