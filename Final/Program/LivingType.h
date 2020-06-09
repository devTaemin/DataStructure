#pragma once
//--------------------------------------------------------------------
//		Living Item information class.
//--------------------------------------------------------------------
class LivingType : public ItemType
{
private:
	int m_Type;							///<  LivingType을 알려주는 타입번호.
	string m_Color;						///<  가구 색상.
	string m_Material;					///<  소재


public:
	LivingType() :ItemType()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		m_Type = 3;
		m_Color = "";
		m_Material = "";
	}


	LivingType(int _serial, string _name, int _num, int _price, string _color, string _material) : ItemType(_serial, _name, _num, _price)
		//--------------------------------------------------------------------
		//		Constructor.
		//--------------------------------------------------------------------
	{
		m_Type = 3;
		m_Color = _color;
		m_Material = _material;
	}


	~LivingType() {}
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


	string GetColor() const;
	//--------------------------------------------------------------------
	//	Brief:	Get living color.
	//	Pre:	none.
	//	Post:	none.
	//	Return: living color.
	//--------------------------------------------------------------------


	string GetMaterial() const;
	//--------------------------------------------------------------------
	//	Brief:	Get living material.
	//	Pre:	none.
	//	Post:	none.
	//	Return: living material.
	//--------------------------------------------------------------------


	void SetColor(string _color);
	//--------------------------------------------------------------------
	//	Brief:	Set living size.
	//	Pre:	none.
	//	Post:	living size is set.
	//	Param:	_size		living size.
	//--------------------------------------------------------------------


	void SetMaterial(string _material);
	//--------------------------------------------------------------------
	//	Brief:	Set living material.
	//	Pre:	none.
	//	Post:	living material is set.
	//	Param:	_material		living material
	//--------------------------------------------------------------------


	void SetRecord(int _serial, string _name, int _num, int _price, string _color, string _material);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//	Param:	_serial			commodity id.
	//	Param:	_name			commodity name.
	//	Param:	_num			commodity number.
	//  Param:  _price			commodity price.
	//	Param:	_color			living color.
	//	Param:	_material		living material.
	//--------------------------------------------------------------------


	void SetColorFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set living color from keyboard
	//	Pre:	none.
	//	Post:	living color is set.
	//--------------------------------------------------------------------


	void SetMaterialFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set living material from keyboard
	//	Pre:	none.
	//	Post:	living material is set.
	//--------------------------------------------------------------------


	void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record from keyboard.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//--------------------------------------------------------------------


	void DisplayColorOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display living color on screen.
	//	Pre:	commodity color is set.
	//	Post:	commodity color is on screen.
	//--------------------------------------------------------------------


	void DisplayMaterialOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display living material on screen.
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
	void operator=(const LivingType*& _item) {
		m_Serial = _item->GetID();
		m_Name = _item->GetName();
		m_Num = _item->GetNum();
		m_Price = _item->GetPrice();
		m_Color = this->GetColor();
		m_Material = this->GetMaterial();
	}


	void print(ostream& _out)
	{
		_out << "\t+--------------------------+" << endl;
		_out << "\t|        LIVINGTYPE        |" << endl;
		_out << "\t+--------------------------+" << endl;
		_out << "\tID   : " << GetID() << endl;
		_out << "\tNAME : " << GetName() << endl;
		_out << "\tNUM  : " << GetNum() << endl;
		_out << "\tPRICE: " << GetPrice() << endl;
		_out << "\tCOLOR: " << this->GetColor() << endl;
		_out << "\tMATERIAL : " << this->GetMaterial() << endl;
		_out << "\t+--------------------------+" << endl;
	}
};