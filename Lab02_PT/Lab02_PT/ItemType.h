#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType { LESS, EQUAL, GREATER };
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
		m_Id = -1;
		m_sName = "";
		m_sAddress = "";
	}


	~ItemType() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	int GetId() const;
	//--------------------------------------------------------------------
	//	Brief:	Get student id.
	//	Pre:	student id is set.
	//	Post:	none.
	//	Return: student id.
	//--------------------------------------------------------------------


	string GetName() const;
	//--------------------------------------------------------------------
	//	Brief:	Get student name.
	//	Pre:	student name is set.
	//	Post:	none.
	//	Return:	student name.
	//--------------------------------------------------------------------


	string GetAddress() const;
	//--------------------------------------------------------------------
	//	Brief:	Get student address.
	//	Pre:	student address is set.
	//	Post:	none.
	//	Return:	student address.
	//--------------------------------------------------------------------

	void SetId(int inId);
	//--------------------------------------------------------------------
	//	Brief:	Set student id.
	//	Pre:	none.
	//	Post:	student id is set.
	//	Param:	inId		studnet id.
	//--------------------------------------------------------------------


	void SetName(string inName);
	//--------------------------------------------------------------------
	//	Brief:	Set student name.
	//	Pre:	none.
	//	Post:	student name is set.
	//	Param	inName		student name.
	//--------------------------------------------------------------------


	void SetAddress(string inAddress);
	//--------------------------------------------------------------------
	//	Brief:	Set student address.
	//	Pre:	none.
	//	Post:	student address is set.
	//	Param:	inAddress		student address.
	//--------------------------------------------------------------------


	void SetRecord(int inId, string inName, string inAddress);
	//--------------------------------------------------------------------
	//	Brief:	Set student record.
	//	Pre:	none.
	//	Post:	student record is set.
	//	Param:	inId		student id.
	//	Param	inName		student name.
	//	Param:	inAddress		student address.
	//--------------------------------------------------------------------


	void DisplayIdOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display student id on screen.
	//	Pre:	student id is set.
	//	Post:	student id is on screen.
	//--------------------------------------------------------------------


	void DisplayNameOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display student name on screen.
	//	Pre:	student name is set.
	//	Post:	student name is on screen.
	//--------------------------------------------------------------------


	void DisplayAddressOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display student address on screen.
	//	Pre:	student address is set.
	//	Post:	student address is on screen.
	//--------------------------------------------------------------------


	void DisplayRecordOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display student record on screen.
	//	Pre:	student record is set.
	//	Post:	student record is on screen.
	//--------------------------------------------------------------------


	void SetIdFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set student id from keyboard.
	//	Pre:	none.
	//	Post:	student id is set.
	//--------------------------------------------------------------------


	void SetNameFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set student name from keyboard
	//	Pre:	none.
	//	Post:	student name is set.
	//--------------------------------------------------------------------


	void SetAddressFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set student address from keyboard.
	//	Pre:	none.
	//	Post:	student address is set.
	//--------------------------------------------------------------------


	void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set student record from keyboard.
	//	Pre:	none.
	//	Post:	student record is set.
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


	RelationType Compare(const ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Compare two itemtypes by item id.
	//	Pre:	two items should be initialized.
	//	Post:	the target file includes the new item record.
	//	Param:	data		target item for comparing.
	//	Return:	return LESS if this.id < data.id,
	//				   EQUAL if this.id == data.id,
	//				   GREATER if this.id > data.id.
	//--------------------------------------------------------------------


	bool operator==(const ItemType& A);
	//--------------------------------------------------------------------
	//	Brief:	Compare id by operator==.
	//	Pre:	both items' serial number should be set.
	//	Post:	none.
	//	Param:	A		target item for comparing.
	//	Return:	return true if this.id == A.id,
	//				   false if this.id != A.id.
	//--------------------------------------------------------------------


	void operator=(const ItemType& _item);
	//--------------------------------------------------------------------
	//	Brief:	Copy the record by operator=.
	//	Pre:	target item's record, going to be copied, should be set.
	//	Post:	a record is copied from target item.
	//	Param:	_item		the target item.
	//--------------------------------------------------------------------


private:
	int m_Id;			///< item ID.
	string m_sName;		///< item name.
	string m_sAddress;	///< item address.
};

#endif _ITEMTYPE_H_