#pragma once
//--------------------------------------------------------------------
//		APPLICATION
//--------------------------------------------------------------------
class Application
{
private:
	SortedList<ItemType> MasterList;
	SortedList<StorageType> StorageList;
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


	int AddStorage();

	void DisplayStorage();

	int AddContainer();

	void DisplayAllContainer();

	void DisplayAllDetailsContainer();

	// Open a file by file descriptor as an input file.
	int OpenInFile(char* filename)
		//----------------------------------------------------------------
		// (1) return 1 if the file is opened successfully, 
		//	   otherwise return 0.
		// ---------------------------------------------------------------
	{
		m_InFile.open(filename);									// (1).
		if (!m_InFile)	return 0;
		else	return 1;
	}


	// Open a file by file descriptor as an output file.
	int OpenOutFile(char* filename)
		//----------------------------------------------------------------
		// (1) return 1 if the file is opened successfully, 
		//	   otherwise return 0.
		//----------------------------------------------------------------
	{
		m_OutFile.open(filename);									// (1).
		if (!m_OutFile)	return 0;
		else	return 1;
	}


	// Open a file as a read mode, read all data on the file, and set list by the data.
	int ReadDataFromFile()
		//----------------------------------------------------------------
		// (1) file명을 입력받는다.
		// (2) 파일이 성공적으로 열리지 않았으면, 실패(0)을 return.
		// (3) 파일 읽어오기
		//	   - 아이템을 저장할 temp 선언, 포인터 초기화.
		//	   - 파일의 끝에 도달할때까지 loop [!m_InFile.eof()] 시작
		//	   - 읽어오기 -> 읽어온 부분이 끝인지 확인(정지판단) -> 리스트 삽입.
		// (4) 파일 종료
		//----------------------------------------------------------------
	{
		char filename[FILENAMESIZE];								// (1).
		cout << "\n\tEnter Input file Name : ";
		cin >> filename;


		if (!OpenInFile(filename))									// (2).
			return 0;

		ItemType temp;												// (3).
		while (!m_InFile.eof())
		{
			temp.ReadDataFromFile(m_InFile);
			MasterList.Add(temp);
		}


		m_InFile.close();											// (4).
		return 1;
	}

	// Open a file as a write mode, and write all data into the file
	int WriteDataToFile()
		//----------------------------------------------------------------
		// (1) file명을 입력받는다.
		// (2) 파일이 성공적으로 열리지 않았으면, 실패(0)을 return.
		// (3) 리스트가 비어있는지 확인. 비어있으면 실패(0)을 return.
		// (4) 파일 읽어오기
		//	   - 아이템을 저장할 temp 선언, 포인터 초기화.
		//	   - 리스트의 마지막 item까지 순차적 접근.
		//	   - 접근한 item을 파일에 작성.
		// (5) 파일 종료
		//----------------------------------------------------------------
	{
		char filename[FILENAMESIZE];								// (1).
		cout << "\n\tEnter Output file Name : ";
		cin >> filename;

		if (!OpenOutFile(filename))									// (2).
			return 0;

		if (MasterList.IsEmpty()) { return 0; }							// (3).

		ItemType temp;												// (4).
		MasterList.ResetList();
		int iPos = MasterList.GetNextItem(temp);
		for (iPos; iPos > -1; iPos = MasterList.GetNextItem(temp)) {
			temp.WriteDataToFile(m_OutFile);
		}

		m_OutFile.close();											// (5).
		return 1;
	}
};