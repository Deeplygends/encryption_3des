#include "Sequence.h"
#include <time.h>
#include <iostream>

sequence::sequence(int taille_sequence) {
	srand(time(NULL) * clock());
	for (int i = 0; i < taille_sequence; i++)
		sequence_.push_back(rand() % 2);
	// random bit sequence generator of size <tailleSequence>
}

sequence::sequence(list<sequence>& listeSequences) {

	for (sequence& seq : listeSequences)
	{
		for (int i = 0; i < seq.size(); i++)
		{
			sequence_.push_back(seq[i]);
		}
	}
}

string sequence::stringify()
{
	string s = "";
	for (int i = 0; i < size(); i++)
		s += sequence_[i] + '0';

	cout << s << endl;
	return s;
}

int& sequence::operator[](int index) {
	// return modifiable <index>th bit of the sequence
	return sequence_[index];
}

const int sequence::operator()(const int index) {
	// return unmodifiable <index>th bit of the sequence
	return sequence_.at(index);
}

double sequence::size() {
	return sequence_.size();
}

sequence& sequence::operator=(int& entier) {
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

void sequence::decalage(int shift) {
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

sequence& sequence::operator*(sequence& seq) {
	// return XOR on two sequences
	if (size() == seq.size())
	{
		for (int i = 0; i < size(); i++)
			sequence_[i] = sequence_[i] != seq[i] ? 1 : 0;
	}

	return *this;
}

sequence sequence::permutation(vector<int>& v) {
	// return Sequence created from permutation
	sequence sequ = sequence(size());
	for (int i = 0; i < size(); i++)
	{
		//sequ[i] = sequence_[v[i] - 1];
		sequ[i] = v[i]-1 < size() ? sequence_[v[i]-1] : 0;
	}
	return sequ;
}

sequence sequence::sous_sequence(int debut, int fin) {
	sequence sequ = sequence(fin - debut + 1);
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
