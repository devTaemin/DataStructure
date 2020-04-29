#include "StorageType.h"

StorageType::StorageType()
{
	m_StorageID = -1;
	m_Length = 0;
	m_MaxSize = 10;
}

StorageType::StorageType(int _max)
{
	m_StorageID = -1;
	m_Length = 0;
	m_MaxSize = _max;
}

StorageType::~StorageType()
{

}

int StorageType::GetId() const
{
	return m_StorageID;
}

int StorageType::GetLength() const
{
	return m_Length;
}

int StorageType::GetMaxSize() const
{
	return m_MaxSize;
}

SingleLinkedList<ContainerType> StorageType::GetContainerList() const
{
	return ContainerList;
}

void StorageType::SetContainerList(SingleLinkedList<ContainerType> _con)
{
	ContainerList = _con;
}

bool StorageType::isFull()
{
	return (m_Length > m_MaxSize - 1);
}

void StorageType::SetId(int _id)
{
	m_StorageID = _id;
}

void StorageType::SetLength(int _len)
{
	m_Length = _len;
}

void StorageType::SetMaxSize(int _max)
{
	m_MaxSize = _max;
}

void StorageType::SetRecord(int _id, int _max)
{
	SetId(_id);
	SetMaxSize(_max);
}

void StorageType::SetIdFromKB()
{
	cout << "\tStorageID: ";
	cin >> m_StorageID;
}

void StorageType::SetMaxSizeFromKB()
{
	cout << "\tContainer-Max: ";
	cin >> m_MaxSize;
}

void StorageType::SetRecordFromKB()
{
	SetIdFromKB();
	SetMaxSizeFromKB();
}

int StorageType::GetContainer(ContainerType& _con)
{
	if (ContainerList.Get(_con) == 1) { return 1; }
	return 0;
}

int StorageType::AddContainer(ContainerType& _con)
{
	if (ContainerList.Add(_con) == 1) { 
		m_Length++;
		return 1; 
	}
	else if (ContainerList.Add(_con) == -1) { return -1; }
	return 0;
}

int StorageType::DeleteContainer(ContainerType& _con)
{
	if (ContainerList.Delete(_con) == 1) { 
		m_Length--;
		return 1; 
	}
	return 0;
}

int StorageType::UpdateContainer(ContainerType& _con)
{
	if (ContainerList.Replace(_con) == 1) { return 1; }
	return 0;
}

void StorageType::DisplayAllRecord()
{
	cout << endl;
	cout << "+===================================+" << endl;
	cout << "\tStorageID: " << m_StorageID << endl;
	cout << "\tContainer-num: " << m_Length << " / " << m_MaxSize << endl;
	cout << "+===================================+" << endl;
}


void StorageType::DisplayAllContainer()
{
	cout << ContainerList << endl;
}