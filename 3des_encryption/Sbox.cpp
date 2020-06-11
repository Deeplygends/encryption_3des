using namespace std;
#include "Sbox.h"
#include "math.h"

Sbox::Sbox(int** matrice) {
	this->matrice = matrice;
}

Sbox::~Sbox() {
	delete matrice;
}

Sbox::Sbox(const Sbox& sbox) {
	this->matrice = sbox.matrice;
}

Sbox& Sbox::operator=(const Sbox& sbox) {
	matrice = sbox.matrice;
	return *this;
}

Sequence Sbox::operator()(Sequence seq) {
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

	int res = matrice[row][col];
	Sequence resSeq = res;
	return resSeq;
}