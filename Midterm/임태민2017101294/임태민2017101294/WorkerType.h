#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class WorkerType
{
private:

	int m_Sequence;					///< 등록순위
	string m_Name;					///< 이름 
	string m_PhoneNumber;			///< 전화번호
	int m_Skill;					///< 숙련도(최하(1) - 최상(5)) 
	int m_Age;						///< 나이
	int m_AgeGroup;					///< (연령층을 (1)에서 - (3)으로 구분)
	double m_TargetWage;			///< 희망 일당
	double m_Score;					///< 점수

public:

	WorkerType();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------

	WorkerType(int _seq);
	//--------------------------------------------------------------------
	//		Constructor.
	//--------------------------------------------------------------------

	~WorkerType();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	int GetSequence() const;
	//--------------------------------------------------------------------
	//	Brief:	Get worker's Sequence.
	//	Pre:	Sequence is set.
	//	Post:	none.
	//	Return:	m_Sequence.
	//--------------------------------------------------------------------

	string GetName() const;
	//--------------------------------------------------------------------
	//	Brief:	Get worker's Name.
	//	Pre:	Name is set.
	//	Post:	none.
	//	Return:	m_Name.
	//--------------------------------------------------------------------

	string GetNumber() const;
	//--------------------------------------------------------------------
	//	Brief:	Get worker's Phone number.
	//	Pre:	Phone number is set.
	//	Post:	none.
	//	Return:	m_PhoneNumber.
	//--------------------------------------------------------------------

	int GetSkill() const;
	//--------------------------------------------------------------------
	//	Brief:	Get worker's Skill level.
	//	Pre:	Skill is set.
	//	Post:	none.
	//	Return:	m_Skill.
	//--------------------------------------------------------------------

	int GetAge() const;
	//--------------------------------------------------------------------
	//	Brief:	Get worker's Age.
	//	Pre:	Age is set.
	//	Post:	none.
	//	Return:	m_Skill.
	//--------------------------------------------------------------------

	int GetAgeGroup() const;
	//--------------------------------------------------------------------
	//	Brief:	Get worker's Age group.
	//	Pre:	Age is set.
	//	Post:	none.
	//	Return:	m_Skill.
	//--------------------------------------------------------------------

	double GetTargetWage() const;
	//--------------------------------------------------------------------
	//	Brief:	Get worker's Target wage.
	//	Pre:	Target wage is set.
	//	Post:	none.
	//	Return:	m_TargetWage.
	//--------------------------------------------------------------------

	double GetScore() const;
	//--------------------------------------------------------------------
	//	Brief:	Get worker's Score.
	//	Pre:	Score is set.
	//	Post:	none.
	//	Return:	m_Score.
	//--------------------------------------------------------------------

	void SetSequence(int _seq);
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Sequence.
	//	Pre:	none.
	//	Post:	none.
	//	Param:	_seq		worker's Sequence.
	//--------------------------------------------------------------------

	void SetName(string _name);
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Name.
	//	Pre:	none.
	//	Post:	none.
	//	Param:	_name		worker's name.
	//--------------------------------------------------------------------

	void SetNumber(string _num);
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Phone number.
	//	Pre:	none.
	//	Post:	none.
	//	Param:	_num		worker's phone number.
	//--------------------------------------------------------------------

	void SetSkill(int _skill);
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Skill level.
	//	Pre:	none.
	//	Post:	none.
	//	Param:	_skill		worker's skill.
	//--------------------------------------------------------------------

	void SetAge(int _age);
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Age.
	//	Pre:	none.
	//	Post:	none.
	//	Param:	_age		worker's age.
	//--------------------------------------------------------------------

	void SetAgeGroup(int _age);
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Age group.
	//	Pre:	none.
	//	Post:	none.
	//	Param:	_age		worker's age.
	//--------------------------------------------------------------------

	void SetTargetWage(double _wage);
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Target wage.
	//	Pre:	none.
	//	Post:	none.
	//	Param:	_wage		worker's target wage.
	//--------------------------------------------------------------------

	void SetScore(double _score);
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Score.
	//	Pre:	none.
	//	Post:	none.
	//	Param:	_score				Worker's score
	//--------------------------------------------------------------------

	void SetRecord(string _name, string _num, int _skill, int _age, double _wage);
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Record.
	//	Pre:	none.
	//	Post:	none.
	//	Param:	_name		worker's Name.
	//	Param:	_num		worker's phone number.
	//	Param:	_skill		worker's skill.
	//	Param:	_age		worker's age.
	//	Param:	_wage		worker's target wage.
	//--------------------------------------------------------------------

	void SetSequenceFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Sequence from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void SetNameFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Name from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void SetNumberFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Phone number from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void SetSkillFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Skill level from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void SetAgeFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Age from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void SetTargetWageFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Target wage from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set worker's Record from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//--------------------------------------------------------------------

	bool operator==(const WorkerType& _worker){
		return (m_Sequence == _worker.m_Sequence);
	}
	bool operator>(const WorkerType& _worker) {
		return (m_Sequence > _worker.m_Sequence);
	}
	bool operator<(const WorkerType& _worker) {
		return (m_Sequence < _worker.m_Sequence);
	}
	void operator=(const WorkerType& _worker)
	//--------------------------------------------------------------------
	//	Brief:	Copy WorkerType Record.
	//	Pre:	Target variable is initialized
	//	Post:	Target variable is copied.
	//  Param:	_worker			copying variable.
	//--------------------------------------------------------------------
	{
		m_Sequence = _worker.m_Sequence;
		m_Name = _worker.m_Name;
		m_PhoneNumber = _worker.m_PhoneNumber;
		m_Skill = _worker.m_Skill;
		m_Age = _worker.m_Age;
		m_AgeGroup = _worker.m_AgeGroup;
		m_TargetWage = _worker.m_TargetWage;
		m_Score = _worker.m_Score;
	}

	friend ostream& operator<<(ostream& os, const WorkerType& _worker)
	{
		os << "\t     +------------- Worker Record ------------+" << endl;
		os << "\t       Ticket-Number: " << _worker.GetSequence() << endl;
		os << "\t       Name         : " << _worker.GetName() << endl;
		os << "\t       Phone-number : " << _worker.GetNumber() << endl;
		os << "\t       Skill-level  : " << _worker.GetSkill() << endl;
		os << "\t       Age          : " << _worker.GetAge() << "  |  [Age group : (" << _worker.GetAgeGroup() << ") ]" << endl;
		os << "\t       Target-Wage  : " << _worker.GetTargetWage() << endl;
		os << "\t     +----------------------------------------+" << endl;
		return os;
	}

};