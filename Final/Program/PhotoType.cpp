#include "Pch.h"


// Set photo id from keyboard.
void PhotoType::SetPhotoIDFromKB()
{
	cout << "\tPhoto ID: ";
	cin >> m_PhotoID;
}


// Set photo record from keyboard.
void PhotoType::SetPhotoRecordFromKB()
{
	cout << "\tPhoto ID: ";
	cin >> m_PhotoID;
	cout << "\tPhoto Address: ";
	cin >> m_address;
}


// Add photo information.
void PhotoType::AddPhoto()
{
	cout << "\tEnter the ID of photo: ";
	cin >> m_PhotoID;
	cout << "\tEnter the address of photo: ";
	cin >> m_address;
	m_found = true;
}


// Delete photo information.
void PhotoType::DeletePhoto()
{
	m_address = "";
	m_found = false;
}


// Update photo information.
void PhotoType::UpdatePhoto()
{
	if (m_found == true)
	{
		cout << "\tEnter the address of photo: ";
		cin >> m_address;
	}
	else
	{
		cout << "\t[ERROR: NO PHOTO TO UPDATE]" << endl;
	}
}


// Display photo on the screen.
void PhotoType::DisplayPhoto()
{
	if (m_found == true)
	{
		cout << "\t[PHOTO] : " << m_address << endl;
	}
	else
	{
		cout << "\t[ERROR: NO PHOTO TO DISPLAY]" << endl;
	}
}