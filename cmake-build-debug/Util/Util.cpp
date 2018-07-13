//
// Created by Alisson on 13/07/2018.
//

#include "Util.h"

int Util::getOPcode(int instrution) {
    int mask  =  -67108864;// representa FC000000 ou seja os seis bits de mais alta ordem
    return instrution & mask;
}

int Util::getFunc(int inst) {
    int mask = 63; // representa os bits 6 bits de mais baixa ondem
    return  inst & mask;
}
