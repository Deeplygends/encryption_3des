//#include "SequenceD.h"
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <bitset>
//using namespace std;
//
//template<int Size>
//ostream& operator<<(ostream& os, SequenceD<64> seq) {
//
//	for (int i = 0; i < 4; i++) {
//		Sequence seq8bits = seq.left().sous_sequence(i * 8, i * 8 + 7);
//		string byteString = seq8bits.to_string();
//		stringstream sstream(byteString);
//		while (sstream.good()) {
//			bitset<8> byte;
//			sstream >> byte;
//			char c = char(byte.to_ulong());
//			os << c;
//		}
//
//
//	}
//	/*for (int i = 0; i < 4; i++) {
//		os << seq.right().sous_sequence(i * 8, i * 8 + 7);
//	}*/
//	return os;
//}



