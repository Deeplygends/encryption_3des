//#include "Permutation.h"
//
//template<int sizeIn, int sizeOut>
//SequenceD<sizeOut>& Permutation<sizeIn, sizeOut>::operator()(SequenceD<sizeIn>& seqD, vector<int> v) {
//	int vSize = v.size();
//	SequenceD<sizeOut> seq1 = SequenceD<sizeOut>();
//	SequenceD<vSize> seq2 = SequenceD<vSize>();
//
//	for (int i = 0; i < vSize; i++) {
//		seq1[i] = seqD[v.at(i)];
//		seq2[i] = seqD[v.at(i)];
//	}
//	if (sizeOut <= vSize) {
//		return seq1;
//	}
//	return seq2;
//}