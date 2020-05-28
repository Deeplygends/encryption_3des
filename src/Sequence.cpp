//
// Created by Victor on 25/04/2020.
//

#include "Sequence.h"

Sequence::Sequence(int tailleSequence) {
    // random bit sequence generator of size <tailleSequence>
}

Sequence::Sequence(std::list<Sequence> listeSequences) {
    // concatenation of list of sequences
}

string &Sequence::operator[](int index){
    // return modifiable "index"th bit of the sequence
}

string &Sequence::operator()(int index){
    // return unmodifiable "index"th bit of the sequence
}