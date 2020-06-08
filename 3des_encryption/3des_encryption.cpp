// 3des_encryption.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Sequence.h"
#include "SequenceD.h"
#include "helper.cpp"
#include "Permutation.h"

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
	vector<int> vect = { 5, 3 , 1 , 4 , 2 };
	Sequence sequ6 = sequ.permutation(vect);
	sequ6.stringify();
}

static void testSequenceD() {
	SequenceD<64> seqD = SequenceD<64>();
	Sequence seq = Sequence();
	/*SequenceD<8> seq2 = SequenceD<8>();


	seq2.to_string();
	cout << seq.size();
	seq.right().to_string();
	seq.left().to_string();
	seq.d	ecalage(3);
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
	affichage(seq);*/

	//test Permutation
	cout << endl << "Test Permutation :" << endl;
	vector<int> v{ 2,0,3,1 };
	Permutation<4, 4> p;
	SequenceD<4> seqD4 = SequenceD<4>();
	SequenceD<4> seqD5 = p(seqD4, v);

	affichage(seqD5);
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
