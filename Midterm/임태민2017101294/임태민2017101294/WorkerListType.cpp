#include "WorkerListType.h"

// Constructor.
WorkerListType::WorkerListType()
{
	m_ListName = "Default";
	m_NumOfWorker = 0;
	m_TicketNumber = 0;
}


// Destructor.
WorkerListType::~WorkerListType()
{

}


// Check whether list's length is 0 or not.
bool WorkerListType::IsEmpty() const
{
	return (m_NumOfWorker == 0);
}


// Set list name(location) by keyboard.
void WorkerListType::SetNameFromKB()
{
	cout << "\tList-Name    : " << endl;
	cin >> m_ListName;
}


// Make list empty.
void WorkerListType::MakeEmpty()
{
	m_WorkerList.MakeEmpty();
	m_NumOfWorker = 0;
	m_TicketNumber = 0;
}


// Get workerlist's Name.
string WorkerListType::GetListName()
{
	return m_ListName;
}


// Get number of workers.
int WorkerListType::GetNumOfWorker()
{
	return m_NumOfWorker;
}


// Get last ticket's number.
int WorkerListType::GetLastTicketNumber()
{
	return m_TicketNumber;
}


// Add a new worker into list.
int WorkerListType::AddList(WorkerType& _worker)
{
	if (m_WorkerList.Add(_worker) == 1) {
		cout << "\t[SUCCESS]" << endl;
		return 1;
	}
	cout << "\t[FAIL]" << endl;
	return 0;
}


// Delete worker in accordance with data's primary key.
int WorkerListType::DeleteList(WorkerType& _worker)
{
	if (m_WorkerList.Delete(_worker) == 1) {
		cout << "\t[SUCCESS]" << endl;
		return 1;
	}
	cout << "\t[FAIL]" << endl;
	return 0;
}


// Find same worker using primary key and replace it.
int WorkerListType::ReplaceList(WorkerType& _worker)
{
	if (m_WorkerList.Replace(_worker) == 1) {
		cout << "\t[SUCCESS]" << endl;
		return 1;
	}
	cout << "\t[FAIL]" << endl;
	return 0;
}


// Find the worker whose primary key matches with the primary key of target. and get the worker in target.
int WorkerListType::GetList(WorkerType& _worker)
{
	if (m_WorkerList.Get(_worker) == 1) {
		cout << "\t[SUCCESS]" << endl;
		return 1;
	}
	cout << "\t[FAIL]" << endl;
	return 0;
}


// Display the name of worker list.
void WorkerListType::DisplayListName()
{
	cout << "\tList-Name    : " << m_ListName << endl;
}


// Display the number of workers.
void WorkerListType::DisplayNumOfWorker()
{
	cout << "\tWorker-Number: " << m_NumOfWorker << endl;
}


// Display the last ticket number of worker.
void WorkerListType::DisplayLastTicketNumber()
{
	cout << "\tTicket-Number: " << m_TicketNumber << endl;
}


// Display workerlist
void WorkerListType::DisplayWorkerList()
{
	cout << "\t[Worker-List]" << endl;
	cout << m_WorkerList << endl;
}