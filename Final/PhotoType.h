#pragma once
//--------------------------------------------------------------------
//		Photo information class.
//--------------------------------------------------------------------
class PhotoType
{
private:
	int m_PhotoID;
	string m_address;
	bool m_found;

public:
	PhotoType()
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------
	{
		m_PhotoID = -1;
		m_address = "";
		m_found = false;
	}
	

	~PhotoType(){}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	void SetPhotoIDFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set photo id from keyboard.
	//	Pre:	photo is initialized.
	//	Post:	photo id is set.
	//--------------------------------------------------------------------


	void SetPhotoRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set photo record from keyboard.
	//	Pre:	photo is initialized.
	//	Post:	photo record is set.
	//--------------------------------------------------------------------


	void AddPhoto();
	//--------------------------------------------------------------------
	//	Brief:	Add photo information.
	//	Pre:	target container exists.
	//	Post:	photo information is added in the container.
	//--------------------------------------------------------------------


	void DeletePhoto();
	//--------------------------------------------------------------------
	//	Brief:	Delete photo information.
	//	Pre:	photo information is set in the container.
	//	Post:	photo information is removed from the container.
	//--------------------------------------------------------------------


	void UpdatePhoto();
	//--------------------------------------------------------------------
	//	Brief:	Update photo information.
	//	Pre:	photo information is set in the container.
	//	Post:	photo information is updated.
	//--------------------------------------------------------------------


	void DisplayPhoto();
	//--------------------------------------------------------------------
	//	Brief:	Display photo on the screen.
	//	Pre:	photo information is set.
	//	Post:	photo is on screen.
	//--------------------------------------------------------------------


	// Overload operator==
	bool operator==(const PhotoType& _photo) {
		if (m_PhotoID == _photo.m_PhotoID)
			return true;
		return false;
	}


	// Overload operator>
	bool operator>(const PhotoType& _photo) {
		if (m_PhotoID == _photo.m_PhotoID)
			return true;
		return false;
	}


	// Overload operator<
	bool operator<(const PhotoType& _photo) {
		if (m_PhotoID == _photo.m_PhotoID)
			return true;
		return false;
	}


	// Overload operator=
	void operator=(const PhotoType& _photo) {
		m_PhotoID = _photo.m_PhotoID;
		m_address = _photo.m_address;
		m_found = _photo.m_found;
	}


	// Overload operator<<
	friend ostream& operator<<(ostream& _out, PhotoType& _photo)
	{
		_out << "\t----------------------------" << endl;


		return _out;
	}
};