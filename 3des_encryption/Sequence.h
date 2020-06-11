#ifndef ENCRYPTION_3DES_SEQUENCE_H
#define ENCRYPTION_3DES_SEQUENCE_H


#include <list>
#include <deque>
#include <vector>
#include <string>

using namespace std;

class sequence {
private:
	deque<int> sequence_;

public:
	sequence(int taille_sequence = 4);

	sequence(list<sequence>& listeSequences);

	int& operator[](int index);

	const int operator()(int index);

	double size();

	sequence& operator=(int& entier);

	void decalage(int shift);

	string stringify();

	sequence& operator*(sequence& seq);

	sequence permutation(vector<int>& v);

	sequence sous_sequence(int debut, int fin);
};

#endif // ENCRYPTION_3DES_SEQUENCE_H