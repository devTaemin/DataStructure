#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// TYPE
#include "WorkerType.h"
#include "WorkerListType.h"

// DATASTRUCTURE
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"
#include "SortedList.h"


class Application
{
private:

	DoublySortedLinkedList<WorkerListType> MasterList;
	int m_Command;

public:

	Application();
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------
	
	~Application();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------

	void Run();
	//--------------------------------------------------------------------
	//	Brief:	Run program.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void GetCommand();
	//--------------------------------------------------------------------
	//	Brief:	Get command number.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void AddList();
	//--------------------------------------------------------------------
	//	Brief:	Add worker list.
	//	Pre:	none.
	//	Post:	new list is added.
	//--------------------------------------------------------------------

	void DeleteList();
	//--------------------------------------------------------------------
	//	Brief:	Delete worker list.
	//	Pre:	none.
	//	Post:	existing list is deleted.
	//--------------------------------------------------------------------

	void UpdateList();
	//--------------------------------------------------------------------
	//	Brief:	Update worker list.
	//	Pre:	none.
	//	Post:	list's record is updated.
	//--------------------------------------------------------------------

	void AddWorker();
	//--------------------------------------------------------------------
	//	Brief:	Add new worker in a list.
	//	Pre:	list is initialized.
	//	Post:	new worker is added in a list.
	//--------------------------------------------------------------------

	void DeleteWorker();
	//--------------------------------------------------------------------
	//	Brief:	Delete worker in a list.
	//	Pre:	list is initialized.
	//	Post:	worker is deleted in a list.
	//--------------------------------------------------------------------

	void UpdateWorker();
	//--------------------------------------------------------------------
	//	Brief:	Update worker in a list.
	//	Pre:	list is initialized.
	//	Post:	worker's record is updated in a list.
	//--------------------------------------------------------------------

	void DisplayOneList();
	//--------------------------------------------------------------------
	//	Brief:	Display one workerlist.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void DisplayAllList();
	//--------------------------------------------------------------------
	//	Brief:	Display all workerlist.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void DisplayBySequence();
	//--------------------------------------------------------------------
	//	Brief:	Display worker's record in order of sequence.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void DisplayByName();
	//--------------------------------------------------------------------
	//	Brief:	Display worker by searching worker's name 
	//          in order of sequence.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void DisplayBySkill();
	//--------------------------------------------------------------------
	//	Brief:	Display worker by searching worker's skill level 
	//          in order of sequence.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void GetWorkerByConditions();
	//--------------------------------------------------------------------
	//	Brief:	Get worker by searching worker's conditions 
	//          (Wanting number, Wanting age, Wanting wage)
	//          in order of sequence.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------
	
	void GetWorkerByScore();
	//--------------------------------------------------------------------
	//	Brief:	Get worker sequently in increasing order of score
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------
	
};