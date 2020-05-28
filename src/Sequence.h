//
// Created by Victor on 25/04/2020.
//

#ifndef ENCRYPTION_3DES_SEQUENCE_H
#define ENCRYPTION_3DES_SEQUENCE_H


#include <list>
#include <deque>
#include <string>

using namespace std;

class Sequence {
private:
    deque<string> sequence;

public:
    explicit Sequence(int tailleSequence = 4);

    explicit Sequence(const list<Sequence> &listeSequences);

    string &operator[](int index);

    string &operator()(int index);

    double size();

    Sequence &operator=(int entier);

    void decalage(int shift);

    Sequence &operator*(const Sequence &seq);
};


#endif //ENCRYPTION_3DES_SEQUENCE_H
