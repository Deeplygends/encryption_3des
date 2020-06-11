using namespace std;
#include "s_box.h"
#include "math.h"

s_box::s_box(int** matrice) {
	this->matrice_ = matrice;
}

s_box::~s_box() {
	delete matrice_;
}

s_box::s_box(const s_box& sbox) {
	this->matrice_ = sbox.matrice_;
}

s_box& s_box::operator=(const s_box& sbox) {
	matrice_ = sbox.matrice_;
	return *this;
}

Sequence s_box::operator()(Sequence seq) {
	//TODO : check seq.size() == 6
	Sequence rowSeq = Sequence(2);
	rowSeq[0] = seq(0);
	rowSeq[1] = seq(5);
	int row = 0;
	for (int i = 0; i < rowSeq.size(); i++) {
		row += rowSeq(i) * pow(2, i);
	}

	Sequence colSeq = Sequence(seq.sous_sequence(1, 4));
	int col = 0;
	for (int i = 0; i < colSeq.size(); i++) {
		col += colSeq(i) * pow(2, i);
	}

	int res = matrice_[row][col];
	Sequence resSeq = res;
	return resSeq;
}