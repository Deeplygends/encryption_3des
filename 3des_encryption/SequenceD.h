#pragma once
#ifndef ENCRYPTION_3DES_SEQUENCED_H
#define ENCRYPTION_3DES_SEQUENCED_H

#include <iostream>
#include "Sequence.h"
#include <string>
#include <sstream>
#include <bitset>
#include <cstdlib>
using namespace std;

template<int Size = 4>
class SequenceD : private Sequence {
public:
	SequenceD();

	SequenceD(Sequence seq1, Sequence seq2);

	

	int& operator[](int index);

	const int operator()(int index);

	double size();

	void decalage(int shift);

	SequenceD& operator*(SequenceD<Size>& seq);

	Sequence& right();

	Sequence& left();

	friend ostream& operator<<(ostream&, SequenceD<64>);
	
	friend istream& operator>>(ostream&, SequenceD<64>&);
	
	void affichage();


private:
	Sequence l_;
	Sequence r_;
};

template<int Size>
SequenceD<Size>::SequenceD() {
	l_ = Sequence(Size / 2);
	r_ = Sequence(Size / 2);
}

template<int Size>
SequenceD<Size>::SequenceD(Sequence seq1, Sequence seq2) {
	l_ = seq1;
	r_ = seq2;
}

template<int Size>
int& SequenceD<Size>::operator[](int index) {
	// return modifiable <index>th bit of the sequence
	if (index < Size / 2)
		return l_[index];
	else
		return r_[index-Size/2];
	//TODO: gestion exception
}

template<int Size>
const int SequenceD<Size>::operator()(const int index) {
	// return unmodifiable <index>th bit of the sequence
	if (index < Size / 2)
		return l_(index);
	return r_(index-Size/2);
	//TODO: gestion exception
}

template<int Size>
double SequenceD<Size>::size() {
	return Size;
}

template<int Size>
void SequenceD<Size>::decalage(int shift) {
	// shift <shift> left bits to the right of the Sequence
	l_.decalage(shift);
	r_.decalage(shift);
}

template<int Size>
Sequence& SequenceD<Size>::right() {
	return r_;
}

template<int Size>
Sequence& SequenceD<Size>::left() {
	return l_;
}

template<int Size>
ostream& write(ostream& os, SequenceD<64> seq) 
{
	return os;
}

template<int Size>
SequenceD<Size>& SequenceD<Size>::operator*(SequenceD<Size>& seq) {
	// return XOR on two sequences
	l_ = l_ * seq.left();
	r_ = r_ * seq.right();
	return *this;
}

template<int Size>
ostream& write(ostream& os, SequenceD<Size> seq)
{
	for (int i = 0; i < Size; i++)
	{
		os << seq(i);
		if (i % 7 == 0) os << " ";
	}
	return os;
}

template<int Size>
ostream& operator<<(ostream& os, SequenceD<Size> seq) {
	if (Size != 64)
		return os;
	string s = "";
	for (int i = 0; i < 4; i++) {
		Sequence seq8bits = seq.left().sous_sequence(i * 8, i * 8 + 7);
		string byteString = seq8bits.stringify();
		bitset<8> byte;
		for (int j = 7; j > -1; j--)
			byte[j] = seq8bits(7-j);
		char c = static_cast<char>(byte.to_ulong());
		s += c;
	}
	for (int i = 0; i < 4; i++) {
		Sequence seq8bits = seq.right().sous_sequence(i * 8, i * 8 + 7);
		string byteString = seq8bits.stringify();
		bitset<8> byte;
		for (int j = 7; j > -1; j--)
			byte[j] = seq8bits(7 - j);
		char c = static_cast<char>(byte.to_ulong());
		s += c;
	}

	os << s;
	return os;
}

template<int Size>
istream& operator>>(istream& in, SequenceD<Size> &seq) {
	if (Size != 64)
		return in;
	for (int i = 0; i < 64; i += 8)
	{
		char c;
		in >> c;
		bitset<8> set = bitset<8>(c);
        string array = set.to_string().c_str();
		int j = 0;
		for(char ele : array)
		{
			seq[i + j] = ele - '0';
			j++;
		}
		/*
		cout << "POUR LA LETTRE " << c << " :";
		cout << "index i : "<< i << " " << bitset<8>(c) << " done" << endl;
		*/
	}
	
	return in;
	
}

template<typename T>
void affichage(T seq)
{
    int size = seq.size();
    cout << "Affichage de la séquence : ";
    for(int i=0; i<size; i++){
        cout << seq(i);
    }
    cout << endl;
}
#endif //ENCRYPTION_3DES_SEQUENCED_H