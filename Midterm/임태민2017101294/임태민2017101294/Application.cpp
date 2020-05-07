#include "Application.h"


// Constructor.
Application::Application()
{
	m_Command = 0;
	m_Ticket = 1;
}


// Destructor.
Application::~Application()
{

}


// Run program.
void Application::Run()
{
	while (1)
	{
		GetCommand();
		switch (m_Command)
		{
		case 1:
			AddWorker();
			break;
		case 2:
			DeleteWorker();
			break;
		case 3:
			UpdateWorker();
			break;
		case 4:
			DisplayBySequence();
			break;
		case 5:
			SearchByName();
			break;
		case 6:
			SearchBySkill();
			break;
		case 7:
			GetWorkerByConditions();
			break;
		case 8:
			GetWorkerByScore();
			break;
		case 0:
			return;
		default:
			cout << endl;
			cout << "\t+----------------------+" << endl;
			cout << "\t| ERROR: WRONG COMMAND |" << endl;
			cout << "\t+----------------------+" << endl;
			break;
		}
	}
}


// Get command number.
void Application::GetCommand()
{
	cout << endl << endl;
	cout << "\t+------ [ Human-Resource Management Program ]--------------+" << endl;
	cout << "\t|====== [MasterList] ======================================|" << endl;
	cout << "\t|  [1 : Add Worker]            [2 : Delete Worker]         |" << endl;
	cout << "\t|  [3 : Update Worker]                                     |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << "\t|====== [Functions]  ======================================|" << endl;
	cout << "\t|  [4 : Display All workers]                               |" << endl;
	cout << "\t|  [5 : Search worker By Name]                             |" << endl;
	cout << "\t|  [6 : Search worker By Skill]                            |" << endl;
	cout << "\t|  [7 : Get workers By Conditions]                         |" << endl;
	cout << "\t|  [8 : Get workers By Score]                              |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << "\t|  [0 : Quit]                                              |" << endl;
	cout << "\t|==========================================================|" << endl;
	cout << endl;
	cout << "\t Choose a Command--> ";
	cin >> m_Command;
	cout << endl;
	cout << endl;
}

// WorkerType을 List화 하는 경우 구현.
/*
// Add worker list.
void Application::AddList()
{

}


// Delete worker list.
void Application::DeleteList()
{

}


// Update worker list.
void Application::UpdateList()
{

}
*/

// Add new worker in a list.
void Application::AddWorker()
{
	WorkerType newWorker(m_Ticket);									// Worker 생성.
	newWorker.SetRecordFromKB();									// 이름, 연락처, 숙련도, 나이, 희망 일당 설정.
	//newWorker.SetSequence(m_Ticket);								// 등록 Ticket 발급.
	if (MasterList.AddWorker(newWorker) == 1) { m_Ticket++; }		// Worker 등록.
}


// Delete worker in a list.
void Application::DeleteWorker()
{
	WorkerType targetWorker;										// Worker 생성.
	targetWorker.SetSequenceFromKB();								// Ticket 번호 입력.
	MasterList.DeleteWorker(targetWorker);							// 해당 Worker 삭제.
}


// Update worker in a list.
void Application::UpdateWorker()
{
	WorkerType targetWorker;										// Worker 생성.
	targetWorker.SetSequenceFromKB();								// Ticket 번호 입력.
	targetWorker.SetRecordFromKB();									// Ticket Record 입력.
	MasterList.ReplaceWorker(targetWorker);							// 해당 Worker 정보 교체.
}


/*
// Display all workerlist.
void Application::DisplayAllList()
{

}
*/


// Display worker's record in order of sequence.
void Application::DisplayBySequence()
{
	cout << MasterList << endl;
}


// Search worker by searching worker's name 
void Application::SearchByName()
{
	WorkerType curWorker;											// Worker cursor 생성.
	curWorker.SetNameFromKB();										// 이름 입력.
	cout << endl;
	MasterList.FindAllWorkerByName(curWorker);						// 이름을 기준으로 Worker 검색, 출력.
}


// Search worker by searching worker's skill level in order of sequence.
void Application::SearchBySkill()
{
	WorkerType curWorker;											// Worker cursor 생성.
	curWorker.SetSkillFromKB();										// 숙련도 입력.
	cout << endl;
	MasterList.FindAllWorkerBySkill(curWorker);						// 숙련도 기준으로 Worker 검색, 출력.
}


// Get worker by searching worker's conditions (Wanting number, Wanting age, Wanting wage) in order of sequence.
void Application::GetWorkerByConditions()
{
	// 희망 인원, 숙련도, 나이, 일당을 입력받는다.
	int MaxWorker;													// 최대 노동자 수
	cout << "\tMAX-Worker : ";
	cin >> MaxWorker;
	WorkerType curWorker;
	curWorker.SetSkillFromKB();										// 최소 숙련도.
	curWorker.SetAgeFromKB();										// 나이 대.
	curWorker.SetTargetWageFromKB();								// 최대 급여.
	MasterList.GetWorkerByConditions(curWorker, MaxWorker);			// 조건에 맞는 리스트 출력.
}


// Get worker sequently in increasing order of score
void Application::GetWorkerByScore()
{
	// 희망 인원, 숙련도, 나이, 일당을 입력받는다.
	int MaxWorker;													// 최대 노동자 수
	cout << "\tMAX-Worker : ";
	cin >> MaxWorker;
	WorkerType curWorker;
	curWorker.SetSkillFromKB();										// 최소 숙련도.
	curWorker.SetAgeFromKB();										// 나이 대.
	curWorker.SetTargetWageFromKB();								// 최대 급여.
	MasterList.GetWorkerByConditions(curWorker, MaxWorker);			// 조건에 맞는 리스트 출력.
}