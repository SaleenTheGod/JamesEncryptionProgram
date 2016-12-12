#include "Encryption.h"

Encryption::Encryption()
{
	m_plaintxt = "";
	m_cipher = "";
}

void Encryption::GetCipher(string & cipher)
{

	cout << "Enter Cipher\n";

	cin >> cipher;


}

void Encryption::GetPlaintxt(string & plaintxt)
{

	cout << "Enter plain Text\n";

	cin >> plaintxt;



}

void Encryption::setPlain(string & plaintxt)
{
	m_plaintxt = plaintxt;
}

void Encryption::setCipher(string & cipher)
{
	m_cipher = cipher;

}

string Encryption::encrypt(string plaintxt, string cipher)
{

	string encrypted;

	for (int i = 0; i < plaintxt.size(); i++)
	{
		encrypted.push_back(plaintxt[i] + cipher.size());
	}

	return encrypted;
}

string Encryption::decrypt(string plaintxt, string cipher)
{

	string decrypted;

	for (int i = 0; i < plaintxt.size(); i++)
	{
		decrypted.push_back(plaintxt[i] - cipher.size());
	}


	return decrypted;
}
