#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*	Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };


/**
*	Item information class.
*/
class ItemType
{
public:
	/**
	*	Default constructor.
	*/
	ItemType()
	{
		m_Id = -1;
		m_sName = "";
		m_sAddress = "";
	}


	/**
	*	Destructor.
	*/
	~ItemType() {}


	/**
	*	@brief	Get student id.
	*	@pre	student id is set.
	*	@post	none.
	*	@return	student id.
	*/
	int GetId() const;


	/**
	*	@brief	Get student name.
	*	@pre	student name is set.
	*	@post	none.
	*	@return	student name.
	*/
	string GetName() const;


	/**
	*	@brief	Get student address.
	*	@pre	student address is set.
	*	@post	none.
	*	@return	student address.
	*/
	string GetAddress() const;


	/**
	*	@brief	Set student Id.
	*	@pre	none.
	*	@post	student id is set.
	*	@param	inId	student id.
	*/
	void SetId(int inId);


	/**
	*	@brief	Set student name.
	*	@pre	none.
	*	@post	student name is set.
	*	@param	inName	student name.
	*/
	void SetName(string inName);


	/**
	*	@brief	Set student address.
	*	@pre	none.
	*	@post	student address is set.
	*	@param	inAddress	student address.
	*/
	void SetAddress(string inAddress);


	/**
	*	@brief	Set student record.
	*	@pre	none.
	*	@post	student record is set.
	*	@param	inId		student id.
	*	@param	inName		student name.
	*	@param	inAddress	student address.
	*/
	void SetRecord(int inId, string inName, string inAddress);


	/**
	*	@brief	Display student id on screen.
	*	@pre	student id is set.
	*	@post	student id is on screen.
	*/
	void DisplayIdOnScreen();


	/**
	*	@brief	Display student name on screen.
	*	@pre	student name is set.
	*	@post	student name is on screen.
	*/
	void DisplayNameOnScreen();


	/**
	*	@brief	Display student address on screen.
	*	@pre	student address is set.
	*	@post	student address is on screen.
	*/
	void DisplayAddressOnScreen();


	/**
	*	@brief	Display a student record on screen.
	*	@pre	student record is set.
	*	@post	student record is on screen.
	*/
	void DisplayRecordOnScreen();


	/**
	*	@brief	Set student id from keyboard.
	*	@pre	none.
	*	@post	student id is set.
	*/
	void SetIdFromKB();


	/**
	*	@brief	Set student name from keyboard.
	*	@pre	none.
	*	@post	student name is set.
	*/
	void SetNameFromKB();


	/**
	*	@brief	Set student address from keyboard.
	*	@pre	none.
	*	@post	student address is set.
	*/
	void SetAddressFromKB();


	/**
	*	@brief	Set student record from keyboard.
	*	@pre	none.
	*	@post	student record is set.
	*/
	void SetRecordFromKB();


	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	student record is set.
	*	@param	fin		file descriptor.
	*	@return	return 1 if this function works well, otherwise -1.
	*/
	int ReadDataFromFile(ifstream& fin);


	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. and the list should be initialized.
	*	@post	the target file includes the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise -1.
	*/
	int WriteDataToFIle(ofstream& fout);


	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file includes the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByID(const ItemType& data);


	/**
	*	@brief	Compare id by operator==.
	*	@pre	two items should be initialized.
	*	@post	none.
	*	@param	A	target item for comparing
	*	@return	return true if this.m_Id == A.id,
	*			return false if this.m_id != A.id.
	*/
	bool operator==(const ItemType& A);


	/**
	*	@brief	Copy the rocord by operator=.
	*	@pre	object's record, which is going to be copied, should be initialized.
	*	@post	target record is copied from object record
	*	@param	_item	target item for copying
	*/
	void operator=(const ItemType& _item);


private:
	int m_Id;			///< student ID.
	string m_sName;		///< student Name.
	string m_sAddress;	///< student Address.
};

#endif _ITEMTYPE_H_