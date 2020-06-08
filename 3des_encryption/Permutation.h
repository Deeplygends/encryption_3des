using namespace std;
#include "SequenceD.h"

template<int sizeIn, int sizeOut>
class Permutation {
public:
	SequenceD<sizeOut>& operator()(SequenceD<sizeIn>&, vector<int>);
};