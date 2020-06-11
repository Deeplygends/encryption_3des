#ifndef ENCRYPTION_3DES_F_H
#define ENCRYPTION_3DES_F_H
using namespace std;

#include "SequenceD.h"
#include "KeyGen.h"
#include "S_fonction.h"

class f {
public:
	f(const sequence_d<64>&);
	sequence operator()(sequence seq);

private:
	key_gen keygen_;
	s_fonction s_fonction_;
};

#endif // ENCRYPTION_3DES_F_H