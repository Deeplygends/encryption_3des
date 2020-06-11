#include "KeyGen.h"
#include "Permutation.h"

key_gen::key_gen(SequenceD<64> seq_d) {
	Permutation<64, 56> permutation;
	round_no_ = 0;
	seq_d56_ = permutation(seq_d, pc1_);
}

SequenceD<48> key_gen::next() {
	int bitsToRotate = ls_[round_no_++];
	seq_d56_.decalage(bitsToRotate);

	Permutation<56, 48> permutation;
	return permutation(seq_d56_, pc2_);
}