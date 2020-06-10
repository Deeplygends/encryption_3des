#include "Crypt.h"

#include <fstream>

#include "DES.h"
#include "DESinv.h"


crypt::crypt(SequenceD<64> k1, SequenceD<64> k2)
{
	this->k1_ = k1;
	this->k2_ = k2;
}

void crypt::operator()(string file_in, string file_out)
{
	des cdes = des(k1_);
	DESinv ddes = DESinv(k2_);
	list<SequenceD<64>> listSeq;
	SequenceD<64> seq;

	// acces fichier -> recup contenu
	ifstream readFile;
	readFile.open(file_in);
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
	writeFile.open(file_out);

	for (SequenceD<64> cryptedSeq : listSeq)
	{
		writeFile << cryptedSeq;
	}
	writeFile.close();
}
