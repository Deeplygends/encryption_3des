#pragma once
#ifndef ENCRYPTION_3DES_SEQUENCED_H
#define ENCRYPTION_3DES_SEQUENCED_H

#include <iostream>
#include "Sequence.h"
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

template<int Size = 4>
class SequenceD : private Sequence {
public:
	SequenceD();

	SequenceD(Sequence seq1, Sequence seq2);

	void to_string();

	int& operator[](int index);

	const int operator()(int index);

	double size();

	void decalage(int shift);

	SequenceD& operator*(SequenceD<Size>& seq);

	Sequence& right();

	Sequence& left();

	template<int Size>
	friend ostream& operator<<(ostream&, const SequenceD<64>);

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
void SequenceD<Size>::to_string()
{
	cout << "SequenceD : ";
	for (int i = 0; i < Size / 2; i++)
		cout << l_[i];
	cout << " ";
	for (int i = Size / 2; i < Size; i++)
		cout << r_[i - Size / 2];
	cout << endl;
}

template<int Size>
int& SequenceD<Size>::operator[](int index) {
	// return modifiable <index>th bit of the sequence
	if (index < Size / 2)
		return l_[index];
	else
		return r_[index];
	//TODO: gestion exception
}

template<int Size>
const int SequenceD<Size>::operator()(const int index) {
	// return unmodifiable <index>th bit of the sequence
	if (index < Size / 2)
		return l_(index);
	else
		return r_(index);
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
SequenceD<Size>& SequenceD<Size>::operator*(SequenceD<Size>& seq) {
	// return XOR on two sequences
	l_ = l_ * seq.left();
	r_ = r_ * seq.right();
	return *this;
}

template<int Size>
ostream& operator<<(ostream& os, SequenceD<Size> seq) {
	if (Size != 64)
		return os;
	for (int i = 0; i < 4; i++) {
		Sequence seq8bits = seq.left().sous_sequence(i * 8, i * 8 + 7);

		string byteString = seq8bits.into_string();
		stringstream sstream(byteString);
		while (sstream.good()) {
			bitset<8> byte;
			sstream >> byte;
			cout << byte;
			char c = static_cast<char>(byte.to_ulong());
			os << c;
		}


	}
	/*for (int i = 0; i < 4; i++) {
		os << seq.right().sous_sequence(i * 8, i * 8 + 7);
	}*/
	return os;
}

#endif //ENCRYPTION_3DES_SEQUENCED_H