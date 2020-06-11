#include "key_gen.h"
#include "permutation.h"

key_gen::key_gen(const sequence_d<64>& seq_d) {
	permutation<64, 56> permutation;
	round_no_ = 0;
	seq_d56_ = permutation(seq_d, pc1_);
}

sequence_d<48> key_gen::next() {
	const auto bits_to_rotate = ls_[round_no_++];
	seq_d56_.decalage(bits_to_rotate);

	permutation<56, 48> permutation;
	return permutation(seq_d56_, pc2_);
}