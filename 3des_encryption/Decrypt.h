#pragma once
#include "SequenceD.h"

class decrypt
{
public:
	decrypt(sequence_d<64> k1, sequence_d<64> k2);
	void operator()(string file_in, string file_out);

private:
	sequence_d<64> k1_;
	sequence_d<64> k2_;
};