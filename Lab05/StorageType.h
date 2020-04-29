#pragma once
#include "DoubleLinkedList.h"
#include "SingleLinkedList.h"
#include "ContainerType.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class StorageType
{
private:
	int m_StorageID;
	int m_Length;
	int m_MaxSize;
	SingleLinkedList<ContainerType> ContainerList;

public:
	StorageType();
	StorageType(int _max);
	~StorageType();

	int GetId() const;
	int GetLength() const;
	int GetMaxSize() const;
	SingleLinkedList<ContainerType> GetContainerList() const; //�߰�
	void SetContainerList(SingleLinkedList<ContainerType> _con); // �߰�

	void SetId(int _id);
	void SetLength(int _len); // �߰�
	void SetMaxSize(int _max);
	void SetRecord(int _id, int _max);
	void SetIdFromKB();
	void SetMaxSizeFromKB();
	void SetRecordFromKB();




	bool isFull();

	int GetContainer(ContainerType& _con);
	int AddContainer(ContainerType& _con);
	int DeleteContainer(ContainerType& _con);
	int UpdateContainer(ContainerType& _con);

	void DisplayAllRecord();
	void DisplayAllContainer();
	void DisplayAllDetailsContainer(DoubleLinkedList<ItemType>& ref)
	{
		ContainerType temp;
		ContainerList.ResetList();
		while (ContainerList.GetNextItem(temp) > 0) {
			temp.DisplayAllDetailsItem(ref);
		}
	}

	bool operator==(const StorageType& _storage) {
		return (m_StorageID == _storage.GetId());
	}
	bool operator>(const StorageType& _storage) {
		return (m_StorageID > _storage.GetId());
	}
	bool operator<(const StorageType& _storage) {
		return (m_StorageID < _storage.GetId());
	}
	void operator=(StorageType& _storage) {
		m_StorageID = _storage.GetId();
		m_Length = _storage.GetLength();
		m_MaxSize = _storage.GetMaxSize();
		ContainerList = _storage.ContainerList;
	}
};