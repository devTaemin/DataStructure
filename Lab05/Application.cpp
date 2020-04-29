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
			cout << "[ERROR: 잘못된 입력입니다.]" << endl;
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
	cout << "\t========Container=======" << endl;
	
	


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
	cout << "\t[생성할 저장 공간을 입력하시오.]" << endl;
	newStorage.SetRecordFromKB();
	if (StorageList.Add(newStorage) == 1) {
		cout << "\t[새로운 저장공간이 생성되었습니다.]" << endl;
		return 1;
	}
	else if (StorageList.Add(newStorage) == -1) {
		cout << "\t[이미 생성된 저장공간입니다.]" << endl;
	}
	cout << "\t[저장공간 생성에 실패하였습니다.]" << endl;
	return 0;
}

int Application::AddStorage(StorageType& _storage)
{
	if (StorageList.Add(_storage) == 1) {
		cout << "\t[새로운 저장공간이 생성되었습니다.]" << endl;
		return 1;
	}
	else if (StorageList.Add(_storage) == -1) {
		cout << "\t[이미 생성된 저장공간입니다.]" << endl;
	}
	cout << "\t[저장공간 생성에 실패하였습니다.]" << endl;
	return 0;
}

int Application::DeleteStorage()
{
	StorageType targetStorage;
	cout << "\t[삭제할 저장 공간을 입력하시오.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.Delete(targetStorage) == 1) {
		cout << "\t[저장 공간 삭제에 성공하였습니다.]" << endl;
		return 1;
	}
	cout << "\t[저장 공간 삭제에 실패하였습니다.]" << endl;
	return 0;
}


int Application::ReplaceStorage()
{
	StorageType targetStorage;
	StorageType tempStorage;
	SingleLinkedList<ContainerType> tempContainerList;

	cout << "\t[교체할 저장 공간을 입력하시오.]" << endl;
	targetStorage.SetRecordFromKB();
	tempStorage.SetId(targetStorage.GetId());
	

	if (StorageList.GetByBinarySearch(tempStorage) != 1) { 
		cout << "\t[검색한 저장 공간은 존재하지 않습니다.]" << endl;
	}
	else {
		int _command;
		while (1) {
			cout << "\t[이전에 보관한 컨테이너를 유지하시겠습니까?] - [NO(0) / YES(1)] : ";
			cin >> _command;
			if (_command == 1) {
				targetStorage.SetLength(tempStorage.GetLength());
				targetStorage.SetContainerList(tempStorage.GetContainerList());
			}
			else if (_command == 0) { break; }
			else { cout << "잘못된 입력입니다." << endl; }
		}
		if (StorageList.Replace(targetStorage) == 1) {
			cout << "\t[저장 공간 교체에 성공하였습니다.]" << endl;
			return 1;
		}
	}
	cout << "\t[저장 공간 교체에 실패하였습니다.]" << endl;
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
	cout << "\t[저장 공간을 선택하시오.]" << endl;
	tempStorage.SetIdFromKB();
	StorageList.ResetList();
	if (StorageList.GetByBinarySearch(tempStorage) != 1){
		cout << "\t[해당 저장 공간을 찾지 못하였습니다.]" << endl;
		return;
	}
	tempStorage.DisplayAllRecord();
	cout << "+=============Container=============+" << endl;
	if (tempStorage.GetLength() != 0) {
		tempStorage.DisplayAllContainer();
	}
	else { cout << "\t      [E M P T Y]" << endl; }
	cout << "+===================================+" << endl;
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
	cout << "\t[컨테이너를 생성할 저장공간을 입력하세요.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(targetStorage) != 1) {
		cout << "\t[검색하신 저장공간은 존재하지 않습니다.]" << endl;
		return 0;
	}
	else
	{
		if (targetStorage.isFull()) {
			cout << "\t[추가 가능한 컨테이너 용량이 부족합니다.]" << endl;
			return 0;
		}
		ptr = &targetStorage;
		//ContainerType newContainer;
		ContainerType *newContainer=new ContainerType;
		cout << "\t[생성할 새로운 컨테이너를 입력하세요.]" << endl;
		newContainer->SetRecordFromKB();
		if ((*ptr).AddContainer(*newContainer) == 1) {
			//추가한 부분
			StorageList.Replace(*ptr);
			cout << "\t[컨테이너 생성에 성공하였습니다.]" << endl;
			return 1;
		}
		else if ((*ptr).AddContainer(*newContainer) == -1) {
			cout << "\t[이미 존재하는 컨테이너 입니다.]" << endl;
		}
		cout << "\t[컨테이너 생성에 실패하였습니다.]" << endl;
	}
	return 0;
}

int Application::AddContainer(ContainerType& _container) // 고쳐야함
{
	StorageType targetStorage;
	StorageType* ptr;
	cout << "\t[컨테이너를 생성할 저장공간을 입력하세요.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(targetStorage) != 1) {
		cout << "\t[검색하신 저장공간은 존재하지 않습니다.]" << endl;
		return 0;
	}
	else
	{
		ptr = &targetStorage;
		if ((*ptr).AddContainer(_container) == 1) {
			cout << "\t[컨테이너 생성에 성공하였습니다.]" << endl;
			return 1;
		}
		else if ((*ptr).AddContainer(_container) == -1) {
			cout << "\t[이미 존재하는 컨테이너 입니다.]" << endl;
		}
		cout << "\t[컨테이너 생성에 실패하였습니다.]" << endl;
	}
	return 0;
}

int Application::DeleteContainer()
{
	StorageType targetStorage;
	cout << "\t[컨테이너를 삭제할 저장공간을 입력하세요.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(targetStorage) != 1) {
		cout << "\t[검색하신 저장공간은 존재하지 않습니다.]" << endl;
		return 0;
	}
	else
	{
		ContainerType targetContainer;
		cout << "\t[삭제할 컨테이너를 입력하세요.]" << endl;
		targetContainer.SetRecordFromKB();
		if (targetStorage.DeleteContainer(targetContainer) == 1) {
			cout << "\t[컨테이너 삭제에 성공하였습니다.]" << endl;
			return 1;
		}
		cout << "\t[컨테이너 삭제에 실패하였습니다.]" << endl;
	}
	return 0;
}

int Application::ReplaceContainer()
{
	StorageType targetStorage;
	cout << "\t[컨테이너 정보를 업로드할 저장공간을 입력하세요.]" << endl;
	targetStorage.SetIdFromKB();
	if (StorageList.GetByBinarySearch(targetStorage) != 1) {
		cout << "\t[검색하신 저장공간은 존재하지 않습니다.]" << endl;
		return 0;
	}
	else
	{
		ContainerType targetContainer;
		cout << "\t[정보를 업로드할 컨테이너를 입력하세요.]" << endl;
		targetContainer.SetRecordFromKB();
		if (targetStorage.UpdateContainer(targetContainer) == 1) {
			cout << "\t[컨테이너 정보 업로드에 성공하였습니다.]" << endl;
			return 1;
		}
		cout << "\t[컨테이너 정보 업로드에 실패하였습니다.]" << endl;
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