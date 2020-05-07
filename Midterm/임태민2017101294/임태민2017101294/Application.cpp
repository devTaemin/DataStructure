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

// WorkerType�� Listȭ �ϴ� ��� ����.
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
	WorkerType newWorker(m_Ticket);									// Worker ����.
	newWorker.SetRecordFromKB();									// �̸�, ����ó, ���õ�, ����, ��� �ϴ� ����.
	//newWorker.SetSequence(m_Ticket);								// ��� Ticket �߱�.
	if (MasterList.AddWorker(newWorker) == 1) { m_Ticket++; }		// Worker ���.
}


// Delete worker in a list.
void Application::DeleteWorker()
{
	WorkerType targetWorker;										// Worker ����.
	targetWorker.SetSequenceFromKB();								// Ticket ��ȣ �Է�.
	MasterList.DeleteWorker(targetWorker);							// �ش� Worker ����.
}


// Update worker in a list.
void Application::UpdateWorker()
{
	WorkerType targetWorker;										// Worker ����.
	targetWorker.SetSequenceFromKB();								// Ticket ��ȣ �Է�.
	targetWorker.SetRecordFromKB();									// Ticket Record �Է�.
	MasterList.ReplaceWorker(targetWorker);							// �ش� Worker ���� ��ü.
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
	WorkerType curWorker;											// Worker cursor ����.
	curWorker.SetNameFromKB();										// �̸� �Է�.
	cout << endl;
	MasterList.FindAllWorkerByName(curWorker);						// �̸��� �������� Worker �˻�, ���.
}


// Search worker by searching worker's skill level in order of sequence.
void Application::SearchBySkill()
{
	WorkerType curWorker;											// Worker cursor ����.
	curWorker.SetSkillFromKB();										// ���õ� �Է�.
	cout << endl;
	MasterList.FindAllWorkerBySkill(curWorker);						// ���õ� �������� Worker �˻�, ���.
}


// Get worker by searching worker's conditions (Wanting number, Wanting age, Wanting wage) in order of sequence.
void Application::GetWorkerByConditions()
{
	// ��� �ο�, ���õ�, ����, �ϴ��� �Է¹޴´�.
	int MaxWorker;													// �ִ� �뵿�� ��
	cout << "\tMAX-Worker : ";
	cin >> MaxWorker;
	WorkerType curWorker;
	curWorker.SetSkillFromKB();										// �ּ� ���õ�.
	curWorker.SetAgeFromKB();										// ���� ��.
	curWorker.SetTargetWageFromKB();								// �ִ� �޿�.
	MasterList.GetWorkerByConditions(curWorker, MaxWorker);			// ���ǿ� �´� ����Ʈ ���.
}


// Get worker sequently in increasing order of score
void Application::GetWorkerByScore()
{
	// ��� �ο�, ���õ�, ����, �ϴ��� �Է¹޴´�.
	int MaxWorker;													// �ִ� �뵿�� ��
	cout << "\tMAX-Worker : ";
	cin >> MaxWorker;
	WorkerType curWorker;
	curWorker.SetSkillFromKB();										// �ּ� ���õ�.
	curWorker.SetAgeFromKB();										// ���� ��.
	curWorker.SetTargetWageFromKB();								// �ִ� �޿�.
	MasterList.GetWorkerByConditions(curWorker, MaxWorker);			// ���ǿ� �´� ����Ʈ ���.
}