#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType { LESS, EQUAL, GREATER };
//--------------------------------------------------------------------
//		Relation between items.
//--------------------------------------------------------------------


enum Genre { CLASSIC, JAZZ, BLUES, HIPHOP, COUNTRY, POP, ELECTRONICA, REST, UNDECIDED };
//--------------------------------------------------------------------
//		Music genres
//--------------------------------------------------------------------	


//--------------------------------------------------------------------
//		Item information class.
//--------------------------------------------------------------------
class ItemType
{
public:
	ItemType()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		Music = "";
		Composer = "";
		Player = "";
		Type = UNDECIDED;
		Serial_Number = -1;
	}


	~ItemType() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	string GetMusic() const;
	//--------------------------------------------------------------------
	//	Brief:	Get music name.
	//	Pre:	music name is set.
	//	Post:	none.
	//	Return: music name.
	//--------------------------------------------------------------------


	string GetComposer() const;
	//--------------------------------------------------------------------
	//	Brief:	Get composer name.
	//	Pre:	composer name is set.
	//	Post:	none.
	//	Return:	composer name.
	//--------------------------------------------------------------------


	string GetPlayer() const;
	//--------------------------------------------------------------------
	//	Brief:	Get player name.
	//	Pre:	player name is set.
	//	Post:	none.
	//	Return:	player name.
	//--------------------------------------------------------------------


	Genre GetType() const;
	//--------------------------------------------------------------------
	//	Brief:	Get type name.
	//	Pre:	type name is set.
	//	Post:	none.
	//	Return: type name.
	//--------------------------------------------------------------------


	int GetSerial_Number() const;
	//--------------------------------------------------------------------
	//	Brief:	Get serial number.
	//	Pre:	serial number is set.
	//	Post:	none.
	//	Return:	serial number.
	//--------------------------------------------------------------------


	void SetMusic(string inMusic);
	//--------------------------------------------------------------------
	//	Brief:	Set music name.
	//	Pre:	none.
	//	Post:	music name is set.
	//	Param:	inMusic		music name.
	//--------------------------------------------------------------------


	void SetComposer(string inComposer);
	//--------------------------------------------------------------------
	//	Brief:	Set composer name.
	//	Pre:	none.
	//	Post:	composer name is set.
	//	Param	inComposer		composer name.
	//--------------------------------------------------------------------


	void SetPlayer(string inPlayer);
	//--------------------------------------------------------------------
	//	Brief:	Set player name.
	//	Pre:	none.
	//	Post:	player name is set.
	//	Param:	inPlayer		player name.
	//--------------------------------------------------------------------


	void SetType(int inType);
	//--------------------------------------------------------------------
	//	Brief:	Set type name.
	//	Pre:	none.
	//	Post:	type name is set.
	//	Param:	inType		type name.
	//--------------------------------------------------------------------


	void SetSerial_Number(int inSerial_Number);
	//--------------------------------------------------------------------
	//	Brief:	Set serial number.
	//	Pre:	none.
	//	Post:	serial number is set.
	//	Param:	inSerial_Number		serial number.
	//--------------------------------------------------------------------


	void SetRecord(string inMusic, string inComposer, string inPlayer, int inType, int inSerial_Number);
	//--------------------------------------------------------------------
	//	Brief:	Set record of music.
	//	Pre:	none.
	//	Post:	a record of music is set.
	//	Param:	inMusic		music name.
	//	Param	inComposer		composer name.
	//	Param:	inPlayer		player name.
	//	Param:	inType		type name.
	//	Param:	inSerial_Number		serial number.
	//--------------------------------------------------------------------


	void DisplayMusicOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display music name on screen.
	//	Pre:	music name is set.
	//	Post:	music name is on screen.
	//--------------------------------------------------------------------


	void DisplayComposerOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display composer name on screen.
	//	Pre:	composer name is set.
	//	Post:	composer name is on screen.
	//--------------------------------------------------------------------


	void DisplayPlayerOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display player name on screen.
	//	Pre:	player name is set.
	//	Post:	player name is on screen.
	//--------------------------------------------------------------------


	void DisplayTypeOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display type name on screen.
	//	Pre:	type name is set.
	//	Post:	type name is on screen.
	//--------------------------------------------------------------------


	void DisplaySerial_NumberOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display serial number on screen.
	//	Pre:	serial number is set.
	//	Post:	serial number is on screen.
	//--------------------------------------------------------------------


	void DisplayRecordOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display record of music on screen.
	//	Pre:	a record is set.
	//	Post:	a record is on screen.
	//--------------------------------------------------------------------


	void SetMusicFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set music name from keyboard.
	//	Pre:	none.
	//	Post:	music name is set.
	//--------------------------------------------------------------------


	void SetComposerFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set composer name from keyboard
	//	Pre:	none.
	//	Post:	composer name is set.
	//--------------------------------------------------------------------


	void SetPlayerFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set player name from keyboard.
	//	Pre:	none.
	//	Post:	player name is set.
	//--------------------------------------------------------------------


	void SetTypeFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set type name from keyboard.
	//	Pre:	none.
	//	Post:	type name is set.
	//--------------------------------------------------------------------


	void SetSerial_NumberFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set serial number from keyboard.
	//	Pre:	none.
	//	Post:	serial number is set.
	//--------------------------------------------------------------------


	void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set a record from keyboard.
	//	Pre:	none.
	//	Post:	a record is set.
	//--------------------------------------------------------------------


	int ReadDataFromFile(ifstream& fin);
	//--------------------------------------------------------------------
	//	Brief:	Read a record from a file.
	//	Pre:	the target file is opened.
	//	Post:	new record is set.
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


	RelationType CompareBySerial_Number(const ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Compare two item's serial number.
	//	Pre:	two items should be initialized.
	//	Post:	the target file includes the new item record.
	//	Param:	data		target item for comparing.
	//	Return:	return LESS if this.Serial_Number < data.Serial_Number,
	//				   EQUAL if this.Serial_Number == data.Serial_Number,
	//				   GREATER if this.Serial_Number > data.Serial_Number.
	//--------------------------------------------------------------------


	bool operator==(const ItemType& A);
	//--------------------------------------------------------------------
	//	Brief:	Compare serial number by operator==.
	//	Pre:	both items' serial number should be set.
	//	Post:	none.
	//	Param:	A		target item for comparing.
	//	Return:	return true if this.Serial_Number == A.Serial_Number,
	//				   false if this.Serial_Number != A.Serial_Number.
	//--------------------------------------------------------------------


	void operator=(const ItemType& _item);
	//--------------------------------------------------------------------
	//	Brief:	Copy the record by operator=.
	//	Pre:	target item's record, going to be copied, should be set.
	//	Post:	a record is copied from target item.
	//	Param:	_item		the target item.
	//--------------------------------------------------------------------


private:
	string Music;
	string Composer;
	string Player;
	Genre Type;
	int Serial_Number;
};

#endif _ITEMTYPE_H_