#include "pch.h"
#include "SimpleItemType.h"


// Get container id.
int SimpleItemType::GetContainerID()
{
	return s_ContainerID;
}


// Get commodity serial.
int SimpleItemType::GetSerial()
{
	return s_Serial;
}


// Get commodity name.
string SimpleItemType::GetName()
{
	return s_Name;
}


// Set container id.
void SimpleItemType::SetContainerID(int inContainerID)
{
	s_ContainerID = inContainerID;
}


// Set commodity serial.
void SimpleItemType::SetSerial(int inSerial)
{
	s_Serial = inSerial;
}


// Set commodity name.
void SimpleItemType::SetName(string inName)
{
	s_Name = inName;
}


// Set commodity record.
void SimpleItemType::SetRecord(int inContainerID, int inSerial, string inName)
{
	SetContainerID(inContainerID);
	SetSerial(inSerial);
	SetName(inName);
}


// Display container id on screen.
void SimpleItemType::DisplayContainerIDOnScreen()
{
	cout << "\tC-ID   : " << s_ContainerID << endl;
}


// Display commodity serial on screen.
void SimpleItemType::DisplaySerialOnScreen()
{
	cout << "\tSerial : " << s_Serial << endl;
};


// Display commodity name on screen.
void SimpleItemType::DisplayNameOnScreen()
{
	cout << "\tName   : " << s_Name << endl;
};


// Display a commodity record on screen.
void SimpleItemType::DisplayRecordOnScreen()
{
	DisplayContainerIDOnScreen();
	DisplaySerialOnScreen();
	DisplayNameOnScreen();
};


// Set container id from keyboard.
void SimpleItemType::SetContainerIDFromKB()
{
	cout << "\tC-ID   : ";
	cin >> s_ContainerID;
}


// Set commodity serial from keyboard.
void SimpleItemType::SetSerialFromKB()
{
	cout << "\tSerial : ";
	cin >> s_Serial;
}


// Set commodity name from keyboard.
void SimpleItemType::SetNameFromKB()
{
	cout << "\tName   : ";
	cin >> s_Name;
}


// Set commodity record from keyboard.
void SimpleItemType::SetRecordFromKB()
{
	SetContainerIDFromKB();
	SetSerialFromKB();
	SetNameFromKB();
}


// Read a record from file.
int SimpleItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> s_ContainerID;
	fin >> s_Serial;
	fin >> s_Name;

	return 1;
};


// Write a record into file.
int SimpleItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << s_ContainerID << " ";
	fout << s_Serial << " ";
	fout << s_Name << " ";

	return 1;
}


// Compare two simpleitemtypes by Serial.
RelationType SimpleItemType::Compare(const SimpleItemType& data)
{
	if (this->s_Serial > data.s_Serial)
		return GREATER;
	else if (this->s_Serial < data.s_Serial)
		return LESS;
	else
		return EQUAL;
}


// Get the record from ItemType to SimpleItemType.
void SimpleItemType::GetRecordFromItemType(ItemType& data)
{
	int temp_Id = data.GetContainerID();
	int temp_Serial = data.GetSerial();
	string temp_Name = data.GetName();
	this->SetRecord(temp_Id, temp_Serial, temp_Name);

}