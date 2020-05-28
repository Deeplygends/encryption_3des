//
// Created by Victor on 25/04/2020.
//

#include "Sequence.h"

Sequence::Sequence(int tailleSequence) {
    // random bit sequence generator of size <tailleSequence>
}

Sequence::Sequence(const list<Sequence> &listeSequences) {
    // concatenation of list of sequences
}

string &Sequence::operator[](const int index) {
    // return modifiable "index"th bit of the sequence
}

string &Sequence::operator()(const int index) {
    // return unmodifiable "index"th bit of the sequence
}

double Sequence::size() {
    // return number of bits in sequence
}

void Sequence::operator=(const int entier) {
    // affect binary value of "entier" to Sequence skipping bits in excess
}
