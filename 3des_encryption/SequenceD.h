#pragma once
#ifndef ENCRYPTION_3DES_SEQUENCED_H
#define ENCRYPTION_3DES_SEQUENCED_H

#include "Sequence.h"

template<typename T>
class SequenceD : public Sequence {
public:
    SequenceD();

    SequenceD(Sequence seq1, Sequence seq2);

private:
    Sequence sequence;
};


#endif //ENCRYPTION_3DES_SEQUENCED_H

