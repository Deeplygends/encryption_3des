#ifndef ENCRYPTION_3DES_S_FONCTION_H
#define ENCRYPTION_3DES_S_FONCTION_H

#include "Sequence.h"
#include "Sbox.h"

class S_fonction {
public:
	S_fonction(int*** sboxes);
	S_fonction() = default;
	~S_fonction();
	S_fonction(const S_fonction& s_fonction);
	S_fonction& operator=(const S_fonction& s_fonction);
	Sequence operator()(Sequence seq);

private:
	int*** sboxes;
};

#endif // ENCRYPTION_3DES_S_FONCTION_H