#ifndef _ItemType_hpp_
#define _ItemType_hpp_
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
enum RelationType { LESS, GREATER, EQUAL };

class ItemType
{
public:
	ItemType();
	~ItemType();

	int GetId();
	string GetName();
	string GetAddress();
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


#endif