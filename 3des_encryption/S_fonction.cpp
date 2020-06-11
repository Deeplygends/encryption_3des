#include "S_fonction.h"

s_fonction::s_fonction(int*** sboxes) {
	this->s_boxes_ = sboxes;
}

s_fonction::~s_fonction() {
	delete s_boxes_;
}

s_fonction::s_fonction(const s_fonction& s_fonction) {
	this->s_boxes_ = s_fonction.s_boxes_;
}

s_fonction& s_fonction::operator=(const s_fonction& s_fonction) {
	s_boxes_ = s_fonction.s_boxes_;
	return *this;
}

Sequence s_fonction::operator()(Sequence seq) {
	list<Sequence> listSeq;
	for (int i = 0; i < 8; i++) {
		Sbox sbox = Sbox(s_boxes_[i]);
		listSeq.push_back(sbox(seq.sous_sequence(i * 8, i * 8 + 5)));
	}
	return Sequence(listSeq);
}