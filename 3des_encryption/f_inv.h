#pragma once
#include "key_gen.h"
#include "s_fonction.h"

class f_inv
{
public:
	f_inv(const sequence_d<64>&);
	sequence operator()(sequence seq);
	sequence_d<48> keys[16]; //tableau qui stock les 16 clés;
	int key_to_use;
private:
	key_gen keygen_;
	s_fonction s_fonction_ = s_fonction();
};