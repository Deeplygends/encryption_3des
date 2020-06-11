#include "crypt.h"

#include <fstream>
#include <utility>

#include "des.h"
#include "des_inv.h"


crypt::crypt(sequence_d<64> k1, sequence_d<64> k2)
{
	this->k1_ = std::move(k1);
	this->k2_ = std::move(k2);
}

void crypt::operator()(const string& file_in, const string& file_out) const
{
	cout << "cdes k1" << endl;
	auto cdes = des(k1_);
	cout << "cdes k2" << endl;
	auto ddes = des_inv(k2_);
	list<sequence_d<64>> list_seq;
	sequence_d<64> seq;

	// acces fichier -> recup contenu
	ifstream read_file;
	ofstream write_file;
	cout << "open read file" << endl;
	read_file.open(file_in);
	cout << "open write file" << endl;
	write_file.open(file_out);
	int size = read_file.tellg();
	
	while(!read_file.eof())
	{
		read_file.read(reinterpret_cast<char*>(&seq), 8);
		cout << seq;
		seq = cdes(ddes(cdes(seq)));
		write_file << seq;
	}
	/*
	if (read_file.is_open())
	{
		while (!read_file.eof())
		{
			read_file >> seq;
			seq = cdes(ddes(cdes(seq)));
			list_seq.push_back(seq);
		}
	}
	*/
	read_file.close();
	write_file.close();
	// ecriture fichier
	
	/*
	for (auto cryptedSeq : list_seq)
	{
		write_file << cryptedSeq;
		write_file << seq;
	}
	*/
	
}