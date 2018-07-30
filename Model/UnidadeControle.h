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
    int getJump() const;
    void setJump(int Jump);
    static UnidadeControle* getInstance();    int getZero() const;

    void setZero(int Zero);
private:
    int RegDst = 0;   //ok
    int Branch = 0;   //ok
    int MemRead = 0;  //ok
    int MemtoReg = 0; //ok
    int AluOp = 0;    //ok
    int MemWrite = 0; //ok
    int AluSrc = 0;   //ok
    int RegWrite = 0; //ok
    int Jump = 0;     //ok
    int Zero = 0;     //ok
    void ItypeSW(int instrution);
    void ItypeLW(int instrution);
    void JtypeJump(int instrution);
    void ItypeLI(int instrution);
    UnidadeControle();
    static UnidadeControle* instance;

    void ItypeBNE(int instrution);

    void ItypeBEQ(int instrution);
};


#endif //TRABOAC_UNIDADECONTROLE_H
