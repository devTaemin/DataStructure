#pragma once
//--------------------------------------------------------------------
//		Item information class.
//--------------------------------------------------------------------
class ItemType
{				
protected:
	int m_Type;						///<  ItemType을 알려주는 타입번호.
	int m_Serial;					///<  물건의 고유번호.
	string m_Name;					///<  물건의 이름.
	int m_Num;						///<  물건의 수량.
	int m_Price;					///<  물건의 가격.

public:
	ItemType()
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------
	{
		m_Type = 0;
		m_Serial = -1;
		m_Name = "";
		m_Num = -1;
		m_Price = 0;
	}


	ItemType(int _serial, string _name, int _num, int _price)
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------
	{
		m_Type = 0;
		m_Serial = _serial;
		m_Name = _name;
		m_Num = _num;
		m_Price = _price;
	}


	~ItemType() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	virtual int GetType() const;
	//--------------------------------------------------------------------
	//	Brief:	Get Type number.
	//	Pre:	none.
	//	Post:	none.
	//	Return: Type number.
	//--------------------------------------------------------------------


	virtual int GetID() const;
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


	int GetPrice() const;
	//--------------------------------------------------------------------
	//	Brief:  Get commodity price.
	//	Pre:	commodity price is set.
	//	Post:	none.
	//	Return: commodity price.
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


	void SetPrice(int inPrice);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity price.
	//	Pre:	none.
	//	Post:	commodity price is set.
	//	Param:	inPrice		commodity price.
	//--------------------------------------------------------------------


	virtual void SetRecord(int inSerial, string inName, int inNum, int inPrice);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//	Param:	inSerial		commodity id.
	//	Param:	inName			commodity name.
	//	Param:	inNum			commodity number.
	//  Param:  inPrice			commodity price.
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


	void SetPriceFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity price from keyboard.
	//	Pre:	none.
	//	Post:	commodity price is set.
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


	void DisplayPriceOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity price on screen.
	//	Pre:	commodity price is set.
	//	Post:	commodity price is on screen.
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
	virtual bool operator==(const ItemType*& _item) {
		if (m_Serial == _item->m_Serial)
			return true;
		return false;
	}


	// Overload operator>
	virtual bool operator>(const ItemType*& _item) {
		if (m_Serial > _item->m_Serial)
			return true;
		return false;
	}


	// Overload operator<
	virtual bool operator<(const ItemType*& _item) {
		if (m_Serial < _item->m_Serial)
			return true;
		return false;
	}


	// Overload operator=
	virtual void operator=(const ItemType*& _item) {
		m_Serial = _item->GetID();
		m_Name = _item->GetName();
		m_Num = _item->GetNum();
		m_Price = _item->GetPrice();
	}


	// Overload operator<<
	friend ostream& operator<<(ostream& _out, ItemType*& _item)
	{
		_item->print(_out);
		return _out;
	}


	virtual void print(ostream& _out) const
	{
		_out << "\t+--------------------------+" << endl;
		_out << "\t|        ITEMTYPE          |" << endl;
		_out << "\t+--------------------------+" << endl;
		_out << "\tID   : " << GetID() << endl;
		_out << "\tNAME : " << GetName() << endl;
		_out << "\tNUM  : " << GetNum() << endl;
		_out << "\tPRICE: " << GetPrice() << endl;
		_out << "\t+--------------------------+" << endl;
	}
};