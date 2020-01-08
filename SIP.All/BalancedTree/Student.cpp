#include "Student.h"

using namespace std;

Student::Student()
{
	FirstName = "TestFirstName";
	LastName = "TestLastName";
	MiddleName = "TestMiddleName";
	Birthday = 9999;
	MidGrade = 0;
}

Student::Student(const Student& othStud)
{
	*this = othStud;
}


Student::~Student()
{
	FirstName.clear();
	LastName.clear();
	MiddleName.clear();
}

ostream& operator<<(ostream& out, Student& student)
{
	out << "\n" << student.LastName + " " + student.FirstName + " " + student.MiddleName << "  Birthday: " << student.Birthday << "   Middle grade: " << student.MidGrade;
	return out;
}

istream& operator>>(istream& in, Student& student)
{
	in >> student.LastName;
	in >> student.FirstName;
	in >> student.MiddleName;
	in >> student.Birthday;
	in >> student.MidGrade;
	return in;
}

int Student::compareStudents(const Student first, const Student second)
{
	return first.LastName.compare(second.LastName) > 0 ? 1 :
		(second.LastName.compare(first.LastName) > 0 ? -1 :
		(first.FirstName.compare(second.FirstName) > 0 ? 1 :
			(second.FirstName.compare(first.FirstName) > 0 ? -1 :
			(first.MiddleName.compare(second.MiddleName) > 0 ? 1 :
				(second.MiddleName.compare(first.MiddleName) > 0 ? -1 : 0)))));
}

string Student::getFirstName()
{
	return FirstName;
}

string Student::getLastName()
{
	return LastName;
}

string Student::getMiddleName()
{
	return MiddleName;
}

string Student::getFullName()
{
	return LastName + " " + FirstName + " " + MiddleName;
}

unsigned short Student::getBirthday()
{
	return Birthday;
}

float Student::getMidGrade()
{
	return MidGrade;
}

void Student::setFirstName(string First)
{
	FirstName = First;
}

void Student::setLastName(string Last)
{
	LastName = Last;
}

void Student::setMiddleName(string Middle)
{
	MiddleName = Middle;
}

void Student::setBirthday(unsigned short Birth)
{
	Birthday = Birth;
}

void Student::setMidGrade(float Grade)
{
	MidGrade = Grade;
}

Student& Student::operator=(const Student& obj)
{
	if (this == &obj)
		return *this;
	MidGrade = obj.MidGrade;
	Birthday = obj.Birthday;
	FirstName = obj.FirstName;
	LastName = obj.LastName;
	MiddleName = obj.MiddleName;

	return *this;
}

bool Student::operator==(Student& obj)
{
	return compareStudents(*this, obj) == 0;
}

bool Student::operator!=(Student& obj)
{
	return compareStudents(*this, obj) != 0;
}

bool Student::operator>=(Student& obj)
{
	return compareStudents(*this, obj) != -1;
}

bool Student::operator<=(Student& obj)
{
	return compareStudents(*this, obj) != 1;
}

bool Student::operator<(Student& obj)
{
	return compareStudents(*this, obj) == -1;
}

bool Student::operator>(Student& obj)
{
	return compareStudents(*this, obj) == 1;
}

void Student::PrintAllInfo()
{
	cout << "Student: " << this;
}