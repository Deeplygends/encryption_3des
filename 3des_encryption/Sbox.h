//
// Created by Victor on 08/06/2020.
//
#include "SequenceD.h"


class Sbox {

private:
    int** matrice;
public:
    Sbox(int** matrice);
    Sbox operator=(Sbox sbox);
    SequenceD<> operator()(SequenceD<>);
};


#endif //ENCRYPTION_3DES_SBOX_H
