#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "SortedList.h"

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


	int AddItem();
	//--------------------------------------------------------------------
	//	Brief:	Add new record into list.
	//	Pre:	list should be initialized.
	//	Post:	new music record is added into the list.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int DeleteItem();
	//--------------------------------------------------------------------
	//	Brief:	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	//	Pre:	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	//	Post:	����Ʈ�� �ش� item�� �����Ѵ�.
	//	Return:	������ 1�� ����, ���н� 0�� ����. //�̰� cpp�ؾ���
	//--------------------------------------------------------------------


	int ReplaceItem();
	//--------------------------------------------------------------------
	//	Brief:	����Ʈ���� �ش� id�� ���� item�� ã�� �����Ѵ�.
	//	Pre:	�Է��ϴ� id�� ����Ʈ�� �����ؾ� �Ѵ�.
	//	Post:	����Ʈ�� item�� ����ȴ�.
	//--------------------------------------------------------------------


	int SearchByID_SequenS();
	//--------------------------------------------------------------------
	//	Brief:	����Ʈ���� �ش� id�� ���� item�� ã�� ����Ѵ�.
	//	Pre:	����.
	//	Post:	ã�� item�� ����Ѵ�.
	//	Return:	������ 1�� ����, ���н� 0�� ����
	//--------------------------------------------------------------------


	int SearchByID_BinarayS();
	//--------------------------------------------------------------------
	//	Brief:	����Ʈ���� �ش� id�� ���� item�� ã�� ����Ѵ�.
	//	Pre:	����.
	//	Post:	ã�� item�� ����Ѵ�.
	//	Return:	������ 1�� ����, ���н� 0�� ����
	//--------------------------------------------------------------------


	int SearchByName();
	//--------------------------------------------------------------------
	//	Brief:	����Ʈ���� �ش� name�� ���� item�� ã�� ����Ѵ�.
	//	Pre:	����.
	//	Post:	ã�� item�� ����Ѵ�.
	//	Return:	������ 1�� ����, ���н� 0�� ����
	//--------------------------------------------------------------------


	int SearchAllItemByName(ItemType& inData);
	//--------------------------------------------------------------------
	//	Brief:	����Ʈ���� �ش� �̸��� ���� item�� ã�� ��ȯ�Ѵ�.
	//	Pre:	���ڷ� �޴� ItemType�� �̸��� �ԷµǾ� �־�� �Ѵ�.
	//	Post:	ã�� item�� ���ڷ� ���´�.
	//	Param	inData	�̸��� �Էµ� �ִ� ItemType��.
	//	Return:	������ 1�� ����, ���н� 0�� ����
	//--------------------------------------------------------------------


	void DisplayAllItem();
	//--------------------------------------------------------------------
	//	Brief:	Display all records record on screen.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------


	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make list empty.
	//	Pre:	none.
	//	Post:	clear list.
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


private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	SortedList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif _APPLICATION_H_