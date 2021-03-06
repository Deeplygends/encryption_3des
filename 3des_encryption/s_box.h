#ifndef ENCRYPTION_3DES_SBOX_H
#define ENCRYPTION_3DES_SBOX_H
#include "sequence_d.h"


class s_box {

private:
	int** matrice_;
public:
	s_box(int** matrice);
	~s_box();
	s_box(const s_box& sbox);
	s_box& operator=(s_box& sbox);
	sequence operator()(sequence);
};

#endif // ENCRYPTION_3DES_SBOX_H