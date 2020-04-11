#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType { LESS, EQUAL, GREATER };


class ItemType
{
public:
	// Default Constructor.
	ItemType()
	{
		m_Id = -1;
		m_Name = "";
		m_Address = "";
	}


	// Destructor.
	~ItemType() {}


	// Get functions
	int GetId() const;


	string GetName() const;


	string GetAddress() const;


	// Set functions
	void SetId(int inId);


	void SetName(string inName);


	void SetAddress(string inAddress);


	void SetRecord(int inId, string inName, string inAddress);


	// Display functions
	void DisplayIdOnScreen();


	void DisplayNameOnScreen();


	void DisplayAddressOnScreen();


	void DisplayRecordOnScreen();


	// Set from KB
	void SetIdFromKB();


	void SetNameFromKB();


	void SetAddressFromKB();


	void SetRecordFromKB();


	// File functions
	int ReadDataFromFile(ifstream& fin);


	int WriteDataToFile(ofstream& fout);


	// Compare functions
	RelationType CompareByID(const ItemType& inData);


private:
	int m_Id;
	string m_Name;
	string m_Address;
};
#endif _ITEMTYPE_H_