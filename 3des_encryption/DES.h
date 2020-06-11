#pragma once
#include "SequenceD.h"

class des
{
public:
	des(const sequence_d<64>& key);
	sequence_d<64> operator()(sequence_d<64> seq_d) const;

private:
	sequence_d<64> key_;
};