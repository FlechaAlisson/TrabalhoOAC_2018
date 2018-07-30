#include <iostream>
#include "Model/BancoReg.h"
#include "Model/RAM.h"
#include "Model/ULA.h"
#include "Model/UnidadeControle.h"
#include "Model/Somador.h"
using namespace std;

int main(){
    BancoReg* bd = BancoReg::getinstance();
    char string[85] = "C:/Users/Alisspn/Desktop/traboac/TrabalhoOAC_2018/Model/dados.txt";
    RAM *ram = new RAM(string);
    ram->setInstance(ram);
    ULA *ula = ULA::getInstance();
    UnidadeControle *unidadeControle = new UnidadeControle();
    Somador *somador = new Somador();
    while (bd->getPC() <= ram->getQtCodigo()) {

        int pc = bd->getPC();
        int instrucao = ram->getcodigo(bd->getPC());
        bd->setPC(somador->incrementa(bd->getPC()));
        unidadeControle->DecodificaOP(instrucao);
        ula->executa();
        cout << "Executando: "<<(void*) instrucao << endl;
        bd->PrinRegs(pc);
    }


    return 0;
}