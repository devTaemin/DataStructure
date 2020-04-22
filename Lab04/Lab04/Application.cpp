#include "pch.h"

#include "pch.h"


Application::Application()
{
	m_Command = -1;
}


Application::~Application() {}


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:
			AddStorage();
			break;
		case 2:
			DisplayStorage();
			break;
		case 3:
			AddContainer();
			break;
		case 4:
			DisplayAllContainer();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}



// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID----- Command -----------" << '\n';
	cout << "\t======= [ StorageList ] =======" << '\n';
	cout << "\t   1  : ���� ���� ����" << '\n';
	cout << "\t   2  : ���� ���� ��� ���" << '\n';
	cout << "\t   3  : ���� ���� �����̳� ����" << '\n';
	cout << "\t   4  : ���� ���� �����̳� ��� ���" << '\n';
	cout << "\t   5  : ���� ���� �����̳� ���, �󼼸���Ʈ ���" << '\n';
	cout << "\t==============================" << '\n';
	cout << "\t   0  : Quit" << '\n';
	cout << "\t==============================" << '\n';
	cout << '\n';

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


int Application::AddStorage()
{
	StorageType newStorage;
	newStorage.SetRecordFromKB();
	if (StorageList.Add(newStorage) == 1) {
		cout << "===[���� ���� ������ �����߽��ϴ�.]===" << '\n';
		return 1;
	}
	cout << "===[���� ���� ������ �����߽��ϴ�.]===" << '\n';
	return 0;
}

void Application::DisplayStorage()
{
	if (StorageList.IsEmpty()) {
		cout << "===[������ ��������� �����ϴ�.]===" << '\n';
	}
	else {
		StorageList.ResetList();
		StorageType curStorage;
		int iPos = StorageList.GetNextItem(curStorage);
		for (iPos; iPos >= 0; iPos = StorageList.GetNextItem(curStorage)) {
			cout << '\n';
			cout << "=========================================" << '\n';
			curStorage.DisplayStorageRecordOnScreen();
			cout << "=========================================" << '\n';
		}
	}
}


int Application::AddContainer()
{
	StorageType findStorage;
	findStorage.SetStorageIDFromKB();

	StorageType curStorage;
	StorageList.ResetList();
	int iPos = StorageList.GetNextItem(curStorage);
	bool found = false;
	for (iPos; iPos >= 0; iPos = StorageList.GetNextItem(curStorage)) {
		if (curStorage.GetStorageID() == findStorage.GetStorageID()) {
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "===[���� ������ ã�� ���Ͽ����ϴ�.]===" << '\n';
		return 0;
	}
	
	ContainerType newContainer;
	newContainer.SetRecordFromKB();
	if (curStorage.AddContainer(newContainer) == 1) {
		cout << "===['" << curStorage.GetName() << "' ���� ����  '" << 
			newContainer.GetLocation() << "' �����̳ʰ� �����Ǿ����ϴ�.]===" << '\n';
		return 1;
	}
	else {
		cout << "===[�����̼� ������ �����Ͽ����ϴ�.]===" << '\n';
	}
	return 1;
}

void Application::DisplayAllContainer()
{
	StorageType findStorage;
	findStorage.SetStorageIDFromKB();

	StorageType curStorage;
	StorageList.ResetList();
	int iPos = StorageList.GetNextItem(curStorage);
	bool found = false;
	for (iPos; iPos >= 0; iPos = StorageList.GetNextItem(curStorage)) {
		if (curStorage.GetStorageID() == findStorage.GetStorageID()) {
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "===[���� ������ ã�� ���Ͽ����ϴ�.]===" << '\n';
	}
	else {
		curStorage.DisplayAllContainer();
	}
}

void Application::DisplayAllDetailsContainer(){}
