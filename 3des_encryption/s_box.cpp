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

s_box& s_box::operator=(s_box& sbox) = default;

sequence s_box::operator()(sequence seq)
{
	//TODO : check seq.size() == 6
	auto row_seq = sequence(2);
	row_seq[0] = seq(0);
	row_seq[1] = seq(5);
	auto row = 0;
	int rowsize = row_seq.size();
	
	for (auto i = rowsize; i >=0 ; i--) {
		row += row_seq(i) * pow(2, row_seq.size()-i);
	}
	cout << "row : " << row << endl;
	auto col_seq = sequence(seq.sous_sequence(1, 4));
	int colsize = col_seq.size();
	auto col = 0;
	for (auto i = colsize; i >= 0; i--) {
		col += col_seq(i) * pow(2, col_seq.size()- i);
	}
	cout << "col : " << col << endl;

	auto res = matrice_[row][col];
	sequence res_seq = res;
	return res_seq;
}
