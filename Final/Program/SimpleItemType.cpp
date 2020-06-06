#include "Pch.h"


// Get commodity serial.
int SimpleItemType::GetID() const
{
	return m_Serial;
}


// Get commodity name.
string SimpleItemType::GetName() const
{
	return m_Name;
}



// Set commodity serial.
void SimpleItemType::SetSerial(int inSerial)
{
	m_Serial = inSerial;
}


// Set commodity name.
void SimpleItemType::SetName(string inName)
{
	m_Name = inName;
}



// Set commodity record.
void SimpleItemType::SetRecord(int inSerial, string inName)
{
	SetSerial(inSerial);
	SetName(inName);
}


// Set commodity serial from keyboard.
void SimpleItemType::SetSerialFromKB()
{
	cout << "\tSerial : ";
	cin >> m_Serial;
}


// Set commodity name from keyboard.
void SimpleItemType::SetNameFromKB()
{
	cout << "\tName   : ";
	cin >> m_Name;
}


// Set commodity record from keyboard.
void SimpleItemType::SetRecordFromKB()
{
	SetSerialFromKB();
	SetNameFromKB();
}


// Display commodity serial on screen.
void SimpleItemType::DisplaySerialOnScreen()
{
	cout << "\tSerial : " << m_Serial << endl;
};


// Display commodity name on screen.
void SimpleItemType::DisplayNameOnScreen()
{
	cout << "\tName   : " << m_Name << endl;
};



// Display a commodity record on screen.
void SimpleItemType::DisplayRecordOnScreen()
{
	cout << endl;
	cout << "--------------------------" << endl;
	DisplaySerialOnScreen();
	DisplayNameOnScreen();
	cout << "--------------------------" << endl;
};


// Read a record from file.
int SimpleItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Serial;
	fin >> m_Name;

	return 1;
};


// Write a record into file.
int SimpleItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Serial << " ";
	fout << m_Name << " ";

	return 1;
}


// Get an information from itemType.
void SimpleItemType::GetRecordFromItemType(ItemType*& _item)
{
	m_Serial = _item->GetID();
	m_Name = _item->GetName();
}