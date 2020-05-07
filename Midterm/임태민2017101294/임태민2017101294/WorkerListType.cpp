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
int WorkerListType::AddWorker(WorkerType& _worker)
{
	if (m_WorkerList.Add(_worker) == 1) {
		cout << "\t[SUCCESS]" << endl;
		m_NumOfWorker++;
		m_TicketNumber++;
		return 1;
	}
	cout << "\t[FAIL]" << endl;
	return 0;
}


// Delete worker in accordance with data's primary key.
int WorkerListType::DeleteWorker(WorkerType& _worker)
{
	if (m_WorkerList.Delete(_worker) == 1) {
		cout << "\t[SUCCESS]" << endl;
		m_NumOfWorker--;
		return 1;
	}
	cout << "\t[FAIL]" << endl;
	return 0;
}


// Find same worker using primary key and replace it.
int WorkerListType::ReplaceWorker(WorkerType& _worker)
{
	if (m_WorkerList.Replace(_worker) == 1) {
		cout << "\t[SUCCESS]" << endl;
		return 1;
	}
	cout << "\t[FAIL]" << endl;
	return 0;
}


// Find the worker whose primary key matches with the primary key of target. and get the worker in target.
int WorkerListType::GetWorker(WorkerType& _worker)
{
	if (m_WorkerList.Get(_worker) == 1) {
		cout << "\t[SUCCESS]" << endl;
		return 1;
	}
	cout << "\t[FAIL]" << endl;
	return 0;
}


// Find the worker whose primary key matches with the primary key of target. and get the worker in target.
void WorkerListType::FindAllWorkerByName(WorkerType& _worker)
{
	DoublyIterator<WorkerType> itor(m_WorkerList);
	itor.Next();
	WorkerType curWorker;
	while (itor.NextNotNull())
	{
		itor.Now(curWorker);
		if (_worker.GetName() == curWorker.GetName()) {
			cout << curWorker << endl;
		}
		itor.Next();
	}
}


// Find the worker whose primary key matches with the primary key of target. and get the worker in target.
void WorkerListType::FindAllWorkerBySkill(WorkerType& _worker)
{
	DoublyIterator<WorkerType> itor(m_WorkerList);
	itor.Next();
	WorkerType curWorker;
	while (itor.NextNotNull())
	{
		itor.Now(curWorker);
		if (_worker.GetSkill() == curWorker.GetSkill()) {
			cout << curWorker << endl;
		}
		itor.Next();
	}
}

// Find the All worker whose conditions matches with the conditions of target. and remove from list.
void WorkerListType::GetWorkerByConditions(WorkerType& _worker, int _max)
{
	DoublyIterator<WorkerType> itor(m_WorkerList);									// iterator.
	WorkerType* ResultList = new WorkerType[_max];									// ���ǿ� �´� worker�� ����.
	itor.Next();						
	WorkerType Worker;																// Cursor WorkType�� ��Ÿ ���ǵ� ����.
	int m_Length = 0;
	int limit = _max;
	while (itor.NextNotNull() && (limit != 0))										// ���� �з� ����.
	{
		if (itor.Now(Worker) == 0) { return; }										// ���� Data�� ���°�� ����.
		// ���� ����
		if (Worker.GetAgeGroup() == _worker.GetAgeGroup()) {						// ���ɴ뿡 ���ϴ���.
			// ���õ� ����
			if (Worker.GetSkill() >= _worker.GetSkill()) {							// ���õ��� ������ �ִ���.
				// �޿� ����
				if (Worker.GetTargetWage() <= _worker.GetTargetWage()) {			// ���� ���ǿ� �´���.
					ResultList[m_Length] = Worker;									// worker ����.
					m_Length++;														// ���� ����, �ִ� �� ����.
					limit--;
				}
			}
		}
		itor.Next();
	}

	if (m_Length == 0) { cout << "\t[NO RESULT]" << endl; }							// ���ǿ� �´� �뵿�ڰ� ���� ���.
	else
	{
		for (int i = 0; i < m_Length; i++)
		{
			cout << endl;
			cout << ResultList[i] << endl;											// ���.
			m_WorkerList.Delete(ResultList[i]);										// ����Ʈ���� ����.
			m_NumOfWorker--;
		}
		if (m_Length == _max) { cout << "\t[COMPLETE]" << endl; }					// �䱸�� ��� �ο��� ��µ� ���.
		else {
			cout << "\t[ " << m_Length << " / " << _max << " COMPLETE]" << endl;	// �䱸�� �ο��� ������ �� ���.
			cout << "\t[ " << _max - m_Length << " WORKERS LEFT]" << endl;
		}
		delete[] ResultList;														// ��� ����Ʈ �Ҵ� ����.
	}
}


