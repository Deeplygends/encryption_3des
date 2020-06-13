#include "des.h"

#include <utility>


#include "f.h"
#include "permutation.h"

des::des(const sequence_d<64>& key)
{
	this->key_ = key;
}

sequence_d<64> des::operator()(sequence_d<64> seq_d)
{
	vector<int> initial_perm{ 58, 50, 42, 34, 26, 18, 10, 2,
							 60, 52, 44, 36, 28, 20, 12, 4,
							 62, 54, 46, 38, 30, 22, 14, 6,
							 64, 56, 48, 40, 32, 24, 16, 8,
							 57, 49, 41, 33, 25, 17, 9, 1,
							 59, 51, 43, 35, 27, 19, 11, 3,
							 61, 53, 45, 37, 29, 21, 13, 5,
							 63, 55, 47, 39, 31, 23, 15, 7 };

	permutation<64, 64> permutation;
	auto round_seq_d = permutation(seq_d, initial_perm);

	// F fonction
	auto f_ = f(key_);

	for (auto i = 0; i < 16; i++)
	{
		// li-1 = round_seq_d.left() && ri-1 = round_seq_d.right()
		auto seq_right = f_(round_seq_d.right());
		auto round_seq = seq_right * round_seq_d.left();
		// round_seq = ri && ri-1 = round_seq_d.right() = li
		//round_seq_d = sequence_d<64>(round_seq.sous_sequence(0, round_seq.size() / 2 - 1), round_seq.sous_sequence(round_seq.size() / 2, round_seq.size() - 1));
		round_seq_d = sequence_d<64>(round_seq_d.right(), round_seq);
	}
	auto swapped_seq_d = sequence_d<64>(round_seq_d.right(), round_seq_d.left());

	vector<int> initial_perm_inv{ 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };
	return permutation(swapped_seq_d, initial_perm_inv);
}