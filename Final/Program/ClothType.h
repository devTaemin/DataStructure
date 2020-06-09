#pragma once
//--------------------------------------------------------------------
//		Cloth Item information class.
//--------------------------------------------------------------------
class ClothType : public ItemType
{
private:
	int m_Type;						///<  ClothType을 알려주는 타입번호.
	int m_Size;						///<  옷 사이즈.
	string m_Material;				///<  소재


public:
	ClothType() :ItemType()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		m_Type = 2;
		m_Size = -1;
		m_Material = "";
	}


	ClothType(int _serial, string _name, int _num, int _price, int _size, string _material) : ItemType(_serial, _name, _num, _price)
		//--------------------------------------------------------------------
		//		Constructor.
		//--------------------------------------------------------------------
	{
		m_Type = 2;
		m_Size = _size;
		m_Material = _material;
	}


	~ClothType() {}
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


	int GetID() const;
	//--------------------------------------------------------------------
	//	Brief:	Get commodity serial.
	//	Pre:	commodity serial is set.
	//	Post:	none.
	//	Return: commodity serial.
	//--------------------------------------------------------------------


	int GetSize() const;
	//--------------------------------------------------------------------
	//	Brief:	Get cloth size.
	//	Pre:	none.
	//	Post:	none.
	//	Return: cloth size.
	//--------------------------------------------------------------------


	string GetMaterial() const;
	//--------------------------------------------------------------------
	//	Brief:	Get cloth material.
	//	Pre:	none.
	//	Post:	none.
	//	Return: cloth material.
	//--------------------------------------------------------------------


	void SetSize(int _size);
	//--------------------------------------------------------------------
	//	Brief:	Set cloth size.
	//	Pre:	none.
	//	Post:	cloth size is set.
	//	Param:	_size		cloth size.
	//--------------------------------------------------------------------


	void SetMaterial(string _material);
	//--------------------------------------------------------------------
	//	Brief:	Set cloth material.
	//	Pre:	none.
	//	Post:	cloth material is set.
	//	Param:	_material		cloth material
	//--------------------------------------------------------------------


	void SetRecord(int _serial, string _name, int _num, int _price, int _size, string _material);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//	Param:	_serial			commodity id.
	//	Param:	_name			commodity name.
	//	Param:	_num			commodity number.
	//  Param:  _price			commodity price.
	//	Param:	_size			cloth size.
	//	Param:	_material		cloth material.
	//--------------------------------------------------------------------


	void SetSizeFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set cloth size from keyboard
	//	Pre:	none.
	//	Post:	cloth size is set.
	//--------------------------------------------------------------------


	void SetMaterialFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set cloth material from keyboard
	//	Pre:	none.
	//	Post:	cloth material is set.
	//--------------------------------------------------------------------


	void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record from keyboard.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//--------------------------------------------------------------------


	void DisplaySizeOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display cloth size on screen.
	//	Pre:	commodity size is set.
	//	Post:	commodity size is on screen.
	//--------------------------------------------------------------------


	void DisplayMaterialOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display cloth material on screen.
	//	Pre:	commodity material is set.
	//	Post:	commodity material is on screen.
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
	void operator=(const ItemType*& _item) {
		m_Serial = _item->GetID();
		m_Name = _item->GetName();
		m_Num = _item->GetNum();
		m_Price = _item->GetPrice();
		m_Size = this->GetSize();
		m_Material = this->GetMaterial();
	}


	void print(ostream& _out) const
	{
		_out << "\t+--------------------------+" << endl;
		_out << "\t|        CLOTHTYPE         |" << endl;
		_out << "\t+--------------------------+" << endl;
		_out << "\tID   : " << GetID() << endl;
		_out << "\tNAME : " << GetName() << endl;
		_out << "\tNUM  : " << GetNum() << endl;
		_out << "\tPRICE: " << GetPrice() << endl;
		_out << "\tSIZE : " << this->GetSize() << endl;
		_out << "\tMATERIAL : " << this->GetMaterial() << endl;
		_out << "\t+--------------------------+" << endl;
	}
};