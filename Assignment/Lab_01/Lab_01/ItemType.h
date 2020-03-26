#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


enum RelationType { LESS, GREATER, EQUAL };
/**
*	Relation between two items 
*/

class ItemType
{
public:

	ItemType();													// default constructor
	~ItemType();												// destructor

	int GetId();												
	string GetName();
	void SetId(int inId);
	void SetName(string inName);
	void SetAddress(string inAddress);
	void SetRecord(int inId, string inName, string inAddress);
	void DisplayIdOnScreen();
	void DisplayNameOnScreen();
	void DisplayAddressOnScreen();
	void DisplayRecordOnScreen();
	void SetIdFromKB();
	void SetNameFromKB();
	void SetAddressFromKB();
	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);
	RelationType CompareByID(const ItemType& data);

private:
	int m_Id;
	string m_sName;
	string m_sAddress;
};

#endif _ITEMTYPE_H_