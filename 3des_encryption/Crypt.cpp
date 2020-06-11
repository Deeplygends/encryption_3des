#include "Crypt.h"

#include <fstream>

#include "DES.h"
#include "des_inv.h"


crypt::crypt(sequence_d<64> k1, sequence_d<64> k2)
{
	this->k1_ = k1;
	this->k2_ = k2;
}

void crypt::operator()(string file_in, string file_out)
{
	des cdes = des(k1_);
	des_inv ddes = des_inv(k2_);
	list<sequence_d<64>> listSeq;
	sequence_d<64> seq;

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

	for (sequence_d<64> cryptedSeq : listSeq)
	{
		writeFile << cryptedSeq;
	}
	writeFile.close();
}

