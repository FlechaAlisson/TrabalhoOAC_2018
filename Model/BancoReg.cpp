//
// Created by Alisson on 06/07/2018.
//



#include <iostream>
#include <iomanip>
#include "BancoReg.h"
#include "UnidadeControle.h"

using namespace std;

BancoReg* BancoReg::instace = 0;
BancoReg::BancoReg() {
    this->reg= (int *) malloc(sizeof(int) * 32);
    for (int i = 0; i <= 32; ++i) {
        this->reg[i] = 0;
    }
    PC =0;
}

int BancoReg::getPC() const {
    return PC;
}

void BancoReg::setPC(int PC) {
    UnidadeControle* unidadeControle = UnidadeControle::getInstance();
    if ( (unidadeControle->getBranch() && unidadeControle->getZero()) || unidadeControle->getJump() )
        this->PC = PC;
}


int BancoReg::GetRegat(int n)
{
    return this->reg[n-1];
}

void BancoReg::PrinRegs(int i) {


    std::cout<<"--REG--"<<endl;
    std::cout<<"REG|VAL"<<endl;
    std::cout<<"---+---"<<endl;
    std::cout.fill('0');// formatação
    std::cout <<"PC | "  << setw(2) << i << endl;
    std::cout<<"---+---"<<endl;
    for (int i = 0; i < 32; i++) {
        std::cout  << setw(2) << i+1 << " | " << this->reg[i]<<" " << std::endl;
    }
    std::cout<<"-------"<<endl;

}

BancoReg *BancoReg::getinstance() {
    if(instace == nullptr)
        instace = new BancoReg();
    return instace;
}

void BancoReg::setRegat(int n, int valor) {
    UnidadeControle* unidadeControle = UnidadeControle::getInstance();
    if (unidadeControle->getRegWrite() != 0)
        reg[n-1] = valor;
}

void BancoReg::incrementaPC(int PC) {
    this->PC = PC;

}

