//
// Created by Alisson on 12/07/2018.
//

#ifndef TRABOAC_UNIDADECONTROLE_H
#define TRABOAC_UNIDADECONTROLE_H


class UnidadeControle {
public:


    int getRegDst() const;

    void setRegDst(int RegDst);

    int getBranch() const;

    void setBranch(int Branch);

    int getMemRead() const;

    void setMemRead(int MemRead);

    int getMemtoReg() const;

    void setMemtoReg(int MemtoReg);

    int getAluOp() const;

    void setAluOp(int AluOp);

    int getMemWrite() const;

    void setMemWrite(int MemWrite);

    int getAluSrc() const;

    void setAluSrc(int AluSrc);

    int getRegWrite() const;
    void setRegWrite(int RegWrite);
    void DecodificaOP(int inst);
    void Rtype(int inst);

private:
    int RegDst = 0;
    int Branch = 0;
    int MemRead = 0;
    int MemtoReg = 0;
    int AluOp = 0;
    int MemWrite = 0;
    int AluSrc = 0;
    int RegWrite = 0;


    void ItypeLUI(int instrution);

    void ItypeSW(int instrution);

    void ItypeLW(int instrution);

    void JtypeJump(int instrution);
};


#endif //TRABOAC_UNIDADECONTROLE_H
