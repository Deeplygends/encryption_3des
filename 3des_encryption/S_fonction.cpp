#include "S_fonction.h"

S_fonction::S_fonction(int*** sboxes) {
	this->sboxes = sboxes;
}

S_fonction::~S_fonction() {
	delete sboxes;
}

S_fonction::S_fonction(const S_fonction& s_fonction) {
	this->sboxes = s_fonction.sboxes;
}

S_fonction& S_fonction::operator=(const S_fonction& s_fonction) {
	sboxes = s_fonction.sboxes;
	return *this;
}

Sequence S_fonction::operator()(Sequence seq) {
	list<Sequence> listSeq;
	for (int i = 0; i < 8; i++) {
		Sbox sbox = Sbox(sboxes[i]);
		listSeq.push_back(sbox(seq.sous_sequence(i * 8, i * 8 + 5)));
	}
	return Sequence(listSeq);
}