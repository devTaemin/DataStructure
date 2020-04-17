#include "pch.h"


ContainerType::ContainerType()
{
	c_Id = -1;
	c_Location = "";
}


ContainerType::~ContainerType() {}



// Get Container ID.
int ContainerType::GetContainerID() const
{
	return c_Id;
}


// Get Container location.
string ContainerType::GetContainerLocation() const
{
	return c_Location;
}


// Set container id.
void ContainerType::SetContainerID(int inContainerID)
{
	c_Id = inContainerID;
}


// Set container location.
void ContainerType::SetContainerLocation(string inContainerLocation)
{
	c_Location = inContainerLocation;
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
	cin >> c_Id;
}


// Set container location from keyboard.
void ContainerType::SetContainerLocationFromKB()
{
	cout << "\tC-Location : ";
	cin >> c_Location;
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
	cout << "\tC-ID       : " << c_Id << endl;
}


// Display container location on screen.
void ContainerType::DisplayContainerLocationOnScreen()
{
	cout << "\tC-Location : " << c_Location << endl;
}


// Display container record on screen.
void ContainerType::DisplayContainerRecordOnScreen()
{
	DisplayContainerIDOnScreen();
	DisplayContainerLocationOnScreen();
}