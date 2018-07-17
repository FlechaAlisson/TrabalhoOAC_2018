//
// Created by Alisson on 13/07/2018.
//

using namespace std;

#include <iostream>
#include "Util.h"

int Util::getOPcode(int instrution) {
    int mask  =  -67108864;// representa FC000000 ou seja os seis bits de mais alta ordem
    return instrution & mask;
}

int Util::getFunc(int inst) {
    int mask = 63; // representa os bits 6 bits de mais baixa ondem
    return  inst & mask;
}

int Util::getReg1TypeR(int inst) {
    int mask = 0x1f00000;
    int aux = inst & mask;
    if (!aux)
        return 0; // se for 0, sai do loop retornando 0
    aux >>= 20;
    return aux;
}

int Util::getReg2TypeR(int inst) {
    int mask = 983040;
    int aux = inst & mask;
    if (!aux)
        return 0;
    aux>>=15;
    return aux;

}

int Util::getRegDSTTypeR(int inst) {
    int mask = 31744;
    int aux = inst & mask;
    if (!aux)
        return 0;
    aux>>=10;

    return aux;

}


