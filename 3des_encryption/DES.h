#pragma once
#include "SequenceD.h"

class DES
{
public:
	DES(SequenceD<64> key);
	SequenceD<64> operator()(SequenceD<64> seqD);

private:
	SequenceD<64> key;
};