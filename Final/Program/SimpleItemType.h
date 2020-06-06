#pragma once
//--------------------------------------------------------------------
//		SimpleItem information class.
//--------------------------------------------------------------------
class SimpleItemType
{
private:
	int m_Serial;					///<  물건의 고유번호.
	string m_Name;					///<  물건의 이름.


public:
	SimpleItemType()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		m_Serial = -1;
		m_Name = "";
	}


	~SimpleItemType() {}
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


	void SetRecord(int inSerial, string inName);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//	Param:	inContainerID	container id.
	//	Param:	inName			commodity name.
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


	void SetRecordFromKB();
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


	void DisplayRecordOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity record on screen.
	//	Pre:	commodity record is set.
	//	Post:	commodity record is on screen.
	//--------------------------------------------------------------------


	int ReadDataFromFile(ifstream& fin);
	//--------------------------------------------------------------------
	//	Brief:	Read a record from a file.
	//	Pre:	the target file is opened.
	//	Post:	student record is set.
	//	Param:	fin		file descriptor.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int WriteDataToFile(ofstream& fout);
	//--------------------------------------------------------------------
	//	Brief:	Write a record into file.
	//	Pre:	the target file is opened, and the list is initialized.
	//	Post:	the target file includes new record.
	//	Param:	fout		file descriptor.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	void GetRecordFromItemType(ItemType*& _item);
	//--------------------------------------------------------------------
	//	Brief:	Get an information from itemType.
	//	Pre:	the target item is initialized.
	//	Post:	target item's information is copied.
	//	Param:	_item		target item for copying.
	//--------------------------------------------------------------------


	// Overload operator==
	bool operator==(const SimpleItemType& _sitem) {
		if (m_Serial == _sitem.GetID())
			return true;
		return false;
	}


	// Overload operator>
	bool operator>(const SimpleItemType& _sitem) {
		if (m_Serial > _sitem.GetID())
			return true;
		return false;
	}


	// Overload operator<
	bool operator<(const SimpleItemType& _sitem) {
		if (m_Serial < _sitem.GetID())
			return true;
		return false;
	}


	// Overload operator=
	void operator=(const SimpleItemType& _sitem) {
		m_Serial = _sitem.GetID();
		m_Name = _sitem.GetName();
	}


	// Overload operator<<
	friend ostream& operator<<(ostream& _out, SimpleItemType& _sitem)
	{
		_out << "\t+--------------------------+" << endl;
		_out << "\tID   : " << _sitem.GetID() << endl;
		_out << "\tNAME : " << _sitem.GetName() << endl;
		_out << "\t+--------------------------+" << endl;

		return _out;
	}
};