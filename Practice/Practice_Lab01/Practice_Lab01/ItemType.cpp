#include "ItemType.h"


string ItemType::GetName() const
{
	return m_Name;
}


string ItemType::GetComposer() const
{
	return m_Composer;
}


string ItemType::GetPlayer() const
{
	return m_Player;
}


int ItemType::GetGenre() const
{
	return m_Genre;
}


int ItemType::GetSerial() const
{
	return m_Serial;
}


void ItemType::SetName(string inName)
{
	m_Name = inName;
}


void ItemType::SetComposer(string inComposer)
{
	m_Composer = inComposer;
}


void ItemType::SetPlayer(string inPlayer)
{
	m_Player = inPlayer;
}


void ItemType::SetGenre(int inGenre)
{
	m_Genre = inGenre;
}


void ItemType::SetSerial(int inSerial)
{
	m_Serial = inSerial;
}


void ItemType::SetRecord(string inName, string inComposer, string inPlayer, int inGenre, int inSerial)
{
	SetName(inName);
	SetComposer(inComposer);
	SetPlayer(inPlayer);
	SetGenre(inGenre);
	SetSerial(inSerial);
}


void ItemType::DisplayNameOnScreen()
{
	cout << "\tName    : " << m_Name << '\n';
}


void ItemType::DisplayComposerOnScreen()
{
	cout << "\tComposer: " << m_Composer << '\n';
}


void ItemType::DisplayPlayerOnScreen()
{
	cout << "\tPlayer  : " << m_Player << '\n';
}


void ItemType::DisplayGenreOnScreen()
{
	cout << "\tGenre   : " << m_Genre << '\n';
}


void ItemType::DisplaySerialOnScreen()
{
	cout << "\tSerial  : " << m_Serial << '\n';
}


void ItemType::DisplayRecordOnScreen()
{
	DisplayNameOnScreen();
	DisplayComposerOnScreen();
	DisplayPlayerOnScreen();
	DisplayGenreOnScreen();
	DisplaySerialOnScreen();
}


void ItemType::SetNameFromKB()
{
	cout << "\tName    : ";
	cin >> m_Name;
}


void ItemType::SetComposerFromKB()
{
	cout << "\tComposer: ";
	cin >> m_Composer;
}


void ItemType::SetPlayerFromKB()
{
	cout << "\tPlayer  : ";
	cin >> m_Player;
}


void ItemType::SetGenreFromKB()
{
	int inGenre;
	while (1) {
		cout << "\t[ CLASSIC(0), JAZZ(1), BLUES(2), HIPHOP(3), COUNTRY(4), POP(5), ELECTRONICA(6), REST(7), UNDECIDED(8) ]" << '\n';
		cout << "\tGenre   : ";
		cin >> inGenre;
		if (inGenre >= 0 && inGenre <= 8) {
			SetGenre(inGenre);
			break;
		}
		cout << "\t=====| ERROR: Wrong Input |======" << '\n';
		cout << '\n';
	}
}


void ItemType::SetSerialFromKB()
{
	cout << "\tSerial  : ";
	cin >> m_Serial;
}


void ItemType::SetRecordFromKB()
{
	SetNameFromKB();
	SetComposerFromKB();
	SetPlayerFromKB();
	SetGenreFromKB();
	SetSerialFromKB();
}


// File functions
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Name;
	fin >> m_Composer;
	fin >> m_Player;
	fin >> m_Genre;
	fin >> m_Serial;

	return 1;
}


int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Name << " ";
	fout << m_Composer << " ";
	fout << m_Player << " ";
	fout << m_Genre << " ";
	fout << m_Serial;

	return 1;
}


RelationType ItemType::CompareBySerial(const ItemType& inData)
{
	if (this->m_Serial > inData.m_Serial) {
		return GREATER;
	}
	else if (this->m_Serial < inData.m_Serial) {
		return LESS;
	}
	else { return EQUAL; }
}