#include "Pch.h"


// Get Type number.
int ItemType::GetType() const
{
	return m_Type;
}


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


// Get commodity price.
int ItemType::GetPrice() const
{
	return m_Price;
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


// Set commodity price.
void ItemType::SetPrice(int inPrice)
{
	m_Price = inPrice;
}


// Set commodity record.
void ItemType::SetRecord(int inSerial, string inName, int inNum, int inPrice)
{
	SetSerial(inSerial);
	SetName(inName);
	SetNum(inNum);
	SetPrice(inPrice);
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


// Set commodity price from keyboard.
void ItemType::SetPriceFromKB()
{
	cout << "\tPrice : ";
	cin >> m_Price;
}


// Set commodity record from keyboard.
void ItemType::SetRecordFromKB()
{
	SetSerialFromKB();
	SetNameFromKB();
	SetNumFromKB();
	SetPriceFromKB();
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


// Display commodity price on screen.
void ItemType::DisplayPriceOnScreen()
{
	cout << "\tPrice  : " << m_Price << endl;
};


// Display a commodity record on screen.
void ItemType::DisplayRecordOnScreen()
{
	cout << endl;
	cout << "--------------------------" << endl;
	DisplaySerialOnScreen();
	DisplayNameOnScreen();
	DisplayNumOnScreen();
	DisplayPriceOnScreen();
	cout << "--------------------------" << endl;
};


// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Serial;
	fin >> m_Name;
	fin >> m_Num;
	fin >> m_Price;

	return 1;
};


// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Serial << " ";
	fout << m_Name << " ";
	fout << m_Num << " ";
	fout << m_Price << " ";

	return 1;
}