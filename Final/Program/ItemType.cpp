#include "Pch.h"


// Get commodity serial.
int ItemType::GetID() const
{
	return m_Serial;
}


// Get commodity name.
string ItemType::GetName() const
{
	return m_Name;
}


// Get commodity number.
int ItemType::GetNum() const
{
	return m_Num;
}


// Set commodity serial.
void ItemType::SetSerial(int inSerial)
{
	m_Serial = inSerial;
}


// Set commodity name.
void ItemType::SetName(string inName)
{
	m_Name = inName;
}


// Set commodity number.
void ItemType::SetNum(int inNum)
{
	m_Num = inNum;
}


// Set commodity record.
void ItemType::SetRecord(int inSerial, string inName, int inNum)
{
	SetSerial(inSerial);
	SetName(inName);
	SetNum(inNum);
}


// Set commodity serial from keyboard.
void ItemType::SetSerialFromKB()
{
	cout << "\tSerial : ";
	cin >> m_Serial;
}


// Set commodity name from keyboard.
void ItemType::SetNameFromKB()
{
	cout << "\tName   : ";
	cin >> m_Name;
}


// Set commodity number from keyboard.
void ItemType::SetNumFromKB()
{
	cout << "\tNumber : ";
	cin >> m_Num;
}


// Set commodity record from keyboard.
void ItemType::SetRecordFromKB()
{
	SetSerialFromKB();
	SetNameFromKB();
	SetNumFromKB();
}


// Display commodity serial on screen.
void ItemType::DisplaySerialOnScreen()
{
	cout << "\tSerial : " << m_Serial << endl;
};


// Display commodity name on screen.
void ItemType::DisplayNameOnScreen()
{
	cout << "\tName   : " << m_Name << endl;
};


// Display commodity number on screen.
void ItemType::DisplayNumOnScreen()
{
	cout << "\tNumber : " << m_Num << endl;
};


// Display a commodity record on screen.
void ItemType::DisplayRecordOnScreen()
{
	cout << endl;
	cout << "--------------------------" << endl;
	DisplaySerialOnScreen();
	DisplayNameOnScreen();
	DisplayNumOnScreen();
	cout << "--------------------------" << endl;
};


// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Serial;
	fin >> m_Name;
	fin >> m_Num;

	return 1;
};


// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Serial << " ";
	fout << m_Name << " ";
	fout << m_Num << " ";

	return 1;
}