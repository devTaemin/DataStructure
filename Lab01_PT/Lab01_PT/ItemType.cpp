#include "ItemType.h"


// Get student id.
int ItemType::GetId() const
{
	return m_Id;
}


// Get student name.
string ItemType::GetName() const
{
	return m_sName;
}


// Get student address.
string ItemType::GetAddress() const
{
	return m_sAddress;
}


// Set student Id.
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
	cout << "\tID	: " << m_Id << '\n';
}


// Display student name on screen.
void ItemType::DisplayNameOnScreen()
{
	cout << "\tName	: " << m_sName << '\n';
}


// Display student address on screen.
void ItemType::DisplayAddressOnScreen()
{
	cout << "\tAddress : " << m_sAddress << '\n';
}


// Display a student record on screen.
void ItemType::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayAddressOnScreen();
}


// Set student id from keyboard.
void ItemType::SetIdFromKB()
{
    int inId;
    cout << "\tID : ";
    cin >> inId;
    SetId(inId);
}


// Set student name from keyboard.
void ItemType::SetNameFromKB()
{
    string inName;
    cout << "\tName : ";
    cin >> inName;
    SetName(inName);
}


// Set student address from keyboard.
void ItemType::SetAddressFromKB()
{
    string inAddress;
    cout << "\tAddress : ";
    cin >> inAddress;
    SetAddress(inAddress);
}


// Set student record from keyboard.
void ItemType::SetRecordFromKB()
{
    SetIdFromKB();
    SetNameFromKB();
    SetAddressFromKB();
}


//Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin)
{
    if (fin.is_open()) {
        fin >> m_Id;
        fin >> m_sName;
        fin >> m_sAddress;
        return 1;
    }
    else {
        return -1;
    }
}


// Write a record into file.
int ItemType::WriteDataToFIle(ofstream& fout)
{
    if (fout.is_open()) {
        fout << m_Id << " ";
        fout << m_sName << " ";
        fout << m_sAddress << " ";
        fout << '\n';
        return 1;
    }
    else {
        return -1;
    }
}


// Compare two itemtypes.
RelationType ItemType::CompareByID(const ItemType& data)
{
    if (this->GetId() > data.GetId()) {
        return GREATER;
    }
    else if (this->GetId() < data.GetId()) {
        return LESS;
    }
    else { return EQUAL; }
}


// Compare id by operator==.
bool ItemType::operator==(const ItemType& A)
{
    if (m_Id == A.GetId())
        return true;
    return false;
}


// Copy the rocord by operator=.
void ItemType::operator=(const ItemType& _item)
{
    m_Id = _item.GetId();
    m_sName = _item.GetName();
    m_sAddress = _item.GetAddress();
}
