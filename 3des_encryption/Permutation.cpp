#include "Permutation.h"

template<int sizeIn, int sizeOut>
SequenceD<sizeOut>& Permutation<sizeIn, sizeOut>::operator()(SequenceD<sizeIn>& seqD, vector<int> v) {
	if (sizeOut <= sizeV) {
		SequenceD<sizeOut> seq = SequenceD<sizeOut>();
	}
	else {
		SequenceD<sizeV> seq = SequenceD<sizeV>();
	}
	for (int i = 0; i < sizeV; i++) {
		seq[i] = seqD[v.at(i)];
	}
	return seq;
}