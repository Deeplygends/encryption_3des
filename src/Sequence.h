#ifndef ENCRYPTION_3DES_SEQUENCE_H
#define ENCRYPTION_3DES_SEQUENCE_H


#include <list>
#include <deque>
#include <vector>

using namespace std;

class Sequence {
private:
    deque<unsigned int> sequence;

public:
    explicit Sequence(int tailleSequence = 4);

    explicit Sequence(const list<Sequence> &listeSequences);

    unsigned int &operator[](int index);

    unsigned int &operator()(int index);

    double size();

    Sequence &operator=(int entier);

    void decalage(int shift);

    Sequence &operator*(const Sequence &seq);

    Sequence permutation(const vector<unsigned int> &v);

    Sequence sous_sequence(int debut, int fin);
};


#endif //ENCRYPTION_3DES_SEQUENCE_H
