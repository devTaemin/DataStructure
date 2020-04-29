#include "ContainerType.h"


ContainerType::ContainerType()
{
	m_ContainerID = -1;
	m_Location = "";
}

ContainerType::~ContainerType()
{

}

int ContainerType::GetId() const
{
	return m_ContainerID;
}

string ContainerType::GetLocation() const
{
	return m_Location;
}

void ContainerType::SetId(int _id)
{
	m_ContainerID = _id;
}

void ContainerType::SetLocation(string _location)
{
	m_Location = _location;
}

void ContainerType::SetIdFromKB()
{
	cout << "\tContainerID : ";
	cin >> m_ContainerID;
}

void ContainerType::SetLocationFromKB()
{
	cout << "\tContainer-Location : ";
	cin >> m_Location;
}

void ContainerType::SetRecordFromKB()
{
	SetIdFromKB();
	SetLocationFromKB();
}

int ContainerType::AddsItem(SimpleItemType& _item)
{
	if (m_SimpleItemList.Add(_item) == 1) { return 1; }
	else if (m_SimpleItemList.Add(_item) == -1) { return -1; }
	return 0;
}

int ContainerType::DeletesItem(SimpleItemType& _item)
{
	if (m_SimpleItemList.Delete(_item) == 1) { return 1; }
	return 0;
}

int ContainerType::UpdatesItem(SimpleItemType& _item)
{
	if (m_SimpleItemList.Replace(_item) == 1) { return 1; }
	return 0;
}

int ContainerType::AddPhoto(string photo)
{
	if (m_PhotoList.Add(photo) == 1) { return 1; }
	return 0;
}

int ContainerType::DeletePhoto(string photo)
{
	if (m_PhotoList.Delete(photo) == 1) { return 1; }
	return 0;
}

void ContainerType::DisplayAllPhoto()
{
	cout << m_PhotoList << endl;
}

void ContainerType::DisplayAllsItem()
{
	cout << m_SimpleItemList << endl;
}

void ContainerType::DisplayAllDetailsItem(DoubleLinkedList<ItemType>& ref)
{
	SimpleItemType temp;
	m_SimpleItemList.ResetList();
	while (m_SimpleItemList.GetNextItem(temp) > 0) {
		ItemType detail;
		detail.SetID(temp.GetId());
		ref.Get(detail);
		cout << detail << endl;
	}
}