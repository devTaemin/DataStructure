#include "ItemType.h"
#include "pch.h"

// Get commodity type.
int ItemType::GetType()
{
	return m_Type;
}


// Get commodity date.
int ItemType::GetDate()
{
	return m_Date;
}


// Get commodity name.
string ItemType::GetName()
{
	return m_Name;
}


// Get commodity serial.
int ItemType::GetSerial()
{
	return m_Serial;
}


// Get commodity number.
int ItemType::GetNum()
{
	return m_Num;
}


// Set commodity type.
void ItemType::SetType(int inType)
{
	m_Type = inType;
}


// Set commodity date.
void ItemType::SetDate(int inDate)
{
	m_Date = inDate;
}


// Set commodity name.
void ItemType::SetName(string inName)
{
	m_Name = inName;
}


// Set commodity serial.
void ItemType::SetSerial(int inSerial)
{
	m_Serial = inSerial;
}


// Set commodity number.
void ItemType::SetNum(int inNum)
{
	m_Num = inNum;
}


// Set commodity record.
void ItemType::SetRecord(int inType, int inDate, string inName, int inSerial, int inNum)
{
	SetType(inType);
	SetDate(inDate);
	SetName(inName);
	SetSerial(inSerial);
	SetNum(inNum);
}


// Display commodity type on screen.
void ItemType::DisplayTypeOnScreen()
{
	cout << "\tType   : " << m_Type << endl;
};


// Display commodity date on screen.
void ItemType::DisplayDateOnScreen()
{
	cout << "\tDate   : " << m_Date << endl;
};


// Display commodity name on screen.
void ItemType::DisplayNameOnScreen()
{
	cout << "\tName   : " << m_Name << endl;
};


// Display commodity serial on screen.
void ItemType::DisplaySerialOnScreen()
{
	cout << "\tSerial : " << m_Serial << endl;
};


// Display commodity number on screen.
void ItemType::DisplayNumOnScreen()
{
	cout << "\tNumber : " << m_Num << endl;
};


// Display a commodity record on screen.
void ItemType::DisplayRecordOnScreen()
{
	DisplayTypeOnScreen();
	DisplayDateOnScreen();
	DisplayNameOnScreen();
	DisplaySerialOnScreen();
	DisplayNumOnScreen();
};


// Set commodity type from keyboard.
void ItemType::SetTypeFromKB()
{
	int inType;
	while (1) {
		cout << "\tType (1: 필기류,  2: 공책)  : ";
		cin >> inType;
		if (inType == 1 || inType == 2) {
			SetType(inType);
			break;
		}
		else {
			cout << "\tWrong Type!" << '\n';
		}
	}
}


// Set commodity date from keyboard.
void ItemType::SetDateFromKB()
{
	cout << "\tDate   : ";
	cin >> m_Date;
}


// Set commodity name from keyboard.
void ItemType::SetNameFromKB()
{
	cout << "\tName   : ";
	cin >> m_Name;
}


// Set commodity serial from keyboard.
void ItemType::SetSerialFromKB()
{
	cout << "\tSerial : ";
	cin >> m_Serial;
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
	SetTypeFromKB();
	SetDateFromKB();
	SetNameFromKB();
	SetSerialFromKB();
	SetNumFromKB();
}


// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Type;
	fin >> m_Date;
	fin >> m_Name;
	fin >> m_Serial;
	fin >> m_Num;

	return 1;
};


// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Type << " ";
	fout << m_Date << " ";
	fout << m_Name << " ";
	fout << m_Serial << " ";
	fout << m_Num;

	return 1;
}


// Compare two itemtypes by Serial.
RelationType ItemType::Compare_Serial(const ItemType& data)
{
	if (this->m_Serial > data.m_Serial)
		return GREATER;
	else if (this->m_Serial < data.m_Serial)
		return LESS;
	else
		return EQUAL;
}