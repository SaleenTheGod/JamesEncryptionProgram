#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

typedef string T;

class Encryption {

public :


	Encryption();
	void GetCipher(string & cipher);
	void GetPlaintxt(string & plaintxt);
	void setPlain(string & plaintxt);
	void setCipher(string & cipher);
	string encrypt(string plaintxt, string cipher);
	string decrypt(string plaintxt, string cipher);


private :

	string m_plaintxt, m_cipher;



};
