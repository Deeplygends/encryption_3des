// 3des_encryption.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Sequence.h"

using namespace std;
static void testSequence();

int main()
{
	testSequence();
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
	sequ.to_string();
	sequ2.to_string();
	sequ[0] = 1;
	sequ[1] = 0;
	cout << "Sequence after editing the 2 first digit : ";
	sequ.to_string();

	cout << "Sequence from list of sequence : ";
	sequ3.to_string();

	cout << "Shift the sequence of 2 digits : ";
	sequ3.decalage(2);
	sequ3.to_string();

	cout << "XOR between 2 sequence" << endl;
	sequ.to_string();
	sequ2.to_string();
	Sequence sequ4 = sequ*sequ2;
	sequ4.to_string();

	cout << "Sous sequence start 1 end 3";
	sequ.to_string();
	Sequence sequ5 = sequ.sous_sequence(1, 3);
	sequ5.to_string();


	cout << "Permutation of sequence (size 5) with vector (5 , 3 , 1 , 4 , 2 )";
	sequ.to_string();
	vector<int> vect = { 5, 3 , 1 , 4 , 2 };
	Sequence sequ6 = sequ.permutation(vect);
	sequ6.to_string();
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
