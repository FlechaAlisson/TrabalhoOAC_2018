//
// Created by Alisson on 12/07/2018.
//

#include <stdio.h>
#include <iostream>
#include "UnidadeControle.h"
#include "../Util/Util.h"
#include "BancoReg.h"


int UnidadeControle::getRegDst() const {
    return RegDst;
}

void UnidadeControle::setRegDst(int RegDst) {
    UnidadeControle::RegDst = RegDst;
}

int UnidadeControle::getBranch() const {
    return Branch;
}

void UnidadeControle::setBranch(int Branch) {
    UnidadeControle::Branch = Branch;
}


int UnidadeControle::getMemRead() const {
    return MemRead;
}

void UnidadeControle::setMemRead(int MemRead) {
    UnidadeControle::MemRead = MemRead;
}

int UnidadeControle::getMemtoReg() const {
    return MemtoReg;
}

void UnidadeControle::setMemtoReg(int MemtoReg) {
    UnidadeControle::MemtoReg = MemtoReg;
}

int UnidadeControle::getAluOp() const {
    return AluOp;
}

void UnidadeControle::setAluOp(int AluOp) {
    UnidadeControle::AluOp = AluOp;
}

int UnidadeControle::getMemWrite() const {
    return MemWrite;
}

void UnidadeControle::setMemWrite(int MemWrite) {
    UnidadeControle::MemWrite = MemWrite;
}

int UnidadeControle::getAluSrc() const {
    return AluSrc;
}

void UnidadeControle::setAluSrc(int AluSrc) {
    UnidadeControle::AluSrc = AluSrc;
}

int UnidadeControle::getRegWrite() const {
    return RegWrite;
}

void UnidadeControle::setRegWrite(int RegWrite) {
    UnidadeControle::RegWrite = RegWrite;
}

void UnidadeControle::DecodificaOP(int instrution) {
  Util *util = new Util();
  int op = util->getOPcode(instrution);
    std::cout<< op << std::endl;

  switch (op)
    {
        case 0:
            Rtype(instrution);
            break;
        case -1946157056: // 8C00000 -> 100011
            //TODO go to I-type
            break;
        case 134217728: // 08000000 ->  000010
            //TODO go to J-type
            break;
    }

    delete util;

}

void UnidadeControle::Rtype(int inst) {
    Util *util = new Util();

    int func = util->getFunc(inst);

    switch (func)
    {
        case 32:
            BancoReg* bd = BancoReg::getinstance();

           /* int rs = util.getRS(inst);
            int rd = util.getRT(inst);
            int rd = util.getRD(inst);*/
            std::cout<< (void*) bd << std::endl;
           break;

    }


}

