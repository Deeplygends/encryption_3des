#ifndef ENCRYPTION_3DES_SBOX_H
#define ENCRYPTION_3DES_SBOX_H
#include "SequenceD.h"


class Sbox {

private:
	int** matrice;
public:
	Sbox(int** matrice);
	~Sbox();
	Sbox(const Sbox& sbox);
	Sbox& operator=(const Sbox& sbox);
	Sequence operator()(Sequence);
};


#endif // ENCRYPTION_3DES_SBOX_H