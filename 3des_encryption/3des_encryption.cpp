// 3des_encryption.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Sequence.h"
#include "SequenceD.h"
#include "helper.cpp"
#include "Permutation.h"
#include "KeyGen.h"
#include "Sbox.h"
#include "F.h"

using namespace std;
static void testSequence();
static void testSequenceD();


int main()
{
	testSequenceD();
}

static void testSequence()
{
	Sequence sequ = Sequence(5);
	Sequence sequ2 = Sequence(5);
	list<Sequence> list;
	list.push_back(sequ);
	list.push_back(sequ2);
	Sequence sequ3 = Sequence(list);

	cout << "Sequence before editing : ";
	sequ.stringify();
	sequ2.stringify();
	sequ[0] = 1;
	sequ[1] = 0;
	cout << "Sequence after editing the 2 first digit : ";
	sequ.stringify();

	cout << "Sequence from list of sequence : ";
	sequ3.stringify();

	cout << "Shift the sequence of 2 digits : ";
	sequ3.decalage(2);
	sequ3.stringify();

	cout << "XOR between 2 sequence" << endl;
	sequ.stringify();
	sequ2.stringify();
	Sequence sequ4 = sequ * sequ2;
	sequ4.stringify();

	cout << "Sous sequence start 1 end 3";
	sequ.stringify();
	Sequence sequ5 = sequ.sous_sequence(1, 3);
	sequ5.stringify();


	cout << "Permutation of sequence (size 5) with vector (5 , 3 , 1 , 4 , 2 )";
	sequ.stringify();
	vector<int> vect = {5, 3, 1, 4, 2};
	Sequence sequ6 = sequ.permutation(vect);
	sequ6.stringify();
}

static void testSequenceD()
{
	SequenceD<64> seqD = SequenceD<64>();
	Sequence seq = Sequence();
	/*SequenceD<8> seq2 = SequenceD<8>();


	seq2.to_string();
	cout << seq.size();
	seq.right().to_string();
	seq.left().to_string();
	seq.decalage(3);
	seq.to_string();
	seq = seq * seq2;
	seq.to_string();
	cout << seq;


	affichage(seq);
	affichage(seqD);

	cin >> seqD;
	cout << seqD;
	write(cout, seqD);

	string jeanvalj = "0100101001000101010000010100111001010110010000010100110001001010";

	read(cin, seqD);
	cout << "WRITE : " << endl;
	write(cout, seqD);

	cout << "AFFICHAGE seqD :" << endl;
	affichage(seqD);

	cout << "AFFICHAGE seq :" << endl;
	affichage(seq);

	//test Permutation
	cout << endl << "Test Permutation :" << endl;
	vector<int> v{ 4,2,0,5,3,1 };
	Permutation<4, 6> p;
	vector<int> v2{ 1,3,2,0 };
	Permutation<6, 4> p2;
	vector<int> v3{ 0,2,1,3 };
	Permutation<4, 4> p3;

	SequenceD<4> seqD4 = SequenceD<4>();
	cout << endl << "Test Permutation :" << endl;
	cout << "Affichage SequenceD<4> :" << endl;
	affichage(seqD4);

	SequenceD<6> seqD6 = p(seqD4, v);
	cout << "Affichage permutation vers SequenceD<6> :" << endl;
	affichage(seqD6);

	seqD4 = p2(seqD6, v2);
	cout << "Affichage permutation2 vers SequenceD<4> :" << endl;
	affichage(seqD4);

	seqD4 = p3(seqD4, v3);
	cout << "Affichage permutation3 vers SequenceD<4> :" << endl;
	affichage(seqD4);

	//test KeyGen
	cout << endl << "====================" << endl << "Test KeyGen :" << endl;
	SequenceD<64> sequenceD;

	KeyGen keyGen(sequenceD);

	for (int i = 0; i < 16; i++) {
		cout << "Cle " << i << " : ";
		affichage(keyGen.next());
		cout << endl;
	}

	 */


	//Test SBox

	int tableau[2][2] = {{1, 2}, {3, 4}};
	// Substitution Boxes (S-Boxes)
	const int sboxes[8][4][16] = {
		{
			{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
			{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
			{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
			{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
		},
		{
			{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
			{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
			{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
			{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
		},
		{
			{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
			{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
			{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
			{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
		},
		{
			{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
			{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
			{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
			{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
		},
		{
			{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
			{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
			{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
			{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
		},
		{
			{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
			{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
			{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
			{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
		},
		{
			{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
			{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
			{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
			{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
		},
		{
			{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
			{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
			{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
			{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
		}
	};

	SequenceD<64> sequenceD = SequenceD<64>();
	f f_ = f(sequenceD);
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
