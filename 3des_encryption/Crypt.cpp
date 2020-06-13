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
	cout << "cdes k1 :"<< k1_ << endl;
	auto cdes = des(k1_);
	cout << "cdes k2 :" << k2_ << endl;
	auto ddes = des_inv(k2_);

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
		cout << endl << "input SEQd : ";
		write(cout, seq);
		cout << seq;

		//encrypt
		auto des1 = cdes(seq);
		auto des2 = ddes(des1);
		seq = cdes(des2);

		//write to file
		write_file << seq;
	}
	read_file.close();
	write_file.close();
}