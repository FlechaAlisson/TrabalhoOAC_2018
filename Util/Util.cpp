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
    unsigned int a = (unsigned int) inst << 6;
    a>>=27;
    return (int) a;
}

int Util::getReg2TypeR(int inst) {
    unsigned int a = (unsigned int) inst << 11;
    a>>=27;
    return (int) a;

}

int Util::getRegDSTTypeR(int inst) {

    unsigned int a = (unsigned int) inst << 16;
    a>>=27;
    return (int) a;

}

int Util::getRegRSTypeI(int inst) {
    unsigned  int  a = (unsigned int)inst<<6;
    a>>=27;
    return (int) a;
}

int Util::getRegRTTypeI(int inst) {
    unsigned  int  a = (unsigned int) inst<<11;
    a>>=27;
    return (int) a;
}

int Util::getConstTypeI(int inst) {
    if (inst <0) {
        unsigned int a = (unsigned int) inst << 26;
        a >>= 26;
        return (int) a;
    }
    inst<<= 26;
    inst>>=26;
    return  inst;


}

int Util::getConstTypeJ(int inst) {
    if(inst < 0) {
        unsigned int a = (unsigned int) inst << 6;
        a >>= 6;
        return (int) a;
    }
    inst <<= 6;
    inst >>= 6;
    return inst;
}


