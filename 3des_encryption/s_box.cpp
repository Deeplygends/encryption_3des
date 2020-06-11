#include "s_box.h"

s_box::s_box(int** matrice) {
	this->matrice_ = matrice;
}

s_box::~s_box() {
	delete matrice_;
}

s_box::s_box(const s_box& sbox) {
	this->matrice_ = sbox.matrice_;
}

s_box& s_box::operator=(const s_box& sbox) = default;

sequence s_box::operator()(sequence seq) const
{
	//TODO : check seq.size() == 6
	auto row_seq = sequence(2);
	row_seq[0] = seq(0);
	row_seq[1] = seq(5);
	auto row = 0;
	for (auto i = 0; i < row_seq.size(); i++) {
		row += row_seq(i) * pow(2, i);
	}

	auto col_seq = sequence(seq.sous_sequence(1, 4));
	auto col = 0;
	for (auto i = 0; i < col_seq.size(); i++) {
		col += col_seq(i) * pow(2, i);
	}

	const auto res = matrice_[row][col];
	sequence res_seq = res;
	return res_seq;
}
