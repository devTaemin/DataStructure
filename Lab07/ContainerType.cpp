/*
#include "Pch.h"


ContainerType::ContainerType()
{
	m_ContainerID = -1;
	m_ContainerLocation = "";
}


ContainerType::~ContainerType() {}



// Get Container ID.
int ContainerType::GetContainerID() const
{
	return m_ContainerID;
}


// Get Container location.
string ContainerType::GetContainerLocation() const
{
	return m_ContainerLocation;
}


// Set container id.
void ContainerType::SetContainerID(int inContainerID)
{
	m_ContainerID = inContainerID;
}


// Set container location.
void ContainerType::SetContainerLocation(string inContainerLocation)
{
	m_ContainerLocation = inContainerLocation;
}


// Set container record.
void ContainerType::SetRecord(int inContainerID, string inContainerLocation)
{
	SetContainerID(inContainerID);
	SetContainerLocation(inContainerLocation);
}


// Set container id from keyboard.
void ContainerType::SetContainerIDFromKB()
{
	cout << "\tC-ID       : ";
	cin >> m_ContainerID;
}


// Set container location from keyboard.
void ContainerType::SetContainerLocationFromKB()
{
	cout << "\tC-Location : ";
	cin >> m_ContainerLocation;
}


//	Set container record from keyboard.
void ContainerType::SetContainerRecordFromKB()
{
	SetContainerIDFromKB();
	SetContainerLocationFromKB();
}


// Display container id on screen.
void ContainerType::DisplayContainerIDOnScreen()
{
	cout << "\tC-ID       : " << m_ContainerID << endl;
}


// Display container location on screen.
void ContainerType::DisplayContainerLocationOnScreen()
{
	cout << "\tC-Location : " << m_ContainerLocation << endl;
}


// Display container record on screen.
void ContainerType::DisplayContainerRecordOnScreen()
{
	DisplayContainerIDOnScreen();
	DisplayContainerLocationOnScreen();
}
*/