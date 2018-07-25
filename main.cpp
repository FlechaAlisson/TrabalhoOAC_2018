#include <iostream>
#include "cmake-build-debug/Model/BancoReg.h"
#include "cmake-build-debug/Model/RAM.h"
#include "cmake-build-debug/Model/UnidadeControle.h"
#include "cmake-build-debug/Util/Util.h"
#include "cmake-build-debug/Model/ULA.h"
#include "cmake-build-debug/Model/Somador.h"

using namespace std;

int main(){
    BancoReg* bd = BancoReg::getinstance();
    RAM *ram = new RAM("dados.txt");
    ram->setInstance(ram);
    ULA *ula = ULA::getInstance();
    UnidadeControle *unidadeControle = new UnidadeControle();
    Somador *somador = new Somador();
    while (bd->getPC() < ram->getQtCodigo()) {

        unidadeControle->DecodificaOP(ram->getcodigo(bd->getPC()));
        ula->executa();
        bd->PrinRegs();
        bd->setPC(somador->incrementa(bd->getPC()));//todo mudar para ser o primeira coisa
    }

    return 0;
}