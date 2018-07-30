//
// Created by Alisson on 06/07/2018.
//

#ifndef TRABOAC_BANCOREG_H
#define TRABOAC_BANCOREG_H

class BancoReg {
private:
    int *reg;
    int PC = 0;
    BancoReg();
    static BancoReg* instace;
public:
    void setRegat(int n, int valor);
    static BancoReg* getinstance();
    int GetRegat(int n);
    void PrinRegs(int i);
    int getPC() const;
    void setPC(int PC);
    void incrementaPC(int PC);
};


#endif //TRABOAC_BANCOREG_H
