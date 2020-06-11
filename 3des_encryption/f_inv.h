#pragma once
#include "KeyGen.h"
#include "S_fonction.h"

class f_inv
{
public:
	f_inv(SequenceD<64>);
	Sequence operator()(Sequence seq);
	SequenceD<48> keys[16]; //tableau qui stock les 16 clés;
	int key_to_use;
private:
	KeyGen keygen_;
	S_fonction s_fonction_;
};