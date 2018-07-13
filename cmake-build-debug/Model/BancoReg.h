//
// Created by Alisson on 06/07/2018.
//

#ifndef TRABOAC_BANCOREG_H
#define TRABOAC_BANCOREG_H

#include <stdlib.h>

class BancoReg {
private:
    int *reg;
    int PC = 0;
    BancoReg();
    static BancoReg* instace;
public:
    static BancoReg* getinstance();
    int GetRegat(int n);
    void PrinRegs();
    int getPC() const;
    void setPC(int PC);
};


#endif //TRABOAC_BANCOREG_H
