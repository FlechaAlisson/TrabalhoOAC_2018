//
// Created by Alisson on 09/07/2018.
//

#ifndef TRABOAC_RAM_H
#define TRABOAC_RAM_H


class RAM {
private:
    int dados[100];
    int codigo[100];


public:
    RAM(char* Nome);
    void printCodigo();
};


#endif //TRABOAC_RAM_H