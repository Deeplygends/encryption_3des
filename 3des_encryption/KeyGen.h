#include "SequenceD.h"
using namespace std;

class KeyGen {
public:
	KeyGen(SequenceD<64> seq);
	SequenceD<48>& next();
};