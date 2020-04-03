#include "ItemType.h"


// Get music name.
string ItemType::GetMusic() const
{
	return Music;
}


// Get composer name.
string ItemType::GetComposer() const
{
	return Composer;
}


// Get player name.
string ItemType::GetPlayer() const
{
	return Player;
}


// Get type of music.
Genre ItemType::GetType() const
{
	return Type;
}


// Get serial_number of music.
int ItemType::GetSerial_Number() const
{
	return Serial_Number;
}


// Set music name.
void ItemType::SetMusic(string inMusic)
{
	Music = inMusic;
}


// Set composer name.
void ItemType::SetComposer(string inComposer)
{
	Composer = inComposer;
}


// Set player name.
void ItemType::SetPlayer(string inPlayer)
{
	Player = inPlayer;
}


// Set type of music.
void ItemType::SetType(int inType)
{
	//CLASSIC(0), JAZZ(1), BLUES(2), HIPHOP(3), COUNTRY(4), POP(5), ELECTRONICA(6), REST(7), UNDECIDED(8)
	switch (inType)
	{
	case(0):
		Type = CLASSIC;
		break;
	case(1):
		Type = JAZZ;
		break;
	case(2):
		Type = BLUES;
		break;
	case(3):
		Type = HIPHOP;
		break;
	case(4):
		Type = COUNTRY;
		break;
	case(5):
		Type = POP;
		break;
	case(6):
		Type = ELECTRONICA;
		break;
	case(7):
		Type = REST;
		break;
	case(8):
		Type = UNDECIDED;
		break;
	default:
		cout << "\tWrong type input!" << '\n';
		break;
	}
}


// Set serial number of music.
void ItemType::SetSerial_Number(int inSerial_Number)
{
	Serial_Number = inSerial_Number;
}


// Set record of music.
void ItemType::SetRecord(string inMusic, string inComposer, string inPlayer, int inType, int inSerial_Number)
{
	SetMusic(inMusic);
	SetComposer(inComposer);
	SetPlayer(inPlayer);
	SetType(inType);
	SetSerial_Number(inSerial_Number);
}


// Display music name on screen.
void ItemType::DisplayMusicOnScreen()
{
	cout << "\tMusic : " << GetMusic() << '\n';
}


// Display composer name on screen.
void ItemType::DisplayComposerOnScreen()
{
	cout << "\tComposer : " << GetComposer() << '\n';
}


// Display player name on screen.
void ItemType::DisplayPlayerOnScreen()
{
	cout << "\tPlayer : " << GetPlayer() << '\n';
}


// Display type name on screen.
void ItemType::DisplayTypeOnScreen()
{
	cout << "\tType : " << GetType() << '\n';
}


// Display serial_number on screen.
void ItemType::DisplaySerial_NumberOnScreen()
{
	cout << "\tSerial_number : " << GetSerial_Number() << '\n';
}


// Display a record on screen.
void ItemType::DisplayRecordOnScreen()
{
	cout << '\n';
	DisplayMusicOnScreen();
	DisplayComposerOnScreen();
	DisplayPlayerOnScreen();
	DisplayTypeOnScreen();
	DisplaySerial_NumberOnScreen();
}


// Set music name from keyboard.
void ItemType::SetMusicFromKB()
{
	cout << "\tMusic : ";
	cin >> Music;
}


// Set composer name from keyboard.
void ItemType::SetComposerFromKB()
{
	cout << "\tComposer : ";
	cin >> Composer;
}


// Set player name from keyboard.
void ItemType::SetPlayerFromKB()
{
	cout << "\tPlayer : ";
	cin >> Player;
}


// Set type name from keyboard.
void ItemType::SetTypeFromKB()
{
	int inType;
	cout << "\tChoose among CLASSIC(0), JAZZ(1), BLUES(2), HIPHOP(3), COUNTRY(4), POP(5), ELECTRONICA(6), REST(7), UNDECIDED(8)\n";
	cout << "\tGenre : ";
	cin >> inType;
	SetType(inType);
}


// Set serial number from keyboard.
void ItemType::SetSerial_NumberFromKB()
{
	cout << "\tSerial Number : ";
	cin >> Serial_Number;
}



// Set a record from keyboard.
void ItemType::SetRecordFromKB()
{
	SetMusicFromKB();
	SetComposerFromKB();
	SetPlayerFromKB();
	SetTypeFromKB();
	SetSerial_NumberFromKB();
}


// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	int inType;
	fin >> Music;
	fin >> Composer;
	fin >> Player;
	fin >> inType;
	fin >> Serial_Number;
	return 1;
}


// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << Music << " ";
	fout << Composer << " ";
	fout << Player << " ";
	fout << Type << " ";
	fout << Serial_Number << " ";
	fout << '\n';
	return 1;
}


// Compare two items' serial number.
RelationType ItemType::CompareBySerial_Number(const ItemType& data)
{
	if (this->GetSerial_Number() > data.GetSerial_Number()) {
		return GREATER;
	}
	else if (this->GetSerial_Number() < data.GetSerial_Number()) {
		return LESS;
	}
	else {
		return EQUAL;
	}
}


// Compare id by operator==.
bool ItemType::operator==(const ItemType& A)
{
	if (CompareBySerial_Number(A) == EQUAL) {
		return true;
	}
	else { return false; }
}



// Copy the rocord by operator=.
void ItemType::operator=(const ItemType& _item)
{
	string inMusic = _item.GetMusic();
	string inComposer = _item.GetComposer();
	string inPlayer = _item.GetPlayer();
	Genre inType = _item.GetType();
	int inSerial_Number = _item.GetSerial_Number();
	this->SetRecord(inMusic, inComposer, inPlayer, inType, inSerial_Number);
}