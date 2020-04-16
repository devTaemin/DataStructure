#ifndef _APPLICATION_H_
#define _APPLICATION_H_
//--------------------------------------------------------------------
//		APPLICATION
//--------------------------------------------------------------------
class Application
{
private:
	SortedList<ItemType> MasterList;
	SortedList<ContainerType> ContainerList;
	TempType TempList;
	ifstream m_InFile;
	ofstream m_OutFile;
	int m_Command;

public:
	Application();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	~Application();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	void Run();
	//--------------------------------------------------------------------
	//	Brief:	Program driver.
	//	Pre:	program is started.
	//	Post:	program is finished.
	//--------------------------------------------------------------------


	int GetCommand();
	//--------------------------------------------------------------------
	//	Brief:	Display command on screen and get a input from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	user's commands.
	//--------------------------------------------------------------------


	int AddCommodityMaster()
	{
		if (MasterList.IsFull()) { return 0; }
		ItemType item;				// Commodity�� ������ �Է¹޴´�.
		item.SetRecordFromKB();
		MasterList.Add(item);

		if (item.GetContainerID() < 0) {
			TempList.Enqueue(item);
			return 1;
		}

		ContainerType Container;	// �����̳� ����, �����̳� ���̵�� ���� �Է� ��, �����̳� ����Ʈ�� �߰�.
		Container.SetContainerID(item.GetContainerID()); // item�� container id�� �����Ͽ� �����̳� ����.
		Container.DisplayContainerIDOnScreen();	// item�� container id ȭ�鿡 ���.
		Container.SetContainerLocationFromKB(); // item�� container location�� �Է¹޴´�.
		Container.AddItem(item);
		
		return 1;
	}
	/*
	{
		if (MasterList.IsFull()) {  // MasterList�� capacity�� check.
			cout << "[ERROR : FULL MASTER LIST!]" << '\n';
			return 0; 
		}

		ItemType item;				// Commodity�� ������ �Է¹޴´�.
		item.SetRecordFromKB();
		if (item.GetContainerID() < 0) { // Commodity�� Container ������ ������(Negative)
			if (TempList.IsFull()){		// TempList�� capacity�� check.
				cout << "[ERROR : FULL TEMP LIST!]" << '\n'; 
				return 0;
			}	// MasterList�� TempList�� ������ ����.
			if (MasterList.Add(item)) { 
				cout << "[SUCCESS ADD MASTER LIST]" << '\n'; 
				if (TempList.Enqueue(item)) { 
					cout << "[SUCCESS ADD TEMP LIST]" << '\n'; 
					return 1;
				}
				else { 
					cout << "[ERROR ON ADD TEMP LIST!]" << '\n'; 
					return 0;
				}
			}
			else { cout << "[ERROR ON ADD MASTER LIST!]" << '\n'; }
			return 0;
		}
		else {
			if (ContainerList.IsEmpty()) {
				ContainerType Container;	// �����̳� ����, �����̳� ���̵�� ���� �Է� ��, �����̳� ����Ʈ�� �߰�.
				Container.SetContainerID(item.GetContainerID()); // item�� container id�� �����Ͽ� �����̳� ����.
				Container.DisplayContainerIDOnScreen();	// item�� container id ȭ�鿡 ���.
				Container.SetContainerLocationFromKB(); // item�� container location�� �Է¹޴´�.
				if (Container.AddItem(item)) {	// container�� item �Է��� �����ϸ�, ContainerList�� container�� �߰�. ����(1)
					ContainerList.Add(Container);
					MasterList.Add(item);
					cout << "[SUCCESS ADD MASTER, CONTAINER LIST]" << '\n';
					return 1;
				}
				cout << "[ERROR ON ADD CONTAINER LIST!]" << '\n'; // container�� item �Է��� �����ϸ�, ���� �޼���, ����(0)
				return 0;
			}
			else {
				// ã�� ������ �ְ�, ã�� ������, full Ȯ���ϰ� 
				// ��Ī�ϴ� �����̳ʸ� ã�Ƽ� �ش� �����̳��� ����Ʈ�� �ִ� �Լ�.
				// sortedlist���� �����̳� ���̵�� ��Ī�ϴ� �Լ��ʿ�.
				// �����̳� ����Ʈ�� ��������� �ٷ� ����
				// �����̳� ����Ʈ�� ������� ������ ã��
				// item�� �����̳� ��ȣ�� ��ϵǾ� ������
				// �����̳�Ÿ�Կ� �ִ� �ش� ��ȣ�� �����̳ʰ� �ִ��� Ȯ���ϰ�
				// ������ �� �����̳ʾ��� ����Ʈ�� ����
				// ������ �����̳ʰ� full���� ���� Ȯ���ϰ�, �����̳� ������ �߰�
				// ���� item�� ���	
				ContainerType curContainer;
				ContainerList.ResetList();
				bool found = false;
				int iPos = ContainerList.GetNextItem(curContainer);
				for (iPos; iPos > 0; iPos = ContainerList.GetNextItem(curContainer)) {
					if (item.GetContainerID() == curContainer.GetContainerID()) {
						found = true;
						break;
					}
				}

				if (!found) {
					if (ContainerList.IsFull()) { 
						cout << "[ERROR: FULL CONTAINER LIST!]" << '\n';
						return 0; 
					}
					ContainerType Container;	// �����̳� ����, �����̳� ���̵�� ���� �Է� ��, �����̳� ����Ʈ�� �߰�.
					Container.SetContainerID(item.GetContainerID()); // item�� container id�� �����Ͽ� �����̳� ����.
					Container.DisplayContainerIDOnScreen();	// item�� container id ȭ�鿡 ���.
					Container.SetContainerLocationFromKB(); // item�� container location�� �Է¹޴´�.
					if (Container.AddItem(item)) {	// container�� item �Է��� �����ϸ�, ContainerList�� container�� �߰�. ����(1)
						ContainerList.Add(Container);
						MasterList.Add(item);
						cout << "[SUCCESS ADD MASTER, CONTAINER LIST]" << '\n';
						return 1;
					}
					cout << "[ERROR ON ADD CONTAINER LIST!]" << '\n'; // container�� item �Է��� �����ϸ�, ���� �޼���, ����(0)
					return 0;
				}
				else {
					if (curContainer.AddItem(item)) {
						MasterList.Add(item);
						cout << "[SUCCESS ADD MASTER, CONTAINER LIST]" << '\n';
						return 1;
					}
					cout << "[ERROR ON ADD CONTAINER LIST!]" << '\n'; // container�� item �Է��� �����ϸ�, ���� �޼���, ����(0)
					return 0;
				}
			}
			
		}
		return 0;
	}
	*/


	int DeleteCommodityMaster();


	int UpdateCommodityMastser();


	int BinarySearchCommodityMaster();
	

	void DisplayAllMaster()
	{
		ItemType curItem;
		MasterList.ResetList();
		int iPos = MasterList.GetNextItem(curItem);
		for (iPos; iPos >= 0; iPos = MasterList.GetNextItem(curItem)) {
			cout << '\n';
			curItem.DisplayRecordOnScreen();
		}
	}

	void MakeEmptyMaster();


	int OpenInFile(char* filename);


	int OpenOutFile(char* filename);


	int ReadDataFromFile();


	int WriteDataToFile();

	//-----------------------------------------------------

	int AddCommodityTemp();

	int DequeueCommodityTemp();

	void DisplayAllTemp();

	//-------------------------------------------------------

	int AddPhotoContainer();

	int DeletePhotoContainer();

	void DisplayAllPhotoContainer();

	void DisplayAllCommodityContainer();

	void DIsplayAllDetailContainer();

};
#endif _APPLICATION_H_