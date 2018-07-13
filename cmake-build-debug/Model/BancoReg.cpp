//
// Created by Alisson on 06/07/2018.
//

#include <iostream>
#include "BancoReg.h"

BancoReg::BancoReg() {
    this->reg= (int *) malloc(sizeof(int) * 31);
    for (int i = 0; i < 32; ++i) {
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
    return this->reg[n];
}

void BancoReg::PrinRegs() {

    for (int i = 0; i < 32; i++) {
        std::cout << "[" << i+1 << "] | " << this->reg[i] << std::endl;

    }
}