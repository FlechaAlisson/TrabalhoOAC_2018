#include <iostream>
#include "cmake-build-debug/Model/BancoReg.h"
#include "cmake-build-debug/Model/RAM.h"

int main() {
    RAM *ram = new RAM("dados.txt");
    ram->printCodigo();
    return 0;
}