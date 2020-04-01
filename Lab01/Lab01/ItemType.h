#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*		Relation between two items.
*/
enum RelationType {LESS, EQUAL, GREATER};

/**
*		item's genre.
*/
enum Genre {CLASSIC, JAZZ, BLUES, HIPHOP, COUNTRY, POP, ELECTRONICA, REST, UNDECIDED};

/**
*		item information class.
*/
class ItemType
{
public:
	/**
	*		default constructor.
	*/
	ItemType()
	{
		Music = "";
		Composer = "";
		Player = "";
		Type = UNDECIDED;
		Serial_Number = -1;
	}

	/**
	*		destructor.
	*/
	~ItemType() {}

	/**
	*		@brief	Get music name.
	*		@pre	music name is set.
	*		@post	none.
	*		@return music name.
	*/
	string GetMusic() const;


	/**
	*		@brief	Get composer name.
	*		@pre	composer name is set.
	*		@post	none.
	*		@return composer name.
	*/
	string GetComposer() const;


	/**
	*		@brief	Get player name.
	*		@pre	player name is set.
	*		@post	none.
	*		@return player name.
	*/
	string GetPlayer() const;


	/**
	*		@brief	Get type of music.
	*		@pre	type of music is set
	*		@post	none.
	*		@return type of music.
	*/
	Genre GetType() const;


	/**
	*		@brief	Get serial_number of music.
	*		@pre	serial_number of music is set.
	*		@post	none.
	*		@return serial number of music.
	*/
	int GetSerial_Number() const;


	/**
	*		@brief	Set music name.
	*		@pre	none.
	*		@post	music name is set
	*		@param	inMusic		music name.
	*/
	void SetMusic(string inMusic);


	/**
	*		@brief	Set composer name.
	*		@pre	none.
	*		@post	composer name is set.
	*		@param	inComposer		composer name
	*/
	void SetComposer(string inComposer);


	/**
	*		@brief	Set player name.
	*		@pre	none.
	*		@post	player name is set.
	*		@param	inPlayer		player name.
	*/
	void SetPlayer(string inPlayer);


	/**
	*		@brief	Set type of music.
	*		@pre	none.
	*		@post	type of music is set.
	*		@param	inType		type of music.
	*/
	void SetType(int inType);


	/**
	*		@brief	Set serial number of music.
	*		@pre	none.
	*		@post	serial number of music is set.
	*		@param	inSerial_Number		serial number of music.
	*/
	void SetSerial_Number(int inSerial_Number);


	/**
	*		@brief	Set record of music.
	*		@pre	none.
	*		@post	a record of music is set.
	*		@param	inMusic		music name.
	*		@param	inComposer		composer name
	*		@param	inPlayer		player name.
	*		@param	inType		type of music.
	*		@param	inSerial_Number		serial number of music.
	*/
	void SetRecord(string inMusic, string inComposer, string inPlayer, int inType, int inSerial_Number);

	
	/**
	*		@brief	Display music name on screen.
	*		@pre	music name is set.
	*		@post	music name is displayed on screen.
	*/
	void DisplayMusicOnScreen();


	/**
	*		@brief	Display composer name on screen.
	*		@pre	composer name is set.
	*		@post	composer name is displayed on screen.
	*/
	void DisplayComposerOnScreen();


	/**
	*		@brief	Display player name on screen.
	*		@pre	player name is set.
	*		@post	player name is displayed on screen.
	*/
	void DisplayPlayerOnScreen();


	/**
	*		@brief	Display type name on screen.
	*		@pre	type name is set.
	*		@post	type name is displayed on screen.
	*/
	void DisplayTypeOnScreen();


	/**
	*		@brief	Display serial_number on screen.
	*		@pre	serial_number is set.
	*		@post	serial_number is displayed on screen.
	*/
	void DisplaySerial_NumberOnScreen();


	/**
	*		@brief	Display a record on screen.
	*		@pre	a record is set.
	*		@post	a record is displayed on screen.
	*/
	void DisplayRecordOnScreen();


	/**
	*		@brief	Set music name from keyboard.
	*		@pre	none.
	*		@post	music name is set.
	*/
	void SetMusicFromKB();


	/**
	*		@brief	Set composer name from keyboard.
	*		@pre	none.
	*		@post	composer name is set.
	*/
	void SetComposerFromKB();


	/**
	*		@brief	Set player name from keyboard.
	*		@pre	none.
	*		@post	player name is set.
	*/
	void SetPlayerFromKB();


	/**
	*		@brief	Set type name from keyboard.
	*		@pre	none.
	*		@post	type name is set.
	*/
	void SetTypeFromKB();


	/**
	*		@brief	Set serial number from keyboard.
	*		@pre	none.
	*		@post	serial number is set.
	*/
	void SetSerial_NumberFromKB();


	/**
	*		@brief	Set a record from keyboard.
	*		@pre	none.
	*		@post	a record is set.
	*/
	void SetRecordFromKB();


	/**
	*		@brief	Read a record from file.
	*		@pre	the target file is opened.
	*		@post	music record is set.
	*		@param	fin		file descriptor.
	*		@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);


	/**
	*		@brief	Write a record into file.
	*		@pre	the target file is opened, and the list is initilized.
	*		@post	the target file includes new record.
	*		@param	fout	file decriptor.
	*		@return	return 1 if this fucntion works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);


	/**
	*		@brief	Compare two items' serial number.
	*		@pre	two item types should be initialized.
	*		@post	the target file is included the nwe item record.
	*		@param	data	target item for comparing.
	*		@return	GREATER, if this.Serial_Number > data.Serial_Number,
	*				LESS, if this.Serial_Number < data.Serial_Number,
	*				EQUAL, if this.Serial_Number == data.Seril_Number.
	*/
	RelationType CompareBySerial_Number(const ItemType& data);


	/**
	*		@brief	Compare id by operator==.
	*		@pre	both items' id should be set.
	*		@post	none.
	*		@param	A	target item for comparing
	*		@return	return true if this.m_Id == A.id,
	*				return false if this.m_id != A.id.
	*/
	bool operator==(const ItemType& A);



	/**
	*		@brief	Copy the rocord by operator=.
	*		@pre	object's record, which is going to be copied, should already be set.
	*		@post	target record is copied from object record.
	*		@param	_item	target item for copying
	*/
	void operator=(const ItemType& _item);

private:
	string Music;
	string Composer;
	string Player;
	Genre Type;
	int Serial_Number;
};
#endif _ITEMTYPE_H_