#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include "ItemType.h"

using namespace std;

#define MAXSIZE 5

/**
*	Array based simple unsorted list.
*/
class ArrayList
{
public:
	/**
	*	Default constructor.
	*/
	ArrayList()
	{
		m_Length = 0;
		ResetList();
	}


	/**
	*	Destructor.
	*/
	~ArrayList(){}


	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();


	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();


	/**
	*	@brief	Check whether capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, other wise return false.
	*/
	bool IsFull();


	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	add the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise -1. 
	*/
	int Add(ItemType data);


	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();


	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if it is not end of list, otherwise return -1.
	*/
	int GetNextItem(ItemType& data);


	/**
	*	@brief	Check whether list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list is empty, otherwise false.
	*/
	bool IsEmpty();


	/**
	*	@brief	Search item in accordance with data's student id as a primary key.
	*	@pre	none.
	*	@post	none.
	*	@param	data	get item from list.
	*	@return	return 1 if this function works well, otherwise -1;
	*/
	int Get(ItemType& data);


	/**
	*	@brief	Delete item in accordance with data's student id as a primary key.
	*	@pre	an array is set.
	*	@post	an item is removed from an array.
	*	@param	data	item to delete from list.
	*	@return return 1 if this function works well, otherwise -1;
	*/
	int Delete(ItemType data);


	/**
	*	@brief	Replace item in accordance with data's student id as a primary key.
	*	@pre	an array is set.
	*	@post	an item is replaced from an array.
	*	@param	data	item to be replaced with the data in list.
	*	@return	return 1 if this function works well, otherwise -1;
	*/
	int Replace(ItemType data);


private:
	ItemType m_Array[MAXSIZE];	///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif _ARRAYLIST_H_