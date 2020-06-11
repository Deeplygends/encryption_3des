#pragma once
#include "SequenceD.h"

class des_inv
{
public:
	des_inv(SequenceD<64>);
	SequenceD<64> operator()(SequenceD<64> seq_d);
private:
	SequenceD<64> key_;
};