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
		if (MasterList.IsFull()) {  // MasterList�� capacity�� check.
			cout << "[ERROR : FULL MASTER!]" << '\n';
			return 0; 
		}

		ItemType item;				// Commodity�� ������ �Է¹޴´�.
		item.SetRecordFromKB();
		if (item.GetContainerID < 0) { // Commodity�� Container ������ ������(Negative)
			if (MasterList.Add(item)) { cout << "[SUCCESS ADD MASTER]" << '\n'; }
			else { cout << "[ERROR ON ADD MASTER!]" << '\n'; }
			if (TempList.Enqueue(item)) { cout << "[SUCCESS ADD TEMP]" << '\n'; }
			else { cout << "[ERROR ON ADD TEMP!]" << '\n'; }
			return 1;
		}
		else {
			if (ContainerList.IsEmpty()) {
				ContainerType container;
				// �����̳� ��ȣ�� ��ġ �̸� ������ �Է��ϴ� �Լ� �ʿ�
				ContainerList.Add(container); // �����̳ʸ� �Է�
				// ��Ī�ϴ� �����̳ʸ� ã�Ƽ� �ش� �����̳��� ����Ʈ�� �ִ� �Լ�.
			}
			else {
				// sortedlist���� �����̳� ���̵�� ��Ī�ϴ� �Լ��ʿ�.
			}
			// �����̳� ����Ʈ�� ��������� �ٷ� ����
			// �����̳� ����Ʈ�� ������� ������ ã��
			// item�� �����̳� ��ȣ�� ��ϵǾ� ������
			// �����̳�Ÿ�Կ� �ִ� �ش� ��ȣ�� �����̳ʰ� �ִ��� Ȯ���ϰ�
			// ������ �� �����̳ʾ��� ����Ʈ�� ����
			// ������ �����̳ʰ� full���� ���� Ȯ���ϰ�, �����̳� ������ �߰�
			// ���� item�� ���
			
		}
	}

	int DeleteCommodityMaster();

	int UpdateCommodityMastser();

	int BinarySearchCommodityMaster();

	void DisplayAllMaster();

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