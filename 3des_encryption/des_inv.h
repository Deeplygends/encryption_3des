#pragma once
#include "sequence_d.h"

class des_inv
{
public:
	des_inv(const sequence_d<64>&);
	sequence_d<64> operator()(sequence_d<64> seq_d);
private:
	sequence_d<64> key_;
};