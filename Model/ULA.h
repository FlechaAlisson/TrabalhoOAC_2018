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
public:
    static ULA* getInstance();
    void setOP(int a , int b, int c, int aluop);
    void setOP(int a , int b, int c);
    int offset(int a , int b);
    int soma();
    int subtrai();
    void executa();
    int somaofset();

    void logicAnd();

    void logicOr();
};


#endif //TRABOAC_ULA_H
