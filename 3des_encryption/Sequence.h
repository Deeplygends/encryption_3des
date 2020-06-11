#ifndef ENCRYPTION_3DES_SEQUENCE_H
#define ENCRYPTION_3DES_SEQUENCE_H


#include <list>
#include <deque>
#include <vector>
#include <string>

using namespace std;

class Sequence {
private:
	deque<int> sequence_;

public:
	Sequence(int tailleSequence = 4);

	Sequence(list<Sequence>& listeSequences);

	int& operator[](int index);

	const int operator()(int index);

	double size();

	Sequence& operator=(int& entier);

	void decalage(int shift);

	string stringify();

	Sequence& operator*(Sequence& seq);

	Sequence permutation(vector<int>& v);

	Sequence sous_sequence(int debut, int fin);
};


#endif // ENCRYPTION_3DES_SEQUENCE_H