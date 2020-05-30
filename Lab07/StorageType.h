/*
#pragma once
//--------------------------------------------------------------------
//		Storage type class.
//--------------------------------------------------------------------
class StorageType
{
private:
	int m_StorageID;


public:
	StorageType(){}
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	~StorageType(){}

	int GetStorageID() const;

	void SetStorageID(int _sid);

	void SetStorageIDFromKB();

	bool operator==(const StorageType& _storage) {
		return (m_StorageID == _storage.m_StorageID);
	}

	bool operator>(const StorageType& _storage) {
		return (m_StorageID > _storage.m_StorageID);
	}

	bool operator<(const StorageType& _storage) {
		return (m_StorageID < _storage.m_StorageID);
	}

	void operator=(const StorageType& _storage) {
		m_StorageID = _storage.m_StorageID;
	}

	friend ostream& operator<<(ostream& os, const StorageType& _storage)
	{
		os << "+-----------------------------------+" << endl;
		os << "\tStorage ID   : " << _storage.GetStorageID() << endl;


		os << "+-----------------------------------+" << endl;
		return os;
	}

};
*/