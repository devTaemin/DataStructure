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
	WorkerType* ResultList = new WorkerType[_max];									// 조건에 맞는 worker을 저장.
	itor.Next();						
	WorkerType Worker;																// Cursor WorkType과 기타 조건들 세팅.
	int m_Length = 0;
	int limit = _max;
	while (itor.NextNotNull() && (limit != 0))										// 조건 분류 시작.
	{
		if (itor.Now(Worker) == 0) { return; }										// 현재 Data가 없는경우 실패.
		// 나이 조건
		if (Worker.GetAgeGroup() == _worker.GetAgeGroup()) {						// 연령대에 속하는지.
			// 숙련도 조건
			if (Worker.GetSkill() >= _worker.GetSkill()) {							// 숙련도는 우위에 있는지.
				// 급여 조건
				if (Worker.GetTargetWage() <= _worker.GetTargetWage()) {			// 봉급 조건에 맞는지.
					ResultList[m_Length] = Worker;									// worker 저장.
					m_Length++;														// 길이 증가, 최대 수 감소.
					limit--;
				}
			}
		}
		itor.Next();
	}

	if (m_Length == 0) { cout << "\t[NO RESULT]" << endl; }							// 조건에 맞는 노동자가 없는 경우.
	else
	{
		for (int i = 0; i < m_Length; i++)
		{
			cout << endl;
			cout << ResultList[i] << endl;											// 출력.
			m_WorkerList.Delete(ResultList[i]);										// 리스트에서 삭제.
			m_NumOfWorker--;
		}
		if (m_Length == _max) { cout << "\t[COMPLETE]" << endl; }					// 요구된 모든 인원이 출력된 경우.
		else {
			cout << "\t[ " << m_Length << " / " << _max << " COMPLETE]" << endl;	// 요구된 인원이 불충족 한 경우.
			cout << "\t[ " << _max - m_Length << " WORKERS LEFT]" << endl;
		}
		delete[] ResultList;														// 결과 리스트 할당 해제.
	}
}


// Find the All worker whose score condition matches with the score condition of target. and remove from list.
void WorkerListType::GetWorkerByScore(WorkerType& _worker, int _max)
{
	DoublyIterator<WorkerType> preItor(m_WorkerList);								// 저장된 기록에 score을 할당하기 위한 iterator.
	preItor.Next();

	// 조건에 필요한 변수들을 정리.
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

	WorkerType* ResultList = new WorkerType[_max];									// 결과를 위한 list를 동적으로 생성한다. 크기는 입력된 최대 수.
	int m_Length = 0;
	DoublyIterator<WorkerType> itor(m_WorkerList);
	itor.Next();
	while (itor.NextNotNull() && (limit != 0))
	{
		itor.Now(Worker);
		// 나이 조건
		if (Worker.GetAgeGroup() == _worker.GetAgeGroup()) {
			// 숙련도 조건
			if (Worker.GetSkill() >= _worker.GetSkill()) {
				// 급여 조건
				if (Worker.GetTargetWage() <= _worker.GetTargetWage()) {
					ResultList[m_Length] = Worker;								// 조건에 맞는 노동자의 기록을 결과 list에 저장.
					m_Length++;
					limit--;
				}
			}
		}
		itor.Next();
	}

	if (m_Length == 0) { cout << "\t[NO RESULT]" << endl; }							// 조건에 맞는 노동자가 없는 경우.
	else
	{
		QuickSortByScore(ResultList, 0, m_Length);									// 퀵정렬을 이용하여 점수 오름차순으로 정렬.
		for (int i = 0; i < m_Length; i++)
		{
			cout << endl;
			cout << ResultList[i] << endl;		
			cout << "\t       Worker-Score : " << _worker.GetScore() << endl;		// 출력.
			cout << "\t     +----------------------------------------+" << endl;
			m_WorkerList.Delete(ResultList[i]);										// 리스트에서 삭제.
		}
		if (m_Length == _max) { cout << "\t[COMPLETE]" << endl; }					// 요구된 모든 인원이 출력된 경우.
		else{
			cout << "\t[ " << m_Length << " / " << _max << " COMPLETE]" << endl;	// 요구된 인원이 불충족 한 경우.
			cout << "\t[ " << _max - m_Length << " LEFT]" << endl;
		}
		delete[] ResultList;														// 결과 리스트 할당 해제.
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