#pragma once
#include "SequenceD.h"

class des
{
public:
	des(SequenceD<64> key);
	SequenceD<64> operator()(SequenceD<64> seq_d);

private:
	SequenceD<64> key_;
};