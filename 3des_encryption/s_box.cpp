#include "s_box.h"
#include "math.h"

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
	//Récupération en du premier et dernier élément de la séquence
	row_seq[0] = seq(0);
	row_seq[1] = seq(5);
	auto row = 0;
	int rowsize = row_seq.size();

	//Binaire => Entier => Indice de ligne de la SBox
	for (auto i = 0; i < rowsize; i++) {
		row += row_seq(i) * pow(2, rowsize - i - 1);
	}
	//Récupération de la sous séquence centrale pour l'indice colone
	auto col_seq = sequence(seq.sous_sequence(1, 4));
	int colsize = col_seq.size();
	auto col = 0;
	//Bianaire => Entier => Indice de colonne de la SBox
	for (auto i = 0; i < colsize; i++) {
		col += col_seq(i) * pow(2, colsize - i - 1);
	}
	//Récupération du nombre dans la SBox correspondant aux indices trouver ci-dessus
	auto res = matrice_[row][col];
	auto res_seq = sequence();
	res_seq = res;
	return res_seq;
}
