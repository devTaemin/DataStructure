#include "ItemType.h"


// Get student id.
int ItemType::GetId()
{
	return m_Id;
}


// Get student name.
string ItemType::GetName()
{
	return m_sName;
}


// Get student address
string ItemType::GetAddress()
{
	return m_sAddress;
}


// Set student id.
void ItemType::SetId(int inId)
{
	m_Id = inId;
}


// Set student name.
void ItemType::SetName(string inName)
{
	m_sName = inName;
}


// Set student address.
void ItemType::SetAddress(string inAddress)
{
	m_sAddress = inAddress;
}


// Set student record.
void ItemType::SetRecord(int inId, string inName, string inAddress)
{
	SetId(inId);
	SetName(inName);
	SetAddress(inAddress);
}


// Display student id on screen.
void ItemType::DisplayIdOnScreen()
{
	cout << "\tID   : " << m_Id << endl;
};


// Display student name on screen.
void ItemType::DisplayNameOnScreen()
{
	cout << "\tName : " << m_sName << endl;
};


// Display student address on screen.
void ItemType::DisplayAddressOnScreen()
{
	cout << "\tAddress : " << m_sAddress << endl;
};


// Display an student record on screen.
void ItemType::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayAddressOnScreen();
};


// Set student id from keyboard.
void ItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> m_Id;
}


// Set student name from keyboard.
void ItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}


// Set student address from keyboard.
void ItemType::SetAddressFromKB()
{
	cout << "\tAddress : ";
	cin >> m_sAddress;
}


// Set student record from keyboard.
void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}


// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Id;
	fin >> m_sName;
	fin >> m_sAddress;

	return 1;
};


// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Id << " ";
	fout << m_sName << " ";
	fout << m_sAddress;

	return 1;
}


// Compare two itemtypes.
RelationType ItemType::Compare(const ItemType& data)
{
	if (this->m_Id > data.m_Id)
		return GREATER;
	else if (this->m_Id < data.m_Id)
		return LESS;
	else
		return EQUAL;
}