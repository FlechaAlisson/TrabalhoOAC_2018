#include <iostream>
#include "cmake-build-debug/Model/BancoReg.h"
#include "cmake-build-debug/Model/RAM.h"
#include "cmake-build-debug/Model/UnidadeControle.h"
#include "cmake-build-debug/Util/Util.h"

using namespace std;

int main(){
    BancoReg* bd = BancoReg::getinstance();
    printf("%p\n",bd);
    RAM *ram = new RAM("dados.txt");
    UnidadeControle *unidadeControle = new UnidadeControle();
    printf("%d\n",ram->getcodigo(0));
    unidadeControle->DecodificaOP(ram->getcodigo(0));


    return 0;
}