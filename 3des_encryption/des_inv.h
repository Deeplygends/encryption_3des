#pragma once
#include "SequenceD.h"

class des_inv
{
public:
	explicit des_inv(sequence_d<64>);
	sequence_d<64> operator()(sequence_d<64> seq_d);
private:
	sequence_d<64> key_;
};