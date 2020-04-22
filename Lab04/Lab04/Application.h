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
		// (1) file���� �Է¹޴´�.
		// (2) ������ ���������� ������ �ʾ�����, ����(0)�� return.
		// (3) ���� �о����
		//	   - �������� ������ temp ����, ������ �ʱ�ȭ.
		//	   - ������ ���� �����Ҷ����� loop [!m_InFile.eof()] ����
		//	   - �о���� -> �о�� �κ��� ������ Ȯ��(�����Ǵ�) -> ����Ʈ ����.
		// (4) ���� ����
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
		// (1) file���� �Է¹޴´�.
		// (2) ������ ���������� ������ �ʾ�����, ����(0)�� return.
		// (3) ����Ʈ�� ����ִ��� Ȯ��. ��������� ����(0)�� return.
		// (4) ���� �о����
		//	   - �������� ������ temp ����, ������ �ʱ�ȭ.
		//	   - ����Ʈ�� ������ item���� ������ ����.
		//	   - ������ item�� ���Ͽ� �ۼ�.
		// (5) ���� ����
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