#include "Sequence.h"
#include <time.h>

Sequence::Sequence(int tailleSequence) {
    srand(time(NULL));
    for (int i = 0; i < tailleSequence; i++)
        sequence.push_back(rand() % 2);
    // random bit sequence generator of size <tailleSequence>
}

Sequence::Sequence(list<Sequence>& listeSequences) {
    
	for (Sequence& seq : listeSequences)
    {
        for (int i = 0; i < seq.size(); i++)
        {
            sequence.push_back(seq[i]);
        }
    }
}

int& Sequence::operator[](int index) {
    // return modifiable <index>th bit of the sequence
    return sequence[index];
}

int& Sequence::operator()(const int index) {
    // return unmodifiable <index>th bit of the sequence
    return sequence.at(index);
}

double Sequence::size() {
    return sequence.size();
}

Sequence& Sequence::operator=(int entier) {
    int position = 0;
    deque<int> binary;
    do
    {
        binary.push_front(entier % 2);
        entier /= 2;
    } while (entier != 0);

    while (binary.size() != 0 && position < size())
    {
        sequence[position] = binary.front();
        binary.pop_front();
        position++;
    }

    return *this;
}

void Sequence::decalage(const int shift) {
    // shift <shift> left bits to the right of the Sequence
}

/*Sequence& Sequence::operator*(const Sequence& seq) {
    // return XOR on two sequences
  
}

Sequence Sequence::permutation(const vector<int>& v) {
    // return Sequence created from permutation
}

Sequence Sequence::sous_sequence(int debut, int fin) {
    // return Sequence created as subsequence of Sequence from <debut>th bit to <fin>th bit
}*/
