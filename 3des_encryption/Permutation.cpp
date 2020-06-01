#include "Permutation.h"

template<int sizeIn, int sizeOut>
class Permutation {
	template<int sizeIn, int sizeOut>
	SequenceD Permutation::operator()(SequenceD<Size> seqD, vector<int> v) {
		int vectorSize = v.size();
		SequenceD<vectorSize> seq = SequenceD<vectorSize>();
		for (int i = 0; i < seqD.size(); i++) {
			seq[i] = seqD[v.at(i)];
		}
		return seq;
	}
}