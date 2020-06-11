#pragma once
#include "SequenceD.h"

class des_inv
{
public:
	des_inv(const sequence_d<64>&);
	sequence_d<64> operator()(sequence_d<64> seq_d) const;
private:
	sequence_d<64> key_;
};