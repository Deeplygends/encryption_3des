#ifndef ENCRYPTION_3DES_S_FONCTION_H
#define ENCRYPTION_3DES_S_FONCTION_H

#include "Sequence.h"
#include "s_box.h"

class s_fonction {
public:
	s_fonction(int*** sboxes);
	s_fonction() = default;
	~s_fonction();
	s_fonction(const s_fonction& s_fonction);
	s_fonction& operator=(const s_fonction& s_fonction);
	sequence operator()(sequence seq);

private:
	int*** s_boxes_;
};

#endif // ENCRYPTION_3DES_S_FONCTION_H