#pragma once
#include "SequenceD.h"

class Decrypt
{
public:
	Decrypt(SequenceD<64> k1, SequenceD<64> k2);
	void operator()(string fileIn, string fileOut);

private:
	SequenceD<64> k1;
	SequenceD<64> k2;
};