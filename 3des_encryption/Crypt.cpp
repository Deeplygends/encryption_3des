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


/*
 * Input : Path du fichier à crypter, et path du fichier où écrire le contenu crypté
 * Construction de séquence_d de 8 caractères (64 bits) et
 * application du 3DES sur chacune de ces séquences_d.
 */
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
	cout << "Length of read file : " << read_file.tellg() << endl;
	read_file.seekg(0, std::ifstream::beg);

	for (auto i = 0; i < file_size; i += 8)
	{
		sequence_d<64> seq;
		read_file >> seq;

		//debug
		cout << endl << "8 char read to binary : ";
		write(cout, seq);
		cout << "8 char read to char : " << endl;
		cout << seq << endl << endl;

		//1st round 3DES
		cout << "1st DES : " << endl;
		auto des1_seq = cdes(seq);
		cout << "Resulting char sequence : " << des1_seq << endl << endl;

		//2nd round 3DES
		cout << "2nd DES : " << endl;
		auto des2_seq = ddes(des1_seq);
		cout << "Resulting char sequence : " << des2_seq << endl << endl;

		//3rd round 3DES
		cout << "3rd DES : " << endl;
		auto des3_seq = cdes(des2_seq);
		cout << "Resulting char sequence : " << des3_seq << endl << endl;

		//write to file
		write_file << des3_seq;
	}
	read_file.close();
	write_file.close();
}