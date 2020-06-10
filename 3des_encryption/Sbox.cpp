using namespace std;
#include "Sbox.h"

sbox::sbox(int** matrice) {
	this->matrice_ = matrice;
}

sbox::~sbox() {
	delete matrice_;
}

sbox::sbox(const sbox& sbox) {
	this->matrice_ = sbox.matrice_;
}

sbox& sbox::operator=(const sbox& sbox) {
	matrice_ = sbox.matrice_;
	return *this;
}

sequence sbox::operator()(sequence seq) {
	//TODO : check seq.size() == 6
	sequence rowSeq = sequence(2);
	rowSeq[0] = seq(0);
	rowSeq[1] = seq(5);
	int row = 0;
	for (int i = 0; i < rowSeq.size(); i++) {
		row += rowSeq(i) * pow(2, i);
	}

	sequence colSeq = sequence(seq.sous_sequence(1, 4));
	int col = 0;
	for (int i = 0; i < colSeq.size(); i++) {
		col += colSeq(i) * pow(2, i);
	}

	auto res = matrice_[row][col];
	sequence resSeq = res;
	return resSeq;
}