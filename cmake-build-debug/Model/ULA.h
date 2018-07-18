//
// Created by Alisson on 13/07/2018.
//

#ifndef TRABOAC_ULA_H
#define TRABOAC_ULA_H


class ULA {
private:
    static ULA* instance;
    ULA();
    int op1;
    int op2;
    int dst;
    int aluop;
    int alucontrol;
public:
    static ULA* getInstance();
    void setOP(int a , int b, int c, int aluop);
    int soma();
    int subtrai();
    void executa();

    void logicAnd();

    void logicOr();
};


#endif //TRABOAC_ULA_H
