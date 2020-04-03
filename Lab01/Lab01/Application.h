#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"
#include "ItemType.h"
#define FILENAMESIZE 1024


//--------------------------------------------------------------------
//		Application class for item management simply.
//--------------------------------------------------------------------
class Application
{
public:
	Application()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		m_Command = 0;
	}



	~Application() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	void Run();
	//--------------------------------------------------------------------
	//	Brief:	Program driver.
	//	Pre:	program is started.
	//	Post:	program is finished.
	//--------------------------------------------------------------------


	int GetCommand();
	//--------------------------------------------------------------------
	//	Brief:	Display command on screen and get a input from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	user's commands.
	//--------------------------------------------------------------------


	int AddMusic();
	//--------------------------------------------------------------------
	//	Brief:	Add new music record into list.
	//	Pre:	list should be initialized.
	//	Post:	new music record is added into the list.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	void DisplayAllMusic();
	//--------------------------------------------------------------------
	//	Brief:	Display all music record on screen.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------


	int OpenInFile(char* fileName);
	//--------------------------------------------------------------------
	//	Brief:	Open a file by file descriptor as an input file.
	//	Pre:	a file for reading is exist.
	//	Post:	open the file for reading.
	//	Param:	fileName		a file to open for reading.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int OpenOutFile(char* fileName);
	//--------------------------------------------------------------------
	//	Brief:	Open a file by file descriptor as an output file.
	//	Pre:	list should be initialized.
	//	Post:	open the file for writing.
	//	Param	fileName		a filename to open for writing.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int ReadDataFromFile();
	//--------------------------------------------------------------------
	//	Brief:	Open a file as a read mode, 
	//			read all data on the file,
	//			and set list by the data.
	//	Pre:	The file is not opened.
	//	Post:	list holds all records from the file.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int WriteDataToFile();
	//--------------------------------------------------------------------
	//	Brief:	Open a file as a write mode,
	//			and write all data into the file.
	//	Pre:	the file is not opened.
	//	Post:	the list is stored in the output file.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int RetrieveMusic();
	//--------------------------------------------------------------------
	//	Brief:	Search record of music by serial number from KB.
	//	Pre:	the list is initialized.
	//	Post:	none.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int DeleteMusic();
	//--------------------------------------------------------------------
	//	Brief:	Delete record of music by serial_number from KB.
	//	Pre:	the list is initialized.
	//	Post:	a record is deleted from the list.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int ReplaceMusic();
	//--------------------------------------------------------------------
	//	Brief:	Replace record's contents with newly input contents.
	//	Pre:	the list is initialized.
	//	Post:	a record of music is replaced from the list.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make list empty.
	//	Pre:	none.
	//	Post:	clear list.
	//--------------------------------------------------------------------


private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	ArrayList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif _APPLICATION_H_