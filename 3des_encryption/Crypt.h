#pragma once
#include "SequenceD.h"

class crypt
{
public:
	crypt(sequence_d<64> k1, sequence_d<64> k2);
	void operator()(const string& file_in, const string& file_out) const;

private:
	sequence_d<64> k1_;
	sequence_d<64> k2_;
};