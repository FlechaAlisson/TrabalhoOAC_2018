#include <iostream>
#include "cmake-build-debug/Model/BancoReg.h"
#include "cmake-build-debug/Model/RAM.h"
#include "cmake-build-debug/Model/UnidadeControle.h"

using namespace std;
int main() {
    RAM *ram = new RAM("dados.txt");
    UnidadeControle* uc = UnidadeControle::getInstance();
    cout<< uc->getAluOp() << endl;
    return 0;
}