#include "Decrypt.h"
#include <fstream>

#include "DES.h"
#include "DESinv.h"


Decrypt::Decrypt(SequenceD<64> k1, SequenceD<64> k2)
{
	this->k1 = k1;
	this->k2 = k2;
}

void Decrypt::operator()(string fileIn, string fileOut)
{
	DES cdes = DES(k2);
	DESinv ddes = DESinv(k1);
	list<SequenceD<64>> listSeq;
	SequenceD<64> seq;

	// acces fichier -> recup contenu
	ifstream readFile;
	readFile.open(fileIn);
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			readFile >> seq;
			seq = ddes(cdes(ddes(seq)));
			listSeq.push_back(seq);
		}
	}
	readFile.close();

	// ecriture fichier
	ofstream writeFile;
	writeFile.open(fileOut);

	for (SequenceD<64> decryptedSeq : listSeq)
	{
		writeFile << decryptedSeq;
	}
	writeFile.close();
}