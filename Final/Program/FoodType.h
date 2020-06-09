#pragma once
//--------------------------------------------------------------------
//		Food Item information class.
//--------------------------------------------------------------------
class FoodType : public ItemType
{
private:
	int m_Type;							///<  FoodType을 알려주는 타입번호.
	int m_PurchaseDate;					///<  구매일
	int m_ExpirationDate;				///<  유통기한


public:
	FoodType() :ItemType()
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------
	{
		m_Type = 1;
		m_PurchaseDate = -1;
		m_ExpirationDate = -1;
	}


	FoodType(int _serial, string _name, int _num, int _price, int _pDate, int _eDate) : ItemType(_serial, _name, _num, _price) 
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------
	{
		m_Type = 1;
		m_PurchaseDate = _pDate;
		m_ExpirationDate = _eDate;
	}


	~FoodType() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	int GetType() const;
	//--------------------------------------------------------------------
	//	Brief:	Get Type number.
	//	Pre:	none.
	//	Post:	none.
	//	Return: Type number.
	//--------------------------------------------------------------------


	int GetPurchaserDate() const;
	//--------------------------------------------------------------------
	//	Brief:	Get purchase date.
	//	Pre:	none.
	//	Post:	none.
	//	Return: purchase date.
	//--------------------------------------------------------------------


	int GetExpirationDate() const;
	//--------------------------------------------------------------------
	//	Brief:	Get expiration date.
	//	Pre:	none.
	//	Post:	none.
	//	Return: expiration date.
	//--------------------------------------------------------------------


	void SetPurchaserDate(int _date);
	//--------------------------------------------------------------------
	//	Brief:	Set purchase date.
	//	Pre:	none.
	//	Post:	purchase date is set.
	//	Param:	_date		purchase date.
	//--------------------------------------------------------------------


	void SetExpirationDate(int _date);
	//--------------------------------------------------------------------
	//	Brief:	Set expiration date.
	//	Pre:	none.
	//	Post:	expiration date is set.
	//	Param:	_date		expiration date
	//--------------------------------------------------------------------


	void SetRecord(int _serial, string _name, int _num, int _price, int _pDate, int _eDate);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//	Param:	_serial			commodity id.
	//	Param:	_name			commodity name.
	//	Param:	_num			commodity number.
	//  Param:  _price			commodity price.
	//	Param:	_pDate			purchase date.
	//	Param:	_eDate			expiration date.
	//--------------------------------------------------------------------


	void SetPurchaseDateFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set purchase date from keyboard
	//	Pre:	none.
	//	Post:	purchase date is set.
	//--------------------------------------------------------------------


	void SetExpirationDateFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set expiration date from keyboard
	//	Pre:	none.
	//	Post:	commodity name is set.
	//--------------------------------------------------------------------


	void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record from keyboard.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//--------------------------------------------------------------------


	void DisplayPurchaseDateOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display purchase date on screen.
	//	Pre:	commodity serial is set.
	//	Post:	commodity serial is on screen.
	//--------------------------------------------------------------------


	void DisplayExpirationDateOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display expiration date on screen.
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


	// Overload operator=
	void operator=(const FoodType*& _item) {
		m_Serial = _item->GetID();
		m_Name = _item->GetName();
		m_Num = _item->GetNum();
		m_Price = _item->GetPrice();
		m_PurchaseDate = this->GetPurchaserDate();
		m_ExpirationDate = this->GetExpirationDate();
	}


	void print(ostream& _out) const
	{
		_out << "\t+--------------------------+" << endl;
		_out << "\t|         FOODTYPE         |" << endl;
		_out << "\t+--------------------------+" << endl;
		_out << "\tID   : " << GetID() << endl;
		_out << "\tNAME : " << GetName() << endl;
		_out << "\tNUM  : " << GetNum() << endl;
		_out << "\tPRICE: " << GetPrice() << endl;
		_out << "\tDATE : " << this->GetPurchaserDate() << endl;
		_out << "\tEX   : " << this->GetExpirationDate() << endl;
		_out << "\t+--------------------------+" << endl;
	}
};