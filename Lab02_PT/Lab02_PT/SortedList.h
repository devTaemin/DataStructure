#ifndef _SORTEDLIST_H_
#define _SORTEDLIST_H_

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 10


//--------------------------------------------------------------------
//		Array based simple 'Sorted list'.
//--------------------------------------------------------------------
class SortedList
{
public:

	SortedList()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		m_Length = 0;
		m_CurPointer = 0;
	}


	~SortedList() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make list empty. (Initialize list)
	//	Pre:	none.
	//	Post:	clear list.
	//--------------------------------------------------------------------


	int GetLength();
	//--------------------------------------------------------------------
	//	Brief:	Return the number of records in the list.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	number of records in current list.
	//--------------------------------------------------------------------


	bool IsFull();
	//--------------------------------------------------------------------
	//	Brief:	Check the list upper is reached to the limit.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	return true if list capacity reached to the upper bound, otherwise return false.
	//--------------------------------------------------------------------


	int Add(ItemType data);
	//--------------------------------------------------------------------
	//	Brief:	Add a new data into list.
	//	Pre:	list should be initialized.
	//	Post:	add the new record in sorted ways into the list 
	//	Param:	data		new data.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	void ResetList();
	//--------------------------------------------------------------------
	//	Brief:	Initialize the list iterator.
	//	Pre:	list should be initialized.
	//	Post:	iterator is reset.
	//--------------------------------------------------------------------


	int GetNextItem(ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Update pointer to point to next record,
	//			and get that new record.
	//	Pre:	list and list iterator should not be initialized.
	//	Post:	iterator is moved to next item.
	//	Param:	data		get current iterator's item. 
	//						it does not need to be initialized
	//	Return:	index of current iterator's item if it is not end of list,
	//			otherwise return -1.
	//--------------------------------------------------------------------


	int Retrieve_SeqS(ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Find the item whose primary key matches with the primary 
	//			key of target. and get the item in target.
	//	Pre:	the list should be initialized.
	//	Post:	matching item is founded and refered the record by target.
	//	Param:	target		the target item to retrieve.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int Delete(ItemType data);
	//--------------------------------------------------------------------
	//	Brief:	Delete item in accordance with data's primary key.
	//	Pre:	data's serial number should be set.
	//	Post:	a item is removed from the list.
	//	Param:	data		the target data to be deleted.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int Replace(ItemType data);
	//--------------------------------------------------------------------
	//	Brief:	Find same record using primary key and replace it.
	//	Pre:	data's serial number should be set,
	//	Post:	a item's record is replaced with new information.
	//	Param:	data		the target data to be replaced.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int RetrieveByBS(ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Retrieve by using binary search.
	//	Pre:	the list should be initialized.
	//	Post:	matching item is founded and refered the record by data.
	//	Param:	data		the target data to retrieve.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


private:
	ItemType m_Array[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};
#endif _SORTEDLIST_H_