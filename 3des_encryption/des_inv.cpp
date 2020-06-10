#include "des_inv.h"


#include "f_inv.h"
#include "Permutation.h"

des_inv::des_inv(sequence_d<64> key)
{
	this->key_ = key;
}

sequence_d<64> des_inv::operator()(sequence_d<64> seq_d)
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
	sequence_d<64> roundSeqD = permutation(seq_d, initial_perm);

	// F fonction
	f_inv f = f_inv(key_);

	for (int i = 0; i < 16; i++)
	{
		sequence seqRight = f(roundSeqD.right());
		sequence roundSeq = seqRight * roundSeqD.left();
		roundSeqD = sequence_d<64>(roundSeq.sous_sequence(0, roundSeq.size() / 2), roundSeq.sous_sequence(roundSeq.size() / 2 + 1, roundSeq.size()));
	}
	sequence_d<64> swappedSeqD = sequence_d<64>(roundSeqD.right(), roundSeqD.left());

	vector<int> initial_perm_inv{ 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };
	return permutation(swappedSeqD, initial_perm_inv);
}