#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


enum RelationType { LESS, GREATER, EQUAL };
//--------------------------------------------------------------------
//		Relation between items.
//--------------------------------------------------------------------


//--------------------------------------------------------------------
//		Item information class.
//--------------------------------------------------------------------
class ItemType
{
public:

	ItemType()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		Type = -1;
		Date = -1;
		Name = "";
		Serial = -1;
		Num = 0;
	}


	~ItemType() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	int GetType();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity type.
	//	Pre:	commodity type is set.
	//	Post:	none.
	//	Return: commodity type.
	//--------------------------------------------------------------------


	int GetDate();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity date.
	//	Pre:	commodity date is set.
	//	Post:	none.
	//	Return: commodity date.
	//--------------------------------------------------------------------


	string GetName();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity name.
	//	Pre:	commodity name is set.
	//	Post:	none.
	//	Return: commodity name.
	//--------------------------------------------------------------------


	int GetSerial();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity serial.
	//	Pre:	commodity serial is set.
	//	Post:	none.
	//	Return: commodity serial.
	//--------------------------------------------------------------------


	int GetNum();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity number.
	//	Pre:	commodity number is set.
	//	Post:	none.
	//	Return: commodity number.
	//--------------------------------------------------------------------


	void SetType(int inType);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity type.
	//	Pre:	none.
	//	Post:	commodity type is set.
	//	Param:	inType		commodity type.
	//--------------------------------------------------------------------


	void SetDate(int inDate);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity date.
	//	Pre:	none.
	//	Post:	commodity date is set.
	//	Param:	inDate		commodity date.
	//--------------------------------------------------------------------


	void SetName(string inName);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity name.
	//	Pre:	none.
	//	Post:	commodity name is set.
	//	Param:	inName		commodity name.
	//--------------------------------------------------------------------


	void SetSerial(int inSerial);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity serial.
	//	Pre:	none.
	//	Post:	commodity serial is set.
	//	Param:	inName		commodity name.
	//--------------------------------------------------------------------


	void SetNum(int inNum);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity number.
	//	Pre:	none.
	//	Post:	commodity number is set.
	//	Param:	inNum		commodity number.
	//--------------------------------------------------------------------


	void SetRecord(int inType, int inDate, string inName, int inSerial, int inNum);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//	Param:	inType		commodity type.
	//	Param	inDate		commodity date.
	//	Param:	inName		commodity name.
	//	Param:	inSerial	commodity serial.
	//	Param:	inNum		commodity number.
	//--------------------------------------------------------------------


	void DisplayTypeOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity type on screen.
	//	Pre:	commodity type is set.
	//	Post:	commodity type is on screen.
	//--------------------------------------------------------------------


	void DisplayDateOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity date on screen.
	//	Pre:	commodity date is set.
	//	Post:	commodity date is on screen.
	//--------------------------------------------------------------------


	void DisplayNameOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity name on screen.
	//	Pre:	commodity name is set.
	//	Post:	commodity name is on screen.
	//--------------------------------------------------------------------


	void DisplaySerialOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity serial on screen.
	//	Pre:	commodity serial is set.
	//	Post:	commodity serial is on screen.
	//--------------------------------------------------------------------


	void DisplayNumOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity number on screen.
	//	Pre:	commodity number is set.
	//	Post:	commodity number is on screen.
	//--------------------------------------------------------------------


	void DisplayRecordOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity record on screen.
	//	Pre:	commodity record is set.
	//	Post:	commodity record is on screen.
	//--------------------------------------------------------------------


	void SetTypeFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity type from keyboard.
	//	Pre:	none.
	//	Post:	commodity type is set.
	//--------------------------------------------------------------------


	void SetDateFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity date from keyboard
	//	Pre:	none.
	//	Post:	commodity date is set.
	//--------------------------------------------------------------------


	void SetNameFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity name from keyboard
	//	Pre:	none.
	//	Post:	commodity name is set.
	//--------------------------------------------------------------------


	void SetSerialFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity serial from keyboard
	//	Pre:	none.
	//	Post:	commodity serial is set.
	//--------------------------------------------------------------------


	void SetNumFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity number from keyboard.
	//	Pre:	none.
	//	Post:	commodity number is set.
	//--------------------------------------------------------------------


	void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record from keyboard.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//--------------------------------------------------------------------


	int ReadDataFromFile(ifstream& fin);
	//--------------------------------------------------------------------
	//	Brief:	Read a record from a file.
	//	Pre:	the target file is opened.
	//	Post:	student record is set.
	//	Param:	fin		file descriptor.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int WriteDataToFile(ofstream& fout);
	//--------------------------------------------------------------------
	//	Brief:	Write a record into file.
	//	Pre:	the target file is opened, and the list is initialized.
	//	Post:	the target file includes new record.
	//	Param:	fout		file descriptor.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	RelationType Compare_Serial(const ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Compare two itemtypes by item serial number.
	//	Pre:	two items should be initialized.
	//	Post:	the target file includes the new item record.
	//	Param:	data		target item for comparing.
	//	Return:	return LESS if this.Serial < data.Serial,
	//				   EQUAL if this.Serial == data.Serial,
	//				   GREATER if this.Serial > data.Serial.
	//--------------------------------------------------------------------


	/*
	RelationType Compare_Type(const ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Compare two itemtypes by item type.
	//	Pre:	two items should be initialized.
	//	Post:	the target file includes the new item record.
	//	Param:	data		target item for comparing.
	//	Return:	return LESS if this.Type < data.Type,
	//				   EQUAL if this.Type == data.Type,
	//				   GREATER if this.Type > data.Type.
	//--------------------------------------------------------------------
	RelationType Compare_Name(const ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Compare two itemtypes by item name.
	//	Pre:	two items should be initialized.
	//	Post:	the target file includes the new item record.
	//	Param:	data		target item for comparing.
	//	Return:	return LESS if this.Name < data.Name,
	//				   EQUAL if this.Name == data.Name,
	//				   GREATER if this.Name > data.Name.
	//--------------------------------------------------------------------
	*/


	int PushOnFullStack();


	int PopOnEmptyStack();


	int EmptyQueue();


	int FullQueue();


	
private:
	int Type;
	int Date;
	string Name;
	int Serial;
	int Num;
};

#endif _ITEMTYPE_H_