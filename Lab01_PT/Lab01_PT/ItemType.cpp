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
    int id;
    string name, address;
    fin >> id; 
    fin >> name; 
    fin >> address;
    SetId(id);
    SetName(name);
    SetAddress(address);

    return 1;
}


// Write a record into file.
int ItemType::WriteDataToFIle(ofstream& fout)
{
    fout << '\n';
    fout << this->GetId() << " ";
    fout << this->GetName() << " ";
    fout << this->GetAddress() << " ";

    return 1;
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
    if (this->GetId() == A.GetId()) {
        return true;
    }
    else { return false; }
}


// Copy the rocord by operator=.
void ItemType::operator=(const ItemType& _item)
{
    int id = _item.GetId();
    string name = _item.GetName();
    string address = _item.GetAddress();

    this->SetId(id);
    this->SetName(name);
    this->SetAddress(address);
}
