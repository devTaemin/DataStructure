#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "DoubleLinkedList.h"
#include "SortedList.h"
#include "StorageType.h"
#include "ItemType.h"
#include "TempType.h"
#define FILENAMESIZE 1024
using namespace std;
class Application
{
private:
	DoubleLinkedList<ItemType> MasterList;
	SortedList<StorageType> StorageList;
	TempType TempList;

	ifstream m_InFile;
	ofstream m_OutFile;
	int m_Command;

public:
	Application();
	~Application();

	void Run();
	void GetCommand();

	int AddItem();
	int AddItem(ItemType& _item);
	int DeleteItem();
	int ReplaceItem();

	int OpenInFile(char* fileName);
	int OpenOutFile(char* fileName);
	int ReadDataFromFile();
	int WriteDataToFile();


	// StorageList
	int AddStorage();
	int AddStorage(StorageType& _storage);
	int DeleteStorage();
	int ReplaceStorage();
	void DisplayAllStorage();
	void DIsplayAllContainer();
	void DisplayAllDetailContainer();

	// ContainerList
	int AddContainer();
	int AddContainer(ContainerType& _container);
	int DeleteContainer();
	int ReplaceContainer();
	void DisplayAllsItem();
	void DisplayAllPhoto();
	void DisplayAllDetailsItem();


	// TempList
	void AddTempItem();
	void DequeueFromTempList();
	void PrintTempList();


	// function
	int Search_Display_ByUsage();
	int SearchByDate();
};