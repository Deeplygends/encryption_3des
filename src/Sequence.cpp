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
    // return modifiable <index>th bit of the sequence
}

string &Sequence::operator()(const int index) {
    // return unmodifiable <index>th bit of the sequence
}

double Sequence::size() {
    // return number of bits in sequence
}

Sequence & Sequence::operator=(int entier) {
    // affect binary value of <entier> to Sequence skipping bits in excess
}

void Sequence::decalage(const int shift) {
    // shift <shift> left bits to the right of the Sequence
}

Sequence &Sequence::operator*(const Sequence &seq) {
    // return XOR on two sequences
}

Sequence Sequence::permutation(const vector<string>& v) {
    // return Sequence created from permutation
}

Sequence Sequence::sous_sequence(int debut, int fin) {
    // return Sequence created as subsequence of Sequence from <debut>th bit to <fin>th bit
}
