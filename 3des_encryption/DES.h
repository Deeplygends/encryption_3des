#pragma once
#include "sequence_d.h"

class des
{
public:
	des(const sequence_d<64>& key);
	sequence_d<64> operator()(sequence_d<64> seq_d);

private:
	sequence_d<64> key_;
};