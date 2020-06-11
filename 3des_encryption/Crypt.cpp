#include "Crypt.h"

#include <fstream>
#include <utility>

#include "DES.h"
#include "des_inv.h"


crypt::crypt(sequence_d<64> k1, sequence_d<64> k2)
{
	this->k1_ = std::move(k1);
	this->k2_ = std::move(k2);
}

void crypt::operator()(const string& file_in, const string& file_out) const
{
	auto cdes = des(k1_);
	auto ddes = des_inv(k2_);
	list<sequence_d<64>> list_seq;
	sequence_d<64> seq;

	// acces fichier -> recup contenu
	ifstream read_file;
	read_file.open(file_in);
	if (read_file.is_open())
	{
		while (!read_file.eof())
		{
			read_file >> seq;
			seq = cdes(ddes(cdes(seq)));
			list_seq.push_back(seq);
		}
	}
	read_file.close();

	// ecriture fichier
	ofstream write_file;
	write_file.open(file_out);

	for (auto cryptedSeq : list_seq)
	{
		write_file << cryptedSeq;
	}
	write_file.close();
}