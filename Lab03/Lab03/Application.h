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
		if (MasterList.IsFull()) {  // MasterList의 capacity를 check.
			cout << "[ERROR : FULL MASTER!]" << '\n';
			return 0; 
		}

		ItemType item;				// Commodity의 정보를 입력받는다.
		item.SetRecordFromKB();
		if (item.GetContainerID < 0) { // Commodity의 Container 정보가 없으면(Negative)
			if (MasterList.Add(item)) { cout << "[SUCCESS ADD MASTER]" << '\n'; }
			else { cout << "[ERROR ON ADD MASTER!]" << '\n'; }
			if (TempList.Enqueue(item)) { cout << "[SUCCESS ADD TEMP]" << '\n'; }
			else { cout << "[ERROR ON ADD TEMP!]" << '\n'; }
			return 1;
		}
		else {
			if (ContainerList.IsEmpty()) {
				ContainerType container;
				// 컨테이너 번호와 위치 이름 정보를 입력하는 함수 필요
				ContainerList.Add(container); // 컨테이너를 입력
				// 매칭하는 컨테이너를 찾아서 해당 컨테이너의 리스트에 넣는 함수.
			}
			else {
				// sortedlist에서 컨테이너 아이디와 매칭하는 함수필요.
			}
			// 컨테이너 리스트가 비어있으면 바로 생성
			// 컨테이너 리스트가 비어있지 않으면 찾기
			// item에 컨테이너 번호가 등록되어 있으면
			// 컨테이너타입에 있는 해당 번호의 컨테이너가 있는지 확인하고
			// 있으면 그 컨테이너안의 리스트에 삽입
			// 없으면 컨테이너가 full인지 먼저 확인하고, 컨테이너 정보를 추가
			// 이후 item을 등록
			
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