#include "Sequence.h"
#include <time.h>
#include <iostream>

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

void Sequence::to_string()
{
    cout << "Sequence : ";
    for (int i = 0; i < size(); i++)
        cout << sequence[i];
    cout << endl;
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

void Sequence::decalage(int shift) {
    // shift <shift> left bits to the right of the Sequence
    int tmp;
	while(shift != 0)
	{
        tmp = sequence.front();
        sequence.pop_front();
        sequence.push_back(tmp);
        shift--;
	}
}

Sequence& Sequence::operator*(Sequence& seq) {
    // return XOR on two sequences
    if (size() == seq.size())
    {
        for (int i = 0; i < size(); i++)
            sequence[i] = sequence[i] != seq[i] ? 1 : 0;
    }

    return *this;
}
/*
Sequence Sequence::permutation(const vector<int>& v) {
    // return Sequence created from permutation
}
*/
Sequence Sequence::sous_sequence(int debut, int fin) {
    Sequence sequ = Sequence(fin - debut + 1);
    int position = 0;
	while(debut <= fin)
	{
        sequ[position] = sequence[debut];
        debut++;
        position++;
	}
    return sequ;
}
