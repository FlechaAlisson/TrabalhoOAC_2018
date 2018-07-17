//
// Created by Alisson on 06/07/2018.
//



#include <iostream>
#include "BancoReg.h"
using namespace std;

BancoReg* BancoReg::instace = 0;
BancoReg::BancoReg() {
    this->reg= (int *) malloc(sizeof(int) * 32);
    for (int i = 0; i <= 32; ++i) {
        this->reg[i] = 0;
    }
}

int BancoReg::getPC() const {
    return PC;
}

void BancoReg::setPC(int PC) {
    BancoReg::PC = PC;
}

int BancoReg::GetRegat(int n)
{
    return this->reg[n-1];
}

void BancoReg::PrinRegs() {

    for (int i = 0; i < 32; i++) {
        std::cout << "[" << i+1 << "] | " << this->reg[i] << std::endl;

    }
}

BancoReg *BancoReg::getinstance() {
    if(instace == nullptr)
        instace = new BancoReg();
    return instace;
}

void BancoReg::setRegat(int n, int valor) {
    reg[n-1] = valor;

}
