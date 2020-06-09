#ifndef ENCRYPTION_3DES_F_H
#define ENCRYPTION_3DES_F_H

#include "SequenceD.h"
#include "KeyGen.h"
#include "S_fonction.h"

class F {
public:
	F(SequenceD<64>);
	Sequence operator()(Sequence seq);

private:
	KeyGen keygen_;
	S_fonction s_fonction_;
};

#endif // ENCRYPTION_3DES_F_H