//
// Created by Alisson on 12/07/2018.
//

#include <stdio.h>
#include <iostream>
#include "UnidadeControle.h"
#include "BancoReg.h"
#include "ULA.h"
#include "RAM.h"
#include "../Util/Util.h"

using namespace std;

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

  switch (op)
    {
        case 0:
            Rtype(instrution);
            break;
        case 15: // 8C00000 -> 100011
            ItypeLUI(instrution);
            break;
        case 43:
            ItypeSW(instrution);
            break;
        case 35:
            ItypeLW(instrution);
            break;
        case 4:
            //goto beq
            break;
        case 5:
            //goto bne
            break;
        case 2:
            JtypeJump(instrution);
            break;
        case 134217728: // 08000000 ->  000010
            //TODO go to J-type
            break;
        default:
            cout<<"ERRO: Opcode não valido"<<endl;
            break;
    }

    delete util;

}

void UnidadeControle::Rtype(int inst) {
    Util *util = new Util();

    int func = util->getFunc(inst);

    ULA* ula = ULA::getInstance();
    BancoReg* bd = BancoReg::getinstance();
    int reg1 = util->getReg1TypeR(inst);
    int reg2 = util->getReg2TypeR(inst);
    int dst = util->getRegDSTTypeR(inst);
    switch (func)
    {
        case 32:
            ula->setOP(reg1,reg2,dst,010);
            break;
        case 34:
            ula->setOP(reg1,reg2,dst,110);
            break;
        case 36:
            ula->setOP(reg1,reg2,dst,000);
            break;
        case 37:
            ula->setOP(reg1,reg2,dst,001);
            break;
        case 8:
            bd->setPC(reg1);
            break;

        default:
            cout<<"ERRO: Function nao valida"<<endl;
            break;
    }


}

void UnidadeControle::ItypeLUI(int inst) {
    Util *util = new Util();

    int regrs = util->getRegRSTypeI(inst);

    int constante = util->getConstTypeI(inst);
    BancoReg* bd = BancoReg::getinstance();

    bd->setRegat(regrs,constante);

}

void UnidadeControle::ItypeSW(int inst) {
    Util *util = new Util();
    RAM* ram = RAM::getInstance();
    ULA* ula = ULA::getInstance();
    BancoReg* bg  = BancoReg::getinstance();


    int regrs = util->getRegRSTypeI(inst);
    int regts = util->getRegRTTypeI(inst);
    int constante = util->getConstTypeI(inst);
    int offset = ula->offset(regts,constante);
    bg->setRegat(regrs,ram->getdado(offset));

    delete(util);

}

void UnidadeControle::ItypeLW(int inst) {
    Util *util = new Util();
    RAM* ram = RAM::getInstance();
    ULA* ula = ULA::getInstance();
    BancoReg* bg  = BancoReg::getinstance();


    int regrs = util->getRegRSTypeI(inst);
    int regts = util->getRegRTTypeI(inst);
    int constante = util->getConstTypeI(inst);
    int address = ula->offset(regts,constante);
    ram->setDadoAt(address,bg->GetRegat(regrs));
    delete(util);
}

void UnidadeControle::JtypeJump(int instrution) {
    BancoReg* bg  = BancoReg::getinstance();
    Util *util = new Util();
    int address = util->getConstTypeJ(instrution);

    bg->setPC(address);
}
