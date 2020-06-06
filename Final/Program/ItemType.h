#pragma once
//--------------------------------------------------------------------
//		Item information class.
//--------------------------------------------------------------------
class ItemType
{
protected:
	int m_Serial;					///<  물건의 고유번호.
	string m_Name;					///<  물건의 이름.
	int m_Num;						///<  물건의 수량.


public:
	ItemType()
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------
	{
		m_Serial = -1;
		m_Name = "";
		m_Num = -1;
	}


	ItemType(int _serial, string _name, int _num)
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------
	{
		m_Serial = _serial;
		m_Name = _name;
		m_Num = _num;
	}


	~ItemType() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	int GetID() const;
	//--------------------------------------------------------------------
	//	Brief:	Get commodity serial.
	//	Pre:	commodity serial is set.
	//	Post:	none.
	//	Return: commodity serial.
	//--------------------------------------------------------------------


	string GetName() const;
	//--------------------------------------------------------------------
	//	Brief:	Get commodity name.
	//	Pre:	commodity name is set.
	//	Post:	none.
	//	Return: commodity name.
	//--------------------------------------------------------------------


	int GetNum() const;
	//--------------------------------------------------------------------
	//	Brief:  Get commodity number.
	//	Pre:	commodity number is set.
	//	Post:	none.
	//	Return: commodity number.
	//--------------------------------------------------------------------


	void SetSerial(int inSerial);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity serial.
	//	Pre:	none.
	//	Post:	commodity serial is set.
	//	Param:	inName		commodity name.
	//--------------------------------------------------------------------


	void SetName(string inName);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity name.
	//	Pre:	none.
	//	Post:	commodity name is set.
	//	Param:	inName		commodity name.
	//--------------------------------------------------------------------


	void SetNum(int inNum);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity number.
	//	Pre:	none.
	//	Post:	commodity number is set.
	//	Param:	inNum		commodity number.
	//--------------------------------------------------------------------


	virtual void SetRecord(int inSerial, string inName, int inNum);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//	Param:	inSerial		commodity id.
	//	Param:	inName			commodity name.
	//	Param:	inNum			commodity number.
	//--------------------------------------------------------------------


	void SetSerialFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity serial from keyboard
	//	Pre:	none.
	//	Post:	commodity serial is set.
	//--------------------------------------------------------------------


	void SetNameFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity name from keyboard
	//	Pre:	none.
	//	Post:	commodity name is set.
	//--------------------------------------------------------------------


	void SetNumFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity number from keyboard.
	//	Pre:	none.
	//	Post:	commodity number is set.
	//--------------------------------------------------------------------


	virtual void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record from keyboard.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//--------------------------------------------------------------------


	void DisplaySerialOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity serial on screen.
	//	Pre:	commodity serial is set.
	//	Post:	commodity serial is on screen.
	//--------------------------------------------------------------------


	void DisplayNameOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity name on screen.
	//	Pre:	commodity name is set.
	//	Post:	commodity name is on screen.
	//--------------------------------------------------------------------


	void DisplayNumOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity number on screen.
	//	Pre:	commodity number is set.
	//	Post:	commodity number is on screen.
	//--------------------------------------------------------------------


	virtual void DisplayRecordOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity record on screen.
	//	Pre:	commodity record is set.
	//	Post:	commodity record is on screen.
	//--------------------------------------------------------------------


	virtual int ReadDataFromFile(ifstream& fin);
	//--------------------------------------------------------------------
	//	Brief:	Read a record from a file.
	//	Pre:	the target file is opened.
	//	Post:	student record is set.
	//	Param:	fin		file descriptor.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	virtual int WriteDataToFile(ofstream& fout);
	//--------------------------------------------------------------------
	//	Brief:	Write a record into file.
	//	Pre:	the target file is opened, and the list is initialized.
	//	Post:	the target file includes new record.
	//	Param:	fout		file descriptor.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	// Overload operator==
	bool operator==(const ItemType*& _item) {
		if (m_Serial == _item->m_Serial)
			return true;
		return false;
	}


	// Overload operator>
	bool operator>(const ItemType*& _item) {
		if (m_Serial > _item->m_Serial)
			return true;
		return false;
	}


	// Overload operator<
	bool operator<(const ItemType*& _item) {
		if (m_Serial < _item->m_Serial)
			return true;
		return false;
	}


	// Overload operator=
	void operator=(const ItemType*& _item) {
		m_Serial = _item->GetID();
		m_Name = _item->GetName();
		m_Num = _item->GetNum();
	}


	// Overload operator<<
	friend ostream& operator<<(ostream& _out, ItemType*& _item)
	{
		_out << "\t+--------------------------+" << endl;
		_out << "\tID   : " << _item->GetID() << endl;
		_out << "\tNAME : " << _item->GetName() << endl;
		_out << "\tNUM  : " << _item->GetNum() << endl;
		_out << "\t+--------------------------+" << endl;

		return _out;
	}
};