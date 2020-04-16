#include "pch.h"
#include "ItemType.h"


// Get container id.
int ItemType::GetContainerID()
{
	return m_ContainerID;
}


// Get commodity serial.
int ItemType::GetSerial()
{
	return m_Serial;
}


// Get commodity name.
string ItemType::GetName()
{
	return m_Name;
}


// Get commodity number.
int ItemType::GetNum()
{
	return m_Num;
}


// Get commodity usage.
string ItemType::GetUsage()
{
	return m_Usage;
}


// Get commodity date.
int ItemType::GetDate()
{
	return m_Date;
}


// Set container id.
void ItemType::SetContainerID(int inContainerID)
{
	m_ContainerID = inContainerID;
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


// Set commodity type.
void ItemType::SetUsage(string inUsage)
{
	m_Usage = inUsage;
}


// Set commodity date.
void ItemType::SetDate(int inDate)
{
	m_Date = inDate;
}


// Set commodity record.
void ItemType::SetRecord(int inContainerID, int inSerial, string inName, int inNum, string inUsage, int inDate)
{
	SetContainerID(inContainerID);
	SetSerial(inSerial);
	SetName(inName);
	SetNum(inNum);
	SetUsage(inUsage);
	SetDate(inDate);
}


// Display container id on screen.
void ItemType::DisplayContainerIDOnScreen()
{
	cout << "\tC-ID   : " << m_ContainerID << endl;
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


// Display commodity usage on screen.
void ItemType::DisplayUsageOnScreen()
{
	cout << "\tUsage  : " << m_Usage << endl;
};


// Display commodity date on screen.
void ItemType::DisplayDateOnScreen()
{
	cout << "\tDate   : " << m_Date << endl;
};


// Display a commodity record on screen.
void ItemType::DisplayRecordOnScreen()
{
	DisplayContainerIDOnScreen();
	DisplaySerialOnScreen();
	DisplayNameOnScreen();
	DisplayNumOnScreen();
	DisplayUsageOnScreen();
	DisplayDateOnScreen();
};


// Set container id from keyboard.
void ItemType::SetContainerIDFromKB()
{
	cout << "\tC-ID   : ";
	cin >> m_ContainerID;
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


// Set commodity usage from keyboard.
void ItemType::SetUsageFromKB()
{
	cout << "\tUsage  : ";
	cin >> m_Usage;
}


// Set commodity date from keyboard.
void ItemType::SetDateFromKB()
{
	cout << "\tDate   : ";
	cin >> m_Date;
}


// Set commodity record from keyboard.
void ItemType::SetRecordFromKB()
{
	SetContainerIDFromKB();
	SetSerialFromKB();
	SetNameFromKB();
	SetNumFromKB();
	SetUsageFromKB();
	SetDateFromKB();
}


// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_ContainerID;
	fin >> m_Serial;
	fin >> m_Name;
	fin >> m_Num;
	fin >> m_Usage;
	fin >> m_Date;

	return 1;
};


// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_ContainerID << " ";
	fout << m_Serial << " ";
	fout << m_Name << " ";
	fout << m_Num << " ";
	fout << m_Usage << " ";
	fout << m_Date;

	return 1;
}


// Compare two itemtypes by Serial.
RelationType ItemType::Compare(const ItemType& data)
{
	if (this->m_Serial > data.m_Serial)
		return GREATER;
	else if (this->m_Serial < data.m_Serial)
		return LESS;
	else
		return EQUAL;
}