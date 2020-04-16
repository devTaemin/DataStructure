#include "pch.h"
#include "ContainerType.h"


ContainerType::ContainerType()
{
	c_Id = -1;
	c_Location = "";
}


ContainerType::~ContainerType() {}



// Get Container ID.
int ContainerType::GetContainerID()
{
	return c_Id;
}


// Get Container location.
string ContainerType::GetContainerLocation()
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


// Compare two itemtypes by Serial.
RelationType ContainerType::Compare(const ContainerType& data)
{
	if (this->c_Id > data.c_Id)
		return GREATER;
	else if (this->c_Id < data.c_Id)
		return LESS;
	else
		return EQUAL;
}

int ContainerType::AddItem(ItemType data)
{
	SimpleItemType temp;
	temp.GetRecordFromItemType(data);
	if (c_itemList.Add(temp)) { return 1; }
	return 0;
}


int ContainerType::DeleteItem(ItemType& data)
{
	SimpleItemType temp;
	int temp_serial = data.GetSerial();
	if (c_itemList.Delete(temp)) { return 1; }
	return 0;
}


int ContainerType::UpdateItem(ItemType data)
{
	SimpleItemType temp;
	temp.GetRecordFromItemType(data);
	if (c_itemList.Replace(temp)) { return 1; }
	return 0;

}


int ContainerType::AddPhoto(string data)
{
	cout << "구현되지 않았다" << '\n';
	return 1;
}


int ContainerType::DeletePhoto(string& data)
{
	cout << "구현되지 않았다" << '\n';
	return 1;
}


int ContainerType::UpdatePhoto(string data)
{
	cout << "구현되지 않았다" << '\n';
	return 1;
}


int ContainerType::DisplayAllItem()
{
	SimpleItemType curItem;
	c_itemList.ResetList();
	int iPos = c_itemList.GetNextItem(curItem);
	for (iPos; iPos > 0; iPos = c_itemList.GetNextItem(curItem)) {
		curItem.DisplayRecordOnScreen();
	}
	return 1;
}


int ContainerType::DisplayAllPhoto()
{
	cout << "구현되지 않았다" << '\n';
	return 1;
}


int ContainerType::FindByName()
{
	cout << "구현되지 않았다" << '\n';
	return 1;
}


int ContainerType::FindByUsage()
{
	cout << "구현되지 않았다" << '\n';
	return 1;
}
