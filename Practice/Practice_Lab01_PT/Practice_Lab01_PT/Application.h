#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <iostream>
#include <fstream>
#include <string>
#include "UnSortedList.h"
using namespace std;

#define FILENAMESIZE 1024

class Application
{
public:
	void Run();


	int GetCommand();


	int AddItem();


	void DisplayAllItem();


	void MakeEmpty();


	int OpenInFile(char* inFilename);


	int OpenOutFile(char* inFilename);


	int ReadDataFromFile();


	int WriteDataToFile();


	int RetrieveStudent();


	int DeleteStudent();


	int Replace();


private:
	ifstream m_InFile;
	ofstream m_OutFile;
	UnSortedList m_List;
	int m_Command;
};
#endif _APPLICATION_H_