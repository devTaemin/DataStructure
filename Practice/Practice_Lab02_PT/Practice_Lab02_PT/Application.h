#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <iostream>
#include <fstream>
#include <string>
#include "SortedList.h"
using namespace std;

#define FILENAMESIZE 1024

class Application
{
public:
	void Run();


	int GetCommand();


	int AddMusic();


	int DeleteMusic();


	int ReplaceMusic();


	int RetrieveMusic();


	void DisplayAllMusic();


	void MakeEmpty();


	int OpenInFile(char* inFilename);


	int OpenOutFile(char* inFilename);


	int ReadDataFromFile();


	int WriteDataToFile();

	
	int SearchByID_SequenS();


	int SearchByID_BinaryS();


	int SearchByName();



	
	


private:
	ifstream m_InFile;
	ofstream m_OutFile;
	SortedList m_List;
	int m_Command;
};
#endif _APPLICATION_H_