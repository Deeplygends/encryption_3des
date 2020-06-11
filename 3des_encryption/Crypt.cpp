#include "Crypt.h"

#include <fstream>

#include "DES.h"
#include "DESinv.h"


Crypt::Crypt(SequenceD<64> k1, SequenceD<64> k2)
{
	this->k1 = k1;
	this->k2 = k2;
}

void Crypt::operator()(string fileIn, string fileOut)
{
	DES cdes = DES(k1);
	DESinv ddes = DESinv(k2);
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
			seq = cdes(ddes(cdes(seq)));
			listSeq.push_back(seq);
		}
	}
	readFile.close();

	// ecriture fichier
	ofstream writeFile;
	writeFile.open(fileOut);

	for (SequenceD<64> cryptedSeq : listSeq)
	{
		writeFile << cryptedSeq;
	}
	writeFile.close();
}

