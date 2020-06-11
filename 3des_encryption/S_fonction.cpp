#include "s_fonction.h"

s_fonction::s_fonction(int*** sboxes) {
	this->s_boxes_ = sboxes;
}

s_fonction::~s_fonction() {
	delete s_boxes_;
}

s_fonction::s_fonction(const s_fonction& s_fonction) {
	this->s_boxes_ = s_fonction.s_boxes_;
}

s_fonction& s_fonction::operator=(const s_fonction& s_fonction) = default;

sequence s_fonction::operator()(sequence seq) const
{
	list<sequence> list_seq;
	for (auto i = 0; i < 8; i++) {
		auto sbox = s_box(s_boxes_[i]);
		list_seq.push_back(sbox(seq.sous_sequence(i * 8, i * 8 + 5)));
	}
	return sequence(list_seq);
}
