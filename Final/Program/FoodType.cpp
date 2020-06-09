#include "Pch.h"


// Get Type number.
int FoodType::GetType() const
{
	return m_Type;
}


// Get purchase date.
int FoodType::GetPurchaserDate() const
{
	return m_PurchaseDate;
}


// Get expiration date.
int FoodType::GetExpirationDate() const
{
	return m_ExpirationDate;
}


// Set purchase date.
void FoodType::SetPurchaserDate(int _date)
{
	m_PurchaseDate = _date;
}


// Set expiration date.
void FoodType::SetExpirationDate(int _date)
{
	m_ExpirationDate = _date;
}


// Set commodity record.
void FoodType::SetRecord(int _serial, string _name, int _num, int _price, int _pDate, int _eDate)
{
	ItemType::SetRecord(_serial, _name, _num, _price);
	SetPurchaserDate(_pDate);
	SetExpirationDate(_eDate);
}


// Set purchase date from keyboard
void FoodType::SetPurchaseDateFromKB()
{
	cout << "\tPurchase-Date: ";
	cin >> m_PurchaseDate;
}


// Set expiration date from keyboard
void FoodType::SetExpirationDateFromKB()
{
	cout << "\tExpiration-Date: ";
	cin >> m_ExpirationDate;
}


// Set commodity record from keyboard.
void FoodType::SetRecordFromKB()
{
	ItemType::SetRecordFromKB();
	SetPurchaseDateFromKB();
	SetExpirationDateFromKB();
}


// Display purchase date on screen.
void FoodType::DisplayPurchaseDateOnScreen()
{
	cout << "\tDATE : " << m_PurchaseDate << endl;
}


// Display expiration date on screen.
void FoodType::DisplayExpirationDateOnScreen()
{
	cout << "\tEX   : " << m_ExpirationDate << endl;
}


// Display commodity record on screen.
void FoodType::DisplayRecordOnScreen()
{
	ItemType::DisplayRecordOnScreen();
	DisplayPurchaseDateOnScreen();
	DisplayExpirationDateOnScreen();
}


// Read a record from a file.
int FoodType::ReadDataFromFile(ifstream& fin)
{
	int serial; string name; int num; int price;
	fin >> m_Type; fin >> serial; fin >> name; fin >> num; fin >> price;

	SetSerial(serial);
	SetName(name);
	SetNum(num);
	SetPrice(price);
	fin >> m_PurchaseDate;
	fin >> m_ExpirationDate;

	return 1;
}


// Write a record into file.
int FoodType::WriteDataToFile(ofstream& fout)
{

	fout << endl;
	fout << GetType() << " ";
	fout << GetID() << " ";
	fout << GetName() << " ";
	fout << GetNum() << " ";
	fout << GetPrice() << " ";
	fout << m_PurchaseDate << " ";
	fout << m_ExpirationDate << " ";

	return 1;
}