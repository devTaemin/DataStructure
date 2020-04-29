#include "Application.h"

Application::Application()
{
	m_Command = 0;
}

Application::~Application()
{

}

void Application::Run()
{
	while (1)
	{
		GetCommand();
		switch (m_Command)
		{
		case 1:
			AddStorage();
			break;
		case 2:
			DeleteStorage();
			break;
		case 3:
			ReplaceStorage();
			break;
		case 4:
			AddContainer();
			break;
		case 5:
			DeleteContainer();
			break;
		case 6:
			ReplaceContainer();
			break;
		case 7:
			DisplayAllStorage();
			break;
		case 8:
			DIsplayAllContainer();
			break;
		case 9:
			DisplayAllDetailContainer();
			break;
		case 0:
			return;
		default:
			cout << "[ERROR: �߸��� �Է��Դϴ�.]" << endl;
			break;
		}
	}
}

void Application::GetCommand()
{
	cout << endl << endl;
	cout << "\t--num--- Command -------" << endl;
	cout << "\t=========Storage========" << endl;
	cout << "\t   1 : Add Storage" << endl;
	cout << "\t   2 : Delete Storage" << endl;
	cout << "\t   3 : Update Storage" << endl;
	cout << "\t   4 : Add Container" << endl;
	cout << "\t   5 : Delete Container" << endl;
	cout << "\t   6 : Update Container" << endl;
	cout << "\t   7 : Display All Storage" << endl;
	cout << "\t   8 : Display All container in a storage" << endl;
	cout << "\t   9 : Display All details of a storage " << endl;
	cout << "\t------------------------" << endl;
	cout << "\t=========Container======" << endl;
	
	


	cout << "\t------------------------" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> m_Command;
	cout << endl;
}

int Application::AddItem()
{
	return 0;
}

int Application::AddItem(ItemType& _item)
{
	return 0;
}

int Application::DeleteItem()
{
	return 0;
}

int Application::ReplaceItem()
{
	return 0;
}

int Application::OpenInFile(char* fileName)
{
	return 0;
}

int Application::OpenOutFile(char* fileName)
{
	return 0;
}

int Application::ReadDataFromFile()
{
	return 0;
}

int Application::WriteDataToFile()
{
	return 0;
}


// StorageList
int Application::AddStorage()
{
	StorageType newStorage;
	cout << "\t[������ ���� ������ �Է��Ͻÿ�.]" << endl;
	newStorage.SetRecordFromKB();
	if (StorageList.Add(newStorage) == 1) {
		cout << "\t[���ο� ��������� �����Ǿ����ϴ�.]" << endl;
		return 1;
	}
	else if (StorageList.Add(newStorage) == -1) {
		cout << "\t[�̹� ������ ��������Դϴ�.]" << endl;
	}
	cout << "\t[������� ������ �����Ͽ����ϴ�.]" << endl;
	return 0;
}

int Application::AddStorage(StorageType& _storage)
{
	if (StorageList.Add(_storage) == 1) {
		cout << "\t[���ο� ��������� �����Ǿ����ϴ�.]" << endl;
		return 1;
	}
	else if (StorageList.Add(_storage) == -1) {
		cout << "\t[�̹� ������ ��������Դϴ�.]" << endl;
	}
	cout << "\t[������� ������ �����Ͽ����ϴ�.]" << endl;
	return 0;
}

int Application::DeleteStorage()
{
	StorageType targetStorage;
	cout << "\t[������ ���� ������ �Է��Ͻÿ�.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.Delete(targetStorage) == 1) {
		cout << "\t[���� ���� ������ �����Ͽ����ϴ�.]" << endl;
		return 1;
	}
	cout << "\t[���� ���� ������ �����Ͽ����ϴ�.]" << endl;
	return 0;
}

int Application::ReplaceStorage()
{
	StorageType targetStorage;
	cout << "\t[��ü�� ���� ������ �Է��Ͻÿ�.]" << endl;
	targetStorage.SetRecordFromKB();
	if (StorageList.Replace(targetStorage) == 1) {
		cout << "\t[���� ���� ��ü�� �����Ͽ����ϴ�.]" << endl;
		return 1;
	}
	cout << "\t[���� ���� ��ü�� �����Ͽ����ϴ�.]" << endl;
	return 0;
}

void Application::DisplayAllStorage()
{
	StorageType tempStorage;
	StorageList.ResetList();
	int iPos = StorageList.GetNextItem(tempStorage);
	for (iPos; iPos >= 0; iPos = StorageList.GetNextItem(tempStorage))
	{
		tempStorage.DisplayAllRecord();
	}
}

