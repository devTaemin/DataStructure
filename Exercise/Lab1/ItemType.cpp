#include "ItemType.hpp"


ItemType::ItemType() 
{
	m_Id = 0;
	m_sName = "default";
	m_sAddress = "default";
}

ItemType::~ItemType() {}

int ItemType::GetId() const 
{
	return m_Id;
}

string ItemType::GetName() 
{
	return m_sName;
}

string ItemType::GetAddress() 
{
	return m_sAddress;
}

void ItemType::SetId(int inId) 
{
	m_Id = inId;
}

void ItemType::SetName(string inName) 
{
	m_sName = inName;
}

void ItemType::SetAddress(string inAddress) 
{
	m_sAddress = inAddress;
}

void ItemType::SetRecord(int inId, string inName, string inAddress) 
{
	SetId(inId);
	SetName(inName);
	SetAddress(inAddress);
}

void ItemType::DisplayIdOnScreen() 
{
	cout << "ID: " << m_Id << endl;
}

void ItemType::DisplayNameOnScreen() 
{
	cout << "Name: " << m_sName << endl;
}

void ItemType::DisplayAddressOnScreen() 
{
	cout << "Address: " << m_sAddress << endl;
}

void ItemType::DisplayRecordOnScreen() 
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayAddressOnScreen();
}

void ItemType::SetIdFromKB()
{
	int input;
	cout << "Enter ID: ";
	cin >> input;
	SetId(input);
}

void ItemType::SetNameFromKB() 
{
	string input;
	cout << "Enter Name: ";
	cin >> input;
	SetName(input);
}

void ItemType::SetAddressFromKB()
{
	string input;
	cout << "Enter Address: ";
	cin >> input;
	SetAddress(input);
}

void ItemType::SetRecordFromKB() 
{
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}
/*
int ItemType::ReadDataFromFile(ifstream& fin) 
{
	return 0;
}

int ItemType::WriteDataToFile(ofstream& fout) 
{
	return 0;
}
*/
RelationType ItemType::CompareByID(const ItemType& data) 
{
	if (this->GetId() > data.GetId()) { return GREATER; }
	else if (this->GetId() < data.GetId()) { return LESS; }
	else { return EQUAL; }
}