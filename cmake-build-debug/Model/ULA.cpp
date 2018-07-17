//
// Created by Alisson on 13/07/2018.
//

#include "ULA.h"
#include "RAM.h"
#include "BancoReg.h"

ULA* ULA::instance = nullptr;
int ULA::subtrai(int a, int b, int c) {
    return a-b;
}

int ULA::soma() {
    BancoReg* bg  = BancoReg::getinstance();
    bg->setRegat(dst,bg->GetRegat(op1) + bg->GetRegat(op2));
}


ULA *ULA::getInstance() {
    if(instance == nullptr)
        instance = new ULA();
    return instance;
}

void ULA::setOP(int a, int b, int c) {
    op1 = a;
    op2 = b;
    dst = c;

}

ULA::ULA() {

}
