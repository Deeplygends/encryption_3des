#ifndef ENCRYPTION_3DES_SBOX_H
#define ENCRYPTION_3DES_SBOX_H
#include "SequenceD.h"


class sbox {
public:
	explicit sbox(int** matrice);
	~sbox();
	sbox(const sbox& sbox);
	sbox& operator=(const sbox& sbox);
	sequence operator()(sequence);

private:
	int** matrice_;
};

#endif // ENCRYPTION_3DES_SBOX_H