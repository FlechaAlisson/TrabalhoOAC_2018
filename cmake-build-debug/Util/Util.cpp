//
// Created by Alisson on 13/07/2018.
//

using namespace std;

#include <iostream>
#include "Util.h"

int Util::getOPcode(int instrution) {

    unsigned  int  a = (unsigned int)instrution >> 26;

    return (int) a;
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
    aux >>= 21;
    return aux;
}

int Util::getReg2TypeR(int inst) {
    int mask = 983040;
    int aux = inst & mask;
    if (!aux)
        return 0;
    aux>>=16;
    return aux;

}

int Util::getRegDSTTypeR(int inst) {
    int mask = 31744;
    int aux = inst & mask;
    if (!aux)
        return 0;
    aux>>=11;

    return aux;

}

int Util::getRegRSTypeI(int inst) {
    inst<<=6;
    inst>>=27;
    return inst;
}

int Util::getRegRTTypeI(int inst) {
    inst<<=11;
    inst>>=27;
    return inst;
}

int Util::getConstTypeI(int inst) {
    inst <<=26;
    inst>>=26;
    return inst;
}


