#include "ItemType.h"


// Get commodity type.
int ItemType::GetType()
{
	return Type;
}


// Get commodity date.
int ItemType::GetDate()
{
	return Date;
}


// Get commodity name.
string ItemType::GetName()
{
	return Name;
}


// Get commodity serial.
int ItemType::GetSerial()
{
	return Serial;
}


// Get commodity number.
int ItemType::GetNum()
{
	return Num;
}


// Set commodity type.
void ItemType::SetType(int inType)
{
	Type = inType;
}


// Set commodity date.
void ItemType::SetDate(int inDate)
{
	Date = inDate;
}


// Set commodity name.
void ItemType::SetName(string inName)
{
	Name = inName;
}


// Set commodity serial.
void ItemType::SetSerial(int inSerial)
{
	Serial = inSerial;
}


// Set commodity number.
void ItemType::SetNum(int inNum)
{
	Num = inNum;
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
	cout << "\tType   : " << Type << endl;
};


// Display commodity date on screen.
void ItemType::DisplayDateOnScreen()
{
	cout << "\tDate   : " << Date << endl;
};


// Display commodity name on screen.
void ItemType::DisplayNameOnScreen()
{
	cout << "\tName   : " << Name << endl;
};


// Display commodity serial on screen.
void ItemType::DisplaySerialOnScreen()
{
	cout << "\tSerial : " << Serial << endl;
};


// Display commodity number on screen.
void ItemType::DisplayNumOnScreen()
{
	cout << "\tNumber : " << Num << endl;
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
		cout << "\tType (1. 필기류, 2. 책)  : ";
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
	cin >> Date;
}


// Set commodity name from keyboard.
void ItemType::SetNameFromKB()
{
	cout << "\tName   : ";
	cin >> Name;
}


// Set commodity serial from keyboard.
void ItemType::SetSerialFromKB()
{
	cout << "\tSerial : ";
	cin >> Serial;
}


// Set commodity number from keyboard.
void ItemType::SetNumFromKB()
{
	cout << "\tNumber : ";
	cin >> Num;
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
	fin >> Type;
	fin >> Date;
	fin >> Name;
	fin >> Serial;
	fin >> Num;

	return 1;
};


// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << Type << " ";
	fout << Date << " ";
	fout << Name << " ";
	fout << Serial << " ";
	fout << Num;

	return 1;
}


// Compare two itemtypes by Serial.
RelationType ItemType::Compare_Serial(const ItemType& data)
{
	if (this->Serial > data.Serial)
		return GREATER;
	else if (this->Serial < data.Serial)
		return LESS;
	else
		return EQUAL;
}

/*
//Compare two itemtypes by Type.
RelationType ItemType::Compare_Type(const ItemType& data)
{
	if (this->Type > data.Type)
		return GREATER;
	else if (this->Type < data.Type)
		return LESS;
	else
		return EQUAL;
}


//Compare two itemtypes by Name.
RelationType ItemType::Compare_Name(const ItemType& data)
{
	if (this->Name > data.Name)
		return GREATER;
	else if (this->Name < data.Name)
		return LESS;
	else
		return EQUAL;
}
*/