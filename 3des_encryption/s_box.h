#ifndef ENCRYPTION_3DES_SBOX_H
#define ENCRYPTION_3DES_SBOX_H
#include "SequenceD.h"


class s_box {

private:
	int** matrice_;
public:
	s_box(int** matrice);
	~s_box();
	s_box(const s_box& sbox);
	s_box& operator=(const s_box& sbox);
	sequence operator()(sequence) const;
};

#endif // ENCRYPTION_3DES_SBOX_H