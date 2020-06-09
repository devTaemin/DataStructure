#include "Pch.h"


// Get Type number.
int LivingType::GetType() const
{
	return m_Type;
}


// Get living color.
string LivingType::GetColor() const
{
	return m_Color;
}


// Get living material.
string LivingType::GetMaterial() const
{
	return m_Material;
}


// Set living color.
void LivingType::SetColor(string _color)
{
	m_Color = _color;
}


// Set cloth material.
void LivingType::SetMaterial(string _material)
{
	m_Material = _material;
}


// Set commodity record.
void LivingType::SetRecord(int _serial, string _name, int _num, int _price, string _color, string _material)
{
	ItemType::SetRecord(_serial, _name, _num, _price);
	SetColor(_color);
	SetMaterial(_material);
}


// Set living color from keyboard
void LivingType::SetColorFromKB()
{
	cout << "\tColor: ";
	cin >> m_Color;
}


// Set living material from keyboard
void LivingType::SetMaterialFromKB()
{
	cout << "\tMaterial: ";
	cin >> m_Material;
}


// Set commodity record from keyboard.
void LivingType::SetRecordFromKB()
{
	ItemType::SetRecordFromKB();
	SetColorFromKB();
	SetMaterialFromKB();
}


// Display living color on screen.
void LivingType::DisplayColorOnScreen()
{
	cout << "\tCOLOR : " << m_Color << endl;
}


// Display living material on screen.
void LivingType::DisplayMaterialOnScreen()
{
	cout << "\tMATERIAL : " << m_Material << endl;
}


// Display commodity record on screen.
void LivingType::DisplayRecordOnScreen()
{
	ItemType::DisplayRecordOnScreen();
	DisplayColorOnScreen();
	DisplayMaterialOnScreen();
}


// Read a record from a file.
int LivingType::ReadDataFromFile(ifstream& fin)
{
	int serial; string name; int num; int price;
	fin >> m_Type; fin >> serial; fin >> name; fin >> num; fin >> price;

	SetSerial(serial);
	SetName(name);
	SetNum(num);
	SetPrice(price);
	fin >> m_Color;
	fin >> m_Material;

	return 1;
}


// Write a record into file.
int LivingType::WriteDataToFile(ofstream& fout)
{

	fout << endl;
	fout << GetType() << " ";
	fout << GetID() << " ";
	fout << GetName() << " ";
	fout << GetNum() << " ";
	fout << GetPrice() << " ";
	fout << m_Color << " ";
	fout << m_Material << " ";

	return 1;
}