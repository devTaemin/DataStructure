#include "WorkerType.h"


// Default Constructor.
WorkerType::WorkerType()
{
	m_Sequence = -1;
	m_Name = "Default";
	m_PhoneNumber = "Default";
	m_Skill = -1;
	m_Age = -1;
	m_AgeGroup = -1;
	m_TargetWage = -1;
	m_Score = -1;
}


// Constructor.
WorkerType::WorkerType(int _seq)
{
	m_Sequence = _seq;
	m_Name = "Default";
	m_PhoneNumber = "Default";
	m_Skill = -1;
	m_Age = -1;
	m_AgeGroup = -1;
	m_TargetWage = -1;
	m_Score = -1;
}


// Destructor.
WorkerType::~WorkerType()
{

}


// Get worker's Sequence.
int WorkerType::GetSequence() const
{
	return m_Sequence;
}


// Get worker's Name.
string WorkerType::GetName() const
{
	return m_Name;
}


// Get worker's Phone number.
string WorkerType::GetNumber() const
{
	return m_Name;
}


// Get worker's Skill level.
int WorkerType::GetSkill() const
{
	return m_Skill;
}


// Get worker's Age.
int WorkerType::GetAge() const
{
	return m_Age;
}


// Get worker's Age group.
int WorkerType::GetAgeGroup() const
{
	return m_AgeGroup;
}


// Get worker's Target wage.
double WorkerType::GetTargetWage() const
{
	return m_TargetWage;
}


// Get worker's Score.
double WorkerType::GetScore() const
{
	return m_Score;
}


// Set worker's Sequence.
void WorkerType::SetSequence(int _seq)
{
	m_Sequence = _seq;
}


// Set worker's Name.
void WorkerType::SetName(string _name)
{
	m_Name = _name;
}


// Set worker's Phone number.
void WorkerType::SetNumber(string _num)
{
	m_PhoneNumber = _num;
}


// Set worker's Skill level.
void WorkerType::SetSkill(int _skill)
{
	m_Skill = _skill;
}


// Set worker's Age.
void WorkerType::SetAge(int _age)
{
	m_Age = _age;
}


// Set worker's Age group.
void WorkerType::SetAgeGroup(int _age)
{

	if (_age < 20 || _age >= 60){											// Group 1(20세 미만, 60세 이상)
		m_AgeGroup = 1;
	}
	else if ((_age >= 20 && _age < 30) || (_age >= 50 && _age < 60)) {		// Group 2(20대, 50대)
		m_AgeGroup = 2;
	}
	else {																	// Group 3(30대, 40대)
		m_AgeGroup = 3; 
	}
}


// Set worker's Target wage.
void WorkerType::SetTargetWage(double _wage)
{
	m_TargetWage = _wage;
}


// Set worker's Score.
void WorkerType::SetScore(int _TotalWorker, int _wantedSkill, int _wantedAgeGroup, double _wantedWage)
{
	double score;
	score = (20.0 * abs(m_Skill - _wantedSkill) / 4.0)
		+ (20.0 * abs(m_AgeGroup - _wantedAgeGroup) / 2.0)
		+ (30.0 * abs(m_TargetWage - _wantedWage) / 100000.0)
		+ (30 * m_Sequence / _TotalWorker);
	m_Score = score;
}


// Set worker's Record.
void WorkerType::SetRecord(string _name, string _num, int _skill, int _age, double _wage)
{
	SetName(_name);
	SetNumber(_num);
	SetSkill(_skill);
	SetAge(_age);
	SetAgeGroup(_age);
	SetTargetWage(_wage);
}


// Set worker's Sequence from keyboard.
void WorkerType::SetSequenceFromKB()
{
	cout << "\tSeqence      : ";
	cin >> m_Sequence;
}


// Set worker's Name from keyboard.
void WorkerType::SetNameFromKB()
{
	cout << "\tName         : ";
	cin >> m_Name;
}


// Set worker's Phone number from keyboard.
void WorkerType::SetNumberFromKB()
{
	cout << "\tPhone-number : ";
	cin >> m_PhoneNumber;
}


// Set worker's Skill level from keyboard.
void WorkerType::SetSkillFromKB()
{
	int level;
	while (true) {
		cout << endl;
		cout << "\t[--- Skill level low(1) to High(5) ---]" << endl;
		cout << "\tSkill-level  : ";
		cin >> level;
		if (level >= 1 && level <= 5) {
			SetSkill(level);
			break;
		}
		cout << "\t[ERROR: Wrong Input...]" << endl;
	}
}


// Set worker's Age from keyboard.
void WorkerType::SetAgeFromKB()
{
	cout << "\tAge          : ";
	cin >> m_Age;
	SetAgeGroup(m_Age);
}


// Set worker's Target wage from keyboard.
void WorkerType::SetTargetWageFromKB()
{
	cout << "\tTarget-Wage  : ";
	cin >> m_TargetWage;
}


// Set worker's Record from keyboard.
void WorkerType::SetRecordFromKB()
{
	SetSequenceFromKB();
	SetNameFromKB();
	SetNumberFromKB();
	SetSkillFromKB();
	SetAgeFromKB();
	SetTargetWageFromKB();
}
