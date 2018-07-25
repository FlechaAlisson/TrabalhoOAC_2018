//
// Created by Alisson on 13/07/2018.
//

#ifndef TRABOAC_UTIL_H
#define TRABOAC_UTIL_H


class Util {
public:
    int getOPcode(int instrution);
    int getFunc(int inst);
    int getReg1TypeR(int inst);
    int getReg2TypeR(int inst);
    int getRegDSTTypeR(int inst);
    int getRegRSTypeI(int inst);
    int getRegRTTypeI(int inst);
    int getConstTypeI(int inst);

    int getConstTypeJ(int i);
};


#endif //TRABOAC_UTIL_H
