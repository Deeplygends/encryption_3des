using namespace std;
#include "Sbox.h"

Sbox::Sbox(int** matrice) {
	this->matrice = matrice;
}

Sbox::~Sbox() {
	delete matrice;
}

Sbox::Sbox(const Sbox& sbox) {
	matrice = sbox.matrice;
}

Sbox& Sbox::operator=(const Sbox& sbox) {
	//Forme canonique ??
}

SequenceD<> Sbox::operator()(SequenceD<>) {

}