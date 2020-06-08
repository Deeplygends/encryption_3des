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
		cout << "i : " << i;
		cout <<", v[i] : " << v[i];
		cout << ", sizeIn : " << sizeIn;
		seq[i] = v[i] < sizeIn ? seqD(v[i]) : 0;
		cout << ", seq(i) : " << seq(i) << endl;
	}
	return seq;
}