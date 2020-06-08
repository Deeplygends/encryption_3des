using namespace std;
#include "SequenceD.h"

template<int sizeIn, int sizeOut>
class Permutation {
public:
	SequenceD<sizeOut>& operator()(SequenceD<sizeIn>&, vector<int>);
};

template<int sizeIn, int sizeOut>
SequenceD<sizeOut>& Permutation<sizeIn, sizeOut>::operator()(SequenceD<sizeIn>& seqD, vector<int> v) {
	SequenceD<sizeOut> seq = SequenceD<sizeOut>();
	cout << endl << "sizeOut :" << sizeOut;
	cout << endl << "size seq :" << seq.size();
	cout << endl << "vector size :" << v.size();

	for (int i = 0; i < sizeOut; i++) {
		seq[i] = seqD[v.at(i)];
	}
	return seq;
}