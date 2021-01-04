#include<iostream>
#include<fstream>
using namespace std;
// 1. state print , stream's 4 error state
// 2. check error method
// 3. test EOF method  

void print_state (const std::ios& stream) {
  std::cout << " good()=" << stream.good();
  std::cout << " eof()=" << stream.eof();
  std::cout << " fail()=" << stream.fail();
  std::cout << " bad()=" << stream.bad();
	std::cout << endl;
}

void checkbit(){
	ofstream ofs;
	//print_state(ofs);

	ofs.clear( ofs.eofbit );
	if( ofs) cout << "ifs is true" << endl ;
	print_state(ofs);

	ofs.clear( ofs.badbit );
	if( ofs) cout << "ifs is true" << endl ;
	print_state(ofs);

	ofs.clear( ofs.failbit );
	if( ofs) cout << "ifs is true" << endl ;
	print_state(ofs);

	ofs.clear( ofs.goodbit );
	if( ofs) cout << "ifs is true" << endl ;
	print_state(ofs);
}

void testEOF(){
	ofstream ofs("tmp.txt");	ofs << "1234567890\n"; ofs.close();
	ifstream ifs("tmp.txt");
	char ch ;
	if( ifs) cout << "ifs is true" ;
	while( ifs.get(ch) )
	{
		cout << (int)ch ;
		print_state( ifs );
	}  // occurence last linefeed "\n"

	if( !ifs) cout << "ifs is fail" ;
	print_state( ifs);
	ifs.close();
	if(remove("tmp.txt")!=0 )	cerr << "remove tmpfile error ";
}

int main(){
	testEOF();

}



	//cout << ( ofs.rdstate() == ostream::goodbit ) << endl;
