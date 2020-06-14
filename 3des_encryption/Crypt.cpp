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
	auto cdes = des(k1_);
	auto ddes = des_inv(k2_);

	// acces fichier -> recup contenu
	cout << "Input file : " << file_in << endl;
	ifstream read_file(file_in);

	cout << "Output file : " << file_out << endl;
	ofstream write_file(file_out);

	//get length
	read_file.seekg(0, std::ifstream::end);
	int file_size = read_file.tellg();
	cout << "Length of read file : " << read_file.tellg();
	read_file.seekg(0, std::ifstream::beg);

	for (auto i = 0; i < file_size; i += 8)
	{
		sequence_d<64> seq;
		read_file >> seq;

		//debug
		cout << endl << "8 char read to binary : ";
		write(cout, seq);
		cout << "8 char read to char : " << endl;
		cout << seq << endl;

		//1st round 3DES
		auto des1 = cdes(seq);
		cout << "1st DES : " << endl;
		cout << seq << endl;

		//2nd round 3DES
		auto des2 = ddes(des1);
		cout << "2nd DES : " << endl;
		cout << seq << endl;

		//3rd round 3DES
		seq = cdes(des2);
		cout << "3rd DES : " << endl;
		cout << seq << endl;

		//write to file
		write_file << seq;
	}
	read_file.close();
	write_file.close();
}