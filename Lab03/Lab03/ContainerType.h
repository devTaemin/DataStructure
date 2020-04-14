#ifndef _CONTAINERTYPE_H_
#define _CONTAINERTYPE_H_
//--------------------------------------------------------------------
//		Temp Item information class.
//--------------------------------------------------------------------
class ContainerType
{
private:
	int m_Id;
	string m_Location;
	UnSortedList<string> m_Photo_list;
	SortedList<ItemType> m_Simple_itemlist;

public:
	ContainerType();
	~ContainerType();

	int AddItem(ItemType data);
	int DeleteItem(ItemType& data);
	int UpdateItem(ItemType data);

	int AddPhoto(string data);
	int DeletePhoto(string& data);
	int UpdatePhoto(string data);

	int DisplayAllItem();
	int DisplayAllPhoto();

	int FindByName();
	int FindByUsage();
};

#endif _CONTAINERTYPE_H_