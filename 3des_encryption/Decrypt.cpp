#include "Decrypt.h"
#include <fstream>

#include "DES.h"
#include "des_inv.h"


decrypt::decrypt(SequenceD<64> k1, SequenceD<64> k2)
{
	this->k1_ = k1;
	this->k2_ = k2;
}

void decrypt::operator()(string file_in, string file_out)
{
	des cdes = des(k2_);
	des_inv ddes = des_inv(k1_);
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
			seq = ddes(cdes(ddes(seq)));
			listSeq.push_back(seq);
		}
	}
	readFile.close();

	// ecriture fichier
	ofstream writeFile;
	writeFile.open(file_out);

	for (SequenceD<64> decryptedSeq : listSeq)
	{
		writeFile << decryptedSeq;
	}
	writeFile.close();
}