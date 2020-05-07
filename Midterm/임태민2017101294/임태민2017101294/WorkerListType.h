#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// TYPE
#include "WorkerType.h"

// DATASTRUCTURE
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"
#include "SortedList.h"


class WorkerListType
{
private:

	string m_ListName;										///< 구직자 등록 시스템 (인력시장 이름)..
	DoublySortedLinkedList<WorkerType> m_WorkerList;		///< 구직자 목록.
	int m_NumOfWorker;										///< 등록된 구직자 수.
	int m_TicketNumber;										///< 발급된 마지막 티켓 번호.

public:

	WorkerListType();
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------

	~WorkerListType();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------

	bool IsEmpty() const;
	//--------------------------------------------------------------------
	//	Brief:	Check whether list's length is 0 or not.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	return true if list is empty, otherwise return false.
	//--------------------------------------------------------------------

	void SetNameFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set list name(location) by keyboard.
	//	Pre:	none.
	//	Post:	list name is set.
	//--------------------------------------------------------------------

	void MakeEmpty();
	//--------------------------------------------------------------------
	//	Brief:	Make list empty.
	//	Pre:	none.
	//	Post:	clear list.
	//--------------------------------------------------------------------

	string GetListName();
	//--------------------------------------------------------------------
	//	Brief:	Get workerlist's Name.
	//	Pre:	listName is set.
	//	Post:	none.
	//	Return:	m_ListName.
	//--------------------------------------------------------------------

	int GetNumOfWorker();
	//--------------------------------------------------------------------
	//	Brief:	Get number of workers.
	//	Pre:	number of workers is set.
	//	Post:	none.
	//	Return:	m_NumOfWorker.
	//--------------------------------------------------------------------

	int GetLastTicketNumber();
	//--------------------------------------------------------------------
	//	Brief:	Get last ticket's number.
	//	Pre:	last ticket's number is set.
	//	Post:	none.
	//	Return:	m_TicketNumber.
	//--------------------------------------------------------------------

	int AddList(WorkerType& _worker);
	//--------------------------------------------------------------------
	//	Brief:	Add a new worker into list.
	//	Pre:	list should be initialized.
	//	Post:	add the new record in sorted ways into the list 
	//	Param:	_worker			new worker.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------

	int DeleteList(WorkerType& _worker);
	//--------------------------------------------------------------------
	//	Brief:	Delete worker in accordance with data's primary key.
	//	Pre:	data's primary key should be set.
	//	Post:	a worker is removed from the list.
	//	Param:	_worker		the target worker to be deleted.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------

	int ReplaceList(WorkerType& _worker);
	//--------------------------------------------------------------------
	//	Brief:	Find same worker using primary key and replace it.
	//	Pre:	data's serial number should be set,
	//	Post:	a worker's record is replaced with new information.
	//	Param:	_worker		the target worker to be replaced.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------

	int GetList(WorkerType& _worker);
	//--------------------------------------------------------------------
	//	Brief:	Find the worker whose primary key matches with the primary 
	//			key of target. and get the worker in target.
	//	Pre:	the list should be initialized.
	//	Post:	matching worker is founded and refered the record by target.
	//	Param:	_worker		the target worker to retrieve.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------

	void DisplayListName();
	//--------------------------------------------------------------------
	//	Brief:	Display the name of worker list.
	//	Pre:	the list should be initialized.
	//	Post:	noen.
	//--------------------------------------------------------------------

	void DisplayNumOfWorker();
	//--------------------------------------------------------------------
	//	Brief:	Display the number of workers.
	//	Pre:	the list should be initialized.
	//	Post:	none.
	//--------------------------------------------------------------------

	void DisplayLastTicketNumber();
	//--------------------------------------------------------------------
	//	Brief:	Display the last ticket number of worker.
	//	Pre:	the list should be initialized.
	//	Post:	none.
	//--------------------------------------------------------------------

	void DisplayWorkerList();
	//--------------------------------------------------------------------
	//	Brief:	Display workerlist
	//	Pre:	the list should be initialized.
	//	Post:	none.
	//--------------------------------------------------------------------

	bool operator==(const WorkerListType& _list) {
		return (m_ListName == _list.m_ListName);
	}
	bool operator<(const WorkerListType& _list) {
		return (m_ListName < _list.m_ListName);
	}
	bool operator==(const WorkerListType& _list) {
		return (m_ListName > _list.m_ListName);
	}
	void operator=(const WorkerListType& _list)
	{
		m_ListName = _list.m_ListName;
		m_WorkerList = _list.m_WorkerList;
		m_NumOfWorker = _list.m_NumOfWorker;
		m_TicketNumber = _list.m_TicketNumber;
	}

	friend ostream& operator<<(ostream& os, const WorkerListType& _list)
	{
		os << "\t+--------------------------------------------------+" << endl;
		os << "\t|                   WORKER LIST                    |" << endl;
		os << "\t+--------------------------------------------------+" << endl;
		os << "\t     LISTNAME            :   " << _list.m_ListName << endl;
		os << "\t     WORKER NUMBER       :   " << _list.m_NumOfWorker << endl;
		os << "\t     LAST TICEKT NUMBER  :   " << _list.m_TicketNumber << endl;
		os << "\t+--------------------------------------------------+" << endl;
		os << "\t+--------------------------------------------------+" << endl;
		os << "\t|                  WORKER RECORDS                  |" << endl;
		os << "\t+--------------------------------------------------+" << endl;
		os << _list.m_WorkerList << endl;
		return os;
	}
};