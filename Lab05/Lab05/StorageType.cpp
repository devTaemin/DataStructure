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

bool StorageType::isFull()
{
	return (m_Length > m_MaxSize - 1);
}

int StorageType::GetContainer(ContainerType& _con)
{
	if (ContainerList.Get(_con) == 1) { return 1; }
	return 0;
}

int StorageType::AddContainer(ContainerType& _con)
{
	if (ContainerList.Add(_con) == 1) { return 1; }
	else if (ContainerList.Add(_con) == -1) { return -1; }
	return 0;
}

int StorageType::DeleteContainer(ContainerType& _con)
{
	if (ContainerList.Delete(_con) == 1) { return 1; }
	return 0;
}

int StorageType::UpdateContainer(ContainerType& _con)
{
	if (ContainerList.Replace(_con) == 1) { return 1; }
	return 0;
}

void StorageType::DisplayAllContainer()
{
	cout << ContainerList << endl;
}