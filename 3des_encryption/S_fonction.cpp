#include "S_fonction.h"

s_fonction::s_fonction(int*** sboxes) {
	this->sboxes_ = sboxes;
}

s_fonction::~s_fonction() {
	delete sboxes_;
}

s_fonction::s_fonction(const s_fonction& s_fonction) {
	this->sboxes_ = s_fonction.sboxes_;
}

s_fonction& s_fonction::operator=(const s_fonction& s_fonction) {
	sboxes_ = s_fonction.sboxes_;
	return *this;
}

Sequence s_fonction::operator()(Sequence seq) {
	list<Sequence> listSeq;
	for (int i = 0; i < 8; i++) {
		Sbox sbox = Sbox(sboxes_[i]);
		listSeq.push_back(sbox(seq.sous_sequence(i * 8, i * 8 + 5)));
	}
	return Sequence(listSeq);
}