#ifndef ENCRYPTION_3DES_PERMUTATION_H
#define ENCRYPTION_3DES_PERMUTATION_H

using namespace std;
#include "SequenceD.h"

template<int SizeIn, int SizeOut>
class permutation {
public:
	SequenceD<SizeOut> operator()(SequenceD<SizeIn>, vector<int>);
};

template<int SizeIn, int SizeOut>
SequenceD<SizeOut> permutation<SizeIn, SizeOut>::operator()(SequenceD<SizeIn> seq_d, vector<int> v) {
	SequenceD<SizeOut> seq = SequenceD<SizeOut>();

	//v[i]-1 if vector contains values starting from 1 instead of 0
	for (auto i = 0; i < SizeOut; i++) {
		seq[i] = v[i] < SizeIn ? seq_d(v[i]) : 0;
	}
	return seq;
}

#endif // ENCRYPTION_3DES_PERMUTATION_H