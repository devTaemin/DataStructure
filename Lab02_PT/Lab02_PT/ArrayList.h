#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"
#define MAXSIZE 5

//--------------------------------------------------------------------
//		Array based simple unsorted list.
//--------------------------------------------------------------------
class ArrayList
{
public:
	ArrayList()
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------
	{
		m_Length = 0;
		ResetList();
	}


	~ArrayList() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	void MakeEmpty();
		//--------------------------------------------------------------------
		//	Brief:	Make list empty.
		//	Pre:	none.
		//	Post:	clear list.
		//--------------------------------------------------------------------


	int GetLength();
		//--------------------------------------------------------------------
		//	Brief:	Get a number of records in current list.
		//	Pre:	none.
		//	Post:	none.
		//	Return:	number of records in current list.
		//--------------------------------------------------------------------


	bool IsFull();
		//--------------------------------------------------------------------
		//	Brief:	Check whether capacity of list is full.
		//	Pre:	none.
		//	Post:	none.
		//	Return:	return true if list capacity reached to the upper bound, otherwise return false.
		//--------------------------------------------------------------------


	int Add(ItemType data);
		//--------------------------------------------------------------------
		//	Brief:	Add a new data into list.
		//	Pre:	list should be initialized.
		//	Post:	add the new record into the list.
		//	Param:	data		new data.
		//	Return:	return 1 if this function works well, otherwise 0.
		//--------------------------------------------------------------------


	void ResetList();
		//--------------------------------------------------------------------
		//	Brief:	Initialize list iterator.
		//	Pre:	list should be initialized.
		//	Post:	iterator is reset.
		//--------------------------------------------------------------------


	int GetNextItem(ItemType& data);
		//--------------------------------------------------------------------
		//	Brief:	Move list iterator to the next item in list 
		//			and get that item.
		//	Pre:	list and list iterator should not be initialized.
		//	Post:	iterator is moved to next item.
		//	Param:	data		get current iterator's item. 
		//						it does not need to be initialized
		//	Return:	index of current iterator's item if it is not end of list,
		//			otherwise return -1.
		//--------------------------------------------------------------------


	bool IsEmpty();
		//--------------------------------------------------------------------
		//	Brief:	Check whether list is empty.
		//	Pre:	none.
		//	Post:	none.
		//	Return:	return true if list is empty, otherwise false.
		//--------------------------------------------------------------------


	int Get(ItemType& data);
		//--------------------------------------------------------------------
		//	Brief:	Search data in accordance with data's serial number,
		//			and refer the record on argument 'data'.
		//	Pre:	data's serial number should be set,
		//			and data is searched from list.
		//	Post:	the new item is added into the list.
		//	Param:	data		the target data to be copied.
		//	Return:	return 1 if this function works well, otherwise 0.
		//--------------------------------------------------------------------


	int Delete(ItemType data);
		//--------------------------------------------------------------------
		//	Brief:	Delete item in accordance with data's serial number.
		//	Pre:	data's serial number should be set.
		//			and data is searched from list.
		//	Post:	a item is removed from the list.
		//	Param:	data		the target data to be deleted.
		//	Return:	return 1 if this function works well, otherwise 0.
		//--------------------------------------------------------------------



	int Replace(ItemType data);
		//--------------------------------------------------------------------
		//	Brief:	Replace item in accordance with data's serial number.
		//	Pre:	data's serial number should be set,
		//			and data is searched from list.
		//	Post:	a item's record is replaced with new information.
		//	Param:	data		the target data to be replaced.
		//	Return:	return 1 if this function works well, otherwise 0.
		//--------------------------------------------------------------------


private:
	ItemType m_Array[MAXSIZE];	///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif _ARRAYLIST_H_