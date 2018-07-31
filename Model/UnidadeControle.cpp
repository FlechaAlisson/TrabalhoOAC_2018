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

UnidadeControle* UnidadeControle::instance = 0;

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

int UnidadeControle::getJump() const {
    return Jump;
}

void UnidadeControle::setJump(int Jump) {
    UnidadeControle::Jump = Jump;
}


void UnidadeControle::DecodificaOP(int instrution) {
    Util *util = new Util();
    int op = util->getOPcode(instrution);

    switch (op)
    {
        case 0:
            RegDst = 1;
            AluSrc = 0;
            MemtoReg = 0;
            RegWrite = 1;
            MemRead = 0;
            MemWrite = 0;
            Branch = 0;
            Jump = 0;
            AluOp = 10;
            Rtype(instrution);

            break;
        case 15: // 8C00000 -> 100011
            RegDst = 0;
            AluSrc = 1;
            MemtoReg = 1;
            RegWrite = 1;
            MemRead = 1;
            MemWrite = 0;
            Branch = 0;
            Jump = 0;
            ItypeLI(instrution);
            break;
        case 43:
            RegDst = 0;
            AluSrc = 1;
            MemtoReg = 1;
            RegWrite = 0;
            MemRead = 0;
            MemWrite = 1;
            Branch = 0;
            Jump = 0;
            AluOp = 00;
            ItypeSW(instrution);
            break;
        case 35:
            RegDst = 0;
            AluSrc = 1;
            MemtoReg = 1;
            RegWrite = 1;
            MemRead = 1;
            MemWrite = 0;
            Branch = 0;
            Jump = 0;
            AluOp = 00;
            ItypeLW(instrution);
            break;
        case 4:
            //goto beq

            RegDst = 0;
            AluSrc = 0;
            MemtoReg = 0;
            RegWrite = 0;
            MemRead = 0;
            MemWrite = 0;
            Branch = 1;
            Jump = 0;
            AluOp = 01;
            ItypeBEQ(instrution);
            break;
        case 5:
            //goto bne
            RegDst = 0;
            AluSrc = 0;
            MemtoReg = 0;
            RegWrite = 0;
            MemRead = 0;
            MemWrite = 0;
            Branch = 1;
            Jump = 0;
            AluOp = 01;
            ItypeBNE(instrution);

            break;
        case 2:
            //todo arrumar essa bagaça pq tem que ir pro somador
            RegDst = 0;
            AluSrc = 0;
            MemtoReg = 0;
            RegWrite = 0;
            MemRead = 0;
            MemWrite = 0;
            Branch = 0;
            Jump = 1;
            JtypeJump(instrution);
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
    int dst;
    if(getRegDst())
        dst = util->getRegDSTTypeR(inst);

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
    ula->executa();

}

void UnidadeControle::ItypeLI(int inst) {
    Util *util = new Util();

    int regrt = util->getRegRTTypeI(inst);

    int constante = util->getConstTypeI(inst);
    BancoReg* bd = BancoReg::getinstance();

    bd->setRegat(regrt,constante);
    delete(util);

}

void UnidadeControle::ItypeLW(int inst) {
    Util *util = new Util();
    RAM* ram = RAM::getInstance();
    ULA* ula = ULA::getInstance();
    BancoReg* bg  = BancoReg::getinstance();


    int regrs = util->getRegRSTypeI(inst);
    int regts;
    if(!getRegDst())
        regts = util->getRegRTTypeI(inst);
    int constante = util->getConstTypeI(inst);
    int address = ula->offset(bg->GetRegat(regrs),constante);
    int value = ram->getdado(address);
    bg->setRegat(regts,value);

    delete(util);

}

void UnidadeControle::ItypeSW(int inst) {
    Util *util = new Util();
    RAM* ram = RAM::getInstance();
    ULA* ula = ULA::getInstance();
    BancoReg* bg  = BancoReg::getinstance();


    int regrs = util->getRegRSTypeI(inst);
    int regts;
    if(!getRegDst())
        regts = util->getRegRTTypeI(inst);
    int constante = util->getConstTypeI(inst);
    int address = ula->offset(bg->GetRegat(regrs),constante);
    UnidadeControle* unidadeControle = UnidadeControle::getInstance();
    if(unidadeControle->getMemtoReg())
    {
        int value = bg->GetRegat(regts);
        ram->setDadoAt(address,value);
    }
    delete(util);
}

void UnidadeControle::JtypeJump(int instrution) {
    BancoReg* bg  = BancoReg::getinstance();
    Util *util = new Util();
    int address = util->getConstTypeJ(instrution);


    bg->setPC(address);
}

UnidadeControle *UnidadeControle::getInstance() {
    if(instance == nullptr)
        instance =  new UnidadeControle();
    return instance;
}

UnidadeControle::UnidadeControle() {

}

int UnidadeControle::getZero() const {
    return Zero;
}

void UnidadeControle::setZero(int Zero) {
    UnidadeControle::Zero = Zero;
}

void UnidadeControle::ItypeBNE(int inst) {
    Util *util = new Util();
    RAM* ram = RAM::getInstance();
    ULA* ula = ULA::getInstance();
    BancoReg* bg  = BancoReg::getinstance();


    int regrs = util->getRegRSTypeI(inst);
    int regts;
    if(!getRegDst())
        regts = util->getRegRTTypeI(inst);
    int constante = util->getConstTypeI(inst);

    ula->setOP(regrs,regts,110);
    ula->executa();
    UnidadeControle* unidadeControle = UnidadeControle::getInstance();

    int pc = bg->getPC();
    if (!unidadeControle->getZero())
        bg->setPC(pc+constante);

    delete(util);

}

void UnidadeControle::ItypeBEQ(int inst) {
    Util *util = new Util();
    RAM* ram = RAM::getInstance();
    ULA* ula = ULA::getInstance();
    BancoReg* bg  = BancoReg::getinstance();


    int regrs = util->getRegRSTypeI(inst);
    int regts;
    if(!getRegDst())
        regts = util->getRegRTTypeI(inst);
    int constante = util->getConstTypeI(inst);

    ula->setOP(regrs,regts,110);
    ula->executa();
    UnidadeControle* unidadeControle = UnidadeControle::getInstance();

    int pc = bg->getPC();
    if (unidadeControle->getZero())
        bg->setPC(pc+constante);

    delete(util);

}

