#pragma once
#include "SequenceD.h"

class des
{
public:
	explicit des(sequence_d<64> key);
	sequence_d<64> operator()(sequence_d<64> seq_d);

private:
	sequence_d<64> key_;
};