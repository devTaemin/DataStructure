#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayList.h"

using namespace std;

#define FILENAMESIZE 1024

/**
*	Application class for item management simply.
*/
class Application
{
public:
	/**
	*	Default constructor
	*/
	Application()
	{
		m_Command = 0;
	}


	/**
	*	Destructor
	*/
	~Application(){}


	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();


	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return user's commands.
	*/
	int GetCommand();


	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return return 1 if this function works well, otherwise -1.
	*/
	int AddItem();


	/**
	*	@brief	Display all record in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();


	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a file to open for reading.
	*	@return return 1 if this function works well, otherwise -1.
	*/
	int OpenInFile(char* fileName);


	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return return 1 if this function works well, otherwise -1.
	*/
	int OpenOutFile(char* fileName);


	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return return 1 if this function works well, otherwise -1.
	*/
	int ReadDataFromFile();


	/**
	*	@brief	Open a file as a write mode, and write all data into the file.
	*	@pre	the file is not opened.
	*	@post	the list is stored in the output file.
	*	@return return 1 if this function works well, otherwise -1.
	*/
	int WriteDataToFile();


	/**
	*	@brief	Search student's record by student's id from KB.
	*	@pre	none.
	*	@post	none.
	*	@return	return 1 if this function works well, otherwise -1.
	*/
	int RetrieveStudent();


	/**
	*	@brief	Delete student's record by student's id from KB.
	*	@pre	an array is set.
	*	@post	a student's record is deleted from an array.
	*	@return return 1 if this function works well, otherwise -1.
	*/
	int DeleteStudent();


	/**
	*	@brief	Replace studnet's record by finding based on student's id, and input information.
	*	@pre	an array is set.
	*	@post	a student's record is replaced from an array.
	*	@return	return 1 if this function works well, otherwise -1.
	*/
	int Replace();

private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	ArrayList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif _APPLICATION_H_