#pragma once
#include "KeyGen.h"
#include "S_fonction.h"

class f_inv
{
public:
	f_inv(sequence_d<64>);
	sequence operator()(sequence seq);
	static sequence_d<48> keys[16]; //tableau qui stock les 16 clés;
	int key_to_use;
private:
	key_gen keygen_;
	s_fonction s_fonction_;
};

