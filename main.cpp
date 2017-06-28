#include <iostream>
#include <string>
#include <fstream>
#include "Encryption.h"


bool isCorrect(char input)
{
	if (input == 'E' || input == 'e' || input == 'D' || input == 'd')
		return true;

	return false;
}


void main()
{

	std::string mainMenuInput = "R";
	char MainMenuInput_Char = 'R', EResponse_C, DResponse_C;
	std::string EStringInput, EFilename, DStringInput, DFilename, EResponse, DResponse;
	std::ifstream EFilein, DFilein;
	std::vector<string> EStringVec, DStringVec;
	std::ofstream EFileOut, DFileOut;

	while (isCorrect(MainMenuInput_Char) == false)
	{
		std::cout << "***James's Encryption Tool***\n"
			<< "[E] -- Encrypt an input file\n"
			<< "[D] -- Decrypt an input file\n";
		std::getline(std::cin, mainMenuInput);
		while (std::cin.fail())
		{
			std::cout << "Please input a valid response!\n";
			std::getline(std::cin, mainMenuInput);
		}
		MainMenuInput_Char = mainMenuInput[0];

		switch (MainMenuInput_Char)
		{
		case 'E':
			std::cout << "Please enter input file name, do NOT include \".txt\"\n";
			std::getline(std::cin, EFilename);
			EFilename += ".txt";
			EFilein.open(EFilename);
			while(!(EFilein.eof()))
			{
				std::getline(EFilein, EStringInput);
				EStringVec.push_back(EStringInput);
			}
			EStringInput = "";
			for(int i = 0; i < EStringVec.size(); i++)
			{
				EStringInput += ((JEncryption::EncryptB64(EStringVec[i])) + "\n");
			}
			std::cout << EStringInput << "\nWould you like to output this text to an output file? Y\\N\n";
			std::getline(std::cin, EResponse);
			EResponse_C = EResponse[0];
			if (EResponse_C == 'Y' || EResponse_C == 'y')
			{
				std::cout << "Output to \"EncryptionOutput.txt\"\n";
				EFileOut.open("EncryptionOutput.txt");
				EFileOut << EStringInput << std::endl;
				EFileOut.close();
			}
			EFilein.close();
			system("pause");
			break;
		case 'D':

			std::cout << "Please enter input file name, do NOT include \".txt\"\n";
			std::getline(std::cin, DFilename);
			DFilename += ".txt";
			DFilein.open(DFilename);
			while (!(DFilein.eof()))
			{
				std::getline(DFilein, DStringInput);
				DStringVec.push_back(DStringInput);
			}
			DStringInput = "";
			for (int i = 0; i < DStringVec.size(); i++)
			{
				DStringInput += ((JEncryption::DecryptB64(DStringVec[i])) + "\n");
			}
			std::cout << DStringInput << "\nWould you like to output this text to an output file? Y\\N\n";
			std::getline(std::cin, DResponse);
			DResponse_C = DResponse[0];
			if (DResponse_C == 'Y' || DResponse_C == 'y')
			{
				std::cout << "Output to \"DecryptionOutput.txt\"\n";
				DFileOut.open("DecryptionOutput.txt");
				DFileOut << DStringInput << std::endl;
				DFileOut.close();
			}
			DFilein.close();

			system("pause");
			break;
		default:
			system("CLS");
			std::cout << "Please input a valid menu selection!\n";
			break;
		}
	}
}