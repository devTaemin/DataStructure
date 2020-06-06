#include "Pch.h"


StorageType::StorageType()
{
	m_StorageID = -1;
	m_StorageLocation = "";
}


StorageType::~StorageType() {}


// Get Storage ID.
int StorageType::GetID() const
{
	return m_StorageID;
}


// Get Storage location.
string StorageType::GetStorageLocation() const
{
	return m_StorageLocation;
}


// Set Storage id.
void StorageType::SetStorageID(int inStorageID)
{
	m_StorageID = inStorageID;
}


// Set Storage location.
void StorageType::SetStorageLocation(string inStorageLocation)
{
	m_StorageLocation = inStorageLocation;
}


// Set Storage record.
void StorageType::SetRecord(int inStorageID, string inStorageLocation)
{
	SetStorageID(inStorageID);
	SetStorageLocation(inStorageLocation);
}


// Set Storage id from keyboard.
void StorageType::SetStorageIDFromKB()
{
	cout << "\tS-ID       : ";
	cin >> m_StorageID;
}


// Set Storage location from keyboard.
void StorageType::SetStorageLocationFromKB()
{
	cout << "\tS-Location : ";
	cin >> m_StorageLocation;
}


//	Set Storage record from keyboard.
void StorageType::SetStorageRecordFromKB()
{
	SetStorageIDFromKB();
	SetStorageLocationFromKB();
}


// Display Storage id on screen.
void StorageType::DisplayStorageIDOnScreen()
{
	cout << "\tS-ID       : " << m_StorageID << endl;
}


// Display Storage location on screen.
void StorageType::DisplayStorageLocationOnScreen()
{
	cout << "\tS-Location : " << m_StorageLocation << endl;
}


// Display container record on screen.
void StorageType::DisplayStorageRecordOnScreen()
{
	DisplayStorageIDOnScreen();
	DisplayStorageLocationOnScreen();
}
