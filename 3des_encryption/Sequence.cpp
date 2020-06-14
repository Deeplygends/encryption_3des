#include "sequence.h"
#include <ctime>
#include <iostream>

/*
 * Constructeur prenant en paramètre une taille taille_sequence,
 * et initialisant aléatoirement une deque de bit de cette taille.
 */
sequence::sequence(const int taille_sequence) {
	srand(time(nullptr) * clock());
	for (auto i = 0; i < taille_sequence; i++)
		sequence_.push_back(rand() % 2);
	// random bit sequence generator of size <tailleSequence>
}

/*
 * Constructeur prenant en paramètre une liste de sequence,
 * puis qui va concatener sequence_ des sequences de cette liste.
 */
sequence::sequence(list<sequence>& liste_sequences) {

	for (auto& seq : liste_sequences)
	{
		for (auto i = 0; i < seq.size(); i++)
		{
			sequence_.push_back(seq[i]);
		}
	}
}

/*
 * Fonction retournant un string des bits qui sont contenu dans _sequence
 */
string sequence::stringify()
{
	string s;
	for (auto i = 0; i < size(); i++)
		s += std::to_string(sequence_[i] + '0');

	cout << s << endl;
	return s;
}

/*
 * Redéfinition de l'opérateur [], prenant en paramètre un int index et
 * retournant le index-ième bit de sequence_
 */
int& sequence::operator[](int index) {
	// return modifiable <index>th bit of the sequence
	return sequence_[index];
}

/*
 * Redéfinition de l'opérateur (), prenant en paramètre un int index et
 * retournant la valeur de la index-ième case de sequence_
 */
int sequence::operator()(const int index)
{
	// return unmodifiable <index>th bit of the sequence
	/*if (index > size())
		return sequence_.at(size()-1);*/
	return sequence_.at(index);
}

/*
 * Fonction retournant la taille de la sequence_
 */
double sequence::size() const
{
	return sequence_.size();
}


/*
 * Redéfinition de l'opérateur =, prenant en paramètre une adresse d'int
 * et convertissant cet int en valeur binaire qui sera stocké dans sequence_
 * La fonction retourne l'adresse de l'objet courant.
 */
sequence& sequence::operator=(int& entier) {
	auto position = static_cast<int>(size()-1);
	deque<int> binary;
	do
	{
		binary.push_front(entier % 2);
		entier /= 2;
	} while (entier != 0);

	while (position >= 0)
	{
		if (!binary.empty())
		{
			sequence_[position] = binary.back();
			binary.pop_back();
		}
		else
		{
			sequence_[position] = 0;
		}

		position--;
	}

	return *this;
}

/*
 * Fonction qui effectue un décalage de valeur shift sur sequence_
 */
void sequence::decalage(int shift) {
	while (shift != 0)
	{
		auto tmp = sequence_.front();
		sequence_.pop_front();
		sequence_.push_back(tmp);
		shift--;
	}
}

/*
 * Redéfinition de l'opérateur *, prenant en paramètre une adresse de sequence.
 * Effectué un XOR entre les deux sequences, qui sera stocké dans l'objet courant.
 * Retourne l'adresse de l'objet courant.
 */
sequence& sequence::operator*(sequence& seq) {
	// return XOR on two sequences
	if (size() == seq.size())
	{
		for (auto i = 0; i < size(); i++)
			sequence_[i] = sequence_[i] != seq[i] ? 1 : 0;
	}

	return *this;
}


/*
 * Fonction effectuant une permutation selon un vecteur v de meme taille.
 */
sequence sequence::permutation(vector<int>& v) {
	// return Sequence created from permutation
	auto sequ = sequence(size());
	for (auto i = 0; i < size(); i++)
	{
		//sequ[i] = sequence_[v[i] - 1];
		sequ[i] = v[i] - 1 < size() ? sequence_[v[i] - 1] : 0;
	}
	return sequ;
}

/*
 * Fonction prenant en paramètre deux int debut et fin..
 * Retourne une séquence débutant à l'index debut de sequence_
 * et se finissant à l'index fin.
 */
sequence sequence::sous_sequence(int debut, const int fin) {
	auto sequ = sequence(fin - debut + 1);
	if (debut < 0 || fin >= size())
		return sequ;
	auto position = 0;
	while (debut <= fin)
	{
		sequ[position] = sequence_[debut];
		debut++;
		position++;
	}
	return sequ;
}
