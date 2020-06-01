#pragma once
#ifndef ENCRYPTION_3DES_SEQUENCE_H
#define ENCRYPTION_3DES_SEQUENCE_H


#include <list>
#include <deque>
#include <vector>

using namespace std;

class Sequence {
private:
    deque<int> sequence;

public:
    Sequence(int tailleSequence = 4);

    Sequence(list<Sequence>& listeSequences);

    int& operator[](int index);

    int& operator()(int index);

    double size();

    Sequence& operator=(int entier);

    void decalage(int shift);

    //Sequence& operator*(const Sequence& seq);

    //Sequence permutation(const vector<int>& v);

    //Sequence sous_sequence(int debut, int fin);
};


#endif //ENCRYPTION_3DES_SEQUENCE_H