void Application::DIsplayAllContainer()
{
	StorageType tempStorage;
	StorageList.ResetList();
	int iPos = StorageList.GetNextItem(tempStorage);
	for (iPos; iPos >= 0; iPos = StorageList.GetNextItem(tempStorage))
	{
		tempStorage.DisplayAllRecord();
		tempStorage.DisplayAllContainer();
	}
}

void Application::DisplayAllDetailContainer()
{
	StorageType tempStorage;
	StorageList.ResetList();
	int iPos = StorageList.GetNextItem(tempStorage);
	for (iPos; iPos >= 0; iPos = StorageList.GetNextItem(tempStorage))
	{
		tempStorage.DisplayAllRecord();
		tempStorage.DisplayAllDetailsContainer(MasterList);
	}
}


// ContainerList
int Application::AddContainer()
{
	StorageType targetStorage;
	StorageType* ptr;
	cout << "\t[�����̳ʸ� ������ ��������� �Է��ϼ���.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(targetStorage) != 1) {
		cout << "\t[�˻��Ͻ� ��������� �������� �ʽ��ϴ�.]" << endl;
		return 0;
	}
	else
	{
		ptr = &targetStorage;
		ContainerType newContainer;
		cout << "\t[������ ���ο� �����̳ʸ� �Է��ϼ���.]" << endl;
		newContainer.SetRecordFromKB();
		if ((*ptr).AddContainer(newContainer) == 1) {
			cout << "\t[�����̳� ������ �����Ͽ����ϴ�.]" << endl;
			return 1;
		}
		else if ((*ptr).AddContainer(newContainer) == -1) {
			cout << "\t[�̹� �����ϴ� �����̳� �Դϴ�.]" << endl;
		}
		cout << "\t[�����̳� ������ �����Ͽ����ϴ�.]" << endl;
	}
	return 0;
}

int Application::AddContainer(ContainerType& _container)
{
	StorageType targetStorage;
	StorageType* ptr;
	cout << "\t[�����̳ʸ� ������ ��������� �Է��ϼ���.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(targetStorage) != 1) {
		cout << "\t[�˻��Ͻ� ��������� �������� �ʽ��ϴ�.]" << endl;
		return 0;
	}
	else
	{
		ptr = &targetStorage;
		if ((*ptr).AddContainer(_container) == 1) {
			cout << "\t[�����̳� ������ �����Ͽ����ϴ�.]" << endl;
			return 1;
		}
		else if ((*ptr).AddContainer(_container) == -1) {
			cout << "\t[�̹� �����ϴ� �����̳� �Դϴ�.]" << endl;
		}
		cout << "\t[�����̳� ������ �����Ͽ����ϴ�.]" << endl;
	}
	return 0;
}

int Application::DeleteContainer()
{
	StorageType targetStorage;
	cout << "\t[�����̳ʸ� ������ ��������� �Է��ϼ���.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(targetStorage) != 1) {
		cout << "\t[�˻��Ͻ� ��������� �������� �ʽ��ϴ�.]" << endl;
		return 0;
	}
	else
	{
		ContainerType targetContainer;
		cout << "\t[������ �����̳ʸ� �Է��ϼ���.]" << endl;
		targetContainer.SetRecordFromKB();
		if (targetStorage.DeleteContainer(targetContainer) == 1) {
			cout << "\t[�����̳� ������ �����Ͽ����ϴ�.]" << endl;
			return 1;
		}
		cout << "\t[�����̳� ������ �����Ͽ����ϴ�.]" << endl;
	}
	return 0;
}

int Application::ReplaceContainer()
{
	StorageType targetStorage;
	cout << "\t[�����̳� ������ ���ε��� ��������� �Է��ϼ���.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(targetStorage) != 1) {
		cout << "\t[�˻��Ͻ� ��������� �������� �ʽ��ϴ�.]" << endl;
		return 0;
	}
	else
	{
		ContainerType targetContainer;
		cout << "\t[������ ���ε��� �����̳ʸ� �Է��ϼ���.]" << endl;
		targetContainer.SetRecordFromKB();
		if (targetStorage.UpdateContainer(targetContainer) == 1) {
			cout << "\t[�����̳� ���� ���ε忡 �����Ͽ����ϴ�.]" << endl;
			return 1;
		}
		cout << "\t[�����̳� ���� ���ε忡 �����Ͽ����ϴ�.]" << endl;
	}
	return 0;
}

void Application::DisplayAllsItem()
{

}

void Application::DisplayAllPhoto()
{

}

void Application::DisplayAllDetailsItem()
{

}

// TempList
void Application::AddTempItem()
{

}

void Application::DequeueFromTempList()
{

}

void Application::PrintTempList()
{

}



// function
int Application::Search_Display_ByUsage()
{
	return 0;
}

int SearchByDate()
{
	return 0;
}