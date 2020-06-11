#pragma once
#include "sequence_d.h"

class decrypt
{
public:
	decrypt(sequence_d<64> k1, sequence_d<64> k2);
	void operator()(const string& file_in, const string& file_out) const;

private:
	sequence_d<64> k1_;
	sequence_d<64> k2_;
};