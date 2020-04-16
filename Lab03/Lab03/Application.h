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
		ItemType item;				// Commodity의 정보를 입력받는다.
		item.SetRecordFromKB();
		MasterList.Add(item);

		if (item.GetContainerID() < 0) {
			TempList.Enqueue(item);
			return 1;
		}

		ContainerType Container;	// 컨테이너 생성, 컨테이너 아이디와 정보 입력 후, 컨테이너 리스트에 추가.
		Container.SetContainerID(item.GetContainerID()); // item의 container id에 대응하여 컨테이너 생성.
		Container.DisplayContainerIDOnScreen();	// item의 container id 화면에 출력.
		Container.SetContainerLocationFromKB(); // item의 container location을 입력받는다.
		Container.AddItem(item);
		
		return 1;
	}
	/*
	{
		if (MasterList.IsFull()) {  // MasterList의 capacity를 check.
			cout << "[ERROR : FULL MASTER LIST!]" << '\n';
			return 0; 
		}

		ItemType item;				// Commodity의 정보를 입력받는다.
		item.SetRecordFromKB();
		if (item.GetContainerID() < 0) { // Commodity의 Container 정보가 없으면(Negative)
			if (TempList.IsFull()){		// TempList의 capacity를 check.
				cout << "[ERROR : FULL TEMP LIST!]" << '\n'; 
				return 0;
			}	// MasterList와 TempList에 정보를 저장.
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
				ContainerType Container;	// 컨테이너 생성, 컨테이너 아이디와 정보 입력 후, 컨테이너 리스트에 추가.
				Container.SetContainerID(item.GetContainerID()); // item의 container id에 대응하여 컨테이너 생성.
				Container.DisplayContainerIDOnScreen();	// item의 container id 화면에 출력.
				Container.SetContainerLocationFromKB(); // item의 container location을 입력받는다.
				if (Container.AddItem(item)) {	// container에 item 입력을 성공하면, ContainerList에 container를 추가. 성공(1)
					ContainerList.Add(Container);
					MasterList.Add(item);
					cout << "[SUCCESS ADD MASTER, CONTAINER LIST]" << '\n';
					return 1;
				}
				cout << "[ERROR ON ADD CONTAINER LIST!]" << '\n'; // container에 item 입력을 실패하면, 에러 메세지, 실패(0)
				return 0;
			}
			else {
				// 찾고 있으면 넣고, 찾고 없으면, full 확인하고 
				// 매칭하는 컨테이너를 찾아서 해당 컨테이너의 리스트에 넣는 함수.
				// sortedlist에서 컨테이너 아이디와 매칭하는 함수필요.
				// 컨테이너 리스트가 비어있으면 바로 생성
				// 컨테이너 리스트가 비어있지 않으면 찾기
				// item에 컨테이너 번호가 등록되어 있으면
				// 컨테이너타입에 있는 해당 번호의 컨테이너가 있는지 확인하고
				// 있으면 그 컨테이너안의 리스트에 삽입
				// 없으면 컨테이너가 full인지 먼저 확인하고, 컨테이너 정보를 추가
				// 이후 item을 등록	
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
					ContainerType Container;	// 컨테이너 생성, 컨테이너 아이디와 정보 입력 후, 컨테이너 리스트에 추가.
					Container.SetContainerID(item.GetContainerID()); // item의 container id에 대응하여 컨테이너 생성.
					Container.DisplayContainerIDOnScreen();	// item의 container id 화면에 출력.
					Container.SetContainerLocationFromKB(); // item의 container location을 입력받는다.
					if (Container.AddItem(item)) {	// container에 item 입력을 성공하면, ContainerList에 container를 추가. 성공(1)
						ContainerList.Add(Container);
						MasterList.Add(item);
						cout << "[SUCCESS ADD MASTER, CONTAINER LIST]" << '\n';
						return 1;
					}
					cout << "[ERROR ON ADD CONTAINER LIST!]" << '\n'; // container에 item 입력을 실패하면, 에러 메세지, 실패(0)
					return 0;
				}
				else {
					if (curContainer.AddItem(item)) {
						MasterList.Add(item);
						cout << "[SUCCESS ADD MASTER, CONTAINER LIST]" << '\n';
						return 1;
					}
					cout << "[ERROR ON ADD CONTAINER LIST!]" << '\n'; // container에 item 입력을 실패하면, 에러 메세지, 실패(0)
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