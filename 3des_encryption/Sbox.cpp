using namespace std;
#include "Sbox.h"

Sbox::Sbox(int** matrice) {
	this->matrice = matrice;
}

Sbox& Sbox::operator=(const Sbox& sbox) {
	//Forme canonique ??
}

SequenceD<> Sbox::operator()(SequenceD<>) {

}