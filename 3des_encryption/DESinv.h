#pragma once
#include "SequenceD.h"

class DESinv
{
public:
	DESinv(SequenceD<64>);
	SequenceD<64> operator()(SequenceD<64> seqD);
private:
	SequenceD<64> key;
};