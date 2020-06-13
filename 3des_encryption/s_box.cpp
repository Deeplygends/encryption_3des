#include "s_box.h"

s_box::s_box(int** matrice) {
	this->matrice_ = new int* [4];

	// Allocate an array of integers for each element of this array
	for (auto y = 0; y < 4; y++)
	{
		this->matrice_[y] = new int[16];

		// Specify a specific value
		for (auto z = 0; z < 16; z++)
		{
			int x = matrice[y][z];
			this->matrice_[y][z] = x;
		}
	}
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

	for (auto i = 0; i < rowsize; i++) {
		row += row_seq(i) * pow(2, rowsize - i - 1);
	}
	cout << "row : " << row << endl;
	auto col_seq = sequence(seq.sous_sequence(1, 4));
	int colsize = col_seq.size();
	auto col = 0;
	for (auto i = 0; i < colsize; i++) {
		col += col_seq(i) * pow(2, colsize - i - 1);
	}
	cout << "col : " << col << endl;

	auto res = matrice_[row][col];
	auto cpt = 0, temp_res = matrice_[row][col];
	do
	{
		temp_res /= 2;
		cpt++;
	} while (temp_res != 0);
	sequence res_seq = sequence();
	res_seq = res;
	return res_seq;
}
