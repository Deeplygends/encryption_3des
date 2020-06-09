#ifndef ENCRYPTION_3DES_SBOX_H
#define ENCRYPTION_3DES_SBOX_H
#include "SequenceD.h"


class Sbox {

private:
	int** matrice;
public:
	Sbox(int** matrice);
	~Sbox();
	Sbox& operator=(const Sbox& sbox);
	SequenceD<> operator()(SequenceD<>);
};


#endif // ENCRYPTION_3DES_SBOX_H