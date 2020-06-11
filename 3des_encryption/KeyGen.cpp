#include "KeyGen.h"
#include "Permutation.h"

KeyGen::KeyGen(SequenceD<64> seqD) {
	Permutation<64, 56> permutation;
	roundNo = 0;
	seqD56 = permutation(seqD, PC1);
}

SequenceD<48> KeyGen::next() {
	int bitsToRotate = LS[roundNo++];
	seqD56.decalage(bitsToRotate);

	Permutation<56, 48> permutation;
	return permutation(seqD56, PC2);
}