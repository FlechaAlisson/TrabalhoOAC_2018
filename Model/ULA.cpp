//
// Created by Alisson on 13/07/2018.
//

#include "ULA.h"
#include "RAM.h"
#include "BancoReg.h"

ULA* ULA::instance = nullptr;


int ULA::soma() {
    BancoReg* bg  = BancoReg::getinstance();
    int result = bg->GetRegat(op1) + bg->GetRegat(op2);
    bg->setRegat(dst,result);
    return result;
}
int ULA::subtrai(){
    BancoReg* bg  = BancoReg::getinstance();
    int result = bg->GetRegat(op1) - bg->GetRegat(op2);
    bg->setRegat(dst,result);
    return result;
}



ULA *ULA::getInstance() {
    if(instance == nullptr)
        instance = new ULA();
    return instance;
}

void ULA::setOP(int a, int b, int c, int aluop) {
    op1 = a;
    op2 = b;
    dst = c;
    this->aluop = aluop;

}

ULA::ULA() {

}

void ULA::executa() {

    switch (aluop) {
        case 010:
            soma();
            break;
        case 110:
            subtrai();
            break;
        case 000:
            logicAnd();
            break;
        case 001:
            logicOr();
            break;

    }


}

void ULA::logicAnd() {
    BancoReg* bg  = BancoReg::getinstance();
    bg->setRegat(dst,bg->GetRegat(op1) & bg->GetRegat(op2));
}

void ULA::logicOr() {
    BancoReg* bg  = BancoReg::getinstance();
    bg->setRegat(dst,bg->GetRegat(op1) | bg->GetRegat(op2));

}

int ULA::offset(int a, int b) {
    op1 = a;
    op2 = b;
    return this->somaofset();
}

int ULA::somaofset() {
    return op1 + op2;
}
