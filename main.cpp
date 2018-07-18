#include <iostream>
#include "cmake-build-debug/Model/BancoReg.h"
#include "cmake-build-debug/Model/RAM.h"
#include "cmake-build-debug/Model/UnidadeControle.h"
#include "cmake-build-debug/Util/Util.h"
#include "cmake-build-debug/Model/ULA.h"

using namespace std;

int main(){
    BancoReg* bd = BancoReg::getinstance();
    RAM *ram = new RAM("dados.txt");
    ULA *ula = ULA::getInstance();
    UnidadeControle *unidadeControle = new UnidadeControle();
    unidadeControle->DecodificaOP(ram->getcodigo(0));
    ula->executa();
    bd->PrinRegs();


    return 0;
}