// Find the All worker whose score condition matches with the score condition of target. and remove from list.
void WorkerListType::GetWorkerByScore(WorkerType& _worker, int _max)
{
	DoublyIterator<WorkerType> preItor(m_WorkerList);								// ����� ��Ͽ� score�� �Ҵ��ϱ� ���� iterator.
	preItor.Next();

	// ���ǿ� �ʿ��� �������� ����.
	int limit = _max;
	int targetSkill = _worker.GetSkill();
	int targetAge = _worker.GetAgeGroup();
	double targetWage = _worker.GetTargetWage();
	int targetTicket = _worker.GetSequence();
	int totalWorker = m_NumOfWorker;

	WorkerType Worker;
	while (preItor.NextNotNull() && (limit != 0)) {
		preItor.Now(Worker);
		double score = (20.0 * abs(Worker.GetSkill() - targetSkill) / 4.0)
			+ (20.0 * abs(Worker.GetAgeGroup() - targetAge) / 2.0)
			+ (30.0 * abs(Worker.GetTargetWage() - targetWage) / 100000.0)
			+ (30 * targetTicket / totalWorker);
		Worker.SetScore(score);
		preItor.Next();
	}

	WorkerType* ResultList = new WorkerType[_max];									// ����� ���� list�� �������� �����Ѵ�. ũ��� �Էµ� �ִ� ��.
	int m_Length = 0;
	DoublyIterator<WorkerType> itor(m_WorkerList);
	itor.Next();
	while (itor.NextNotNull() && (limit != 0))
	{
		itor.Now(Worker);
		// ���� ����
		if (Worker.GetAgeGroup() == _worker.GetAgeGroup()) {
			// ���õ� ����
			if (Worker.GetSkill() >= _worker.GetSkill()) {
				// �޿� ����
				if (Worker.GetTargetWage() <= _worker.GetTargetWage()) {
					ResultList[m_Length] = Worker;								// ���ǿ� �´� �뵿���� ����� ��� list�� ����.
					m_Length++;
					limit--;
				}
			}
		}
		itor.Next();
	}

	if (m_Length == 0) { cout << "\t[NO RESULT]" << endl; }							// ���ǿ� �´� �뵿�ڰ� ���� ���.
	else
	{
		QuickSortByScore(ResultList, 0, m_Length);									// �������� �̿��Ͽ� ���� ������������ ����.
		for (int i = 0; i < m_Length; i++)
		{
			cout << endl;
			cout << ResultList[i] << endl;		
			cout << "\t       Worker-Score : " << _worker.GetScore() << endl;		// ���.
			cout << "\t     +----------------------------------------+" << endl;
			m_WorkerList.Delete(ResultList[i]);										// ����Ʈ���� ����.
		}
		if (m_Length == _max) { cout << "\t[COMPLETE]" << endl; }					// �䱸�� ��� �ο��� ��µ� ���.
		else{
			cout << "\t[ " << m_Length << " / " << _max << " COMPLETE]" << endl;	// �䱸�� �ο��� ������ �� ���.
			cout << "\t[ " << _max - m_Length << " LEFT]" << endl;
		}
		delete[] ResultList;														// ��� ����Ʈ �Ҵ� ����.
	}
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