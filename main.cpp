#include <iostream>
#include "Model/BancoReg.h"
#include "Model/RAM.h"
#include "Model/ULA.h"
#include "Model/UnidadeControle.h"
#include "Model/Somador.h"
using namespace std;

int main(){
    BancoReg* bd = BancoReg::getinstance();
    char string[85] = "../Model/dados.txt";
    RAM *ram = new RAM(string);
    ram->setInstance(ram);
    ULA *ula = ULA::getInstance();
    UnidadeControle *unidadeControle = UnidadeControle::getInstance();
    Somador *somador = new Somador();
    while (bd->getPC() <= ram->getQtCodigo()) {

        int pc = bd->getPC();
        int instrucao = ram->getcodigo(bd->getPC());
        bd->incrementaPC(somador->incrementa(bd->getPC()));
        unidadeControle->DecodificaOP(instrucao);
        cout << "Executando: "<<(void*) instrucao << endl;
        bd->PrinRegs(pc);
        ram->printDado();

    }


    return 0;
}