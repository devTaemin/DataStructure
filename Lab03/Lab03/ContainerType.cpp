#include "ContainerType.h"
#include "pch.h"


ContainerType::ContainerType()
{
	c_Id = -1;
	c_Location = "";
}


ContainerType::~ContainerType() {}


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
	cout << "�������� �ʾҴ�" << '\n';
	return 1;
}


int ContainerType::DeletePhoto(string& data)
{
	cout << "�������� �ʾҴ�" << '\n';
	return 1;
}


int ContainerType::UpdatePhoto(string data)
{
	cout << "�������� �ʾҴ�" << '\n';
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
	cout << "�������� �ʾҴ�" << '\n';
	return 1;
}


int ContainerType::FindByName()
{
	cout << "�������� �ʾҴ�" << '\n';
	return 1;
}


int ContainerType::FindByUsage()
{
	cout << "�������� �ʾҴ�" << '\n';
	return 1;
}