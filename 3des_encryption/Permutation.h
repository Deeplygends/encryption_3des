#ifndef ENCRYPTION_3DES_PERMUTATION_H
#define ENCRYPTION_3DES_PERMUTATION_H

using namespace std;
#include "sequence_d.h"

template<int SizeIn, int SizeOut>
class permutation {
public:
	sequence_d<SizeOut> operator()(sequence_d<SizeIn>, vector<int>);
};

template<int SizeIn, int SizeOut>
sequence_d<SizeOut> permutation<SizeIn, SizeOut>::operator()(sequence_d<SizeIn> seq_d, vector<int> v) {
	sequence_d<SizeOut> seq = sequence_d<SizeOut>();

	//v[i]-1 if vector contains values starting from 1 instead of 0
	for (auto i = 0; i < SizeOut; i++) {
		//seq[i] = v[i]-1 < SizeIn ? seq_d(v[i]-1) : 0;
		seq[i] = seq_d(v[i] - 1);
	}
	return seq;
}

#endif // ENCRYPTION_3DES_PERMUTATION_H