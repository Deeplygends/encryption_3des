#pragma once
#include "SequenceD.h"

class decrypt
{
public:
	decrypt(SequenceD<64> k1, SequenceD<64> k2);
	void operator()(string file_in, string file_out);

private:
	SequenceD<64> k1_;
	SequenceD<64> k2_;
};