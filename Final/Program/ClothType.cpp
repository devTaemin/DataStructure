#include "Pch.h"


// Get Type number.
int ClothType::GetType() const
{
	return m_Type;
}


// Get commodity serial.
int ClothType::GetID() const
{
	return m_Serial;
}


// Get cloth size.
int ClothType::GetSize() const
{
	return m_Size;
}


// Get cloth material.
string ClothType::GetMaterial() const
{
	return m_Material;
}


// Set cloth size.
void ClothType::SetSize(int _size)
{
	m_Size = _size;
}


// Set cloth material.
void ClothType::SetMaterial(string _material)
{
	m_Material = _material;
}


// Set commodity record.
void ClothType::SetRecord(int _serial, string _name, int _num, int _price, int _size, string _material)
{
	ItemType::SetRecord(_serial, _name, _num, _price);
	SetSize(_size);
	SetMaterial(_material);
}


// Set cloth size from keyboard
void ClothType::SetSizeFromKB()
{
	cout << "\tCloth-Size: ";
	cin >> m_Size;
}


// Set cloth material from keyboard
void ClothType::SetMaterialFromKB()
{
	cout << "\tCloth-Material: ";
	cin >> m_Material;
}


// Set commodity record from keyboard.
void ClothType::SetRecordFromKB()
{
	ItemType::SetRecordFromKB();
	SetSizeFromKB();
	SetMaterialFromKB();
}


// Display cloth size on screen.
void ClothType::DisplaySizeOnScreen()
{
	cout << "\tSIZE : " << m_Size << endl;
}


// Display cloth material on screen.
void ClothType::DisplayMaterialOnScreen()
{
	cout << "\tMATERIAL : " << m_Material << endl;
}


// Display commodity record on screen.
void ClothType::DisplayRecordOnScreen()
{
	ItemType::DisplayRecordOnScreen();
	DisplaySizeOnScreen();
	DisplayMaterialOnScreen();
}


// Read a record from a file.
int ClothType::ReadDataFromFile(ifstream& fin)
{
	int serial; string name; int num; int price;
	fin >> m_Type; fin >> serial; fin >> name; fin >> num; fin >> price;

	SetSerial(serial);
	SetName(name);
	SetNum(num);
	SetPrice(price);
	fin >> m_Size;
	fin >> m_Material;


	return 1;
}


// Write a record into file.
int ClothType::WriteDataToFile(ofstream& fout)
{

	fout << endl;
	fout << GetType() << " ";
	fout << GetID() << " ";
	fout << GetName() << " ";
	fout << GetNum() << " ";
	fout << GetPrice() << " ";
	fout << m_Size << " ";
	fout << m_Material << " ";

	return 1;
}