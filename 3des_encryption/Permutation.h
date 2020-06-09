#ifndef ENCRYPTION_3DES_PERMUTATION_H
#define ENCRYPTION_3DES_PERMUTATION_H

using namespace std;
#include "SequenceD.h"

template<int sizeIn, int sizeOut>
class Permutation {
public:
	SequenceD<sizeOut> operator()(SequenceD<sizeIn>, vector<int>);
};

template<int sizeIn, int sizeOut>
SequenceD<sizeOut> Permutation<sizeIn, sizeOut>::operator()(SequenceD<sizeIn> seqD, vector<int> v) {
	SequenceD<sizeOut> seq = SequenceD<sizeOut>();
	for (int i = 0; i < sizeOut; i++) {
		seq[i] = v[i] < sizeIn ? seqD(v[i]) : 0;
	}
	return seq;
}

#endif // ENCRYPTION_3DES_PERMUTATION_H