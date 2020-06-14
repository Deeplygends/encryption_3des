#ifndef ENCRYPTION_3DES_SEQUENCED_H
#define ENCRYPTION_3DES_SEQUENCED_H

#include <iostream>
#include "sequence.h"
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

/*
 * INFORMATION : Le contenu des fonctions a été spécifié dans le .h à
 * cause de multiple erreurs différentes entre les différents auteurs du projet
*/

template<int Size = 4>
class sequence_d : private sequence {
public:
	sequence_d();

	sequence_d(sequence seq1, sequence seq2);

	int& operator[](int index);

	const int operator()(int index);

	double size();

	void decalage(int shift);

	sequence_d& operator*(sequence_d<Size>& seq);

	sequence& right();

	sequence& left();

	void import_string(string line);

	template<int>
	friend ostream& operator<<(ostream&, sequence_d<64>);

	template<int>
	friend istream& operator>>(istream&, sequence_d<64>&);

	void affichage();

private:
	sequence l_;
	sequence r_;
};


/*
 * Input : Constructeur par défaut de sequence_d
 */
template<int Size>
sequence_d<Size>::sequence_d() {
	l_ = sequence(Size / 2);
	r_ = sequence(Size / 2);
}

/*
 * Constructeur prenant en paramètre deux séquences qui seront affectés à l_ et r_
 */
template<int Size>
sequence_d<Size>::sequence_d(const sequence seq1, const sequence seq2) {
	l_ = seq1;
	r_ = seq2;
}

/*
 * Redéfinition de l'opérateur [] permettant de récupérer dynamiquement
 * une valeur situé dans les séquences r_ et l_ via l'index passé en paramètre
 */
template<int Size>
int& sequence_d<Size>::operator[](const int index) {
	// return modifiable <index>th bit of the sequence
	if (index < Size / 2)
		return l_[index];
	else
		return r_[index - Size / 2];
	//TODO: gestion exception
}

/*
 * Redéfinition de l'opérateur () permettant de récupérer dynamiquement
 * une valeur d'index entre les deux séquences
 */
template<int Size>
const int sequence_d<Size>::operator()(const int index) {
	//TODO: gestion index
	// return unmodifiable <index>th bit of the sequence
	if (index < Size / 2)
		return l_(index);
	return r_(index - Size / 2);
	//TODO: gestion exception
}

/*
 * Retourne la taille de sequence_d.
 */
template<int Size>
double sequence_d<Size>::size() {
	return Size;
}

/*
 * Effectue un décalage de valeur shift.
 * Le décalage s'effectue séparement entre l_ et r_.
 */
template<int Size>
void sequence_d<Size>::decalage(const int shift) {
	// shift <shift> left bits to the right of the Sequence
	l_.decalage(shift);
	r_.decalage(shift);
}

/*
 * Retourne la sequence r_
 */
template<int Size>
sequence& sequence_d<Size>::right() {
	return r_;
}

/*
 * Retourne la sequence l_
 */
template<int Size>
sequence& sequence_d<Size>::left() {
	return l_;
}

/*
 * Redéfinition de l'opératuer *, effectuant un XOR entre deux sequence_d
 * (Le XOR s'effectue indépendament entre les sequences droites et gauche.
 * Retour l'adresse de l'objet courant
 */
template<int Size>
sequence_d<Size>& sequence_d<Size>::operator*(sequence_d<Size>& seq) {
	// return XOR on two sequences
	l_ = l_ * seq.left();
	r_ = r_ * seq.right();
	return *this;
}

template<int Size>
ostream& operator<<(ostream& os, sequence_d<Size> seq) {
	if (Size != 64)
		return os;
	string s = "";
	for (auto i = 0; i < 4; i++) {
		sequence seq8_bits = seq.left().sous_sequence(i * 8, i * 8 + 7);
		bitset<8> byte;
		for (auto j = 7; j > -1; j--)
			byte[j] = seq8_bits(7 - j);
		const auto c = static_cast<char>(byte.to_ulong());
		s += c;
	}
	for (auto i = 0; i < 4; i++) {
		sequence seq8_bits = seq.right().sous_sequence(i * 8, i * 8 + 7);
		bitset<8> byte;
		for (auto j = 7; j > -1; j--)
			byte[j] = seq8_bits(7 - j);
		const auto c = static_cast<char>(byte.to_ulong());
		s += c;
	}

	os << s;
	return os;
}

template<int Size>
istream& operator>>(istream& is, sequence_d<Size>& seq) {
	if (Size != 64)
		return is;
	for (auto i = 0; i < 64; i += 8)
	{
		char c;
		// read stream without skipping whitespaces
		if (!(is >> noskipws >> c))
		{
			c = '\0';
		}
		cout << "debug >> : c=" << c << endl;
		auto set = bitset<8>(c);
		string array = set.to_string().c_str();
		auto j = 0;
		for (auto ele : array)
		{
			seq[i + j] = ele - '0';
			j++;
		}
	}
	return is;
}

template<int Size>
void sequence_d<Size>::import_string(string line)
{
	auto seq = sequence_d<64>();
	for (auto i = 0; i < 8; i++)
	{
		auto c = line[i];
		auto set = bitset<8>(c);
		string array = set.to_string().c_str();
		auto j = 0;
		for (auto ele : array)
		{
			/*if (i * 8 + j > 32)
				r_[(i * 8 + j) % 32] = ele - '0';
			else
				l_[(i * 8 + j) % 32] = ele - '0';*/
			this->operator[](i + j) = ele - '0';
			j++;
		}
	}
}

template<int Size>
ostream& write(ostream& os, sequence_d<Size> seq)
{
	if (Size != 64)
		return os;
	os << endl;
	for (auto i = 0; i < Size; i++)
	{
		os << seq(i);
		if ((i + 1) % 8 == 0) os << " ";
	}
	os << endl;
	return os;
}

template<int Size>
istream& read(istream& is, sequence_d<Size>& seq)
{
	if (Size != 64)
		return is;
	char c;
	for (auto i = 0; i < 64; i++) {
		is >> c;
		seq[i] = c - '0';
	}

	return is;
}

template<typename T>
void affichage(T seq)
{
	const int size = seq.size();
	for (auto i = 0; i < size; i++) {
		cout << seq(i);
		if ((i + 1) % 8 == 0) cout << " ";
	}
	cout << endl;
}
#endif // ENCRYPTION_3DES_SEQUENCED_H