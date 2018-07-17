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
public:
    static ULA* getInstance();
    void setOP(int a , int b, int c);
    int soma();
    int subtrai(int a, int b, int c);


};


#endif //TRABOAC_ULA_H
