#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "ItemType.h"
#include "Application.h"

class Application
{
public:
	void Run();
	int GetCommand();
	int AddItem();
	void DisplayAllItem();
	int OpenInFile(char* fileName);
	int OpenOutFile(char* fileName);
	int ReadDataFromFile();
	int WriteDataToFile();

	void RetrieveStudent();
	void DeleteStudent();
	void Replace();

private:
	ifstream m_InFile;
	ofstream m_OutFile;
	ArrayList m_List;
	int m_Command;
};



#endif _APPLICATION_H_