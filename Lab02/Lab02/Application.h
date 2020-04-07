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
	//	Brief:	리스트에서 해당 id를 가진 item을 찾아 제거한다.
	//	Pre:	입력하는 id가 리스트에 존재해야 한다.
	//	Post:	리스트에 해당 item을 제거한다.
	//	Return:	성공시 1을 리턴, 실패시 0을 리턴. //이거 cpp해야함
	//--------------------------------------------------------------------


	int ReplaceItem();
	//--------------------------------------------------------------------
	//	Brief:	리스트에서 해당 id를 가진 item을 찾아 변경한다.
	//	Pre:	입력하는 id가 리스트에 존재해야 한다.
	//	Post:	리스트에 item이 변경된다.
	//--------------------------------------------------------------------


	int SearchByType_SequenS();
	//--------------------------------------------------------------------
	//	Brief:	리스트에서 해당 Type를 가진 item을 찾아 출력한다.
	//	Pre:	없음.
	//	Post:	찾은 item을 출력한다.
	//  Return: 성공시 1을 리턴, 실패시 0을 리턴.
	//--------------------------------------------------------------------


	int SearchByName_SequenS();
	//--------------------------------------------------------------------
	//	Brief:	리스트에서 해당 Name를 가진 item을 찾아 출력한다.
	//	Pre:	없음.
	//	Post:	찾은 item을 출력한다.
	//  Return: 성공시 1을 리턴, 실패시 0을 리턴.
	//--------------------------------------------------------------------


	int SearchBySerial_BinaryS();
	//--------------------------------------------------------------------
	//	Brief:	리스트에서 해당 id를 가진 item을 이진검색하여 출력한다.
	//	Pre:	없음.
	//	Post:	찾은 item을 출력한다.
	//	Return:	성공시 1을 리턴, 실패시 0을 리턴
	//--------------------------------------------------------------------


	int ReplaceFromKB_BinaryS();
	//--------------------------------------------------------------------
	//	Brief:	리스트에서 해당 id를 가진 item을 이진검색, record를 바꾼다.
	//	Pre:	입력한 id가 리스트에 있어야한다.
	//	Post:	리스트에 item이 변경된다.
	//	Return:	성공시 1을 리턴, 실패시 0을 리턴
	//--------------------------------------------------------------------


	void DisplayAllItem();
	//--------------------------------------------------------------------
	//	Brief:	Display all records record on screen.
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


	int SearchByName();
	//--------------------------------------------------------------------
	//	Brief:	리스트에서 해당 name을 가진 item을 찾아 출력한다.
	//	Pre:	없음.
	//	Post:	찾은 item을 출력한다.
	//	Return:	성공시 1을 리턴, 실패시 0을 리턴
	//--------------------------------------------------------------------
	

	int SearchAllItmeByName(ItemType& inData);
	//--------------------------------------------------------------------
	//	Brief:	리스트에서 해당 이름을 가진 item을 찾아 반환한다.
	//	Pre:	인자로 받는 ItemType에 이름이 입력되어 있어야 한다.
	//	Post:	찾은 item이 인자로 들어온다.
	//	Param	inData	이름이 입력되 있는 ItemType값.
	//	Return:	성공시 1을 리턴, 실패시 0을 리턴
	//--------------------------------------------------------------------
	

private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	SortedList m_List;		///< item list.
	int m_Command;			///< current command number.
};
#endif _APPLICATION_H_