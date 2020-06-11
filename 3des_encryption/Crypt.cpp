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
	//sequence_d<64> seq;

	// acces fichier -> recup contenu
	cout << "open read file : " << file_in << endl;
	ifstream read_file(file_in);
	
	cout << "open write file" << file_out << endl;
	ofstream write_file(file_out);

	//get length
	read_file.seekg(0, std::ifstream::end);
	int file_size = read_file.tellg();
	cout << "read_file length :" << read_file.tellg();
	read_file.seekg(0, std::ifstream::beg);

	for (auto i = 0; i < file_size; i += 8)
	{
		sequence_d<64> seq;
		read_file >> seq;

		//debug
		cout << "input SEQd : " << endl;
		write(cout, seq);

		//encrypt
		seq = cdes(ddes(cdes(seq)));

		//write to file
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