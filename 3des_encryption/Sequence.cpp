#include "Sequence.h"
#include <time.h>
#include <iostream>

Sequence::Sequence(int tailleSequence) {
	srand(time(NULL) * clock());
	for (int i = 0; i < tailleSequence; i++)
		sequence_.push_back(rand() % 2);
	// random bit sequence generator of size <tailleSequence>
}

Sequence::Sequence(list<Sequence>& listeSequences) {

	for (Sequence& seq : listeSequences)
	{
		for (int i = 0; i < seq.size(); i++)
		{
			sequence_.push_back(seq[i]);
		}
	}
}

string Sequence::stringify()
{
	string s = "";
	for (int i = 0; i < size(); i++)
		s += sequence_[i] + '0';

	cout << s << endl;
	return s;
}

int& Sequence::operator[](int index) {
	// return modifiable <index>th bit of the sequence
	return sequence_[index];
}

const int Sequence::operator()(const int index) {
	// return unmodifiable <index>th bit of the sequence
	return sequence_.at(index);
}

double Sequence::size() {
	return sequence_.size();
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
		sequence_[position] = binary.front();
		binary.pop_front();
		position++;
	}

	return *this;
}

void Sequence::decalage(int shift) {
	// shift <shift> left bits to the right of the Sequence
	int tmp;
	while (shift != 0)
	{
		tmp = sequence_.front();
		sequence_.pop_front();
		sequence_.push_back(tmp);
		shift--;
	}
}

Sequence& Sequence::operator*(Sequence& seq) {
	// return XOR on two sequences
	if (size() == seq.size())
	{
		for (int i = 0; i < size(); i++)
			sequence_[i] = sequence_[i] != seq[i] ? 1 : 0;
	}

	return *this;
}

Sequence Sequence::permutation(vector<int>& v) {
	// return Sequence created from permutation
	Sequence sequ = Sequence(size());
	for (int i = 0; i < size(); i++)
	{
		sequ[i] = sequence_[v[i] - 1];
	}
	return sequ;
}

Sequence Sequence::sous_sequence(int debut, int fin) {
	Sequence sequ = Sequence(fin - debut + 1);
	if (debut < 0 || fin >= size())
		return sequ;
	int position = 0;
	while (debut <= fin)
	{
		sequ[position] = sequence_[debut];
		debut++;
		position++;
	}
	return sequ;
}
