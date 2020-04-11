#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType { LESS, EQUAL, GREATER };


class ItemType
{
public:
	// Default Constructor.
	ItemType()
	{
		m_Name = "";
		m_Composer = "";
		m_Player = "";
		m_Genre = -1;
		m_Serial = -1;
	}


	ItemType(string inName, string inComposer, string inPlayer, int inGenre, int inSerial) :
		m_Name(inName), m_Composer(inComposer), m_Player(inPlayer), m_Genre(inGenre), m_Serial(inSerial) {}



	// Destructor.
	~ItemType() {}


	// Get functions
	string GetName() const;


	string GetComposer() const;


	string GetPlayer() const;


	int GetGenre() const;


	int GetSerial() const;


	// Set functions
	void SetName(string inName);


	void SetComposer(string inComposer);


	void SetPlayer(string inPlayer);


	void SetGenre(int inGenre);


	void SetSerial(int inSerial);


	void SetRecord(string inName, string inComposer, string inPlayer, int inGenre, int inSerial);


	// Display functions
	void DisplayNameOnScreen();


	void DisplayComposerOnScreen();


	void DisplayPlayerOnScreen();


	void DisplayGenreOnScreen();


	void DisplaySerialOnScreen();


	void DisplayRecordOnScreen();


	// Set from KB
	void SetNameFromKB();


	void SetComposerFromKB();


	void SetPlayerFromKB();


	void SetGenreFromKB();


	void SetSerialFromKB();


	void SetRecordFromKB();


	// File functions
	int ReadDataFromFile(ifstream& fin);


	int WriteDataToFile(ofstream& fout);


	// Compare functions
	RelationType CompareBySerial(const ItemType& inData);


private:
	string m_Name;
	string m_Composer;
	string m_Player;
	int m_Genre;
	int m_Serial;
};
#endif _ITEMTYPE_H_