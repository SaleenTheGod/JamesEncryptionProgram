#include "Encryption.h"
#include <fstream>
#include <list>


using namespace std;

int main() 
{
	char ans, chc;
	T ePlain, eCipher, eEncrypted;
	T dEncrypt, dCipher, dDecrypted;
	T jinFileName, joutFileName, jPlain, jCipher, jEncrypted, jtempStr;
	T ginFileName, goutFileName, gPlain, gCipher, gDecrypted, gtempStr;
	list<string> jList, gList;

	ifstream jIN, gIN;
	ofstream jOUT, gOUT;

	Encryption E, D, G, J;

	do {

		cout << "*** James's Encryption Menu ***\n\n\n"
			<< "[E] -- Encrypt a string\n"
			<< "[D] -- Decrypt a string\n"
			<< "[J] -- Encrypt an input file (only .txt)\n"
			<< "[G] -- Decrypt an input file (only .txt)\n"
			<< "[H] -- Help / Info\n"
			<< "\n";
		
		cin >> chc;

		switch (chc)
		{

		case 'E' : 

			cout << "Enter a string to encrypt\n";
		
			cin >> ePlain;
		
			cout << "Enter a cipher\n";
			
			cin >> eCipher;

			eEncrypted = E.encrypt(ePlain, eCipher);

			cout << "Plain Text :\t" << ePlain << " Cipher :\t" << eCipher << " Encrypted Text :\t" << eEncrypted << endl;

			break;

		case 'e':

			cout << "Enter a string to encrypt\n";

			cin >> ePlain;

			cout << "Enter a cipher\n";

			cin >> eCipher;

			eEncrypted = E.encrypt(ePlain, eCipher);

			cout << "Plain Text :\t" << ePlain << " Cipher :\t" << eCipher << " Encrypted Text :\t" << eEncrypted << endl;

			break;
	
		case 'D' :

			cout << "Enter a string to decrypt\n";

			cin >> dEncrypt;

			cout << "Enter the cipher\n";

			cin >> dCipher;

			dDecrypted = D.decrypt(dEncrypt, dCipher);

			cout << "Encrypted Text :\t" << dEncrypt << " Cipher :\t" << dCipher << " Decrypted :\t" << dDecrypted << endl;
			
			break;

		case 'd':

			cout << "Enter a string to decrypt\n";

			cin >> dEncrypt;

			cout << "Enter the cipher\n";

			cin >> dCipher;

			dDecrypted = D.decrypt(dEncrypt, dCipher);

			cout << "Encrypted Text :\t" << dEncrypt << " Cipher :\t" << dCipher << " Decrypted :\t" << dDecrypted << endl;

			break;
		
		case 'J' :

			cout << "Enter input file name. Leave out the file extension\n";
			cin >> jinFileName;
			jinFileName = jinFileName + ".txt";
			cout << "Enter output file name. Leave out the file extension\n";
			cin >> joutFileName;
			joutFileName = joutFileName + ".txt";

			cout << "Enter your cipher\n";

			cin >> jCipher;

			jIN.open(jinFileName);
			jOUT.open(joutFileName);

			if (!jIN.fail()) {
				while (jIN.good())
				{
					getline(jIN, jtempStr);
					jList.push_back(jtempStr);
				}
			}
			else 
			{
				cerr << "Input File Doesn't exist\n";
			}

			while (!jList.empty()) {

				jEncrypted = J.encrypt(jList.front(), jCipher);
				jList.pop_front();
				jOUT << jEncrypted << endl;
			}


			jIN.clear();
			jIN.close();
			jOUT.clear();
			jOUT.close();
			jList.clear();

			break;

		case 'j':

			cout << "Enter input file name. Leave out the file extension\n";
			cin >> jinFileName;
			jinFileName = jinFileName + ".txt";
			cout << "Enter output file name. Leave out the file extension\n";
			cin >> joutFileName;
			joutFileName = joutFileName + ".txt";

			cout << "Enter your cipher\n";

			cin >> jCipher;

			jIN.open(jinFileName);
			jOUT.open(joutFileName);

			if (!jIN.fail()) {
				while (jIN.good())
				{
					getline(jIN, jtempStr);
					jList.push_back(jtempStr);
				}
			}
			else
			{
				cerr << "Input File Doesn't exist\n";
			}

			while (!jList.empty()) {

				jEncrypted = J.encrypt(jList.front(), jCipher);
				jList.pop_front();
				jOUT << jEncrypted << endl;
			}


			jIN.clear();
			jIN.close();
			jOUT.clear();
			jOUT.close();
			jList.clear();

			break;

		case 'G' : 
			
			cout << "Enter input file name. Leave out the file extension\n";
			cin >> ginFileName;
			ginFileName = ginFileName + ".txt";
			cout << "Enter output file name. Leave out the file extension\n";
			cin >> goutFileName;
			goutFileName = goutFileName + ".txt";

			cout << "Enter your cipher\n";

			cin >> gCipher;

			gIN.open(ginFileName);
			gOUT.open(goutFileName);

			if (!gIN.fail()) {
				while (gIN.good())
				{
					getline(gIN, gtempStr);
					gList.push_back(gtempStr);
				}
			}
			else
			{
				cerr << "Input File Doesn't exist\n";
			}

			while (!gList.empty()) {

				gDecrypted = G.decrypt(gList.front(), gCipher);
				gList.pop_front();
				gOUT << gDecrypted << endl;
			}

			gIN.clear();
			gIN.close();
			gOUT.clear();
			gOUT.close();
			gList.clear();

			break;

		case 'g':

			cout << "Enter input file name. Leave out the file extension\n";
			cin >> ginFileName;
			ginFileName = ginFileName + ".txt";
			cout << "Enter output file name. Leave out the file extension\n";
			cin >> goutFileName;
			goutFileName = goutFileName + ".txt";

			cout << "Enter your cipher\n";

			cin >> gCipher;

			gIN.open(ginFileName);
			gOUT.open(goutFileName);

			if (!gIN.fail()) {
				while (gIN.good())
				{
					getline(gIN, gtempStr);
					gList.push_back(gtempStr);
				}
			}
			else
			{
				cerr << "Input File Doesn't exist\n";
			}

			while (!gList.empty()) {

				gDecrypted = G.decrypt(gList.front(), gCipher);
				gList.pop_front();
				gOUT << gDecrypted << endl;
			}

			gIN.clear();
			gIN.close();
			gOUT.clear();
			gOUT.close();
			gList.clear();

			break;

		case 'H' : 

			cout << "This algorithm is derived from taking the character in the string, and advancing it by the size of the cipher, then it is reversed.\n\nSo 'James' with the cipher 'test' is 'niqew'\n\n\n\n***DISCLAIMER THIS ALGORITHM IS NOT VERY SECURE, THIS WAS A HOBBY***\n\n";

			break;

		case 'h':

			cout << "This algorithm is derived from taking the character in the string, and advancing it by the size of the cipher, then it is reversed.\n\nSo 'James' with the cipher 'test' is 'niqew'\n\n\n\n***DISCLAIMER THIS ALGORITHM IS NOT VERY SECURE, THIS WAS A HOBBY***\n\n";

			break;

		default :

			cerr << "That was not a proper input, please pick from the list!\n";
			break;
		}

		cout << "Would you like to go back to the menu? [Y] or [N]\n";
		cin >> ans;

	} while (ans == 'Y' || ans == 'y');
}