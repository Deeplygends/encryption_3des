#include "s_fonction.h"

s_fonction::s_fonction(int*** sboxes) {
	this->s_boxes_ = new int** [8];

	// Allocate an array for each element of the first array
	for (auto x = 0; x < 8; ++x)
	{
		this->s_boxes_[x] = new int* [4];

		// Allocate an array of integers for each element of this array
		for (auto y = 0; y < 4; ++y)
		{
			this->s_boxes_[x][y] = new int[16];

			// Specify an specific value
			for (auto z = 0; z < 16; ++z)
			{
				this->s_boxes_[x][y][z] = sboxes[x][y][z];
			}
		}
	}
}

//s_fonction::~s_fonction() {
//	delete s_boxes_;
//}

s_fonction::s_fonction(const s_fonction& s_fonction) {
	this->s_boxes_ = s_fonction.s_boxes_;
}

s_fonction& s_fonction::operator=(const s_fonction& s_fonction) = default;

sequence s_fonction::operator()(sequence seq) const
{
	list<sequence> list_seq;
	for (auto i = 0; i < 8; i++) {
		auto sbox = s_box(s_boxes_[i]);
		sequence sous_sequence = seq.sous_sequence(i * 6, i * 6 + 5);
		list_seq.push_back(sbox(sous_sequence));
	}
	return sequence(list_seq);
}
